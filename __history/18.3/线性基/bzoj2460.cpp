using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <functional>
namespace OI {
typedef long long lld;
class LinearBase {
public:
	lld base[65];
	lld join(lld x) {
		for (int i = 63; i >= 0; i--) {
			if (x >> i & 1) {
				if (base[i]) {
					x ^= base[i];
				} else {
					base[i] = x;
					break;
				}
			}
		}
		return x;
	}
}base;
struct Stone {
	lld id;
	int val;
	bool operator > (const Stone &b) const {
		return val > b.val;
	}
}rock[1005];
struct _Main {
	_Main() {
		int n, ans = 0;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(rock[i].id); read(rock[i].val);
		}
		sort(rock + 1, rock + n + 1, greater<Stone>());
		for (int i = 1; i <= n; i++) {
			if (base.join(rock[i].id)) {
				ans += rock[i].val;
			}
		}
		printf("%d\n", ans);
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
}bzoj2460;
	

}

