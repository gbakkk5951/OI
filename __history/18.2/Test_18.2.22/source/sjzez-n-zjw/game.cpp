#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n;
int val[205][205];
int f[205][205];
int dis[205];
int vis[203];
int tot,point[400005],nxt[400005],had[405];
inline void add(int x,int y)
{
	tot++;
	point[tot]=y;
	nxt[tot]=had[x];
	had[x]=tot;
}
int pre[204];
int num[205];
int out[205];
inline void find_cir(int s)
{
	queue<int>q;
	q.push(s);
	vis[s]=1;
	num[s]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		vis[t]=0;
		if(num[t]==n)
			break;
		for(int i=had[t];i;i=nxt[i])
		{
			int to=point[i];
			if(dis[to]<dis[t]+1)
			{
				dis[to]=dis[t]+1;
				if(vis[to]==0)
				{
					q.push(to);
					vis[to]=1;
					pre[to]=t;
					num[to]++;
				}
			}
		}
	}
	int j=n;
	out[n]=s;
	for(int i=pre[s];i!=s;i=pre[i])
		out[--j]=i;
	for(int i=1;i<=n;i++)
		printf("%d ",out[i]);
	return;
}
struct dou{
	int num;
	int val;
};
bool operator < (dou x,dou y)
{
	if(x.val==y.val)return x.num<y.num;
	return x.val<y.val;
}
inline void find_way(int s)
{
/*	queue<int>q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		vis[t]=0;
		if(dis[t]==n-1)break;
		for(int i=had[t];i;i=nxt[i])
		{
			int to=point[i];
			if(dis[to]<dis[t]+1)
			{
				dis[to]=dis[t]+1;
				if(vis[to]==0)
				{
					q.push(to);
					vis[to]=1;
					pre[to]=t;
				}
			}
		}
	}*/
	priority_queue<dou>q;
	dou x;
	x.num=s;
	x.val=0;
	q.push(x);
	int cnt=0;
	while(!q.empty())
	{
		dou y=q.top();
		int t=y.num;
		q.pop();
		cnt++;
		if(cnt==n)break;	
		for(int i=had[t];i;i=nxt[i])
		{
			int to=point[i];
			if(dis[to]<dis[t]+1)
			{
				pre[to]=t;
				dis[to]=dis[t]+1;
				dou x;
				x.num=to;
				x.val=dis[to];
				q.push(x);
			}
		}
	}
		int nd;
	for(int i=1;i<=n;i++)
		if(dis[i]==n-1)
		{
			nd=i;
			break;
		}
	int j=n;
	for(int i=nd;i;i=pre[i])
		out[j--]=i;
	for(int i=1;i<=n;i++)
		printf("%d ",out[i]);
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
//	memset(val,0x3f,sizeof(val));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
			if(f[i][j])add(i,j);
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=k&&j!=k&&f[i][k]!=0&&f[k][j]!=0)f[i][j]=max(f[i][j],f[i][k]+f[k][j]);
	int flag=-1;
	int bg;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]==n-1)
			{
				flag=1;
				bg=i;
				break;
			}
	for(int i=1;i<=n;i++)
		if(f[i][i]==n)
		{
			flag=0;
			bg=i;
			break;
		}
	printf("%d\n",flag);
	if(flag==1)find_way(bg);
	if(flag==0)find_cir(bg);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
