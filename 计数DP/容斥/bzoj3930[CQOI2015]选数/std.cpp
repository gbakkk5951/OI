int main() {}
#include <cstdio>
namespace OI {
typedef long long lld;
const lld MOD = 1e9 + 7;
const int MXN = 1e5 + 10;
struct _Main {
	int dp[MXN];
	lld fastpower(lld base, int pow) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : base;
		}
		return ret;
	}
	_Main() {
		int l, r, n, k;
		scanf("%d%d%d%d", &n, &k, &l, &r);
		l = (l + k - 1) / k;
		r = r / k;
		int len = r - l + 1, slen;
		lld tmp;
		dp[1] += l <= 1 && 1 <= r;
		for (int i = len; i >= 1; i--) {
			slen = r / i - (l - 1) / i;
			tmp = fastpower(slen, n) - slen;
			for (int j = i << 1; j <= len; j += i) {
				tmp -= dp[j];
			}
			dp[i] = (dp[i] + tmp) % MOD;
		}
		dp[1] += dp[1] < 0 ? MOD : 0;
		printf("%d", dp[1]);
	}
}std;
}

