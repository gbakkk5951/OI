#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
int getint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-')f=-1; ch=getchar();	}
	while('0'<=ch&&ch<='9') { x=x*10+ch-'0'; ch=getchar();	}
	return f*x;
}
#define N 412345
int n,K,m;
int a[N]; 
int P[N],Q[N]; 
ll pw(ll x,ll y,ll m){
	x%=m; ll res=1ll;
	while(y){
		if(y&1) res=res*x%m;
		x=x*x%m;
		y>>=1;
	} return res;
}
#define fi first
#define se second
typedef pair<ll, ll > pll;
ll mod,p;
ll inv(ll x){ return pw(x,mod-2,mod); }
void change(pll &x){	while(x.fi%p==0) x.fi/=p, x.se++; x.fi%=mod;}
pll PLL(ll x){
	pll res=make_pair(x,0); change(res); return res;
}
pll mul(pll x,pll y){
	return make_pair(x.fi*y.fi%mod,x.se+y.se); 
}
pll div(pll x,pll y){
	return make_pair(x.fi*inv(y.fi)%mod, x.se-y.se);
} 
ll p2n(pll x) { return x.fi*pw(p,x.se,mod)%mod; }
ll ans[N]; 
pll iv[N],fac[N];
void init(int n){
	iv[1]=iv[0]=fac[0]=PLL(1);
	for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],PLL(i));
//	for(int i=1;i<=n;i++) cout<<p2n(fac[i])<<" "; cout<<endl;
//	for(int i=2;i<=n;i++) iv[i]=mul(PLL(mod-mod/i), iv[mod%i]); 
//	for(int i=1;i<=n;i++) iv[i]=mul(iv[i-1],iv[i]);
}
pll C(ll x,ll y){
//	cout<<"c"<<x<<" "<<y<<endl;
//	cout<<p2n(div(div(fac[x],fac[y]),fac[x-y]))<<endl;
	return div(div(fac[x],fac[y]),fac[x-y]);
} 
void solve(int i){
	mod=pw(P[i],Q[i],K); p=P[i];
//	cout<<mod<<" "<<p<<endl;
	init(n);
	for(int j=1;j<=n;j++) {
		ans[i]+=p2n(C(n-1,j-1))*a[j]%mod; if(ans[i]>=mod) ans[i]-=mod;
	} return ;
}
ll M[N];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=getint(); K=getint(); int odK=K;
	for(int i=1;i<=n;i++) a[i]=getint();
	for(int i=2;i<=K;i++){
		if(K%i==0){
			P[++m]=i;
			while(K%i==0) K/=i,Q[m]++;
		}
	} K=odK;
	
//	for(int i=1;i<=m;i++) cout<<P[i]<<" "<<Q[i]<<endl;
	for(int i=1;i<=m;i++) solve(i);
//	cout<<"solveover"<<endl;
	ll answer=0; 
	for(int i=1;i<=m;i++) {
//		cout<<ans[i]<<"a"<<endl;
		P[i]=pw(P[i],Q[i],K+1);	
		M[i]=K/P[i];
//		cout<<P[i]<<" "<<M[i]<<endl;	 
//		cout<<pw(M[i],P[i]-2,P[i])<<endl;
		answer+=ans[i]*M[i]*pw(M[i],P[i]-2,P[i])%K;
	}
	cout<<answer<<endl;
}

