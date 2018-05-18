using namespace std;
int main(){}
#include<cstdio>
 
const long long mod=(long long)1e9+7;
 
struct _Main{
long long ans;
long long sum;
long long tmp;
int div[5000010];
 
void getdiv(int mx){
    int i;
    div[1]=1;
    for(i=2;i<=mx;i++){
        div[i]=(long long)-mod/i*div[mod%i]%mod+mod;
    }
}
long long n,m;  
     
_Main(){
    int i;
    scanf("%lld%lld",&n,&m);
    getdiv(n);
    ans=m;sum=m;
    for(i=2;i<=n;i++){
        tmp=(m+(m-1)*div[i]%mod*sum)%mod;
        ans+=tmp;
        sum=(sum+i*tmp)%mod;
    }
    ans%=mod;
    printf("%lld",ans);
}
     
     
     
}ezoj1179;
