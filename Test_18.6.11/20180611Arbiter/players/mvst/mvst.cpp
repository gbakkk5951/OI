#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define N 100100
#define M 100100
#define INF  1000000000000000000
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int n,m;
struct edge
{
	int u,v,w;
	inline void read()
	{
		rd(u),rd(v),rd(w);
	}
	inline friend bool operator < (edge a,edge b)
	{
		return a.w<b.w;
	}
};
edge e[M];
int ac[N],sz[N];
int get(int u)
{
	if(ac[u]==u)
		return u;
	ac[u]=get(ac[u]);
	return ac[u];
}
inline bool merge(int u,int v)
{
	u=get(u),v=get(v);
	if(u!=v)
	{
		ac[u]=v;
		sz[v]+=sz[u];
		return 1;
	}
	return 0;
}
long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
bool chos[N];
long long sm;
inline long long solve(int l)
{
	if(l+n-2>m)
		return INF;
	for(int i=1;i<=n;++i)
		ac[i]=i,sz[i]=1,chos[i]=0;
	sm=0;
	for(int i=l;i<=m&&sz[get(1)]!=n;++i)
		if(merge(e[i].u,e[i].v))
		{
			sm+=e[i].w;
			chos[i]=1;
		}
	if(sz[get(1)]!=n)
		return INF;
	long long re=0;
	for(int i=l;i<=m;++i)
		if(chos[i])
			re+=(1LL*(n-1)*e[i].w-sm)*(1LL*(n-1)*e[i].w-sm);
	return re;
}
int main()
{
	freopen("mvst.in","r",stdin);
	freopen("mvst.out","w",stdout);
	rd(n),rd(m);
	for(int i=1;i<=m;++i)
		e[i].read();
	sort(e+1,e+m+1);
	long long ans=INF;
	for(int l=1;l<=m;++l)
		ans=min(ans,solve(l));
	long long d=1LL*(n-1)*(n-1)*(n-1);
	long long g=gcd(ans,d);
	ans/=g,d/=g;
	so("%lld/%lld\n",ans,d);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
