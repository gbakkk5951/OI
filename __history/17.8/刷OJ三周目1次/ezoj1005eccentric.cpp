int main(){}
using namespace std;
#include<cstdio>
#include<bitset>

int mod;
struct _Main{

bitset<4000010>noprime;
int prime[290000];
int pow[290000];
int mindiv[4000010];
int cnt;
void getprime(int mx){
	int i,j,t;
	for(i=2;i<=mx;i++){
		if(!noprime[i]){
			prime[cnt]=i;
			mindiv[i]=cnt;
			cnt++;
		}
		for(j=0;j<cnt&&(t=prime[j]*i)<=mx ;j++){
			noprime[t]=1;
			mindiv[t]=j;
			if(i%prime[j]==0){
				break;
			}
		}
	}
	
}
void add(int num,int kind=1){
	while(num>1){
		pow[mindiv[num]]+=kind;
		num/=prime[mindiv[num]];
	}
}
long long fastpower(long long base,int pow){
	long long ans=1;
	while(pow){
		if(pow & 1){
			ans=ans*base%mod;
		}
		base=base*base%mod;
		pow>>=1;
	}return ans;
}
long long getans(int max){
	long long ans=1;
	int i;
	for(i=0;prime[i]<=max && i<cnt;i++)if(pow[i]){
		ans=ans*fastpower((long long)prime[i],pow[i])%mod;
	}return ans;
	
}

_Main(){
	int n;int i;
	scanf("%d%d",&n,&mod);
	getprime(4*n);
	for(i=2;i<=n;i++){
		add(4*i-2);add(i+1,-1);
	}printf("%lld\n",getans(4*n));
	
}





}ezoj1005;
