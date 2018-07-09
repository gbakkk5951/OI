using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int MXN = 1e2 + 10;
struct _Main {
	int a[MXN];
	int n;
	_Main() {
		int k;
		read(n); read(k);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n && a[i] <= k; i++) {
			++ans;
		}
		if (ans != n) {
			for (int j = n; j >= 1 && a[j] <= k; j--) {
				++ans;
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
