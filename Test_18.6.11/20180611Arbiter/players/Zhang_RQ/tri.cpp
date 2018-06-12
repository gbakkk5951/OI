#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cassert>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN=3E6+10;
const int P=1E9+7;
const int inv2=500000004;
const int inv6=166666668;
ll phi[MAXN],s1[MAXN],s2[MAXN],s3[MAXN];
bool vis[MAXN];
int pri[MAXN],tot;
inline ll calc(ll n,ll m,ll a,ll b,ll d) 
{
    ll t1,t2,t3,t4;++n;++m;
    t1=n*m%P*a%P*b%P;
    t2=n*(b+1)%P*b%P*inv2%P*d%P*a%P;
    t3=m*(a+1)%P*a%P*inv2%P*d%P*b%P;
    t4=(a+1)%P*a%P*inv2%P*(b+1)%P*b%P*inv2%P*d%P*d%P;
    return (t1+t4-(t2+t3)%P+P)%P;
}
inline ll get(int tp,int l,int r)
{
    if(tp==1) return ((s1[r]-s1[l-1])%P+P)%P;
    if(tp==2) return ((s2[r]-s2[l-1])%P+P)%P;
    if(tp==3) return ((s3[r]-s3[l-1])%P+P)%P;
    assert(0);return -1;
}
void sieve()
{
    phi[1]=1;
    for(int i=2;i<=3000000;i++)
    {
        if(!vis[i]) pri[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&1ll*pri[j]*i<=3000000;j++)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) {phi[i*pri[j]]=phi[i]*pri[j];break;}
            else phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
    for(int i=1;i<=3000000;i++) s1[i]=(s1[i-1]+phi[i])%P,s2[i]=(s2[i-1]+phi[i]*i%P)%P,s3[i]=(s3[i-1]+phi[i]*i%P*i%P)%P;
}
ll gcd(ll a,ll b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans=0,tans=0,t=(n+1)*(m+1),tmp;
    ans=t*(t-1)%P*(t-2)%P*inv6%P;
    int pos=0,lim=min(n,m);
    for(int i=1;i<=lim;i=pos+1)
    {
        pos=min(n/(n/i),m/(m/i));
        tmp=1ll*(n/i)*(m/i)%P*(n+1)%P*(m+1)%P*get(1,i,pos);
        tmp=(tmp+1ll*(n/i)*(n/i+1)%P*inv2%P*(m/i)%P*(m/i+1)%P*inv2%P*get(3,i,pos)%P)%P;
        tmp=(tmp-(1ll*(m+1)*(m/i)%P*(n/i)%P*(n/i+1)%P*inv2%P*get(2,i,pos)%P+1ll*(n+1)*(n/i)%P*(m/i)%P*(m/i+1)%P*inv2%P*get(2,i,pos)%P)%P+P)%P;
        (tans+=2ll*tmp%P)%=P;
    }
    tans=(tans-2*calc(n,m,n,m,1)%P+P)%P;
    (tans+=(m+1)*(1ll*(n+2)*(n+1)%P*n%P*inv2%P-(1ll*(n+1)*n%P+1ll*n*(n+1)%P*(2*n+1)%P*inv6%P)%P+P)%P)%=P;
	(tans+=(n+1)*(1ll*(m+2)*(m+1)%P*m%P*inv2%P-(1ll*(m+1)*m%P+1ll*m*(m+1)%P*(2*m+1)%P*inv6%P)%P+P)%P)%=P;
    printf("%lld\n",(ans-tans+P)%P);
}

int main()
{
    #ifndef LOCAL
        freopen("tri.in","r",stdin);
        freopen("tri.out","w",stdout);
    #endif
    int T;
    for(sieve(),scanf("%d",&T);T--;solve());
    #ifdef LOCAL
        system("pause");
    #endif
}