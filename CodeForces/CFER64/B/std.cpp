using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
struct _Main {
	int aft[MXN];
	int time[MXN];
	_Main() {
		int ans = 0;
		int n, m, tot = 0;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(time[i]);
		}
		time[n + 1] = m;
		for (int i = 0; i <= n; i++) {
			if (~i & 1) {
				aft[i] = time[i + 1] - time[i];
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			aft[i] += aft[i + 1];
		}
		ans = tot = aft[0];
		for (int i = n; i >= 0; i--) {
			if (time[i] + 1 != time[i + 1]) {
				ans = max(ans, tot - (aft[i] - (~i & 1)) + (m - time[i] - 1 -(aft[i] - (~i & 1))));
			}
		}
		printf("%d", ans);
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
