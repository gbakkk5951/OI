using namespace std;
int main(){}
#include<cstdio>
const long long mod=(long long)1e9+7;
struct _Main{
long long ans;
long long sum;
long long tmp;
long long getdiv(long long base){
	long long ans=1;
	int pow=mod-2;
	while(pow){
		if(pow&1){
			ans=ans*base%mod;
		}
		if(pow>>=1)
			base=base*base%mod;
	}
	return ans;
}
long long n,m;  
     
_Main(){
    int i;
    scanf("%lld%lld",&n,&m);
    getdiv(n);
    ans=m;sum=m;
    for(i=2;i<=n;i++){
        tmp=(m+(m-1)*getdiv(i)%mod*sum)%mod;
        ans+=tmp;
        sum=(sum+i*tmp)%mod;
    }
    ans%=mod;
    printf("%lld",ans);
}
     
     
     
}ezoj1179;
