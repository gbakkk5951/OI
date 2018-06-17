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
struct edge
{
	int t,n;
}e[N*2];
int a[N],b[N],h[N],par[N],dep[N];
int n,m,tote;
void clear()
{
	tote=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(h,0,sizeof(h));
	memset(dep,0,sizeof(dep));
	memset(par,0,sizeof(par));
	return ;
}
void adde(int f,int t)
{
	e[++tote].t=t;
	e[tote].n=h[f];
	h[f]=tote;
	return ;
}
void dfs(int u,int fa,int d)
{
	queue<int> Q;
	dep[u]=d; par[u]=fa; Q.push(u);
	while (!Q.empty())
	{
		int u=Q.front(); Q.pop();
		for (int i=h[u];i;i=e[i].n)
		{
			int v=e[i].t;
			if (v==par[u]) continue;
			dep[v]=dep[u]+1; par[v]=u;
			Q.push(v);
		}
	}
	return ;
}
void updata(int u,int fa,int o,int x)
{
	queue<int> Q; Q.push(u);
	while (!Q.empty())
	{
		int u=Q.front(); Q.pop();
		if (!o) a[u]=x; else b[u]=x;
		for (int i=h[u];i;i=e[i].n)
		if (e[i].t!=par[u]) Q.push(e[i].t);
	}
	return ;
}
char in[22],out[22];
int main()
{
	for (int t=1;t<=10;t++)
	{
	sprintf(in,"rabbit%d.in",t);
	sprintf(out,"rabbit%d.out",t);
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	clear();
	n=getint(); m=getint();
	for (int i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		adde(u,v); adde(v,u);
	}
	dfs(1,1,1);
	for (int i=1;i<=m;i++)
	{
		char ch[10];
		scanf("%s",ch);
		if (ch[0]=='Q')
		{
			int u=getint(),v=getint(),l=getint(),r=getint(),ans=0;
			while (dep[u]>dep[v])
			{
				if (a[u]>=l&&a[u]<=r) ans=max(ans,b[u]);
				u=par[u];
			}
			while (dep[v]>dep[u])
			{
				if (a[v]>=l&&a[v]<=r) ans=max(ans,b[v]);
				v=par[v];
			}
			while (u!=v)
			{
				if (a[u]>=l&&a[u]<=r) ans=max(ans,b[u]);
				if (a[v]>=l&&a[v]<=r) ans=max(ans,b[v]);
				v=par[v]; u=par[u];
			}
			if (a[u]>=l&&a[u]<=r) ans=max(ans,b[u]);
			printf("%d\n",ans);
		}
		else if (ch[6]=='B')
		{
			int u=getint(),x=getint();
			updata(u,par[u],1,x);
		}
		else 
		{
			int u=getint(),x=getint();
			updata(u,par[u],0,x);			
		}
	}
	fclose(stdin);
	fclose(stdout);
	}
	return 0;
}
