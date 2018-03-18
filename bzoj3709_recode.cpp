using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>

namespace OI {
typedef long long lld;
const int MXN = 100010;
struct M {
	int a, d, id;
}a[2][MXN];
int c[2];
bool cmp(const M &a, const M &b) {
	return a.d < b.d;
}
struct _Main {
	int ans[2][MXN];
	bool calc(int I) {
		for (int i = 0; i < c[I]; i++) {
			if (hp[I] <= a[I][i].d) {
				return 1;
			}
			hp[I] += a[I][i].a - a[I][i].d;
			ans[I][i] = a[I][i].id;
		}
		return 0;
	}
	lld hp[2];
	_Main() {
		int pos;
		M tmp;
		int n;
		read(n); read(hp[0]);
		hp[1] = hp[0];
		for (int i = 1; i <= n; i++) {
			tmp.id = i; read(tmp.d); read(tmp.a);
			hp[1] += tmp.a - tmp.d;
			if (pos = tmp.a < tmp.d) {
				swap(tmp.a, tmp.d);
			}
			a[pos][c[pos]++] = tmp;
		}
		if (hp[1] <= 0) {
			printf("NIE");
			return;			
		}
		for (int I = 0; I < 2; I++) {
			sort(a[I], a[I] + c[I], cmp);
			if (calc(I)) {
				printf("NIE");
				return;
			}
		}
		for (int i = 0; i < c[1] >> 1; i++) {
			swap(ans[1][i], ans[1][c[1] - i - 1]);
		}
		printf("TAK\n");
		for (int I = 0; I < 2; I++) {
			for (int i = 0; i < c[I]; i++) {
				printf("%d ", ans[I][i]);
			}
		}
	}
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
}bzoj3709;

}
