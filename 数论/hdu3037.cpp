using namespace std;
int main() {}
#include <cstdio>
#include <cctype>

namespace OI {
const int MAXN = 100010;
typedef long long lld;
lld fact[MAXN];
lld mod;
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
lld fastpower(lld base) {
	lld ret = 1, pow = mod - 2;
	while (pow) {
		if (pow & 1) {
			ret = ret * base % mod;
		}
		pow >>= 1;
		base = base * base % mod;
	}
	return ret;
}
lld com(lld n, lld m) {
	if (n < m) {
		return 0;
	} else if (n == m) {
		return 1;
	}
	return fact[n] * fastpower(fact[m]) % mod * fastpower(fact[n - m]) % mod;
}
lld lucas(lld n, lld m) {
	if (m == 0) {
		return 1;
	} else if (m < mod && n < mod) {
		return com(n, m);
	}
	lld a = com(n % mod, m % mod);
	return a ? (a * lucas(n / mod, m / mod) % mod) : a;
}
struct _Main {
	_Main() {
		int i;
		int T, Tn;
		int n, m;
		fact[0] = 1;
		read(Tn);
		for (T = 1; T <= Tn; T++) {
			read(n); read(m); read(mod);
			n++;
			for (i = 1; i < mod; i++) {
				fact[i] = fact[i - 1] * i % mod;
			}
			printf("%lld\n", lucas(n + m - 1, n - 1));
		}
	}
}hdu3037;


}
