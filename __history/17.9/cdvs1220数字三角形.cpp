using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>
struct _Main{
int num[105][105];
int dp[105][105];
_Main(){
	int n;
	int i,j;int ans=-10000000;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			dp[i][j]=num[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
		}
	}
	for(i=1;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	printf("%d",ans);
	
}	
	
	
}cdvs1220;
