using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>

namespace Protector {
typedef long long lld;
const lld
    MOD = (479LL << 21) + 1,
    PHI = MOD - 1,
    G = 3
;

lld fastpower(lld base, lld pow) {
    lld ret = 1;
    pow = (pow % PHI + PHI) % PHI;
    while (pow) {
        if (pow & 1) {
            ret = ret * base % MOD;
        }
        pow >>= 1;
        base = base * base % MOD;
    }
    return ret;
}
void mov_ele(lld arr[], int len) {
    int i, j, k;
    for (i = 1, j = 0; i < len; i++) {
        for (k = 1; j & len >> k; k++) {
            j ^= len >> k;
        }
        j |= len >> k;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
} 

void NTT(lld arr[], int len, int rev = 0) {
    static lld w[140000];
    lld *a, *b;
    lld wn, y;
    int i, j, k, half;
    mov_ele(arr, len);
    rev = rev ? -1 : 1;
    w[0] = 1;
    for (i = 1; 1 << i <= len; i++) {
        wn = fastpower(G, rev * PHI >> i);
        half = 1 << i - 1;
        for (j = half; j >= 0; j -= 2) {
            w[j] = w[j >> 1];
        }
        for (j = 1; j < half; j += 2) {
            w[j] = w[j - 1] * wn % MOD;
        }
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j]; b = a + half;
            for (k = 0; k < half; k++) {
                y = b[k] * w[k];
                b[k] = (a[k] - y) % MOD;       
                a[k] = (a[k] + y) % MOD;
            }
        }
    }
    if (rev == -1) {
        wn = fastpower(len, -1);
        for (i = 0; i < len; i++) {
            arr[i] = arr[i] * wn % MOD;
            if (arr[i] < 0) {
                arr[i] += MOD;
            }            
        }
    }
}


struct _Main {
template <typename Type>
    void read(Type &a ) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }
lld a[270000], b[270000];

    _Main() {
        int len, i, j, k;
        int n, m;
        read(n); read(m);
        for (len = 1; len < (n + m + 2); len <<= 1);
        for (i = 0; i <= n; i++) {
            read(a[i]);
        }
        for (i = 0; i <= m; i++) {
            read(b[i]);
        }
        NTT(a, len);
        NTT(b, len);
        for (i = 0; i < len; i++) {
            a[i] = a[i] * b[i] % MOD;
        }
        NTT(a, len, 1);
        for (j = 0; j <= n + m; j++) {
            printf("%lld ", a[j]);
        }
    }
    
}uoj34;


}
