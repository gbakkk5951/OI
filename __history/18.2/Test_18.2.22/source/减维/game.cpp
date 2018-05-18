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
#define maxn 205
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
	int to,ne,cap,pd;
}e[maxn*maxn*8];

int n,s,t,ans,top,ecnt=1,head[maxn<<2],layer[maxn<<2],nxt[maxn<<2],sta[maxn<<2];
bool pd[maxn<<2],vis[maxn<<2];

void add(int x,int y,int z,int v)
{
	e[++ecnt]=(edge){y,head[x],z,v};head[x]=ecnt;
	e[++ecnt]=(edge){x,head[y],0,0};head[y]=ecnt;
}

bool bfs()
{
	queue<int>q;q.push(s);
	memset(layer,0,sizeof layer);layer[s]=1;
	while(!q.empty())
	{
		int d=q.front();q.pop();
		for(int i=head[d];i;i=e[i].ne)
		{
			int dd=e[i].to;
			if(e[i].cap>0&&!layer[dd])
			{
				layer[dd]=layer[d]+1;
				if(dd==t) return 1;
				q.push(dd);
			}
		}
	}
	return 0;
}

int dfs(int x,int cap)
{
	if(x==t||!cap) return cap;
	int tmp,ret=0;
	for(int i=head[x];i;i=e[i].ne)
	{
		int dd=e[i].to;
		if(layer[dd]==layer[x]+1&&e[i].cap>0)
		{
			tmp=dfs(dd,min(cap,e[i].cap));
			ret+=tmp,cap-=tmp;
			e[i].cap-=tmp,e[i^1].cap+=tmp;
			if(cap==0) return ret;
		}
	}
	if(!ret) layer[x]=0;
	return ret;
}

int dinic()
{
	int ret=0;
	while(bfs()) ret+=dfs(s,inf);
	return ret;
}

void bl()
{
	for(int x=1;x<=n;++x)
	{
		for(int i=head[x];i;i=e[i].ne)
		{
			int dd=e[i].to;
			if(dd!=s&&e[i].cap==0) nxt[x]=dd-n,pd[dd-n]=1;
		}
	}
}

void dfs(int x)
{
	//printf("%d %d\n",x,top);
	if(top==n+1){
		if(sta[n+1]!=1) return ;
		for(int i=1;i<=n;++i) printf("%d ",sta[i]);
		exit(0);
	}
	for(int i=head[x];i;i=e[i].ne)
	{
		int dd=e[i].to;
		if(vis[dd-n]) continue;
		if(e[i].pd){
			vis[dd-n]=1;
			sta[++top]=dd-n;
			dfs(dd-n);
			top--;
			vis[dd-n]=0;
		}
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	s=0,t=2*n+1;
	for(int i=1,x;i<=n;++i)
	{
		add(s,i,1,0);
		for(int j=1;j<=n;++j)
		{
			x=read();
			if(i<=j) continue;
			if(x) add(i,n+j,1,1);
			else if(i!=j) add(j,n+i,1,1);
		}
		add(i+n,t,1,0);
	}
	ans=dinic();
	bl();
//	for(int i=1;i<=n;++i) printf("%d ",nxt[i]);puts("");
	if(ans==n){
		puts("0");
		sta[++top]=1;dfs(1);
	}else if(ans==n-1){
		puts("1");
		int x;
		for(int i=1;i<=n;++i) if(!pd[i]) x=i;
		while(x!=0){
			printf("%d ",x);
			x=nxt[x];
		}
	}else{
		puts("-1");
	}
	return 0;
}

/*
5
0 0 1 1 1
1 0 1 1 0
0 0 0 1 0
0 0 0 0 1
0 1 1 0 0
4
0 1 0 0
0 0 1 0
1 0 0 1
1 1 0 0
5 
0 0 1 1 1
1 0 1 1 0
0 0 0 1 0
0 0 0 0 0
0 1 1 1 0

*/
