using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cmath>
struct _Main{
long long dp[3010][60];//拼成3010,最大为60^2 

_Main(){
	int n;
	scanf("%d",&n); 
	int g=sqrt(n);
	int i,j;
	for(i=0;i<60;i++){
		dp[0][i]=1;
	}
	
	for(i=1;i<=n;i++){
		
		for(j=1;j*j<=i;j++){
			dp[i][j]=dp[i-j*j][j]+dp[i][j-1];
		}
		for(j;j<=g;j++){
			dp[i][j]=dp[i][j-1];
		}
	}
	
	
	printf("%lld",dp[n][g]);
	
}

	
	
}cdvs5115;
 
