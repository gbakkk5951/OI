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
namespace OI {
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
const int DST = 0, NXT = 1;
const int MXN = 1e7 + 10;
lld mod, rev6, rev2, phi;
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	while (pow) {//这怎么有个 & 1啊 ??
		ret = (pow & 1) ? ret * base % mod : ret;
		base = (pow >>= 1) ? base * base % mod : base;
	}
	return ret;
}
struct _Main {
	map<lld, lld> mp;
	lld n, Qn, Tn;
	inline lld pf(lld a) {
		return a * a % mod;
	}
	lld sum(lld a) {
		return (a + 1) * a % mod * rev2 % mod;
	}
	int mx;
	lld calc(lld n) {
		lld ret = 0, t;
		for (lld st = 1, ed; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			ret += pf(sum(t % mod)) * (geti2phs(ed) - geti2phs(st - 1)) % mod;
		}
		ret %= mod;
		ret += ret < 0 ? mod : 0;
		return ret;
	}
	lld i2sum(lld n) {
		return n * (n + 1) % mod * (2 * n + 1) % mod * rev6 % mod;
	}
	lld geti2phs(lld n) {
		if (n <= mx) {
			return i2phs[n];
		}
		if (mp.count(n)) {
			return mp[n];
		}
		lld ret = 0, t;
		for (lld st = 2, ed; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			ret -= (i2sum(ed % mod) - i2sum((st - 1) % mod)) * geti2phs(t) % mod;
		}
		return mp[n] = (pf(sum(n % mod)) + ret) % mod;
	}
	_Main() {
		read(mod); read(n);
		phi = mod - 1;
		rev2 = fastpower(2, phi - 1);
		rev6 = fastpower(6, phi - 1);
		getprime(mx = min(MXN - 5LL, n));
		printf("%lld", calc(n));
	}
	char isp[MXN];
	int p[670000], pn, ph[MXN];
	lld i2phs[MXN];
	void getprime(int mx) {
		memset(isp + 2, 1, mx - 1);
		int t;
		ph[1] = 1;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				ph[i] = i - 1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {//神Tm j = 2
				isp[t] = 0;
				if (i % p[j]) {
					ph[t] = ph[i] * (p[j] - 1);
				} else {
					ph[t] = ph[i] * p[j];
					break;
				}
			}
		}
		for (int i = 1; i <= mx; i++) {
			t = i % mod;
			i2phs[i] = (i2phs[i - 1] + (lld) t * t % mod * ph[i]) % mod;
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
