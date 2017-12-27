using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
const long long p=1073741824LL;
struct Mod{
template<typename Type>	
	void inline friend operator %= (Type &a,Mod b){
		a%=p;a+=p;a%=p;
	}
}mod;

struct _Main{
long long musqsum[400010];
long long muisum[400010];
long long musum[400010];
int mu[400010]; 
bool vis[400010];
int cnt;
int prime[34000];

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
	
void getprime(int mx){
	int i,j,t;
	mu[1]=1;
	for(i=2;i<=mx;i++){
		if(!vis[i]){
			prime[cnt++]=i;
			mu[i]=-1;
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
void getsum(int mx){
	long long i;
	for(i=1;i<=mx;i++){
		musum[i]=musum[i-1]+mu[i];
		muisum[i]=muisum[i-1]+i*mu[i];
		musqsum[i]=musqsum[i-1]+i*i*mu[i];
		musum[i]%=p;muisum[i]%=p;musqsum[i]%=p;
	}
}
long long ans;
_Main(){
	long long i,j,k;long long a,b,c;long long k1,k2;
	long long t,m,n;
	getprime(400005);
	getsum(400005);
	read(t);


	while(t--){
		ans=0;
		read(n);read(m);
		m--;n--;
		c=min(m,n);
		for(i=1;i<=c;i=j+1){
			j=min(m/(m/i),n/(n/i));
			k1=n/i;k2=m/i;	
			ans+=(musum[j]-musum[i-1])*k1*k2%p*(m+1)*(n+1)%p;
			ans+=-(m+1)*(muisum[j]-muisum[i-1])*(1+k1)*k1/2%p*k2%p;
			ans+=-(n+1)*(muisum[j]-muisum[i-1])*(1+k2)*k2/2%p*k1%p;
			ans+=(musqsum[j]-musqsum[i-1])*(1+k1)*k1/2%p*(1+k2)*k2/2%p;
		}
		a=ans;
		c=min((m+1)/2,(n+1)/2);
		for(i=1;i<=c;i=j+1){
			j=min(m/(m/i),n/(n/i));
			j=min(((m+1)/2)/((m+1)/2/i),j);
			j=min(((n+1)/2)/((n+1)/2/i),j);
			k1=min(n/i,(n+1)/2/i);
			k2=min(m/i,(m+1)/2/i);
			ans-=(musum[j]-musum[i-1])*k1*k2%p*(m+1)*(n+1)%p;
			ans-=-2*(m+1)*(muisum[j]-muisum[i-1])*(1+k1)*k1/2%p*k2%p;
			ans-=-2*(n+1)*(muisum[j]-muisum[i-1])*(1+k2)*k2/2%p*k1%p;
			ans-= 4*(musqsum[j]-musqsum[i-1])*(1+k1)*k1/2%p*(1+k2)*k2/2%p;
		}
		ans*=2;ans+=m+n+1+1;
		ans%=mod;
		printf("%lld\n",ans);
		
	}
}







	
}jsk;
