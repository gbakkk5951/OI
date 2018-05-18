using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
namespace OI {
const int MXN = 1005;

typedef double lf;
const lf 
	EPS = 1e-6,
	PI = acos(-1.0);
;

bool inline eq(lf a, lf b) {
	return fabs(a - b) < EPS;
}
int inline judge(lf a) {
	return eq(a, 0) ? 0 : (a < 0 ? -1 : 1);
}


struct P {
	lf x, y;
	bool operator < (const P &b) const {
		return eq(x, b.x) ? y < b.y : x < b.x;
	}
	P operator - (const P &b) const {
		P ret = *this;
		ret.x -= b.x;
		ret.y -= b.y;
		return ret;
	}
	lf mod() {
		return sqrt(x * x + y * y);
	}
};
lf cross(P a, P b) {
	return a.x * b.y - a.y * b.x;
}
lf dis(P a, P b) {
	return (a - b).mod();
}

struct _Main {
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
	P arr[MXN];
	P stk[MXN];
	int stkidx;
	int n;
	lf L;
	void make_convex_hull(P arr[], P stk[], int &top, int n) {
		for (int i = 0; i < n; i++) {
			while (top >= 2 && 
				judge(cross(arr[i] - stk[top - 1], stk[top - 1] - stk[top - 2])) <= 0) {
					top--;
				}
			stk[top++] = arr[i];
		}
		int top1 = top;
		for (int i = n - 2; i >= 0; i--) {
			while (top >= top1 + 1 && 
				judge(cross(arr[i] - stk[top - 1], stk[top - 1] - stk[top - 2])) <= 0) {
					top--;
				}
			stk[top++] = arr[i];
		}
	}
	_Main() {
		int i, j, k;
		lf ans = 0;
		read(n); read(L);
		for (i = 0; i < n; i++) {
			read(arr[i].x); read(arr[i].y);
		}
		sort(arr, arr + n);
		make_convex_hull(arr, stk, stkidx, n);
		for (i = 1; i < stkidx; i++) {
			ans += dis(stk[i], stk[i - 1]);
		}
		ans += 2.0 * PI * L;
		printf("%lld", (long long)round(ans));
	}
}poj1113;

}
