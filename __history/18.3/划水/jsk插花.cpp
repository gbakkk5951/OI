using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 100010;
struct _Main {
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
	int n, m, cnt[MXN];
	_Main() {
		read(n); read(m);
		int now = n - 1;
		lld ans = 0;
		for (int i = 1; i <= m; i++) {
			read(cnt[i]);
			if (cnt[i] > 1) { //°Ñ1Ð´³É0 
				ans += now;
				now -= 2;
			}
		}
		printf("%lld", ans);
	}
}jsk;
}
