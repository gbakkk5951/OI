#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<utility>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 1111111111
#define N 111111
#define eps 1e-9
using namespace std;
typedef long long LL;
int getint()
{
	char ch;
	do
	{
		ch=getchar();
	}while (ch!='-'&&(ch<'0'||ch>'9'));
	int ans=0,f=0;
	if (ch=='-') f=1; else ans=ch-'0';
	while (isdigit(ch=getchar())) ans=ans*10+ch-'0';
	if (f) ans*=-1;
	return ans;
}
int lazya[N*4],lazyb[N*4],dep[N],par[N],h[N],L[N],R[N];
int n,m,ta,tb,idx,tote,ans,l,r;
struct edge
{
	int t,n;
}e[N*2];
void adde(int f,int t)
{
	e[++tote].t=t;
	e[tote].n=h[f];
	h[f]=tote;
	return ;
}
void putdown(int o)
{
	if (lazya[o]) lazya[o*2]=lazya[o*2+1]=lazya[o];
	if (lazyb[o]) lazyb[o*2]=lazyb[o*2+1]=lazyb[o];
	lazya[o]=lazyb[o]=0;
	return ;
}
void modify(int o,int l,int r,int ll,int rr,int a,int b)
{
	if (ll<=l&&rr>=r)
	{
		if (a) lazya[o]=a;
		if (b) lazyb[o]=b;
		return ;
	}
	int mid=(l+r)>>1;
	putdown(o);
	if (ll<=mid) modify(o*2,l,mid,ll,rr,a,b);
	if (rr>mid) modify(o*2+1,mid+1,r,ll,rr,a,b);
	return ;
}
void query(int o,int l,int r,int p)
{
	if (l==r)
	{
		ta=lazya[o]; tb=lazyb[o];
		return ;
	}
	int mid=(l+r)>>1;
	putdown(o);
	if (p<=mid) query(o*2,l,mid,p);
	else query(o*2+1,mid+1,r,p);
	return ;
}
void dfs(int u,int d,int fa)
{
	dep[u]=d; par[u]=fa;
	L[u]=++idx;
	for (int i=h[u];i;i=e[i].n)
	if (e[i].t!=fa) dfs(e[i].t,d+1,u);
	R[u]=idx;
	return ;
}
void updata(int u)
{
	query(1,1,n,L[u]);
	if (ta>=l&&ta<=r) ans=max(ans,tb);
	return ;
}
int main()
{
	freopen("rabbit10.in","r",stdin);
	freopen("rabbit10.out","w",stdout);
	n=getint(); m=getint();
	for (int i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		adde(u,v); adde(v,u);
	}
	dfs(1,0,1);
	for (int i=1;i<=m;i++)
	{
		char ch[10];
		scanf("%s",&ch);
		if (ch[0]=='Q')
		{
			int u=getint(),v=getint();
			l=getint(),r=getint();ans=0;
			while (dep[u]>dep[v]) updata(u),u=par[u];
			while (dep[v]>dep[u]) updata(v),v=par[v];
			while (u!=v) 
			{
				updata(u),u=par[u];
				updata(v),v=par[v];
			}
			updata(u);
			printf("%d\n",ans);
		}
		else if (ch[6]=='B')
		{
			int u=getint(),x=getint();
			modify(1,1,n,L[u],R[u],0,x);
		}
		else 
		{
			int u=getint(),x=getint();
			modify(1,1,n,L[u],R[u],x,0);
		}
	}
	return 0;
}
