#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int read()
{
	int sum;char c;
	while(!isdigit(c=getchar()));sum=c-'0';
	while(isdigit(c=getchar())){sum*=10;sum+=c-'0';}
	return sum;
}
int head[310],p[610][3],tot=1,dp[310][310][2],n,m,k;
bool vis[310];
void add(int a,int b,int c)
{
	p[tot][0]=b,p[tot][1]=c,p[tot][2]=head[a];head[a]=tot++;
}
void dfs(int on)
{
	printf("on=%d\n",on);
	int i,j,u,cnt=0;
	vis[on]=1;
	if(!p[head[on]][2])dp[on][1][1]=dp[on][0][0]=0;
	for(i=head[on];i;i=p[i][2])
	{
		int son=p[i][0];
		if(vis[son])continue;
		cnt++;
		dfs(son);
		if(cnt==1)
		{
			for(j=k;j>=1;j--)
			{
				dp[on][j][1]=min(dp[son][j-1][1]+p[i][1],dp[son][j-1][0]);
			}
			for(j=k;j>=0;j--)
			{
				dp[on][j][0]=min(dp[son][j][1],dp[son][j][0]+(m==2?p[i][1]:0));
			}
		}
		else
		{
			for(j=k;j>=0;j--)
			{
//				dp[on][j][1]=min(dp[on][1][1]+dp[son][j-1][1]+p[i][1],dp[on][1][1]+dp[son][j-1][0]);
				dp[on][j][1]+=dp[son][0][0];
				for(u=1;u<j;u++)
				{
					dp[on][j][1]=min(dp[on][j][1],dp[on][u][1]+dp[son][j-u][1]+p[i][1]);
					dp[on][j][1]=min(dp[on][j][1],dp[on][u][1]+dp[son][j-u][0]);
				}
//				dp[on][j][0]=min(dp[on][0][0]+dp[son][j][1],dp[on][0][0]+dp[son][j][0]+(m==2?p[i][1]:0));
				dp[on][j][0]+=dp[son][0][0]+(m==2?p[i][1]:0);
				for(u=0;u<j;u++)
				{
					dp[on][j][0]=min(dp[on][j][0],dp[on][u][0]+dp[son][j-u][1]);
					dp[on][j][0]=min(dp[on][j][0],dp[on][u][0]+dp[son][j-u][0]+(m==2?p[i][1]:0));
				}
			}
		}
			printf("son=%d\n",son);
			for(u=1;u<=n;u++)
			{
				printf("u=%d ",u);
				for(j=0;j<=k;j++)
				{
					printf("%d(%d) ",dp[u][j][0],dp[u][j][1]);
				}
				printf("\n");
			}
	}
	return;
}
signed main()
{
	int i,j,a,b,c;
	memset(dp,0x3f,sizeof(dp));
	n=read(),m=read(),k=read();
	if(n-k<m-1) {printf("-1\n");return 0;}
	for(i=1;i<n;i++)
	{
		a=read(),b=read(),c=read();
		add(a,b,c);add(b,a,c);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("i=%d ",i);
		for(j=0;j<=k;j++)
		{
			printf("%d(%d) ",dp[i][j][0],dp[i][j][1]);
		}
		printf("\n");
	}
	printf("%d\n",dp[1][k][1]);
}
/*
7 2 1
1 2 17828
2 3 58018
2 4 49892
4 5 42440
2 6 98856
3 7 73921
*/
