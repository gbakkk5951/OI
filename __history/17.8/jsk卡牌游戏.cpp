using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
struct _Main{
	
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int inline min(int a,int b){
	return ((a+b)-abs(a-b))>>1;
}
int val[105];
int dp[105][105];
int n;
_Main(){
	int i,j,k;
	int l;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(l=3;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j=i+l-1;
			dp[i][j]=8000000;
			for(k=i+1;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+val[i]*val[k]*val[j]);
			}
		}
	}
	printf("%d",dp[1][n]);

}

}card;
