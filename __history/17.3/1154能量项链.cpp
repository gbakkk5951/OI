#include<cstdio>
struct begin{
	int dp[201][201];
	int b[201];
	int n;
	int ans;
	int max(int a,int b)
	{
		return a>b?a:b;
	}
	int min(int a,int b)
	{return a<b?a:b;
	}
	
	begin(){
		int i,j,k,l,m;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);

		}
			for(;i<2*n;i++){
				b[i]=b[i-n];
			}
			
		for(i=1;i<2*n-1;i++){
			for(j=i;j>max(0,i-n+1);j--){
				if(i^j)
				for(k=i-1;k>=j;k--){
					dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+b[j]*b[k+1]*b[i+1]);
				//	printf("fdp[%d][%d]=%d;",j,i,dp[j][i]);
				}
				dp[max(0,i-n+1)][i]=
				max(
					dp[max(0,i-n+1)][i],
					dp[max(0,i-n+1)][j-1]+dp[j][i]+b[max(0,i-n+1)]*b[j]*b[i+1]
				);
			//	printf("dp[%d][%d]=%d;",max(0,i-n+1),i,dp[max(0,i-n+1)][i]);
				ans=max(ans,dp[max(0,i-n+1)][i]);
			}
			
			
		}
		
		printf("%d",ans);
	}
	
	
	
}instance;
int main(){}
