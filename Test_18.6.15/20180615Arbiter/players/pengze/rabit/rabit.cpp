#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define N 100100
#define nxt t[j]
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
namespace seg
{
	#define ls (o<<1)
	#define rs (ls|1)
	int l[N*4],r[N*4];
	int tag[N*4][2];
	void build(int o,int ll,int rr)
	{
		l[o]=ll,r[o]=rr;
		tag[o][0]=tag[o][1]=0;
		if(ll==rr)	return;
		int mid=(ll+rr)>>1;
		build(ls,ll,mid),build(rs,mid+1,rr);
	}
	inline void update(int o,int col,int cnt)
	{
		tag[o][col]=cnt;
	}
	inline void pass(int o)
	{
		if(tag[o][0]>=0&&l[o]!=r[o])
		{
			update(ls,0,tag[o][0]);
			update(rs,0,tag[o][0]);
		}
		if(tag[o][1]>=0&&l[o]!=r[o])
		{
			update(ls,1,tag[o][1]);
			update(rs,1,tag[o][1]);
		}
		tag[o][0]=tag[o][1]=-1;
	}
	void modify(int o,int ll,int rr,int col,int cnt)
	{
		if(ll<=l[o]&&r[o]<=rr)
		{
			update(o,col,cnt);
			return;
		}
		pass(o);
		int mid=(l[o]+r[o])>>1;
		if(ll<=mid)
			modify(ls,ll,rr,col,cnt);
		if(mid+1<=rr)
			modify(rs,ll,rr,col,cnt);
		return;
	}
	inline int ask(int po,int col)
	{
		int o=1,mid;
		while(l[o]!=r[o])
		{
			pass(o);
			mid=(l[o]+r[o])>>1;
			if(po<=mid)
				o=ls;
			else
				o=rs;
		}
		return tag[o][col];
	}
}
int n,nq;
int h[N],x[N*2],t[N*2],tot=1;
inline void ade(int u,int v)
{
	++tot;
	x[tot]=h[u];
	h[u]=tot;
	t[tot]=v;
}
int bs[N][2],df,f[N][21],dep[N];
void dfs(int now,int fa)
{
	dep[now]=dep[fa]+1;
	f[now][0]=fa;
	bs[now][0]=++df;
	for(int j=h[now];j;j=x[j])
		if(nxt!=fa)
			dfs(nxt,now);
	bs[now][1]=df;
}
inline int LCA(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int k=20;k>=0;--k)
		if(dep[f[u][k]]>=dep[v])
			u=f[u][k];
	if(u==v)	return u;
	for(int k=20;k>=0;--k)
		if(f[u][k]!=f[v][k])
			u=f[u][k],v=f[v][k];
	return f[u][0];
}
inline int solve(int u,int lca,int l,int r)
{
	int re=0,cntw;
	while(u)
	{
		cntw=seg::ask(bs[u][0],0);
		if(l<=cntw&&cntw<=r)
			re=max(re,seg::ask(bs[u][0],1));
		if(u==lca)
			return re;
		else
			u=f[u][0];
	}
	return re;
}
int main()
{
	freopen("rabit.in","r",stdin);
	freopen("rabit.out","w",stdout);
	rd(n),rd(nq);
	for(int i=1,u,v;i<n;++i)
	{
		rd(u),rd(v);
		ade(u,v),ade(v,u);
	}
	dfs(1,0);
	seg::build(1,1,n);
	for(int k=1;k<=20;++k)
	for(int i=1;i<=n;++i)
		f[i][k]=f[f[i][k-1]][k-1];
	char op[10];
	for(int qq=1,u,v,l,r,lca;qq<=nq;++qq)
	{
		si("%s",op+1);
		if(op[1]=='C')
		{
			rd(u),rd(v);
			if(op[7]=='W')
				seg::modify(1,bs[u][0],bs[u][1],0,v);
			else
				seg::modify(1,bs[u][0],bs[u][1],1,v);
		}
		else
		{
			rd(u),rd(v),rd(l),rd(r),lca=LCA(u,v);
			so("%d\n",max(solve(u,lca,l,r),solve(v,lca,l,r)));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
