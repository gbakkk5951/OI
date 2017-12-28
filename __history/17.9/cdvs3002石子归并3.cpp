using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
struct _Main{
	int sum[3005];
	int dp[3005][3005];
	int num[3005];
	int sol[3005][3005];
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int n;
int n2;
int ans;
_Main(){
	int i,j,k,l;
	read(n);
	for(i=1;i<=n;i++){
		read(num[i]);
		sum[i]=sum[i-1]+num[i];
		sol[i][i]=i;		
	}
	for(l=2;l<=n;l++){
		for(i=1;i+l-1<=n;i++){
			for(j=(k=sol[i][i+l-2])+1;j<=sol[i+1][i+l-1]&&j<(i+l-1);j++){
				if(dp[i][j]+dp[j+1][i+l-1]<=dp[i][k]+dp[k+1][i+l-1]){
					k=j;
				}
			}
			sol[i][i+l-1]=k;
			dp[i][i+l-1]=dp[i][k]+dp[k+1][i+l-1]+sum[i+l-1]-sum[i-1];
		}
	}
	ans=dp[1][n];
	printf("%d",ans);
}	
	
	
	
	
	
}cdvs3002;
