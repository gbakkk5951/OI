using namespace std;
int main () {}
#include<cstdio>

namespace Protector {
const int MOD = 1e9 + 7;
int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}
int pow[1005];
int power(int base, int pow) {
    long long ret = 1;
    int i;
    for (i = 1; i <= pow; i++) {
        (ret *= base) %= MOD;
    }
    return ret;
}

struct _Main {
    _Main() {
        int n, k;
        scanf("%d%d", &n, &k);
        int i, j;
        int ans ;
        for (i = 1; i <= n; i++) {
            pow[i] = power(i, k);
        }
        for (i = 1, ans = 0; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                ans += pow[gcd(i, j)];
                if (ans > MOD) {
                    ans -= MOD;
                }
            }
        }
        ans *= 2;
        if (ans > MOD) {
            ans -= MOD;
        }
        for (i = 1; i <= n; i++) {
            ans += pow[i];
            if (ans > MOD) {
                ans -= MOD;
            }
        }
        printf("%d", (ans % MOD + MOD) % MOD); 
    }
    
}T3;
}

