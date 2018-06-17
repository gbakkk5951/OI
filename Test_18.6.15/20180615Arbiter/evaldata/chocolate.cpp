#include<cstdio>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define N 26
#define K 6
#define M 1111111
#define INF 111111111
using namespace std;
int dis[N][N][1<<K],w[N][N],c[N][N],a[N][N],id[N*N];
bool inq[N][N][1<<K];
int n,m,kk,ans;
int sx[M],sy[M],st[M];
int ch[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
inline int min(int a,int b)
{
	return a<b ? a:b;
}
inline void spfa(int x)
{
	int l=1,r=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (dis[i][j][x]!=INF)
	{
		sx[++r]=i; sy[r]=j; st[r]=x;
		inq[i][j][x]=true;
	}
	while (l<=r)
	{
		inq[sx[l]][sy[l]][st[l]]=false;
		for (int i=0;i<4;i++)
		{
			int x=sx[l]+ch[i][0],y=sy[l]+ch[i][1],t;
			if (!(x>=1&&x<=n&&y>=1&&y<=m)||a[x][y]==-1) continue;
			t=st[l]|(1<<(c[x][y]-1)); 
			if (dis[x][y][t]>dis[sx[l]][sy[l]][st[l]]+w[x][y])
			{
				dis[x][y][t]=dis[sx[l]][sy[l]][st[l]]+w[x][y];
				if (!inq[x][y][t])
				{
					inq[x][y][t]=true;
					sx[++r]=x; sy[r]=y; st[r]=t;
				}
			}
		}
		l++;
	}
	return ;
}
int calc()
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		for (int k=1;k<1<<kk;k++) dis[i][j][k]=INF;
		if (c[i][j]!=-1) dis[i][j][1<<(c[i][j]-1)]=w[i][j];
	}
	for (int i=1;i<1<<kk;i++)
	{
		for (int x=1;x<=n;x++)
		for (int y=1;y<=m;y++)
		if (a[x][y]!=-1)
		{
			if (!(i&(1<<(c[x][y]-1)))) continue;
			for (int j=(i-1)&i;j;j=(j-1)&i)
			{
				if (!(j&(1<<(c[x][y]-1)))) continue;
				if (dis[x][y][j]==INF) continue;
				int tmp=dis[x][y][j|(1<<(c[x][y]-1))];
				tmp+=dis[x][y][(i^j)|(1<<(c[x][y]-1))];
				dis[x][y][i]=min(dis[x][y][i],tmp-w[x][y]);
			}
		}
		spfa(i);
		for (int x=1;x<=n;x++)
		for (int y=1;y<=m;y++)
		if (dis[x][y][i]>ans) dis[x][y][i]=INF;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) 
		ans=min(ans,dis[i][j][(1<<kk)-1]);
	return ans;
}
void solve()
{
	scanf("%d%d%d",&n,&m,&kk);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) scanf("%d",&w[i][j]);
	ans=INF;
	for (int t=1;t<=200;t++)
	{
		for (int j=1;j<=n*m;j++) id[j]=rand()%kk+1;
		for (int x=1;x<=n;x++)
		for (int y=1;y<=m;y++) 
		if (a[x][y]==-1) c[x][y]=-1;
		else c[x][y]=id[a[x][y]];
		ans=min(ans,calc());
	}
	if (ans==INF) ans=-1;
	printf("%d\n",ans);
	return ;
}
int main()
{
	freopen("chocolate10.in","r",stdin);
	freopen("chocolate10.out","w",stdout);
	srand(time(0));
	int test;
	scanf("%d",&test);
	for (int i=1;i<=test;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
