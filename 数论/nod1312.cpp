using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
struct _Main {
lld base[51];
void insert(lld v) {
	for (int I = 50; I >= 0; I--) {
		if (v >> I & 1) {
			if (base[I]) {
				v ^= base[I];
			} else {
				base[I] = v;
				break;
			}
		}
	}
}
void guase(lld n) {
	for (int I = 0; I <= 50; I++) {
		if (!(base[I] >> I & 1)) continue;
		for (int j = I + 1; j <= 50; j++) {
			if (base[j] >> I & 1) {
				base[j] ^= base[I];
			}
		}
	}
	int idx = 0;
	for (int I = 0; I <= 50; I++) {
		if (base[I]) base[idx++] = base[I];
	}
	for (int i = idx; i <= 50; i++) {
		base[i] = 0;
	}
	
}
lld getmax(lld num) {
	for (int I = 50; I >= 0; I--) {
		if (!(num >> I & 1)) num ^= base[I];
	}
	return num;
}
	_Main() {
		int n;
		lld ans = 0, mx, a;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a);
			insert(a);
		}
		mx = getmax(0);
		guase(n);
		sort(base, base + n);
		ans += mx;
		for (int J = n - 2; J >= 0; J--) {
			ans += mx ^ base[J];
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
}nod1312;
}
