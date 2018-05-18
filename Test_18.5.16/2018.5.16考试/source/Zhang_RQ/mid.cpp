#include<cstdio>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN=4.4E7+10;
const int P=1E9+7;
int val[MAXN],ls[MAXN],rs[MAXN],mid,cnt=1,n,a;
ll ans=0;
int lsans;
void change(int pos)
{
    int x=1,l=1,r=1E9+6;
    while(l<r)
    {
        mid=(l+r)>>1;val[x]++;
        if(pos<=mid) r=mid,x=ls[x]?ls[x]:ls[x]=++cnt;
        else l=mid+1,x=rs[x]?rs[x]:rs[x]=++cnt;
    }
    val[x]++;
}
int query(int rk)
{
    int x=1,l=1,r=1E9+6;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(rk<=val[ls[x]]) x=ls[x],r=mid;
        else rk-=val[ls[x]],x=rs[x],l=mid+1;
    }
    return l;
}
int main()
{
    #ifndef LOCAL
        freopen("mid.in","r",stdin);
        freopen("mid.out","w",stdout);
    #endif
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
    {
        change(a);
        lsans=query((1+i)>>1);
        a=((1714636915ll*a+1681692777)%P*((846930886ll*lsans+1804289383)%P))%P;
        ans^=lsans;
    }
    printf("%lld\n",ans);
}
