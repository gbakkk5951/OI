#include<cstdio>
#include<algorithm>
#define ll long long
#define N 400010
#define Pair pair<ll,ll>
using namespace std;

int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	while('0'<=ch&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}

int n,K;
int a[N];
Pair fac[N],anow[N];
ll m[N],c[N],p[N];
int tot;
ll M[N],H[N],ans[N];

ll ksm(ll a,int b,int p){
	ll ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret%p;
}

ll ksm(ll a,int b){
	ll ret=1;
	while(b){
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

ll inv(ll a,int x){
	return ksm(a,(p[x]-1)*ksm(p[x],c[x]-1)-1,m[x]);
}

Pair mul(Pair A,Pair B,int x){
	return Pair(A.first*B.first%m[x],A.second+B.second);
}

Pair div(Pair A,Pair B,int x){
	return Pair(A.first*inv(B.first,x)%m[x],A.second-B.second);
}

Pair trans(int K,int x){
	Pair ret=Pair(0,0);
	while(K%p[x]==0&&K){
		ret.second++;
		K/=p[x];
	}
	ret.first=K;
	return ret;
}

Pair C(int n,int m,int x){
	return div(fac[n],mul(fac[m],fac[n-m],x),x);
}

ll toNum(Pair A,int x){
	return ksm(p[x],A.second,m[x])*A.first%m[x];
}

ll crt(int x){
	fac[0]=Pair(1,0);
	for(int i=1;i<=n;i++){
		fac[i]=mul(fac[i-1],trans(i,x),x);
	}
	for(int i=1;i<=n;i++){
		anow[i]=trans(a[i],x);
	}
	ll ret=0;
	for(int i=1;i<=n;i++){
		ret=ret+toNum(mul(anow[i],C(n-1,i-1,x),x),x);
	}
	return ret;
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();K=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int tmp=K;
	for(int i=2;i<=tmp;i++){
		if(tmp%i==0){
			p[++tot]=i;
			c[tot]=0;
			while(tmp%i==0){
				c[tot]++;
				tmp/=i;
			}
		}
	}
	for(int i=1;i<=tot;i++){
		m[i]=ksm(p[i],c[i]);
		M[i]=K/m[i];
		H[i]=inv(M[i],i);
		ans[i]=crt(i);
	}
	ll ret=0;
	for(int i=1;i<=tot;i++){
		ret=(ret+(ll)M[i]*H[i]%K*ans[i]%K)%K;
	}
	printf("%I64d\n",ret);
	return 0;
}
