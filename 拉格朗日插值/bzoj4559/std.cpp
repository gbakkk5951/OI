using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 123;
const lld MOD = 1e9 + 7;
struct _Main {
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : base;
		}
		return ret;
	}
	lld y[MXN];
	lld f[MXN];
	lld rev[MXN];
	lld fr[MXN];
	lld lagrange(int n, lld v) {
		lld l = 1, ret = 0, pirev;
		for (int i = 0; i < n; i++) {
			l = l * (v - i) % MOD;
		}
		for (int i = 0; i < n; i++) {
			pirev = fr[i] * fr[n - i - 1] * (n - i - 1 & 1 ? -1 : 1) % MOD;
			ret = (ret + pirev * y[i] % MOD * fastpower(v - i, MOD - 2)) % MOD;
		}
		return ret * l % MOD;
	}
	lld com[MXN][MXN];
	void init() {
		f[0] = fr[0] = 1;
		rev[1] = 1;
		for (int i = 2; i < MXN; i++) {
			rev[i] = -MOD / i * rev[MOD % i] % MOD + MOD;//因为模数是质数所以必然是负数
		}
		for (int i = 1; i < MXN; i++) {
			f[i] = f[i - 1] * i % MOD;
			fr[i] = fr[i - 1] * rev[i] % MOD;
		}
		for (int i = 0; i < MXN; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
			}
		}
	}
	lld dp[2][MXN];
	int rk[MXN], u[MXN];
	void calc(int id, int kn) {
		lld a, b, y;
		int rk = this->rk[id], u = this->u[id];
		for (int i = 1; i <= kn; i++) {
			a = 1; b = fastpower(i, n - 1);
			y = 0;
			for (int j = 0; j <= rk - 1; j++) {
				y = (y + com[rk - 1][j] * a % MOD * b * (rk - 1 - j & 1 ? -1 : 1)) % MOD;
				a = a * u % MOD;
				b = rev[i] * b % MOD;
			}
			this->y[i] = (y + this->y[i - 1]) % MOD;
		}
	}
	void getdp() {
		int mn = n - 1;
		dp[0][n - 1] = 1;
		int it = 0;
		lld p;
		for (int i = 1; i <= m; i++) {
			it ^= 1;
			lld *ndp = dp[it], *ldp = dp[it ^ 1];
			int rk = this->rk[i], u = this->u[i];
			if (u <= n + 5) {
				calc(i, u);
				p = y[u];
			} else {
				calc(i, n + 5);
				p = lagrange(n + 6, u);
			}
			p += p < 0 ? MOD : 0;
			for (int j = min(mn, n - rk); j >= cn; j--) {
				lld a = 0;
				for (int k = j; k <= mn; k++) {
					if (rk - 1 - (k - j) < 0) break;
					if (ldp[k] != 0) {
						a = (a + ldp[k] * com[k][k - j] % MOD * com[n - k - 1][rk - 1 - (k - j)]) % MOD;
					}
				}
				ndp[j] = a * p % MOD;
			}
			memset(ldp, 0, sizeof(dp[0]));
			mn = min(mn, n - rk);
		}
	}
	int n, m, cn;
	_Main() {
		read(n); read(m); read(cn);
		init();
		for (int i = 1; i <= m; i++) {
			read(u[i]);
		}
		for (int i = 1; i <= m; i++) {
			read(rk[i]);
		}
		getdp();
		printf("%lld", dp[m & 1][cn]);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
