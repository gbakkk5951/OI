#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define M 1005
#define N 400005
using namespace std;
typedef long long ll;
ll f[M][M],a[N],fac[N],rev[N],k,ans;
int n;
inline int read(){
	int ret=0;char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		ret=(ret<<1)+(ret<<3)+c-'0';
		c=getchar();
	}
	return ret;
}
inline ll po(ll x,int k,ll p){
	ll ret=1ll;
	while(k){
		if(k&1) ret=ret*x%p;
		x=x*x%p;k>>=1;
	}
	return ret;
}
inline bool chk(int k){
	for(int i=sqrt(k);i>1;--i)
		if(!(k%i)) return false;
	return true;
}
inline void Aireen(){
	n=read();k=(ll)(read()); 
	for(int i=1;i<=n;++i)
		a[i]=(ll)(read());
	if(n<=1000){
		for(int i=0;i<n;++i)
			f[i][0]=1ll;
		for(int i=1;i<n;++i)
			for(int j=1;j<=i;++j)
				f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
		for(int i=1;i<=n;++i)
			ans=(ans+a[i]*f[n-1][i-1])%k;
		printf("%lld\n",ans);
		return;
	}
	if(chk((int)(k))){
		fac[0]=fac[1]=1ll;
		for(int i=2;i<n;++i)
			fac[i]=1ll*i*fac[i-1]%k;
		rev[0]=rev[1]=1ll;
		rev[n-1]=po(fac[n-1],(int)(k-2),k);
		for(int i=n-2;i>1;--i)
			rev[i]=1ll*(i+1)*rev[i+1]%k;
		for(int i=1;i<=n;++i)
			ans=(ans+a[i]*fac[n-1]*rev[i-1]%k*rev[n-i])%k;
		printf("%lld\n",ans);
		return;
	} 
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	Aireen();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

