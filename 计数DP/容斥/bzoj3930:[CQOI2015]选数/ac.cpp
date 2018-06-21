using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
namespace OI {
typedef long long lld;
const lld MOD = 1e9 + 7;
const int MXN = 1e5 + 10;
struct _Main {
    lld dp[MXN];
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
        read(n); read(k); read(l); read(r);
        l = (l + k - 1) / k;
        r = r / k;
        int len = r - l + 1, slen;
        dp[1] += l <= 1 && 1 <= r;
        for (int i = len; i >= 1; i--) {
            slen = r / i - (l - 1) / i;
            dp[i] += fastpower(slen, n) - slen;
            for (int j = i << 1; j <= len; j += i) {
                dp[i] -= dp[j];
            }
            dp[i] %= MOD;
        }
        dp[1] += dp[1] < 0 ? MOD : 0;
        printf("%lld", dp[1]);
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
