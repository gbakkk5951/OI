#include<bits/stdc++.h>
#define maxn 400010
#define ll long long
using namespace std;

int val[maxn],tmp[maxn],n,p;
ll fac[maxn],ifac[maxn];
ll pw(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)
			ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}
ll c(int a,int b){
	return fac[a]*ifac[b]%p*ifac[a-b]%p;
}
int C[10][10];
int cp(int a,int b){
	if(a<b)
		return 0;
	if(a<p&&b<p)
		return C[a][b]%p;
	return cp(a/p,b/p)*cp(a%p,b%p)%p;
}
int getans(int _p){
	p=_p;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+cp(n-1,i-1)*val[i])%p;
	return ans%p;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	if(n<=1000){
		for(int i=n;i>=2;i--){
			for(int j=1;j<=i;j++)
				tmp[j]=(val[j]+val[j+1])%p;
			for(int j=1;j<=i;j++)
				val[j]=tmp[j];
		}
		printf("%d\n",val[1]);
		return 0;
	}
	if(p==10){
		C[0][0]=1;
		for(int i=1;i<=5;i++)
			for(int j=0;j<=i;j++)
				C[i][j]=C[i-1][j]+(j?C[i-1][j-1]:0);
		printf("%d\n",(getans(2)*5+getans(5)*16)%10);
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%p;
	ifac[n]=pw(fac[n],p-2);
	for(int i=n-1;~i;i--)
		ifac[i]=ifac[i+1]*(i+1)%p;
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+c(n-1,i-1)*val[i])%p;
	printf("%lld\n",ans);
	return 0;
}
