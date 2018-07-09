using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e4 + 10, MXV = 1e7 + 10;
struct _Main {
	int a[MXN], b[MXN];
	lld calc(int n, int m) {
		int mn = min(n, m), t1, t2;
		lld ret = 0;
		for (int st = 1, ed; st <= mn; st = ed + 1) {
			ed = min(n / (t1 = n / st), m / (t2 = m / st));
			ret += (lld)t1 * t2 * (fs[ed] - fs[st - 1]);
		}
		return ret;
	}
	_Main() {
		int Qn, mx = 2;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(a[Q]); read(b[Q]);
			mx = max(mx, min(a[Q], b[Q]));
		}
		getprime(mx);
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%lld\n", calc(a[Q], b[Q]));
		}
	}
	char isp[MXV], mu[MXV], lowpow[MXV], f[MXV];
	int p[400000], pn, pi[MXV];
	int fs[MXV];
	void getprime(int mx) {
		int t, tmp;
		mu[1] = 1;
		memset(isp + 2, 1, mx);
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				mu[i] = -1;
				lowpow[i] = 1;
				pi[i] = i;
				f[i] = 1;
				p[pn++] = i;
			}
			for (int j = 0; j < pn && (t = p[j] * i) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					mu[t] = -mu[i];
					lowpow[t] = 1;
					f[t] = mu[i];
					pi[t] = p[j];
				} else {
					mu[t] = 0;
					lowpow[t] = lowpow[i] + 1;
					pi[t] = pi[i] * p[j];
					if ((tmp = t / pi[t]) == 1) {
						f[t] = 1;
					} else {
						if (lowpow[tmp] == lowpow[t]) {
							f[t] = -f[tmp];
						} else {
							f[t] = 0;
						}
					}
					break;
				}
			}
		}
		for (int i = 1; i <= mx; i++) {
			fs[i] = fs[i - 1] + f[i];
		}
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
}std;
}
