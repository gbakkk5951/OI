using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
 
struct _Main{	
int prime[10000];
int cnt;
bool vis[100010];
int mu[100010];
int musum[100010];
void getprime(int mx){
	int i,j,t;musum[1]=mu[1]=1;
	for(i=2;i<=mx;i++){
		if(!vis[i]){
			mu[i]=-1;
			prime[cnt++]=i;
		}
		for(j=0;j<cnt && (t=i*prime[j])<=mx;j++){
			vis[t]=1;
			if(i%prime[j]){
				mu[t]=-mu[i];
			}else{
				mu[t]=0;
				break;
			}
		}musum[i]=musum[i-1]+mu[i];
	}
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
_Main(){
	long long n,m,T;long long i,j,k;long long a,b,c;long long ans=0;
	getprime(100005);
	read(T);
	while(T--){
		read(n);read(m);read(a);
		n/=a;m/=a;
		c=min(m,n);
		for(i=1,ans=0;i<=c;i=j+1){
			j=min(m/(m/i),n/(n/i));
			ans+=(musum[j]-musum[i-1])*(long long)(n/i)*(long long)(m/i);
		}printf("%lld\n",ans);
	}
		
		
	
	
	
	
}	
	
}jsk;
