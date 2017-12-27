#include<cstdio>

using namespace std;
int n;
int dp[1001];

int main(){
	dp[0]=1;
	dp[1]=1;
	scanf("%d",&n);
	int i=0,j=0;
	for(i=2;i<=n/2;i++)
	{
    dp[i]=0	;
	for(j=0;j<=i/2;j++)
	dp[i]+=dp[j];
	}
	
	dp[n]=0;
	for(j=0;j<=n/2;j++)
	dp[n]+=dp[j];
if(!n)
dp[n]=1;
	printf("%d",dp[n]);
	
	
	
	
}
