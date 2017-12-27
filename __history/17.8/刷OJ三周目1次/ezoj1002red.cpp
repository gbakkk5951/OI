#include<cstdio>
using namespace std;
int main(){}
#include<algorithm>
#include<cmath> 
struct _Main{
	double dp[2][5005];
_Main(){
	int r,b;int i,j,k;int iter=0;
	scanf("%d%d",&r,&b);
	
	for(i=0;i<=r;i++){
		dp[iter][i]=i;
	}
	
	for(i=1;i<=b;i++){
		iter^=1;
		for(j=1;j<=r;j++){
			dp[iter][j]=max(0.0,(-1+dp[iter^1][j])* (double) i/( (double) i+j) + (1+dp[iter][j-1])* (double) j /( (double) i+j) );
		}
	}printf("%f",floor(dp[iter][r]*1e6)/(1e6) );
	
}	
	
	
}ezoj1002red;
