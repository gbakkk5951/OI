using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
namespace OI {
typedef long long lld;
typedef double lf;
typedef pair<lld, lld> p;
const int MXN = 1e3 + 5;
const lf PI = acos(-1);
lld x[MXN], y[MXN];
lf rate[MXN];
int id[MXN];
int cmp(int a, int b) {
	return rate[a] < rate[b];
}
lld ans[MXN];
p arr[MXN];
struct _Main {
	int n;
	void calc(lld a, lld b) {
		for (int i = 1; i <= n; i++) {
			arr[i] = (p) {x[i] * a + y[i] * b, i};
		}
		sort(arr + 1, arr + n + 1);
		a = b = 0;
		int id;
		for (int i = 1; i <= n; i++) {
			id = arr[n - i + 1].second;
			a += x[id]; b += y[id];
			ans[i] = max(ans[i], a * a + b * b);
		}
	}
	_Main() {
		lld xq, yq, ans1;
		n = 1000;
		read(n);
		read(xq); read(yq);
		for (int i = 1; i <= n; i++) {
			read(x[i]); read(y[i]);
		}
		ans1 = 0;
		calc(xq, yq);
		for (int i = n; i >= 1; i--) {
			if (arr[i].first <= 0) break;
			ans1 += arr[i].first;
		}
		printf("%lld\n", ans1);
		for (int i = 1; i <= n; i++) {
			calc(x[i], y[i]);
		}
		lld a, b;
		calc(1, 0);
		calc(0, 1);
		calc(-1, 0);
		calc(1, 0);
		calc(1, 1);
		calc(1, -1);
		calc(-1, 1);
		calc(-1, -1);
		for (int i = 1; i <= 1000; i++) {
			a = rand() % 1000001 - 500000; b = rand() % 1000001 - 500000;
			calc(a, b);
		}
		for (int i = 1; i <= 1000; i++) {
			a = rand() % 101 - 50;
			b = rand() % 1000001 - 500000;
			if (i & 1) swap(a, b);
			calc(a, b);
		}
		for (int i = 1; i <= n; i++) {
			id[i] = i;
			if (y[i] < 0) {
				rate[i] = 2 * PI - acos((lf)x[i] / (x[i] * x[i] + y[i] * y[i]));
			} else {
				rate[i] = acos((lf)x[i] / (x[i] * x[i] + y[i] * y[i]));
			}
		}
		sort(id + 1, id + n + 1, cmp);
		lf ax, ay, bx, by, m;
		for (int I = 0; I <= 0; I++) {
			for (int i = 1; i <= n; i++) {
				if (id[i] > 1) {
					ax = x[id[i]]; bx = x[id[i] - 1]; 
					ay = y[id[i]]; by = y[id[i] - 1];
					m = sqrt(ax * ax + ay * ay);
					ax /= m; ay /= m;
					m = sqrt(bx * bx + by * by);
					bx /= m; by /= m;
					
					ax *= 1e9; bx *= 1e9;
					ay *= 1e9; by *= 1e9;
					calc(x[id[i]] + x[id[i] - 1], y[id[i]] + y[id[i] - 1]);
					calc(2 * x[id[i]] + x[id[i] - 1], 2 * y[id[i]] + y[id[i] - 1]);
					calc(x[id[i]] + x[id[i] - 1] * 2, y[id[i]] + y[id[i] - 1] * 2);
					
					calc(ax + bx, ay + by);
					calc(2 * ax + bx, 2 * ay + by);
					calc(ax + bx * 2, ay + by * 2);
					
					by = -by; bx = -bx;
					
					calc(x[id[i]] + x[id[i] - 1], y[id[i]] + y[id[i] - 1]);
					calc(2 * x[id[i]] + x[id[i] - 1], 2 * y[id[i]] + y[id[i] - 1]);
					calc(x[id[i]] + x[id[i] - 1] * 2, y[id[i]] + y[id[i] - 1] * 2);
					
					calc(ax + bx, ay + by);
					calc(2 * ax + bx, 2 * ay + by);
					calc(ax + bx * 2, ay + by * 2);
					
					by = -by; bx = -bx;
					ax = -ax; ay = -ay;
					
					calc(x[id[i]] + x[id[i] - 1], y[id[i]] + y[id[i] - 1]);
					calc(2 * x[id[i]] + x[id[i] - 1], 2 * y[id[i]] + y[id[i] - 1]);
					calc(x[id[i]] + x[id[i] - 1] * 2, y[id[i]] + y[id[i] - 1] * 2);
					
					calc(ax + bx, ay + by);
					calc(2 * ax + bx, 2 * ay + by);
					calc(ax + bx * 2, ay + by * 2);
				}
				
			}
			for (int i = 2; i <= n; i++) {
				int tmp = rand() % i + 1;
				swap(id[i], id[tmp]);
	//			swap(x[i], x[tmp]); swap(y[i], y[tmp]);
			}		
		}
		lld ans2 = 0;
		for (int i = 1; i <= n; i++) {
			ans2 = max(ans2, ans[i]);
		}
		printf("%lld\n", ans2);
		for (int i = 1; i <= n; i++) {
			printf("%lld ", ans[i]);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	} 
}std;
}
