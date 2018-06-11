//by achhhy
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
inline int in()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}
//need changing
const int inf=(1<<30);
const int mod=1e9+7;
const int N=100010;

LL n,m;
LL f(LL x) {return x*x%mod;}
LL ksm(LL a,LL b)
{
	LL ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

LL C3(LL x)
{
	x%=mod;
	return x*(x-1)%mod*(x-2)%mod*ksm(6,mod-2)%mod;
}

int main()
{
 	freopen("tri.in","r",stdin);
 	freopen("tri.out","w",stdout);
	while(scanf("%lld%lld",&n,&m))
	{
		if(!(n+m)) break;
		++n,++m;
		LL ans=C3(m*n),ret=0;
		(ret+=4ll*f(n>>1)*f(m>>1))%=mod;
		if(n&1) (ret+=2ll*n*f(m>>1))%=mod;
		if(m&1) (ret+=2ll*m*f(n>>1))%=mod;
		if((n&1)&&(m&1)) (ret+=n*m)%=mod;
		(ret-=1ll*n*m)%=mod;
		ret=(ret+mod)%mod;
		ret=ret*ksm(2,mod-2)%mod;	
		printf("%lld\n",(ans-ret+mod)%mod);
	}
	return 0;
}
