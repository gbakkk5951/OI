#include<bits/stdc++.h>
#define maxn 3000010
#define ll long long
using namespace std;

int pr[maxn],ph[maxn],prc=0;
ll sp[maxn],sp1[maxn],sp2[maxn],inv2,inv6;
const ll p=1e9+7;
bool np[maxn];
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
void init(){
	ph[1]=1;
	for(int i=2;i<maxn;i++){
		if(!np[i]){
			pr[++prc]=i;
			ph[i]=i-1;
		}
		for(int j=1;j<=prc;j++){
			if(i*pr[j]>=maxn)
				break;
			np[i*pr[j]]=true;
			if(i%pr[j]==0){
				ph[i*pr[j]]=ph[i]*pr[j];
				break;
			}
			ph[i*pr[j]]=ph[i]*ph[pr[j]];
		}
	}
	for(int i=1;i<maxn;i++)
		sp[i]=(sp[i-1]+ph[i])%p,sp1[i]=(sp1[i-1]+1LL*i*ph[i]%p)%p,sp2[i]=(sp2[i-1]+1LL*i*i%p*ph[i]%p)%p;
	inv2=pw(2,p-2),inv6=pw(6,p-2);
}
ll c(ll x){
	x%=p;
	return x*(x-1)%p*(x-2)%p*inv6%p;
}
ll s1(int x){
	return 1LL*x*(x+1)/2%p;
}
ll pt1(int x,int y){
	return 1LL*x*y%p;
}
ll pt2(int x,int y){
	return 1LL*x*s1(y)%p;
}
ll pt3(int x,int y){
	return s1(x)*y%p;
}
ll pt4(int x,int y){
	return s1(x)*s1(y)%p;
}
ll S(int n,int m){
	ll ret=0;
	if(n>m)
		swap(n,m);
	for(int i=1,pos;i<=n;i=pos+1){
		pos=min(n/(n/i),m/(m/i));
		ret=(ret+(sp[pos]-sp[i-1]+p)*pt1(n/i,m/i)%p*(n+1)%p*(m+1)%p)%p;
		ret=(ret-(sp1[pos]-sp1[i-1]+p)*pt2(n/i,m/i)%p*(n+1)%p+p)%p;
		ret=(ret-(sp1[pos]-sp1[i-1]+p)*pt3(n/i,m/i)%p*(m+1)%p+p)%p;
		ret=(ret+(sp2[pos]-sp2[i-1]+p)*pt4(n/i,m/i)%p)%p;
	}
	return ret;
}
ll T(int n,int m){
	return 1LL*n*m%p*(n+1)%p*(m+1)%p*inv2%p;
}
void solve(int n,int m){
	ll num=(n+1)*(m+1),ans=(c(num)-(n+1)*c(m+1)%p-(m+1)*c(n+1)%p+2*p)%p;
	printf("%lld\n",(ans-2*S(n,m)+T(n,m)+2*p)%p);
}
int main(){
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	init();
	int n,m;
	while(scanf("%d%d",&n,&m)&&n&&m)
		solve(n,m);
	return 0;
}
