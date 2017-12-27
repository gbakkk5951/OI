using namespace std;
int main(){}
#include<cstdio>
#include<cstring>

struct _Main{
	
int n,m;int x1,y1,x2,y2;
long long dp[55][55];

	_Main(){
		scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
		int i,j,k;
		dp[x1][y1]=1;
		for(i=x1;i<x2;i++){
			for(j=1;j<=n;j++){
				if(i+1<=x2){
					if(j+2<=n){
						dp[i+1][j+2]+=dp[i][j];
					}
					if(j-2>=1){
						dp[i+1][j-2]+=dp[i][j];
					}
				}
				if(i+2<=x2){
					if(j+1<=n){
						dp[i+2][j+1]+=dp[i][j];
					}
					if(j-1>=1){
						dp[i+2][j-1]+=dp[i][j];
					}				
				}
			}
		}
		printf("%lld",dp[x2][y2]);
	}
	
	
	
}cdvs1219;
