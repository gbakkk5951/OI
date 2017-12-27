using namespace std;
int main(){}
#include<cstdio> 
#include<cstring>
const int p=100003;
int dp[2][68];
struct _Main{
int n,m;
_Main(){
	scanf("%d%d",&n,&m);
	int i,j,k,iter,g;
	g=1<<n;
	dp[0][0]=1;
	iter=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			iter^=1;
			memset(dp[iter],0,68*4);
			for(k=0;k<g;k++){
				dp[iter][k]%=p;
				if(dp[iter^1][k]){
					dp[iter][k^(1<<j)]+=dp[iter^1][k];
					if(j && k & 1 << ( j-1 ) && ! ( k & (1<<j) ) ){
						dp[iter][k ^ (1<<j-1)]+=dp[iter^1][k];
					}
				}
			}
		}
	}
	printf("%d",dp[iter][0]%p);	
}	
}codevs1184;
