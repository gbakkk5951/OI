using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
namespace OI {
typedef long long lld;
const int MXN = 50010;


struct _Main {
	char v[MXN];
	int p[MXN], pn, u[MXN], us[MXN];
	void sieve(int mx) {
		int t;
		u[1] = 1;
		for(int i = 2; i <= mx; i++) {
			if (!v[i]) {
				p[pn++] = i;
				u[i] = -1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				v[t] = 1;
				if (i % p[j]) {
					u[t] = u[i] * -1;
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
	int calc(int n, int m) {
		int ret = 0;
		int mn = min(n, m);
		int st, ed;
		for (st = 1; st <= mn; st = ed + 1) {
			ed = min(n / (n / st), m / (m / st));
			ret += (us[ed] - us[st - 1]) * (n / st) * (m / st);
		}
		return ret;
	}
	_Main() {
		int Qn;
		prepro(50005);
		read(Qn);
		lld n, m, d;
		for (int Q = 1; Q <= Qn; Q++) {
			read(n); read(m); read(d);
			printf("%d\n", calc(n / d, m / d));
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

}bzoj1101;
}
