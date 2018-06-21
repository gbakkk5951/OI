using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
namespace OI {
typedef long long lld;
const int MXN = 1e6 + 10;
const lld MOD = 1e9 + 7;
const lld REV6 = 166666668;
struct _Main {
	map<int, lld> mp;
	int n;
	int mx;
	lld getiphs(int n) {
		if (n <= mx) {
			return iphs[n];
		}
		if (mp.count(n)) {
			return mp[n];
		}
		lld ret = 0;
		int t;
		for (int st = 2, ed; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			ret -= ((ed + st) * (ed - st + 1LL) >> 1) % MOD * getiphs(t) % MOD;
		}
		return mp[n] = ((lld) n * (n + 1) % MOD * (2 * n + 1) % MOD * REV6 + ret) % MOD;
	}
	_Main() {
		scanf("%d", &n);
		mx = min(n, MXN - 5);
		getprime(mx);
		lld ans = getiphs(n);
		ans += ans < 0 ? MOD : 0;
		printf("1 %lld", ans);
	}
	char isp[MXN];
	int p[79000], pn, ph[MXN],iphs[MXN];
	void getprime(int mx) {
		ph[1] = 1;
		memset(isp + 2, 1, mx - 1);
		int t;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				ph[i] = i - 1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					ph[t] = ph[i] * (p[j] - 1);
				} else {
					ph[t] = ph[i] * p[j];
					break;
				}
			}
		}
		for (int i = 1; i <= mx; i++) {//神Tm i <= n
			iphs[i] = (iphs[i - 1] + (lld)i * ph[i]) % MOD;
		}
	}
}bzoj4916;
}
