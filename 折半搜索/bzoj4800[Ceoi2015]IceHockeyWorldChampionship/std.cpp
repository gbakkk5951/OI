using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
lld a1[(1 << 20) + 47], a2[(1 << 20) + 47];
lld *a, *b;
int ln, rn;
struct _Main {
int n;
lld m;
lld cst[45];
lld sum;
int cnt;
void calc(lld *res, int now, int r) {
	if (now > r) {
		res[++cnt] = sum;
		return;
	}
	calc(res, now + 1, r);
	if (sum + cst[now] <= m) {
		sum += cst[now];
		calc(res, now + 1, r);
		sum -= cst[now];
	}
}
	_Main() {
		a = a1; b = a2;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(cst[i]);
			if (cst[i] > m) {
				--i; --n;
			}
		}
		if (n <= 1) {
			printf("%d", n + 1);
			return;
		}
		calc(a, 1, n >> 1);
		ln = cnt;
		cnt = 0;
		calc(b, (n >> 1) + 1, n);
		rn = cnt;
		cnt = 0;
		sort(a + 1, a + ln + 1);
		sort(b + 1, b + rn + 1);
		lld ans = 0;
		for (int i = 1, j = rn; i <= ln; ++i) {
			while (b[j] + a[i] > m) --j;
			ans += j;
		}
		printf("%lld", ans);
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
