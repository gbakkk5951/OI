using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 1e9 + 7;
const lld PHI = MOD - 1;
const int MXN = 11;
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	pow = pow < 0 ? pow + PHI : pow;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}
lld tmp[MXN];
int n, m;
struct Poly {
	lld arr[MXN];
	lld & operator [] (int id) {
		return arr[id];
	}
	void operator *= (Poly &b) {
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i <= m; i++) {
			for (int j = 0; i + j <= m; j++) {
				tmp[i + j] = (tmp[i + j] + arr[i] * b[j]) % MOD; 
			}
		}
		memcpy(arr, tmp, sizeof(tmp));
	}
	void clear() {
		memset(this, 0, sizeof(Poly));
	}
}poly[MXN];
struct _Main {
	lld fact[MXN], rf[MXN];
	_Main() {
		int a;
		fact[0] = rf[0] = 1;
		for (int i = 1; i <= 10; i++) {
			fact[i] = fact[i - 1] * i % MOD;
			rf[i] = fastpower(fact[i], -1);
		}
		while (~scanf("%d", &n)) {
			read(m);
			for (int i = 1; i <= n; i++) {
				read(a);
				poly[i].clear();
				for (int j = 0; j <= min(a, m); j++) {
					poly[i][j] = rf[j];
				}
				if (i != 1) poly[i] *= poly[i - 1];
			}
			printf("%lld\n", poly[n][m] * fact[m] % MOD);
		}
		
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a = a * 10 + t - '0';
		}
	}
}hdu1521;
}
