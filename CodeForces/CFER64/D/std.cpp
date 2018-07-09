using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e3 + 10;
const lld MOD = 998244353;
struct _Main {
	int arr[MXN];
	lld ans;
	lld sum[MXN];
	lld com[MXN][MXN];
	_Main () {
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		for (int i = 0; i <= n; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
			}
		}
		sum[n + 1] = 1;//空序列
		for (int i = n; i >= 1; i--) {
			if (arr[i] > 0) {
				int dst = i + arr[i] + 1;
				if (dst <= n + 1) {
					for (int j = dst; j <= n + 1; j++) {
						sum[i] = (sum[i] + com[j - 2 - i][arr[i] - 1] * sum[j]) % MOD;
					}
				}
			}
			if (sum[i]) {
				ans += sum[i];
			}
			sum[i] = (sum[i] + sum[i + 1]) % MOD;
		}
		printf("%d", (int)(ans % MOD));
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
