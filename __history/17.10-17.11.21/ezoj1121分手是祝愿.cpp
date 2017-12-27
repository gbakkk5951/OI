using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
const long long mod=(long long)1e5+3;
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
char light[100010];	
long long dp[100010];
long long div[100010];
long long delta[100010];
void getdiv(){
	div[1]=1;
	int i;
	for(i=2;i<=n;i++){
		div[i]=((-mod/i*div[mod%i])%mod+mod)%mod;
	}
}

int n,mx;int needs;
long long fac;
_Main(){
	int i,j,k;
	
	read(n);read(mx);
	getdiv();
	
	for(i=0;i<=mx;i++){
		dp[i]=i;
	}
	for(i=1;i<=n;i++){
		read(light[i]);
	}
	for(i=n;i>=1;i--)if(light[i]){
		needs++;
		for(j=1;j*j<=i;j++){
			if(i%j==0){
				light[j]^=1;
				if(j*j!=i){
					light[i/j]^=1;
				}
			}
		}
	}
	fac=1;
	for(i=2;i<=n;i++){
		fac=(long long)fac*i%mod;
	}
	delta[n]=1;
	for(i=n-1;i>=1;i--){
		delta[i]=((long long)delta[i+1]*(n-i)+n)%mod*div[i]%mod;
	}
	for(i=mx+1;i<=needs;i++){
		dp[i]=(dp[i-1]+delta[i])%mod;
	}
	printf("%lld",dp[needs]*fac%mod);
}	
	
}ezoj1121;
