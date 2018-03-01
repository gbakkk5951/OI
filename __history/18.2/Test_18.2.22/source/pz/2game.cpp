#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define si scanf
#define so printf
#define N 210
#define M (N*N*5)
#define nxt t[j]
#define INF 100000
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0;
	char tmp=getchar();
	if(tmp==EOF)
		return 0;
	if(tmp=='-')
		mns=1;
	while(tmp<'0'||tmp>'9')
	{
		tmp=getchar();
		if(tmp==EOF)
			return 0;
		if(tmp=='-')
			mns=1;
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=r*10+tmp-'0';
		tmp=getchar();
	}
	if(mns)
		r=-r;
	return 1;
}
bool mp[N][N];
int ns[N][N];
int n;
int h[N*2],x[M*2],t[M*2],c[M*2],tot=1;
int S,T,np,ni;
void add(int u,int v,int cap)
{
	++tot;
	x[tot]=h[u];
	h[u]=tot;
	t[tot]=v;
	c[tot]=cap;
}
void ade(int u,int v,int cap)
{
	add(u,v,cap);
	add(v,u,0);
}
int q[N],qr;
int d[N];
bool bfs()
{
	qr=0;
	q[++qr]=S;
	int now;
	memset(d,0,sizeof(int)*(2*n+20));
	d[S]=1;
	for(int i=1;i<=qr;++i)
	{
		now=q[i];
		for(int j=h[now];j;j=x[j])
			if(d[nxt]==0&&c[j])
			{
				d[nxt]=d[now]+1;
				q[++qr]=nxt;
			}
	}
	return d[T];
}
long long pushmore(int now,long long got)
{
	if(now==T)
		return got;
	long long re=0,mr;
	for(int j=h[now];j;j=x[j])
		if(c[j]&&d[nxt]==d[now]+1)
		{
			mr=pushmore(nxt,min(got,1LL*c[j]));
			c[j]-=mr,c[j^1]+=mr;
			got-=mr,re+=mr;
		}
	if(got>0)
		d[now]=0;
	return re;
}
long long Dinic()
{
	long long re=0;
	while(bfs())
		re+=pushmore(S,INF);
	return re;
}
int nxs[N];

bool vis[N];
int stk[N];
int ans=-1;
int ln[N];
void dfs(int tp)
{
	
	int now=stk[tp];
	vis[now]=1;
	if(tp==n)
	{
		if(ans==-1)
		{
			ans=1;
			for(int i=1;i<=n;++i)
				ln[i]=stk[i];
		}
		if(ans==1&&mp[now][stk[1]])
		{
			ans=0;
			for(int i=1;i<=n;++i)
				ln[i]=stk[i];
		}
		vis[now]=0;
		return ;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]&&mp[now][i])
		{
			stk[tp+1]=i;
			dfs(tp+1);
		}
	vis[now]=0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	rd(n);
	S=2*n+3,T=2*n+4;
	int in;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	{
		rd(in);
		mp[i][j]=in;
	}
	if(n<=10)
	{
		for(int i=1;i<=n&&ans!=0;++i)
		{
			stk[1]=i;
			dfs(1);
		}
		so("%d\n",ans);
		for(int i=1;i<=n;++i)
			so("%d ",ln[i]);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		ade(S,i,1);
		ade(i+n,T,1);
		for(int j=1;j<=n;++j)
			if(mp[i][j])
			{
				ade(i,j+n,1);
				ns[i][j]=tot;
			}
	}
	long long re=Dinic();
	if(re==n)//ÍêÃÀÆ¥Åä
	{
		so("0\n");
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(c[ns[i][j]])
				nxs[i]=j;
		int now=1;
		for(int i=1;i<=n;++i)
		{
			so("%d ",now);
			now=nxs[now];
		}
	}
	else if(re==n-1)
	{
		so("1\n");
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(c[ns[i][j]])
				nxs[i]=j;
		int bg=0;
		bool vis[N];
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)
			vis[nxs[i]]=1;
		for(int i=1;i<=n;++i)
			if(!vis[i])
				bg=i;
		int now=bg;
		for(int i=1;i<=n;++i)
		{
			so("%d ",now);
			now=nxs[now];
		}
	}
	else
		so("-1\n");
	return 0;
}
