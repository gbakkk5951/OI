#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
int n,MOD;
int a[1000005];
ll f[1000005],ny[1000005],g[1005][1005];
ll Ny(ll x)
{
    ll s1=1LL,s2=(ll)x,m=MOD-2;
    while (m)
    {
        if (m&1) s1=s1*s2%MOD;
        m>>=1;
        s2=s2*s2%MOD;
    }
    return s1;
}
ll C(ll x,ll y)
{
    return f[x]*ny[y]%MOD*ny[x-y]%MOD;
}
int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    cin>>n>>MOD;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    if (n<=1000)
    {
        for (int i=1;i<=n;++i) g[i][0]=g[i][i]=1;
        for (int i=2;i<=n;++i) for (int j=1;j<i;++j) g[i][j]=(g[i-1][j-1]+g[i-1][j])%MOD;
        ll ans=0LL;
        for (int i=1;i<=n;++i) ans=(ans+(ll)(g[n-1][i-1])*a[i])%MOD;
        cout<<ans<<endl;
        return 0;
    }
    f[0]=1LL;
    for (int i=1;i<=n;++i) f[i]=f[i-1]*i%MOD;
    for (int i=0;i<=n;++i) ny[i]=Ny(f[i]);
    ll ans=0LL;
    for (int i=1;i<=n;++i) ans=(ans+C(n-1,i-1)*a[i])%MOD;
    cout<<ans<<endl;
}
