#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=150;
const int P=1234567891;
int T,k;
ll a,n,d,m;
ll s1[N],s2[N];
ll g[N],f[N],inv[N<<1];
inline void Add(ll& x,ll y){
    x=(x+y)%P;
}
inline ll Pow(ll x,ll y){
    ll Ans=1;
    for(;y;y>>=1,x=x*x%P)
    if(y&1)Ans=Ans*x%P;
    return Ans;
}
inline void Init(int n){
    inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=inv[P%i]*(P-P/i)%P;
    for(int i=2;i<=n;i++)inv[i]=inv[i]*inv[i-1]%P;
}
inline ll Lagrange(ll* a,int n,ll pos){
    if(pos<=n)return a[pos];
    s1[0]=s2[n+1]=1;
    for(int i=1;i<=n;i++)s1[i]=s1[i-1]*(pos-i)%P;
    for(int i=n;i;i--)s2[i]=s2[i+1]*(pos-i)%P;
    ll Ans=0;
    for(int i=1;i<=n;i++)Add(Ans,a[i]*s1[i-1]%P*s2[i+1]%P*inv[i-1]%P*inv[n-i]%P*((n-i)&1?-1:1));
    return Ans;
}
int main(){
    scanf("%d",&T);
    Init(300);
    while(T--){
        scanf("%d%lld%lld%lld",&k,&a,&n,&d);
        for(int i=1;i<=k+3;i++)g[i]=Pow(i,k);
        for(int i=2;i<=k+3;i++)Add(g[i],g[i-1]);
        for(int i=2;i<=k+3;i++)Add(g[i],g[i-1]);
        f[0]=Lagrange(g,k+3,a);
        for(int i=1;i<=k+5;i++)f[i]=Lagrange(g,k+3,(i*d+a)%P),Add(f[i],f[i-1]);
        printf("%lld\n",(Lagrange(f,k+5,n)+P)%P);
    }
    return 0;
}
