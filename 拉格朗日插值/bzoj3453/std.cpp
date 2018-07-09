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
const int MXN = 155;
const lld MOD = 1234567891;
const lld PHI = MOD - 1;
struct _Main {
	lld g[MXN], h[MXN];
	lld fr[MXN], rev[MXN];
	int k, a, n, d;
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		pow += pow < 0 ? PHI : 0;
		while (pow) {
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : base;
		}
		return ret;
	}
	void init() {
		fr[0] = fr[1] = rev[1] = 1;
		for (int i = 2; i <= k + 4; i++) {
			if (rev[i]) continue;
			rev[i] = -MOD / i * rev[MOD % i] % MOD + MOD;
			fr[i] = fr[i - 1] * rev[i] % MOD;
		}
	}
	lld pow[MXN];
	void calcg() {
		for (int i = 1; i <= k + 2; i++) {
			//历史遗留的剪枝 + 多组数组 = WA
			/*if (pow[i] == 0)*/ pow[i] = fastpower(i, k);
			lld ans = 0;
			for (int j = 1; j <= i; j++) {
				ans = (ans + (i - j + 1) * pow[j]) % MOD;
			}
			g[i] = ans;
		}
	}
	void calch() {
		lld id = a;
		for (int i = 0; i <= k + 3; i++) {
			h[i] = ((i ? h[i - 1] : 0) + lagrange(g, k + 3, id)) % MOD; 
			id = (id + d) % MOD;
		}
	}
	lld lagrange(lld y[], int n, lld v) {
		if (v < n) return y[v];
		lld l = 1, ret = 0, pi;
		for (int i = 0; i < n; i++) {
			l = l * (v - i) % MOD;
		}
		for (int i = 0; i < n; i++) {
			pi = fr[i] * fr[n - i - 1] * (n - i - 1 & 1 ? -1 : 1) % MOD;
			ret = (ret + y[i] * pi % MOD * fastpower(v - i, -1)) % MOD;
		}
		ret += ret < 0 ? MOD : 0;
		return ret * l % MOD;
	}
	_Main() {
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(k); read(a); read(n); read(d);
			init();
			calcg();
			calch();
			printf("%lld\n", lagrange(h, k + 4, n));
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
