using namespace std;
int main() {}
#include <cstdio>
namespace Protector {
const long long MOD = 1e9 + 7;
long long fastpower(long long base, long long pow) {
    pow %= MOD - 1;
    base %= MOD;
    long long ans = 1;
    while (pow) {
        if (pow & 1) {
            (ans *= base) %= MOD;
        }
        pow >>= 1;
        (base *= base) %= MOD;
    }
    return ans;
}
struct _Main {
    _Main() {
        long long n, m;
        long long ans;
        int i, j, k;
        scanf("%lld%lld", &n, &m);
        ans = ((fastpower(m, n) - fastpower(m - 1, n - 1) * (m % MOD) ) % MOD + MOD) % MOD;
        printf("%lld", ans);
    } 
    
    
    
}E;


}
//被乘数爆MOD的话会直接乘爆 （m % MOD） 
