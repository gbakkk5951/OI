//by achhhy
#pragma GCC optimize(2)
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

int n,k,a[N];

set<int> s;
set<int>::iterator it;

void solve()
{
	LL ans=0;
	rep(l,1,n)
	{
		int ret=inf;
		s.clear();
		rep(i,l,n)
		{
			it=s.lower_bound(a[i]);
			if((*it)==a[i])
			{
				ret=0;
				if(ret!=inf && 1ll*(n-l)*ret<=ans) break;
				continue;
			}
			s.insert(a[i]);
			it=s.lower_bound(a[i]);
			++it;
			if(it!=s.end()) ret=min(ret,(*it)-a[i]);	
			--it;
			if(it!=s.begin()) --it,ret=min(ret,a[i]-(*it));			
			if(i>=l+k-1) ans=max(ans,1ll*(i-l)*ret);
			if(ret!=inf && 1ll*(n-l)*ret<=ans) break;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
 	freopen("gap.in","r",stdin);
 	freopen("gap.out","w",stdout);
	int T=in();
	while(T--)
	{
		n=in(),k=in();
		rep(i,1,n) a[i]=in();
		solve();
	}
	return 0;
}
