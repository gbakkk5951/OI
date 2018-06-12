#include<cstdio>
#include<algorithm>
using namespace std;const int N=1e5+10;typedef long long ll;
inline ll gcd(ll a,ll b){if(a<b)swap(a,b);while(b){ll c=a%b;a=b;b=c;}return a;}
struct ed
{
	int val;ll nv;int u;int v;
	friend bool operator <(ed a,ed b){return a.nv<b.nv;}
}e[N];int n;int m;
struct bcj
{
	int fa[N];
	inline bool ih(){for(int i=1;i<=n;i++)fa[i]=i;}
	inline int f(int x){return fa[x]=(fa[x]==x)?x:f(fa[x]);}
	inline void u(int x,int y){fa[f(x)]=y;}
}s;
inline void jud(ll x,ll& res,ll& tot)
{
	for(int i=1;i<=m;i++)e[i].nv=(e[i].val-x)*(e[i].val-x);
	sort(e+1,e+m+1);s.ih();res=0;tot=0;
	for(int i=1;i<=m;i++)
	{
		if(s.f(e[i].v)==s.f(e[i].u))continue;
		tot+=e[i].v;res+=e[i].nv;s.u(e[i].u,e[i].v);
	}
}
int main()
{
	freopen("mvst.in","r",stdin);
	freopen("mvst.out","w",stdout);
	scanf("%d%d",&n,&m);ll l=0;ll r=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].val);
		if(e[i].val>0)r+=e[i].val;else l+=e[i].val;
	}ll res=0;ll tot=0;
	while(l!=r)
	{
		int mid=(l+r)/2;ll res;ll tot;jud(mid,res,tot);
		if(mid<tot){l=mid+1;}else {r=mid;}
	}jud(l,res,tot);
	ll g=gcd(res,n-1);printf("%lld/%lld\n",res/g,(n-1)/g);
	fclose(stdin);fclose(stdout);return 0;
}
