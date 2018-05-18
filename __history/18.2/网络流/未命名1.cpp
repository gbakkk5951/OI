#include <cstdio>
const long long MOD = 507;
int main() {
    long long a = 9223372036854775808LLU;
    printf("%lld\n", a);
    printf("%lld", (a % MOD + MOD) % MOD);
}
