#include<cstdio>
int n;
unsigned long long dp[92][2];
int main()
{

	  
	dp[0][1]=1;
	dp[0][0]=1;
	scanf("%d",&n);
	int i=0;
	for(i=1;i<n;i++)
	{
		dp[i][1]=(unsigned long long)dp[i-1][0];
		dp[i][0]=(unsigned long long)dp[i-1][0]+dp[i-1][1];
		
	}
	if(n==0)
	printf("1");
	else
	printf("%llu",(unsigned long long)dp[n-1][0]+dp[n-1][1]);
}
