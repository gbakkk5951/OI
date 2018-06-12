//by achhhy
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
inline int in()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}
//need changing
const int inf=(1<<30);
const int mod=1e9+7;
const int N=100010;

int n,m,fa[N];
LL A,B,ans=-1,val[N];

struct E
{
	int u,v,w;
	bool operator <(const E &a) const {return w<a.w;}
}e[N];

LL f(int x) {return 1ll*x*x;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
inline int find(int x) {return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}

bool solve(int k)
{
	rep(i,1,n) fa[i]=i;
	LL sum=0;
	int o=0;
	rep(i,k,m)
	{
		int u=e[i].u,v=e[i].v;
		int r1=find(u),r2=find(v);
		if(r1==r2) continue;
		fa[r1]=r2;
		sum+=e[i].w;	
		val[++o]=e[i].w;
		if(o==n-1) break;
	}
	if(o<n-1) return 0;
	LL ret=0;
	rep(i,1,n-1) ret+=f(sum-val[i]*(n-1));
	if((ans==-1)|| ret<ans) ans=ret;
	
//	LL G=gcd(1ll*(n-1)*(n-1)*(n-1),ret);
//	printf("%lld/%lld\n",ret/G,1ll*(n-1)*(n-1)*(n-1)/G);
	
	return 1;
}

int main()
{
	freopen("mvst.in","r",stdin);
	freopen("mvst.out","w",stdout);
	n=in(),m=in();
	rep(i,1,m) e[i].u=in(),e[i].v=in(),e[i].w=in();
	sort(e+1,e+m+1);
	rep(i,1,m) if(!solve(i)) break;
	LL G=gcd(1ll*(n-1)*(n-1)*(n-1),ans);
	printf("%lld/%lld\n",ans/G,1ll*(n-1)*(n-1)*(n-1)/G);
	return 0;
}



