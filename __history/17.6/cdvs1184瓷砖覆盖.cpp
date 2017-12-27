int main(){} 
#include<cstdio>
using namespace std;
const int mod=100003;
struct _Main{
int dp[70][2];
int n,m,g;
int iter;
_Main(){
	int i=1,j=1;
	iter=1;
	scanf("%d%d",&n,&m);
	g=1<<n;
	dp[g-1][0]=1;
	for(i=0;i<m;i++){
		for(j=0;j<g;j++){
			dp[j][iter]=0;
		}
		for(j=0;j<g;j++){
			if(dp[j][iter^1]){
				bottom=j;
				dfs(0,0,dp[j][iter^1]);
			}
			dp[j][iter]%=mod;	
		}
		iter^=1;
	}
	printf("%d",dp[g-1][iter^1]);
}
int bottom;
void dfs(int pos,int status,int beg){
	if(pos==n){
		dp[status][iter]+=beg;
		return;
	}
	if(bottom&(1<<pos)){
		if(pos+2<=n && bottom & (1<<pos+1)){
			dfs(pos+2,status|(1<<pos)|(1<<(pos+1)),beg);
		}
		dfs(pos+1,status,beg);
	}else{
		dfs(pos+1,status|(1<<pos),beg);
	}
}		
}cdvs1184;

