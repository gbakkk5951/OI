using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
long long inline abs(long long a){
	return a>>63^((a>>63)+a);
}
template<typename Type>
Type inline min(Type a,Type b){
	return (a+b-abs(a-b))>>1;
}
template<typename Type>
Type inline max(Type a,Type b){
	return (a+b+abs(a-b))>>1;
}
template<typename Type>
Type inline pow(Type a){
	return a*a;
}
struct _Main{
int n,c,h[50010];
long long dp[50010][103];
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
	
	_Main(){
		int i,j,k;
		int mx=0;
		int idx;
		read(n);read(c);
		for(i=0;i<n;i++){
			read(h[i]);
			mx=max(h[i],mx);
		}
		for(i=h[0];i<=mx;i++){
			dp[0][i]=pow(i-h[0]);
		}
		
		for(i=1;i<n;i++){
			idx=h[i-1];
			for(j=h[i];j<=mx;j++){
				while(idx<mx && (c*abs(idx+1-j)+dp[i-1][idx+1]) < (c*abs(idx-j)+dp[i-1][idx]) ){
					idx++;
				}
				dp[i][j]=pow(j-h[i])+c*abs(j-idx)+dp[i-1][idx];
			}
		}
		long long ans=90000000000;
		for(i=h[n-1];i<=mx;i++){
			ans=min(ans,dp[n-1][i]);
		}
		printf("%lld",ans);
		
	}
	
	
	
}jsk;
