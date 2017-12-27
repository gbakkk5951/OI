using namespace std;
int main(){}
#include<cstring>
#include<cstdio>
#include<cstdlib>
const int mod =1000000007;
int m,n,g_k;
char a[1005],b[205];
int dp[2][205][205];
int used[205][205];
bool use[205];
struct _Main{   

_Main(){
	scanf("%d%d%d",&n,&m,&g_k);
	scanf("%s%s",a,b);
	int i,j,k;
	int iter=0;
	for(i=0;i<n;i++){
		
		iter^=1;
		memset(dp[iter],0,sizeof(dp[iter]));
		if(a[i]==b[0]){
			dp[iter][0][0]=1;
		}
		
		for(j=1;use[j-1]&&j<m&&j<=i;j++){
			if(a[i]==b[j]){
				dp[iter][j][0]=dp[iter^1][j-1][0];
				for(k=1;k<=j&&k<g_k;k++){
					dp[iter][j][k]=(dp[iter^1][j-1][k]+used[j-1][k-1])%mod;
				}
			}
		}
		
		if(dp[iter][0][0]){
			use[0]=true;
			used[0][0]=used[0][0]+dp[iter][0][0];
		}
		
		for(j=1;use[j-1]&&j<m&&j<=i;j++){
			for(k=0;k<=j&&k<g_k;k++){
				if(dp[iter][j][k]){
					use[j]=true;
					used[j][k]=(used[j][k]+dp[iter][j][k])%mod;
				}
			}
		}
		
	}

	printf("%d",used[m-1][g_k-1]);	
}
	
	
	
	
	
}cdvs4560;
