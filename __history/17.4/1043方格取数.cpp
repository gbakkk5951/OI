#include<cstdio>
struct _Main{
int map[11][11];
int dp[22][11][11];
int n;
int max(int a,int b){
	return a>b?a:b;
}
int max(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}

_Main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&j,&k);
		scanf("%d",&map[j][k]);
	}

	for(k=1;k<=n*2+2;k++){
		for(i=0;i<=n&&i<=k;i++){
			for(j=0;j<=n&&j+i<=k;j++){
				dp[k][i][j]=max(i&&(k-j)?dp[k-1][i-1][j]:0,
							j&&(k-i)?dp[k-1][i][j-1]:0,
							(k-i)&&(k-j)?dp[k-1][i][j]:0,
							i&&j?dp[k-1][i-1][j-1]:0)
							
							+i==j?(map[i][k-i]):(map[i][k-i]+map[j][k-j]);
				printf("dp[%d][%d][%d]=%d\n",k,i,j,dp[k][i][j]);
			}
		}
	}
//	printf("%d",dp[n-1][n][n]);
}
}instance;int main(){}
