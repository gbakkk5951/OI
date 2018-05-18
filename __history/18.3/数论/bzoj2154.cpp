using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 10000010;
const lld mod = 20101009;
struct _Main {
	int u[MXN], p[MXN], pn, ui2[MXN];
	char v[MXN];
	void sieve(int mx) {
		int t;
		u[1] = 1;
		for (int i = 2; i <= mx; i++) {
			if (!v[i]) {
				p[pn++] = i;
				u[i] = -1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				v[t] = 1;
				if (i % p[j]) {
					u[t] = u[i] * (-1);
				} else {
					u[t] = 0;
					break;
				}
			}
		}
	}
	void prepro(int mx) {
		sieve(mx);
		for (int i = 1; i <= mx; i++) {
			ui2[i] = ((lld)i * i * u[i] + ui2[i - 1]) % mod;
		}
	}
	lld sum(lld s, lld t, lld n) {
		return ((s + t) * n >> 1) % mod;
	}
	lld subcalc(lld n, lld m) {
		int st, ed;
		lld ret = 0;
		int mn = min(n, m);
		for (st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (n / st), m / (m / st));
			ret += (ui2[ed] - ui2[st - 1]) * sum(1, n / st, n / st) % mod * sum (1, m / st, m / st);
			ret %= mod;
		}
		return ret;
	}
	lld calc(int n, int m) {
		int st, ed;
		lld ret = 0;
		int mn = min(n, m);
		for (st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (n / st), m / (m / st));
			ret += sum(st, ed, ed - st + 1) * subcalc(n / st, m / st);
			ret %= mod;
		}
		if (ret < 0) ret += mod; // 前缀和取模可能减出负数 
		return ret;
	}
	
	_Main() {
		int n, m;
		read(n); read(m);
		prepro(min(n, m));
		printf("%lld\n", calc(n, m));
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
	
	
}bzoj2693;
}

