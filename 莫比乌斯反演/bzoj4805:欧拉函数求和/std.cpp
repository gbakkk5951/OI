using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <map>
namespace OI {
typedef long long lld;
const int MXN = 1e6 + 10;
struct _Main {
	map<int, lld> mmp;
	char isp[MXN];
	int p[(int)1e5], pn, mx, phi[MXN];
	lld phs[MXN];
	void getprime(int mx) {
		int t;
		phi[1] = 1;
		memset(isp + 2, 1, mx);
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				phi[i] = i - 1;
			} 
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					phi[t] = phi[i] * (p[j] - 1);
				} else {
					phi[t] = phi[i] * p[j];
					break;
				}
			}
		}
		for (int i = 1; i <= mx; i++) {
			phs[i] = phs[i - 1] + phi[i];
		}
	}
	lld getphs(int n) {
		if (n <= mx) {
			return phs[n];
		}
		if (mmp.count(n)) {
			return mmp[n];
		}
		lld minus = 0;
		int t;
		for (int st = 2, ed; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			minus += (ed - st + 1) * getphs(t);
		}
		return mmp[n] = (n * (n + 1LL) >> 1) - minus;
	}
	_Main() {
		int n;
		read(n);
		mx = min((int)1e6, n);
		getprime(mx);
		printf("%lld", getphs(n));
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

