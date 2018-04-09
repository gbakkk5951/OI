using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
namespace OI {
const char fail[] = "Impossible";
typedef long long lld;
struct _Main {
	lld exgcd(lld a, lld b, lld &x, lld &y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		lld ret = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return ret;
	}
	_Main() {
		lld x, y, m, n, L;
		while (~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L)) {
			if (m == n) {
				printf("%s\n", fail);
				continue;
			}
			if (m < n) {
				swap(m, n);
				swap(x, y);
			}
			lld a = m - n;
			lld b = -L;
			lld c = (L - (x - y)) % L;
			lld g = exgcd(a, b, x, y);
			if (c % g) {
				printf("%s\n", fail);
				continue;
			}
			x *= c / g;
			m = b / g;
			x %= m;
			if (x < 0) {
				x += m;
			}
			printf("%lld\n", x);
		}
	}
}poj1061;


}
