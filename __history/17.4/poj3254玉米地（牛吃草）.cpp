#include<cstdio>
#define mod 100000000
struct _Main{
char n,m;

char map[12][12];
unsigned long long dp[2050][2];
void dfs(char po,char m,bool ceng,short from,short down){
	long long ans;
	if(po==n-1){
		if(!((1<<(n-2))&from|(1<<(n-1)&down))&&map[m][po]){
			dp[from|(1<<(n-1))][ceng]+=dp[from][!ceng];
			dp[from|(1<<(n-1))][ceng]%=mod;
		}
		dp[from][ceng]+=dp[from][!ceng];
		dp[from][ceng]%=mod;
	}else{
		if(!((1<<(po-1))&from|((1<<po)&down))&&map[m][po]){
			dfs(po+1,from|(1<<(n-1)),down,ceng,m);
		}
		dfs(po+1,from,down,ceng,m);
	}


}
void ini(char po,short from){
	if(po==n-1){
		if(!(from&(1<<(n-2)))&&map[0][po])
			dp[from|(1<<(n-1))][0]=1;
	}else{
		if(!(from&(1<<(n-2)))&&map[0][po]){
			ini(po+1,from|(1<<(po)));
		}
			ini(po+1,from);
	}
	
	
}
_Main(){
	char i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]);	
		}
	}
	ini(0,0);
	for(i=1;i<m;i++){
		
		for()
			dfs(0,1,1,0,);
		for(j=0;j<2050;j++){
			dp[j][(i+1)%2]=0;
		}
	}
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}poj3254;int main(){}
