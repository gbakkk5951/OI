using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {

typedef long long lld;
const int MXN = 2e5 + 10;

struct _Main {
	int n, m, k, p, phi;
	int pn[MXN];
	lld f[MXN], fr[MXN];
	lld fastpower(lld base, lld pow) {
		const lld p = this->p;
		lld ret = 1;
		pow += pow < 0 ? phi : 0;
		while (pow) {
			ret = (pow & 1) ? ret * base % p : ret;
			base = (pow >>= 1) ? base * base % p : base;
		}
		return ret;
	}
	inline lld com(int n, int m) {
		return pn[n] - pn[m] - pn[n - m] == 0 ? f[n] * fr[m] % p * fr[n - m] % p : 0;
	}
	void init() {
		int mx = max(n, m) + k + 3, tmp;
		f[0] = fr[0] = 1;
		for (int i = 1; i <= mx; i++) {
			pn[i] = pn[i - 1];
			for (tmp = i; tmp % p == 0; tmp /= p, ++pn[i]);
			f[i] = f[i - 1] * tmp % p;
			fr[i] = fastpower(f[i], -1);
		}
	}
	lld calc() {
		if (k == 0) return 1;
		if (n == 0) {
			if (m == 0 || (k & 1)) {
				return 0;
			}
			init();
			return com(m + (k >> 1) - 1, m - 1);
		} 
		init();
		if (m == 0) {
			return com(n + k - 1, n - 1);
		}
		
		//以上几种特殊情况需要特判
		lld ret = 0;
		for (int i = k & 1; i <= k; i += 2) {
			ret = (ret + com(n + i - 1, n - 1) * com(m + (k - i >> 1) - 1, m - 1)) % p;
		}
		return ret;
	}
	_Main() {
		freopen("luckye.in", "r", stdin);
		freopen("luckye.out", "w", stdout);
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m); read(k); read(p);
			phi = p - 1;
			printf("%lld\n", calc());
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
}luckye;
}
