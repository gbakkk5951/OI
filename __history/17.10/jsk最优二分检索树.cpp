using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
struct _Main{
int dp [2005][2005];
int sol[2005][2005];
int sum[2005];
int num[2005];
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
_Main(){
	int i,j,k,l;
	read(n);
	for(i=1;i<=n;i++){
		read(num[i]);
	}
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];
		dp[i][i]=num[i];sol[i][i]=i;
	}
	for(l=2;l<=n;l++){
		for(i=1;i+l-1<=n;i++){
			for(j= (k=sol[i][i+l-2]) +1;j<=sol[i+1][i+l-1];j++ ){
				if(dp[i][j-1]+dp[j+1][i+l-1]<=dp[i][k-1]+dp[k+1][i+l-1]){
					k=j;
				}
			}
			sol[i][i+l-1]=k;
			dp [i][i+l-1]=dp[i][k-1]+dp[k+1][i+l-1]+sum[i+l-1]-sum[i-1];
		}
	}
	printf("%d",dp[1][n]);
}
	
}jsk;
