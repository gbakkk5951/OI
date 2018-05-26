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
	return (fabs(rate[a] - rate[b]) < 1e-8) ? rate[a] < rate[b] : 0;
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
			id[i] = i;
			if (y[i] < 0) {
				rate[i] = 2 * PI - acos((lf)x[i] / (x[i] * x[i] + y[i] * y[i]));
			} else {
				rate[i] = acos((lf)x[i] / (x[i] * x[i] + y[i] * y[i]));
			}
		}
		sort(id + 1, id + n + 1, cmp);
		id[0] = id[n];
		lld vx, vy;
		for (int i = 1; i <= n; i++) {
			calc(x[i], y[i]);
		}
		for (int i = 1; i <= n; i++) {
			calc(rand() % 200001 - 100000, rand() % 200001 - 100000);
		}
		for (int i = 1; i <= n; i++) {
			vx = x[id[i]] - x[id[i - 1]];
			vy = y[id[i]] - y[id[i - 1]];
			calc(-vy, vx);
			calc(vy, -vx);
			calc(vx, vy);
			calc(-vx, -vy);
			vx = x[id[i]] + x[id[i - 1]];
			vy = y[id[i]] + y[id[i - 1]]; 
			calc(-vy, vx);
			calc(vy, -vx);
			calc(vx, vy);
			calc(-vx, -vy);
			for (int j = 0; j <= 10; j++) {
				int tmp = rand() % (n + 1);
				vx = x[id[i]] - x[id[tmp]];
				vy = y[id[i]] - y[id[tmp]];
				calc(-vy, vx);
				calc(vy, -vx);
				calc(vx, vy);
				calc(-vx, -vy);
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

