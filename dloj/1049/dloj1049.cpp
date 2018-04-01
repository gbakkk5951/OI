using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 10000010, MXQ = 1000010;
const lld mod = 1e9 + 9;
char v[MXN];
int p[MXN / 15], pcnt, ph[MXN];
void sieve(int mx) {
	ph[1] = 1;
	int t;
	for (int i = 2; i <= mx; i++) {
		if (!v[i]) {
			ph[i] = i - 1;
			p[pcnt++] = i;
		}
		for (int j = 0; j < pcnt && (t = i * p[j]) <= mx; j++) {
			v[t] = 1;
			if (i % p[j]) {
				ph[t] = ph[i] * (p[j] - 1);
			} else {
				ph[t] = ph[i] * p[j];
				break;
			}
		}
	}
}

struct _Main {
	lld n[MXQ], m[MXQ];
	lld getph(lld n) {
		lld ret = n;
		for (lld i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ret -= ret / i;
				do {
					n /= i;
				} while (n % i == 0);
			}
		}
		if (n > 1) {
			ret -= ret / n;
		}
		return ret;
	}
	_Main() {
		int Qn;
		lld mx = 0;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(n[Q]); read(m[Q]);
			mx = max(mx, n[Q]);
			mx = max(mx, m[Q]);
		}
		if (mx > 1e7) {
			for (int Q = 1; Q <= Qn; Q++) {
				printf("%lld\n", n[Q] % mod * (m[Q] % mod) % mod 
								* (getph(n[Q]) % mod) % mod * (getph(m[Q]) % mod) % mod
					);
			}
		} else {
			sieve(mx);
			for (int Q = 1; Q <= Qn; Q++) {
				printf("%lld\n", (lld)n[Q] * m[Q] % mod * ph[n[Q]] % mod * ph[m[Q]] % mod);
			}
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
}dloj1049;
}
