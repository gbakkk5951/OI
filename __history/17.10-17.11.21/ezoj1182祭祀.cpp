using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<bitset>
int l,r;
int	mxsum;
int sum;
bitset<80010> dp;
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
	int n;
	_Main(){
		int i,j;
		read(n);
		dp[0]=1;
		for(i=1;i<=n;i++){
			read(l);read(r);
			for(j=sum;j>=0;j--){
				if(dp[j]){
					dp[j+l+r]=1;
				}
			}
			mxsum+=r;
			sum+=l+r;
		}
		int ans=1e9;
		for(i=0;i<=sum;i++){
			if(dp[i])
				ans=min(ans,max(abs(mxsum-i),abs(mxsum-(sum-i))));
		}
		printf("%d",ans);
	}
	
	
}ezoj1182;



