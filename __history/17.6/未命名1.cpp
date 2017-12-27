int main(){} 
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=100003;
struct _Main{
int dp[2][65];
int n,m,g;
int iter;
_Main(){
	int i=1,j=1;
	iter=1;
	scanf("%d%d",&n,&m);
	g=1<<n;
	dp[0][g-1]=1;
	for(i=0;i<m;i++){
		memset(dp[iter],0,sizeof(dp[iter]));
		for(j=0;j<g;j++){
			if(dp[iter^1][j]){
				bottom=j;
				dfs(0,0,dp[iter^1][j]);
			}
			dp[iter][j]%=mod;	
		}
		iter^=1;
	}
	printf("%d",dp[iter^1][g-1]);
}
int bottom;
void dfs(int pos,int status,int beg){
	if(pos==n){
		dp[iter][status]+=beg;
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

