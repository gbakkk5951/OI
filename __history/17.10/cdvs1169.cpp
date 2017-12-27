using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>


struct _Main{
	
int f[55][55];
int dp[2][55][55];//a向下走了j步 b向下走了k步 
int n,m;
	
_Main(){
	scanf("%d%d",&n,&m);int i,j,k,iter=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&f[i][j]);
		}
	}
	for(i=1;i<=m+n-2;i++){
		iter^=1;
		for(j=max(0,i-(m-1));j<=n-1&&j<=i;j++){
			for(k=max(0,i-(m-1));k<=n-1&&k<=i;k++){
				if(j==k && i!=m+n-2){
					dp[iter][j][k]=-100000;
					continue;
				}
				dp[iter][j][k]=dp[iter^1][j][k];
				if(j)dp[iter][j][k]=max(dp[iter][j][k],dp[iter^1][j-1][k]);
				if(k)dp[iter][j][k]=max(dp[iter][j][k],dp[iter^1][j][k-1]);
				if(j&&k)dp[iter][j][k]=max(dp[iter][j][k],dp[iter^1][j-1][k-1]);
				dp[iter][j][k]+=f[1+j][1+i-j]+f[1+k][1+i-k];
			}
		}
	}printf("%d",dp[iter][n-1][n-1]);
}	
	
	
	
	
	
	
}cdvs1169;
