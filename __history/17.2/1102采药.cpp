#include<cstdio>
int t,m;
int val[101];
int cost[101];
int dp[1001][2];
int zmax;
int main()
{
	scanf("%d%d",&t,&m);
	int i=1;
	for(i=1;i<=m;i++)
	scanf("%d%d",&cost[i],&val[i]);
	int j=1;i=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<t;j++)
		{
			if((dp[j][i%2]!=0||j==0)&&(dp[j][i%2]+val[i]>dp[j+cost[i]][(i+1)%2])&&(j+cost[i]<=t))
            {

			dp[j+cost[i]][(i+1)%2]=dp[j][i%2]+val[i];
				printf("[%d]=%d\n",j+cost[i],dp[j+cost[i]][(i+1)%2]); 
            if(dp[j+cost[i]][(i+1)%2]>zmax)
            zmax=dp[j+cost[i]][(i+1)%2];
			}
			if(dp[j][i%2]>dp[j][(i+1)%2])
			dp[j][(i+1)%2]=dp[j][i%2];
		}
		
	}
	printf("%d",zmax);
}
