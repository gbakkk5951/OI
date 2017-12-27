#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
#define lli long long
#define debug cout
using namespace std;
const int maxn=1e4+1e2;

int in[maxn],fac[maxn],len,n,m;
int vis[maxn],num[maxn];
lli ans;

inline int gcd(int x,int y)
{
    register int t;
    while( t = x % y )
        x=y,y=t;
    return y;
}

inline void getfac(int x)
{
    int sq=sqrt(x);
    for(int i=1;i<=sq;i++)
    {
        if(!(x%i))
        {
            fac[++len] = i;
            if( i*i != x) fac[++len] = x/i;
        }
    }
    sort(fac+1,fac+1+len);
}

inline void getans()
{
    for(int i=1;i<=n;i++)
    {
        int g = gcd( in[i] , m );
        for(int k=1;k<=len;k++)
            vis[k] |= !( fac[k] % g );
    }
    vis[len] = 0;
    
    for(int i=1;i<=len;i++)
    {
        if(vis[i] == num[i]) continue;
        //debug<<"fac = "<<fac[i]<<" lambda = "<<(vis[i] - num[i])<<endl;
        lli tmp = m / fac[i];
        ans += tmp * (tmp-1) / 2 * fac[i] * ( vis[i] - num[i] );
        for(int j=i+1;j<=len;j++)
            if( ! ( fac[j] % fac[i] ) )
                num[j] += vis[i] - num[i];
    }
}

inline int getint()
{
    int ret=0,fix=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fix=-1; ch=getchar();}
    while(ch>='0'&&ch<='9')
        ret=ret*10+(ch-'0'),
        ch=getchar();
    return ret*fix;
}

signed main()
{
    n=getint(),m=getint();
    for(int i=1;i<=n;i++) in[i]=getint();
    
    getfac(m);
    
    //for(int i=1;i<=len;i++) debug<<fac[i]<<" ";debug<<endl;
    
    getans();
    
    printf("%lld\n",ans);
    
    return 0;
}



