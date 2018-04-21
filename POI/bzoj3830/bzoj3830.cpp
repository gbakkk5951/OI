using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
namespace OI {
typedef unsigned int lld;
const lld LINF = 2147483647;
const int MXN = 1e6 + 5;
struct _Main {
	lld dp[MXN];
	lld n;
	lld s;
	_Main() {
		lld mid = 0;
		lld lst = -1;
		lld nd, t;
		read(n); read(s);
		for (lld i = 1; i <= n; i++) {
			read(nd);
			nd = max(nd, lst + 1);
			while (mid + 1 < i && (t = dp[mid + 1] + i - mid - 2) <= nd) mid++;
			dp[i] = i - 1 + 2 * s + min(nd - mid, (mid + 1 == i) ? LINF : t);
			lst = nd;
		}
		printf("%u", dp[n]);
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
}bzoj3830;
}
