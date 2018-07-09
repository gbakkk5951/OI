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
const int MXN = 510;
struct _Main {
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		pow += (pow < 0 ? phi : 0);
		while (pow) {
			ret = (pow & 1) ? ret * base % mod : ret;
			base = (pow >>= 1) ? base * base % mod : base;
		}
		return ret;
	}
	lld val[2][MXN];
	lld y[MXN << 1];
	void calc(int mx) {
		int it = 0;
		lld *lv, *nv;
		for (int i = 1; i <= mx; i++) {
			it ^= 1;
			lv = val[it ^ 1]; nv = val[it];
			nv[1] = (lv[1] + i) % mod;
			for (int j = 2; j <= i && j <= n; j++) {
				nv[j] = (lv[j] + lv[j - 1] * i % mod * j) % mod;//有顺序
			}
			y[i] = nv[n];
		}
	}
	lld lagrange(lld n, lld v) {
		static lld rev[MXN << 1], fr[MXN << 1];
		rev[1] = 1;
		fr[1] = fr[0] = 1;
		for (int i = 2; i < n; i++) {
			rev[i] = -mod / i * rev[mod % i] % mod + mod;
			fr[i] = fr[i - 1] * rev[i] % mod;
		}
		lld l = 1, ret = 0, pi;
		for (int i = 0; i < n; i++) {
			l = l * (v - i) % mod;
		}
		for (int i = 0; i < n; i++) {
			pi = fr[i] * fr[n - i - 1] * (n - i - 1 & 1 ? -1 : 1) % mod;
			ret = (ret + pi * y[i] % mod * fastpower(v - i, -1)) % mod;
		}
		ret += ret < 0 ? mod : 0;
		return ret * l % mod;
	}
	lld mod;
	lld phi;
	int A, n;
	_Main() {
		read(A); read(n); read(mod);
		phi = mod - 1;
		if (A <= 2 * n + 5) {
			calc(A);
			printf("%lld", y[A]);
		} else {
			calc(2 * n + 5);
			printf("%lld", lagrange(2 * n + 5 + 1, A));
		}
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
