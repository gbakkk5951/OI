using namespace  std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
namespace OI {
typedef double lf;
const lf EPS = 1e-8;
const lf PI = 3.14159265;

struct _Main {
	lf a, b;
	inline lf calc(lf x) {
		return b / a * sqrt(a * a - x * x) * 2.0;
	}
	inline lf simpson(lf l, lf r) {
		return (calc(l) + 4.0 * calc((l + r) / 2.0) + calc(r)) / 6.0 * (r - l);
	}
	lf selfsimp(lf l, lf r, lf tot, int iter) {
		lf mid = (l + r) / 2.0;
		lf L = simpson(l, mid);
		lf R = simpson(mid, r);
		if (iter < 5 || fabs(L + R - tot) > EPS) {
			
			return selfsimp(l, mid, L, iter + 1) + selfsimp(mid, r, R, iter + 1);
		} else {
			return L + R;
		}
	}
	_Main() {
		int Qn;
		lf l, r;
		scanf("%d", &Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%lf%lf%lf%lf", &a, &b, &l, &r);
			printf("%.3lf\n", selfsimp(l, r, simpson(l, r), 1));
		}
	}
}std;

}
