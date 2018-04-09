using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>

namespace OI {
typedef long long lld;
struct _Main {
template <typename Type>
	int read(Type &a) {
		char t;
		while (!isdigit(t = getchar())) {
			if (t == EOF) {
				return 0;
			}
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		return 1;
	}
	_Main() {
		lld n, m, ans, u, d;
		while (read(n) && read(m)) {
			ans = 0x3f3f3f3f3f3f3f3fLL;	
			for (int i = 1; i <= m; i++) {
				read(u); read(d);
				ans = min(ans, (n * d / (u + d) + 1) * (u + d) - n * d);
			}
			printf("%lld\n", ans);
		}
	}
}uva1648;

}
//看好式子算出来的是什么，有可能不是答案本身 
