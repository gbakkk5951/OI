using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
const int MXN = 500010;
struct _Main {
	char v[MXN];
	int p[MXN], pn, u[MXN], us[MXN];
	void sieve(int mx) {
		int t;
		u[1] = 1;
		for (int i = 2; i <= mx; i++) {
			if (!v[i]) {
				u[i] = -1;
				p[pn++] = i;
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
			us[i] = us[i - 1] + u[i];
		}
	}
	int calc(int n, int m, int k) {
		n /= k; m /= k;
		int mn = min(n, m);
		int st, ed;
		int ret = 0;
		for (st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (n / st), m / (m / st));
			ret += (us[ed] - us[st - 1]) * (n / st) * (m / st);
		}
		return ret;
	}
	_Main() {
		prepro(50005);
		int Qn;
		int a, b, c, d, e;
		read(Qn);
		for(int Q = 1; Q <= Qn; Q++) {
			read(a); read(b); read(c); read(d); read(e);
			printf("%d\n", calc(b, d, e) 
						- calc(a - 1, d, e) 
						- calc(b, c - 1, e) 
						+ calc(a - 1, c - 1, e));
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
}bzoj2301;
}
