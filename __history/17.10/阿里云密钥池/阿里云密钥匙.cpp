using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<vector>
struct _Main{
	
int maxbit;	
long long p,l,r;
long long pow[64];
long long dp1[64][1005];
long long dp2[8][100005];
long long dptmp[100005];
int prime[10000];
int mu[100010];
vector<int>factor[100010];
int cnt;
bool vis[100010];
void getprime(long long mx){
	int i,j,t;
	mu[1]=1;
	for(i=2;i<=mx;i++){
		if(!vis[i]){
			prime[cnt++]=i;mu[i]=-1;
		}
		for(j=0;j<cnt && (t=prime[j]*i)<=mx;j++){
			vis[t]=true;
			if(i%prime[j]){
				mu[t]=-mu[i];
			}else{
				mu[t]=0;
				break;
			}
		}
	}
}
void getfactor(){
	int i;int n;
	for(n=1;n<=100000;n++){
		for(i=1;i*i<=n;i++)if(n%i==0){
			factor[n].push_back(i);
			if(i*i!=n)factor[n].push_back(n/i); 
		}
	}
}

long long *dp[64];
long long getval(int num){
	long long ans=0;int i;
	for(i=0;i<factor[num].size();i++){
		ans+=mu[factor[num][i]]*dptmp[factor[num][i]];
	}return ans;
}
void getdptmp(int bit){
	int i,j,k;
	
	for(i=1;i<p;i++){
		dptmp[i]=0;
	}
	for(i=1;i<p;i++){
		for(j=0;j<factor[i].size();j++){
			dptmp[factor[i][j]]+=dp[bit][i];
		}
	}
}
void getdp(int bit){
	long long i,j;
	for(i=1;i<bit;i++){
		dp[0][i]=1;
	}
	for(i=1;i<=maxbit;i++){
		getdptmp(i-1);
		for(j=1;j<bit;j++){
			dp[i][j]=getval(j);
		}
		dp[i][0]=0;
		for(j=0;j<bit;j++){
			dp[i][0]+=dp[i-1][j];
		}
	}
}
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

long long getans(long long mx){
	if(mx<=0)return 0;
	long long ans=0;int i,j;long long lst=0;long long nd;
	
	for(i=maxbit;i>0 && mx<pow[i];i--); 
	if(i)ans+=dp[i][0];
	
	for( ;i>=0;i--){
		nd=mx/pow[i]%p;
		if(nd==0)break;
		if(i==0)nd++;
		for(j=1;j<nd;j++)if(!lst || gcd(lst,j)==1){
			ans+=dp[i][j];
		}
		
		if(lst && gcd(lst,nd)!=1)break;
		lst=nd;
	}
	return ans;
}
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
void getpointer(int bit){
	int i;
	if(bit>1000){
		for(i=0;i<=maxbit;i++){
			dp[i]=dp2[i];
		}
	}else{
		for(i=0;i<=maxbit;i++){
			dp[i]=dp1[i];
		}
	}
}
_Main(){
	int t;int i;
	getprime(100005);
	getfactor();
	read(t);pow[0]=1;
	while(t--){
		read(l);read(r);read(p);
		for(i=1;r/pow[i-1]>=p ;i++){
			pow[i]=p*pow[i-1];
		}
		maxbit=i-1;
		getpointer(p);
		getdp(p);
		r=getans(r);
		l=getans(l-1);
		printf("%lld\n",r-l);
	}
}
	
	
	
	
}jsk;
