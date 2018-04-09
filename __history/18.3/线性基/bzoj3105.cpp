using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
class LinearBase {
public:
	int base[30];
	void clear() {
		memset(this, 0, sizeof(LinearBase));
	}
	int join(int a) {
		for (int i = 29; i >= 0; i--) {
			if (a >> i & 1) {
				if (base[i]) {
					a ^= base[i]; 
				} else {
					base[i] = a;
					break;
				}
			}
		}
		return a;
	}
}base;
int arr[105];
int n;
lld calc() {
	lld sum = 0;
	base.clear();
	for (int i = 1; i <= n; i++) {
		if (base.join(arr[i]) == 0) {
			sum += arr[i];
		}
	}
	return sum;
}
struct _Main {
_Main() {
	lld ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1, greater<int>());
	ans = calc();
	printf("%lld", ans);
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
}bzoj3105;
}
