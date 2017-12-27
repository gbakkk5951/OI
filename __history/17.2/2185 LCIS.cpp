#include<cstdio>
#include<cstring>
int a[3002],b[3002];
int n;
int dp[3002];
int main()
{
	scanf("%d",&n);
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i+1]);
	}
	for(j=0;j<n;j++)
	scanf("%d",&b[j+1]);
	memset(dp,0,3002);
	int pos=0;
	for(i=1;i<=n;i++)
	{
		int max=0;
		for(j=1;j<=n;j++)
		{
			if(a[i]>b[j]&&dp[j]>max)
			max=dp[j];
			else if(a[i]==b[j])
		    dp[j]=max+1;
		}
		
		
	}
	int mx=0;
	for(i=1;i<=n;i++)
	if(dp[i]>mx)
	mx=dp[i];
	printf("%d",mx);
	
	
}
