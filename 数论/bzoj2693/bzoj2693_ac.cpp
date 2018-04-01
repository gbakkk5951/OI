using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>
namespace OI {
typedef long long lld;
const lld MOD = 1e8 + 9;//这题有毒1e8 
const int MXN = 10000020;
int p[MXN], pcnt, v[MXN];
lld f[MXN], u[MXN], fs[MXN];
void sieve(int mx) {
	u[1] = f[1] = 1;
	int t;
	for (int i = 2; i <= mx; i++) {
		if (!v[i]) {
			p[pcnt++] = i;
			u[i] = -1;
			f[i] = i * (1LL - i) % MOD;//没加LL爆了 
		}
		for (int j = 0; j < pcnt && (t = i * p[j]) <= mx; j++) {
			v[t] = 1;
			if (i % p[j]) {//不是完全积性 得分别考虑 
				f[t] = f[i] * f[p[j]] % MOD;
				u[t] = -u[i];	
			} else {
				f[t] = p[j] * f[i] % MOD;
				u[t] = 0;
				break;
			}
		}
	}
	for (int i = 1 ; i <= mx; i++) { //这个得从1开始算 
		fs[i] = (fs[i - 1] + f[i]) % MOD;
	}
}
inline lld sum(lld a, lld b) {
	return ((a * (a + 1LL) >> 1) % MOD) * ((b * (b + 1LL) >> 1) % MOD) % MOD;
}
lld calc(int n, int m) {
	lld ret = 0;
	if (n > m) swap(n, m);
	int st, ed;
	for (st = 1; st <= n; st = ed + 1) {
		ed = min(n / (n / st), m / (m / st));
		ret = (ret + sum(n / st, m / st) * (fs[ed] - fs[st - 1])) % MOD;
	}
	return ret < 0 ? ret + MOD : ret;
}
struct _Main {
int a[10010], b[10010];
	_Main() {
		int Qn, mx = 2;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(a[Q]); read(b[Q]);
			mx = max(mx, min(a[Q], b[Q]));
		}
		sieve(mx);
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%lld\n", calc(a[Q], b[Q]));
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
