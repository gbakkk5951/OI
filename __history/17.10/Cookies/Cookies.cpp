using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
struct _Main{
void read(int &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}	
int g[35];
int dp[32][5005];
_Main(){
	int i,j,k;
	int n,m;
	read(n);read(m);
	for(i=1;i<=n;i++){
		read(g[i]);
	}
	int p,t;
	
	
	
	
	/*
	memset(dp,127,sizeof(dp));
	dp[0][0]=0;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			dp[i][j]=dp[i][j-i];
			for(k=0;k<j;k++){
				t=0;
				for(p=k+1;p<=i;p++){
					t+=g[p];
				}
				dp[i][j]=min(dp[i][j],dp[k][j-(i-k)]+k*t);
			}
		}
	}
	*/
	printf("%d",dp[n][m]);
}

	
	
	
	
}Cookies;

