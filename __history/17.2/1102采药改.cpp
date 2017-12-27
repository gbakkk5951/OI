#include<cstdio>
int t,m;
int val[101];
int cost[101];
int dp[1001];
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
		for(j=t;j>=0;j--)
		{if(j-cost[i]<0)
		break;
		if((dp[j-cost[i]]!=0||j-cost[i]==0)&&dp[j]<dp[j-cost[i]]+val[i])
		{
		dp[j]=dp[j-cost[i]]+val[i];
		printf("[%d]=%d\n",j,dp[j]); 
		if(zmax<dp[j])
		zmax=dp[j];
		
	    }    
		}
		
	}
	printf("%d",zmax);
}
