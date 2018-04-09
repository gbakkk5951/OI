using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
namespace OI {
typedef long long lld;
struct _Main {
	
	int p[10010];
	int pn;
	char v[100010];
	int ph[100010];
	lld phs[100010];
	void sieve(int mx) {
		int t;
		ph[1] = 1; //1的值别忘了 
		for (int i = 2; i <= mx; i++) {
			if (!v[i]) {
				ph[i] = i - 1;
				p[pn++] = i;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				v[t] = 1;
				if (i % p[j]) {
					ph[t] = ph[i] * (p[j] - 1);
				} else {
					ph[t] = ph[i] * p[j];
				}
			}
		}
	}
	
	void prepro(int mx) {
		sieve(mx);
		for (int i = 1; i <= mx; i++) {
			phs[i] = phs[i - 1] + ph[i];
		}
	}
	
	lld calc(int n, int m) {
		int mn = min(n, m);
		lld ret = 0;
		int ed;
		for (int st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (n / st), m / (m / st));
			ret += (lld)(phs[ed] - phs[st - 1]) * (n / st) * (m / st);
		}
		return ret;
	}
	_Main() {
		int n, m;
		scanf("%d%d", &n, &m);
		prepro(max(n, m));
		lld ans = calc(n, m);
		ans <<= 1;
		ans -= (lld)n * m;
		printf("%lld", ans);
	}
	
}bzoj2005;
}

