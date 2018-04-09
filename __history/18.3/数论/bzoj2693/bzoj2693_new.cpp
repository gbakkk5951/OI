using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 10000010;
const lld mod = 1e8 + 9;
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
	int rem[5003][5003];
	lld subcalc(int n, int m) {
		if (n <= 5000 && m <= 5000 && rem[n][m]) {
			return rem[n][m];
		}
		int st, ed;
		lld ret = 0;
		int mn = min(n, m);
		int nn, mm;
		for (st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (nn = n / st), m / (mm = m / st));
			ret += (ui2[ed] - ui2[st - 1]) * sum(1, nn, nn) % mod * sum (1, mm, mm);
			ret %= mod;
		}
		if (n <= 5000 && m <= 5000) {
			rem[n][m] = rem[m][n] = ret;
		}
		return ret;
	}
	lld calc(int n, int m) {
		int st, ed;
		lld ret = 0;
		int mn = min(n, m);
		int nn, mm;
		for (st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (nn = n / st), m / (mm = m / st));
			ret += sum(st, ed, ed - st + 1) * subcalc(nn, mm);
			ret %= mod;
		}
		if (ret < 0) ret += mod; 
		return ret;
	}
	int n[10005], m[10005];
	_Main() {
		int Qn;
		read(Qn);
		int mx = 0;
		for (int Q = 1; Q <= Qn; Q++) {
			read(n[Q]); read(m[Q]);
			mx = max(mx, min(n[Q], m[Q]));
		}
		prepro(mx);
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%lld\n", calc(n[Q], m[Q]));
		}
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

