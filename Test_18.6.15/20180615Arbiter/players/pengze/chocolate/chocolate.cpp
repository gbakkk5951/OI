#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define si scanf
#define so printf
#define N 30
#define INF 10000000000000000
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
int r,c,K,np;
int a[N][N],ns[N][N];
long long b[N][N];
int as[N*N];
long long bs[N*N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int d[N*N][N*N];
long long ans=INF;
namespace BF
{
	int ac[100];
	int get(int u)
	{
		if(ac[u]==u)
			return u;
		ac[u]=get(ac[u]);
		return ac[u];
	}
	inline void merge(int u,int v)
	{
		u=get(u),v=get(v);
		if(u!=v)
			ac[u]=v;
	}
	int vis[100],cnt;
	long long sm;
	bool ln[100];
	void dfs(int now)
	{
		if(now>np)
		{
			cnt=0;
			for(int i=1;i<=np;++i)
				vis[as[i]]=0,ac[i]=i;
			for(int i=1;i<=np;++i)
				if(ln[i]&&!vis[as[i]])
				{
					vis[as[i]]=1;
					++cnt;
				}
			if(cnt<K)
				return;
			for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				if(ns[i][j]&&ln[ns[i][j]])
					for(int k=0;k<4;++k)
						if(ns[i+dy[k]][j+dx[k]]&&ln[ns[i+dy[k]][j+dx[k]]])
							merge(ns[i][j],ns[i+dy[k]][j+dx[k]]);
			cnt=0,sm=0;
			for(int i=1;i<=np;++i)
				if(ln[i])
				{
					sm+=bs[i];
					if(get(i)==i)
						++cnt;
				}
			if(cnt==1)
				ans=min(ans,sm);
			return;
		}
		ln[now]=0;
		dfs(now+1);
		ln[now]=1;
		dfs(now+1);
		ln[now]=0;
	}
}
long long f[N*N][600];
inline void init()
{
	np=0;
	memset(d,0x3f,sizeof(d));
	memset(ns,0,sizeof(ns));
	memset(f,0x3f,sizeof(f));
}
inline int cnt(int s)
{
	int re=0;
	for(int i=0;i<=8;++i)
		if(s&(1<<i))
			++re;
	return re;
}
int main()
{
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	int T;
	rd(T);
	while(T--)
	{
		init();
		rd(r),rd(c),rd(K);
		for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
		{
			rd(a[i][j]);
			if(a[i][j]!=-1)
				ns[i][j]=++np;
		}
		for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			rd(bs[ns[i][j]]),as[ns[i][j]]=a[i][j];
		if(r*c<=20)
			BF::dfs(1);
		else
		{
			for(int i=1;i<=np;++i)
				d[i][i]=0;
			for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
			for(int k=0;k<4;++k)
			{
				if(ns[i+dy[k]][j+dx[k]])
					d[ns[i][j]][ns[i+dy[k]][j+dx[k]]]=bs[ns[i+dy[k]][j+dx[k]]];
			}
			for(int k=1;k<=np;++k)
			for(int i=1;i<=np;++i)
			for(int j=1;j<=np;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			for(int i=1;i<=np;++i)
			for(int j=1;j<=np;++j)
				f[i][1<<as[j]]=min(f[i][1<<as[j]],d[j][i]+bs[j]);
			for(int s=1,sub;s<(1<<9);++s)
			{
				for(int i=1;i<=np;++i)
				for(int sub=(s-1)&s;sub;sub=(sub-1)&s)
					f[i][s]=min(f[i][s],f[i][sub]+f[i][s^sub]-bs[i]);
				for(int i=1;i<=np;++i)
				for(int j=1;j<=np;++j)
					f[i][s]=min(f[i][s],f[j][s]+d[j][i]);
				if(cnt(s)>=K)
					for(int i=1;i<=np;++i)
						ans=min(ans,f[i][s]);
			}

		}
		
		if(ans>=INF)
			so("-1\n");
		else
			so("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
