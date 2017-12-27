using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<algorithm>
struct _Main{
	
	
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
		
		
	}	
	
	int n,m;
	int x,y;	
	
long long getdp(int i,int j){
	if(abs(i-x)==2 &&abs(j-y)==1 || abs(i-x)==1 &&abs(j-y)==2 
		|| i<0 || j<0 || i==x && j==y
	)return 0;
	return dp[i][j];
}


long long dp[22][22];	
_Main(){

	read(n);read(m);read(x);read(y);
	int i,j,k;
	dp[0][0]=1;

	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			dp[i][j]=max(dp[i][j],getdp(i-1,j)+getdp(i,j-1));
		}
	}
	printf("%lld",dp[n][m]);
	
}	
	
	
	
	
	
	
	
	
	
}cdvs1010;
