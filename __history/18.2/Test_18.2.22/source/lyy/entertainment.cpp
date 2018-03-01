#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define SIZ(x) ((int)x.size())
#define SET(x,k) memset(x,k,sizeof(x))
#define ALL(x) x.begin(),x.end()

typedef long long LL;
typedef long double DB;
typedef vector<int> VI;
typedef pair<int,int> PII;

inline LL read() {
	LL f=1,x=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f*x;
}

const int N=10+5;
int k,ms,me,n;
int vs[N],ve[N];

int calc(int s) {
	for (int i=0;i<=n-k;++i) {
		int ns=0,ne=0;
		for (int j=i;j<i+k;++j)
			if (s&(1<<j))
				++ns;
			else
				++ne;
		if (ns<ms||ne<me)
			return -1e9;
	}
	int ans=0;
	for (int i=0;i<n;++i)
		if (s&(1<<i))
			ans+=vs[i];
		else
			ans+=ve[i];
	return ans;
}
int main() {
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	n=read(),k=read(),ms=read(),me=read();
	for (int i=0;i<n;++i)
		vs[i]=read();
	for (int i=0;i<n;++i)
		ve[i]=read();
	int ans=-1e9,lim=1<<n;
	for (int i=0;i<lim;++i) {
		ans=max(ans,calc(i));
	}
	cout<<ans<<endl;
	return 0;
}
