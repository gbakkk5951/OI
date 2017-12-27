using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
int m,n,p;
char a[1005],b[205];
int match[1005][205];
int sum[2][1005][205];
int dp[2][1005][205];
const long long mod=(long long)1e9+7;
int main(){
	int i,j,k;
	scanf("%d%d%d%s%s",&n,&m,&p,a+2,b+2);
	for(i=2;i<=n+1;i++){
		for(j=2;j<=m+1;j++){
			for(k=j;j-k<i-1 && j-k<m;k--){
				if(b[k]!=a[i-(j-k)]){
					break;
				}
			}
			match[i][j]=j-k;
		}
	}
	for(i=1;i<=n+1;i++){
		for(j=1;j<=m+1;j++){
			sum[0][i][j]=1;
		}
		dp[0][i][1]=1;
	}

	for(k=1;k<=p;k++){
		memset(sum[k&1],0,sizeof(sum[k&1]));
		memset(dp[k&1],0,sizeof(dp[k&1]));
		for(i=1+k;i<=n+1;i++){
			for(j=1+k;j<=m+1 && j<=i;j++){
				dp[k&1][i][j]=((sum[(k&1)^1][i-1][j-1]-sum[(k&1)^1][i-match[i][j]-1][j-match[i][j]-1])%mod
								+dp[k&1][i-1][j])%mod;					
				sum[k&1][i][j]=(sum[k&1][i-1][j-1]+dp[k&1][i][j])%mod;
			}
		}
	}
	printf("%d",(dp[p&1][n+1][m+1]%mod+mod)%mod);
}
