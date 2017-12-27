using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cmath>
namespace Protector{

const int mod=998244353;
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}	
	int dp[455][100010];
	_Main(){
		int ans=0;
		int n,m;
		int i,j;
		read(n);read(m);
		int sq=ceil(sqrt(2*m));
		dp[0][0]=1;
		(ans+=dp[0][m])%=mod;
		for(i=1;i<=sq;i++){
			for(j=i;j<=m;j++){
				dp[i][j]=(dp[i-1][j-i]+dp[i][j-i])%mod;
				if(j>n){
					(dp[i][j]-=dp[i-1][j-(n+1)])%=mod;
				}
			}
			(ans+=dp[i][m])%=mod;
		}
		printf("%d",(ans%mod+mod)%mod);
	}
	
}jsk;


}
