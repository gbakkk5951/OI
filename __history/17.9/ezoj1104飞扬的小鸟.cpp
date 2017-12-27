using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}	
int n,m;
int dp[2][1005];
int low[10005];
int high[10005];
int rise[10005];
int fall[10005];
_Main(){
	int i,j,k;int tubenum;int a,b,c;int iter;
	int tubecnt;
	read(n);read(m);read(tubenum);
	for(i=0;i<n;i++){
		read(rise[i]);read(fall[i]);
	}
	for(i=0;i<tubenum;i++){
		read(a);read(b);read(c);
		high[a]=c;low[a]=b;
	}
	
	for(i=0,iter=0,tubecnt=0;i<n;i++){
		iter^=1;
		memset(dp[iter],63,sizeof(dp[iter]));
		for(j=1;j<=m;j++){
		
			dp[iter][min(m,j+rise[i])]=min(dp[iter][min(m,j+rise[i])],dp[iter][j]+1); // 点多次 
			if(high[i]&& ( j>=high[i] || j<=low[i]) )continue;
			dp[iter][min(m,j+rise[i])]=min(dp[iter][min(m,j+rise[i])],dp[iter^1][j]+1);//点一次 
			if(j-fall[i]>=1){
				dp[iter][j-fall[i]]=min(dp[iter][j-fall[i]],dp[iter^1][j]);//不点 
			}
			
		}
		for(j=1;j<=m;j++){
			if(dp[iter][j]<1e9){
				break;
			}
		}
		if(j==m+1)break;
		if(high[i]!=0 || low[i]!=0){
			tubecnt++;
		}
	}
	int ans=1e9;
	if(i==n){
		printf("%d\n",1);
		for(i=1;i<=m;i++){
			ans=min(ans,dp[iter][i]);
		}
		printf("%d",ans);
	}else{
		printf("%d\n%d",0,tubecnt);
	}
	
}	
	
	
	
}ezoj1104;
