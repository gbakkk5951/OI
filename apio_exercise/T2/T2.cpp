using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e4 + 10;
struct _Main {
	lld a[MXN];
	_Main() {
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a[n - i + 1]);
		}
		for (int i = 1; i <= n; i++) {
			printf("%lld ", a[i]);
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
}T2;
}
