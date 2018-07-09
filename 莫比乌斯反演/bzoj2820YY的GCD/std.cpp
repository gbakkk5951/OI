using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e7 + 10;
struct _Main {
	int Qn, mx;
	char isp[MXN], f[MXN], mu[MXN];
	int p[670000], pn;
	int fs[MXN];
	void getprime(int mx) {
		int t;
		mu[1] = 1; 
		memset(isp, 1, (mx + 1) * sizeof(char));
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				mu[i] = -1;
				f[i] = 1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					mu[t] = -mu[i];
					f[t] = -f[i] + mu[i];
				} else {
					mu[t] = 0; 
					f[t] = mu[i];
					break;
				}
			}
		}
		for (int i = 1; i <= mx; i++) {
			fs[i] = fs[i - 1] + f[i];
		}
	}
	lld calc(int n, int m) {
		lld ret = 0;
		int st = 1, mn = min(n, m), ed;
		for (; st <= mn; st = ed + 1) {
			ed = min(n / (n / st), m / (m / st));
			ret += (lld)(n / st) * (m / st) * (fs[ed] - fs[st - 1]);
		}
		return ret;
	}
	_Main() {
		getprime(1e7);
		read(Qn);
		int a, b;
		for (int Q = 1; Q <= Qn; Q++) {
			read(a); read(b);
			printf("%lld\n", calc(a, b));
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
