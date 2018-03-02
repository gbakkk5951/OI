#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define si scanf
#define so printf
#define N 110
#define M (N*N*5)
#define INF 100000000
#define nxt t[j]
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
int n,m;
int h[N],x[M*2],t[M*2],c[M*2],cori[M*2],tot=1;
int S,T,np,ni;
void add(int u,int v,int cap)
{
	++tot;
	x[tot]=h[u];
	h[u]=tot;
	t[tot]=v;
	c[tot]=cap;
	cori[tot]=cap;
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
	memset(d,0,sizeof(int)*(np+10));
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
int ks[N];
struct info
{
	int a,b,c;
	info(int aa=0,int bb=0,int cc=0)
	{
		a=aa,b=bb,c=cc;
	}
};
info nf[M];
int ns[N][N];
int dcs[N];
bool fbd[N][N];
long long ans=0;
void dfs(int po)
{
	if(po>ks[1])
	{
		memset(h,0,sizeof(int)*(np+10));
		np=2,tot=1;
		memset(fbd,0,sizeof(fbd));
		for(int j=1;j<=ks[1];++j)
			fbd[1][j]=1;
		for(int i=1;i<=ni;++i)
			if(nf[i].c==1)
			{
				if(dcs[nf[i].a])
					fbd[nf[i].c%m+1][nf[i].b]=1;
			}
			else if(nf[i].c==m)
			{
				if(dcs[nf[i].b])
					fbd[nf[i].c][nf[i].a]=1;
			}
		for(int i=2;i<=m;++i)
			for(int j=1;j<=ks[i];++j)
				if(!fbd[i][j])
					ns[i][j]=++np;
		for(int j=1;j<=ks[1];++j)
			ns[m+1][j]=ns[1][j],fbd[m+1][j]=fbd[1][j];
		for(int i=2;i<=m;++i)
			for(int j=1;j<=ks[i];++j)
				if(!fbd[i][j])
				{
					if(i&1)
						ade(S,ns[i][j],1);
					else
						ade(ns[i][j],T,1);
				}
		for(int i=1;i<=ni;++i)
			if(!fbd[nf[i].c][nf[i].a]&&!fbd[nf[i].c%m+1][nf[i].b])
			{
				if(nf[i].c&1)
					ade(ns[nf[i].c][nf[i].a],ns[nf[i].c+1][nf[i].b],INF);
				else
					ade(ns[nf[i].c+1][nf[i].b],ns[nf[i].c][nf[i].a],INF);
			}
		int cnt=0;
		for(int i=1;i<=ks[1];++i)
			cnt+=dcs[i];
		ans=max(ans,np-2-Dinic()+cnt);
		return;
	}
	dcs[po]=0;
	dfs(po+1);
	dcs[po]=1;
	dfs(po+1);
}
int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	S=++np,T=++np;
	rd(m);
	int a,b,c;
	while(rd(a)&&rd(b)&&rd(c))
	{
		nf[++ni]=info(a,b,c);
		ks[c]=max(ks[c],a);
		ks[c%m+1]=max(ks[c%m+1],b);
	}
	
	if((m&1)==0)//Å¼Êý 
	{
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=ks[i];++j)
				ns[i][j]=++np;
		}
		for(int j=1;j<=ks[1];++j)
			ns[m+1][j]=ns[1][j];
		for(int i;i<=m;++i)
			for(int j=1;j<=ks[i];++j)
				if(i&1)
					ade(S,ns[i][j],1);
				else
					ade(ns[i][j],T,1);
		for(int i=1;i<=ni;++i)
			if(nf[i].c&1)
				ade(ns[nf[i].c][nf[i].a],ns[nf[i].c+1][nf[i].b],INF);
			else
				ade(ns[nf[i].c+1][nf[i].b],ns[nf[i].c][nf[i].a],INF);
		long long ans=np-2-Dinic();
		so("%lld\n",ans);
	}
	else
	{
		int mn=1;
		for(int i=1;i<=m;++i)
			if(ks[i]<ks[mn])
				mn=i,n+=ks[i];
		for(int i=1;i<=ni;++i)
			nf[i].c=(nf[i].c-mn+m)%m+1;
		for(int i=1;i<=m;++i)
			ks[i]=0;
		for(int i=1;i<=ni;++i)
		{
			ks[nf[i].c]=max(ks[nf[i].c],nf[i].a);
			ks[nf[i].c%m+1]=max(ks[nf[i].c%m+1],nf[i].b);
		}
		dfs(1);
		so("%lld\n",ans);
	}
	return 0;
}
