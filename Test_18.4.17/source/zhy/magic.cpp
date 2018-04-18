using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 400010;
lld arr[MXN];
int n;
lld mod;
lld fastpower(lld base, lld pow, lld mod) {
	lld ret = 1;
	pow += pow < 0 ? mod - 1: 0;
	while (pow) {
		ret = (pow & 1) ? base * ret % mod : 0;
		base = (pow >>= 1) ? base * base % mod : 0;
	}
	return ret;
}
namespace Case1 {
	void solve() {
		static lld com[1005][1005];
		lld ans = 0;
		for (int i = 0; i <= n; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]) % mod;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans = (ans + arr[i] * com[n - 1][i - 1]) % mod;
		}
		printf("%lld", ans);
	}
}

namespace Case2 {
	lld f[MXN], fr[MXN];
	inline lld getcom(lld n, lld m) {
		return f[n] * fr[m] % mod * fr[n - m] % mod;
	}
	void solve() {
		lld ans = 0;
		f[0] = fr[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1] * i % mod;
			fr[i] = fr[i - 1] * fastpower(i, -1, mod) % mod;
		}
		for (int i = 1; i <= n; i++) {
			ans = (ans + arr[i] * getcom(n - 1, i - 1)) % mod;
		}
		printf("%lld", ans);
	}
}

namespace Case3 {
	lld f[MXN], fr[MXN];
	inline lld lucus(lld n, lld m) {
		if (n < mod && m < mod) {
			if (m > n) return 0;
			return f[n] * fr[m] % mod * fr[n - m] % mod;
		}
		return lucus(n / mod, m / mod) * lucus(n % mod, m % mod);
	}
	void solve() {
		lld ans[30] = {0, 0};
		lld mod[30];
		int cnt;
		lld orgmod = OI::mod, rem = OI::mod;
		for (int i = 2; i * i <= rem; i++) {
			if (rem % i == 0) {
				mod[cnt++] = i;
				do {
					rem /= i;
				} while (rem % i == 0);
			}
		}
		if (rem > 1) {
			mod[cnt++] = rem;
		}
		for (int I = 0; I < cnt; I++) {
			OI::mod = mod[I];
			f[0] = fr[0] = 1;
			for (int i = 1; i <= mod[I] && i <= n; i++) {
				f[i] = f[i - 1] * i % mod[I];
				fr[i] = fr[i - 1] * fastpower(i, -1, mod[I]) % mod[I];
			}
			for (int i = 1; i <= n; i++) {
				ans[I] = (ans[I] + arr[i] * lucus(n - 1, i - 1)) % mod[I];
			}
		}
		for (int i = 1; i < cnt; i++) {
			lld delta = ans[i] - ans[0];
			lld x = fastpower(mod[0], -1, mod[i]);
			ans[0] = (x * delta / 1 % (mod[i] / 1) * 2 + ans[0]);
			mod[0] = mod[0] * mod[i];
			ans[0] %= mod[0];
		}
		ans[0] %= orgmod;
		ans[0] += ans[0] < 0 ? orgmod : 0;
		printf("%lld", ans[0]);
	}
}

struct _Main {
	_Main() {
		freopen("magic.in", "r", stdin);
		freopen("magic.out", "w", stdout);
		read(n); read(mod);
		if (mod == 1) {
			printf("0");
			return;
		}
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		if (n <= 1000) {
			Case1::solve();
		} else {
			Case3::solve();
		}
		fclose(stdout);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}magic;

}
