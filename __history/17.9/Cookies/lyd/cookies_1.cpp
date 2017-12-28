#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[50][5010];
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
bool cmp(const int a,const int b)
{
	return a>b;
}
int main()
{
	freopen("cookies.in","r",stdin);
	freopen("cookies_1.out","w",stdout);
	int i,j,k,n,m,g[50],sum[50];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&g[i]);
	}
	sort(g+1,g+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		sum[i]=g[i]+sum[i-1];
	}
	memset(dp,0x7f,sizeof(dp));
	for(i=0;i<=n;i++) dp[i][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=m;j++)
		{
			dp[i][j]=dp[i][j-i];
			for(k=max(i-(j-i),1);k<i;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i-k][j-k]+(sum[i]-sum[i-k])*(i-k));
			}
		}
	}
//	for(i=0;i<=n;i++)
//	{
//		for(j=0;j<=m;j++)
//		{
//			printf("%15d ",dp[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d",dp[n][m]);
	return 0;
}
/*
2 3 1 2
*/
