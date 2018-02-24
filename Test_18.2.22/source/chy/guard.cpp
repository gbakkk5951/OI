//by sdfzchy
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long LL;
const int inf=(1<<30),N=110;
inline int in()
{
	char ch=getchar();
	int f=1,tmp=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {tmp=(tmp<<1)+(tmp<<3)+(ch-'0');ch=getchar();}
	return tmp*f;
}

int n,m,cnt;
int num[N][N],ecnt,head[N];
struct E
{
	int from,to,nxt;
}e[N*N];

struct node
{
	int id,cnt;
}p[N];

void add(int u,int v)
{
	++ecnt; e[ecnt]=(E){u,v,head[u]}; head[u]=ecnt;
	++ecnt; e[ecnt]=(E){v,u,head[v]}; head[v]=ecnt;
	p[u].cnt++;
	p[v].cnt++;
}

bool vis[N],cs[N];

bool cmp1(node a,node b)
{
	return a.cnt<b.cnt;
}
int pp[N];

int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	srand(time(0));
	n=in();
	int A,B,C,D;
	while(~scanf("%d%d%d",&A,&B,&C))
	{
		D=C==n?1:C+1;
		if(!num[C][A]) num[C][A]=++cnt;
		if(!num[D][B]) num[D][B]=++cnt;
		add(num[C][A],num[D][B]);
	}
	for(int i=1;i<=cnt;i++) p[i].id=i;
	sort(p+1,p+cnt+1,cmp1);
	int ans=0;
	for(int T=1;T<=1;T++)
	{
		int ret=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=cnt;i++)
		{
			int u=p[i].id;
			if(vis[u]) continue;
			ret++;	vis[u]=1;
			for(int j=head[u];j;j=e[j].nxt)	vis[e[j].to]=1;	
		}
		ans=max(ans,ret);
	}
	for(int i=1;i<=cnt;i++) pp[i]=p[i].id;
	for(int T=1;T<=100000;T++)
	{
		int ret=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=cnt;i++)
		{
			int u=pp[i];
			if(vis[u]) continue;
			ret++; vis[u]=1;
			for(int j=head[u];j;j=e[j].nxt)	vis[e[j].to]=1;	
		}
		ans=max(ans,ret);
		for(int j=1;j<=n;j++) swap(pp[rand()%cnt+1],pp[rand()%cnt+1]);
	}
	cout<<ans<<endl;
	return 0;
}

