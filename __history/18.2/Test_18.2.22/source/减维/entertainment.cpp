//by ¼õÎ¬
#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define il inline
#define db double
#define rg register
#define mpr make_pair
#define maxn 1005
#define eps 1e-8
#define inf (1<<30)
#define pi 3.1415926535897932384626L
using namespace std;

inline int read()
{
    int ret=0;bool fla=0;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-'){fla=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return fla?-ret:ret;
}

struct edge{
	int to,ne,cap,val;
}e[maxn<<3];

int n,k,s,ss,tt,ms,me,mx,mn,ecnt=1,head[maxn],dis[maxn];
ll sum,ans,a[maxn],b[maxn];
bool pd[maxn],vis[maxn];

void add(int x,int y,int z,int v)
{
	e[++ecnt]=(edge){y,head[x],z,v};head[x]=ecnt;
	e[++ecnt]=(edge){x,head[y],0,-v};head[y]=ecnt;
}

bool bfs()
{
	deque<int>q;q.push_back(tt);
	for(int i=0;i<=tt;++i) dis[i]=inf;dis[tt]=0;
	memset(pd,0,sizeof pd);pd[tt]=1;
	while(!q.empty())
	{
		int d=q.front();q.pop_front();
		pd[d]=0;
		for(int i=head[d];i;i=e[i].ne)
		{
			int dd=e[i].to;
			if(e[i^1].cap&&dis[dd]>dis[d]-e[i].val)
			{
				dis[dd]=dis[d]-e[i].val;
				if(!pd[dd]){
					pd[dd]=1;
					if(q.empty()||dis[dd]>dis[q.front()]) q.push_back(dd);
					else q.push_front(dd);
				}
			}
		}
	}
	return dis[ss]<inf;
}

int dfs(int x,int cap)
{
	vis[x]=1;
	if(x==tt||!cap)return cap;
	int tmp,ret=0;
	for(int i=head[x];i;i=e[i].ne)
	{
		int dd=e[i].to;
		if(!vis[dd]&&e[i].cap&&dis[dd]==dis[x]-e[i].val)
		{
			tmp=dfs(dd,min(e[i].cap,cap));
			cap-=tmp;ret+=tmp;
			e[i].cap-=tmp;e[i^1].cap+=tmp;
		}
	}
	return ret;
}

ll zkw()
{
	ll ret=0;
	while(bfs())
	{
		vis[tt]=1;
		while(vis[tt])
		{
			memset(vis,0,sizeof vis);
			ret+=1ll*dfs(ss,inf)*dis[ss];
		}
	}
	return ret;
}

int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	n=read();k=read();ms=read();me=read();
	s=0,ss=n+1,tt=n+2;
	mn=me,mx=k-ms;
	for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i];
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=n;++i) add(i,i+1<=n?i+1:tt,mx-mn,0);
	for(int i=1;i<=n;++i) add(i,i+k<=n?i+k:tt,1,a[i]-b[i]);
	for(int i=1;i<=k;++i) add(s,i,inf,0);
	add(ss,s,mx,0);
	ans=zkw();
	printf("%lld",sum-ans);
	return 0;
}
/*
10 4 1 2
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
*/

























