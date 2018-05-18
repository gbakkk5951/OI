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
struct _Main {
	int arr[MXN];
	_Main() {
		int n, now;
		int mxbit = 0;
		lld ans = 0, pow = 1;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
			while (1 << mxbit <= arr[i]) {
				mxbit++;
			}
		}	
		lld cnt[2];
		for (int I = 0; I < mxbit; I++) {
			cnt[0] = 1, cnt[1] = 0;
			now = 0;
			for (int i = 1; i <= n; i++) {
				now ^= arr[i] & 1;
				ans += cnt[now ^ 1] * pow;
				cnt[now]++;
				arr[i] >>= 1;
			}
			pow <<= 1;
		}
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
}dloj1040;
}

