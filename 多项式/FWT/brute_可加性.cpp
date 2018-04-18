using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 479 << 21 | 1;
const lld MXN = 4100;
struct _Main {
	lld a[MXN], b[MXN];
	lld ans[MXN];
	_Main() {
		int n;
		read(n);
		for (int i = 0; i < n; i++) {
			read(a[i]);
		}
		for (int i = 0; i < n; i++) {
			read(b[i]);
			a[i] = b[i] = (a[i] + b[i]) % MOD;
 		}
		for (int i = 0; i < n; i++) {
			if (a[i]) for (int j = 0; j < n; j++) {
				ans[i & j] = (ans[i & j] + a[i] * b[j]) % MOD;
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%lld\n", ans[i]);
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
}brute;
}
