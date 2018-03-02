using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
namespace Protector {
typedef long long lld;
const lld 
    MOD = (17LL << 27) + 1,
    PHI = MOD - 1,
    G = 3
;
lld fastpower(lld base, lld pow) {
    lld ret = 1;
    if (pow < 0) {
        pow += PHI;
    }
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

void NTT(lld arr[], int len, int pow = 1) {
    static lld w[1050000];
    lld *a, *b;
    lld y, wn;
    int i, j, k, half;
    w[0] = 1;
    mov_ele(arr, len);
    for (i = 1; 1 << i <= len; i++) {
        wn = fastpower(G, pow * PHI >> i);
        half = 1 << i - 1;
        for (j = half; j > 0; j -= 2) {
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
    if (pow == -1) {
        wn = fastpower(len, -1);
        for (i = 0; i < len; i++) {
            arr[i] = arr[i] * wn % MOD;
            if (arr[i] < 0) {
                arr[i] += MOD;
            }
        }
    }
    
}

lld w[1050000];
lld a[2][2100000];
lld b[2100000];

char str[1000010];
struct _Main {
    
    _Main() {
        int len, l[2];
        int i, j, k;
        int I;
        int n;
        scanf("%d", &n);
        for (I = 0; I < 2; I++) {
            scanf("%s", str);
            l[I] = strlen(str);
            for (i = 0; i < l[I]; i++) {
                a[I][i] = isdigit(str[l[I] - i - 1]) ? 
                              str[l[I] - i - 1] - '0' : 
                              str[l[I] - i - 1] - 'A' + 10;
            }
        }
        for (len = 1; len < l[0] + l[1]; len <<= 1);
        for (I = 0; I < 2; I++) {
            NTT(a[I], len);
        }
        for (i = 0; i < len; i++) {
            a[0][i] = a[0][i] * a[1][i] % MOD;
        }
        NTT(a[0], len, -1);
        for (i = 0; i < len; i++) {
            if (a[0][i] >= n) {
                a[0][i + 1] += a[0][i] / n;
                a[0][i] %= n;
            }
        }
        for (i = len - 1; i > 0; i--) {
            if (a[0][i]) {
                break;
            }
        }
        for (; i >= 0; i--) {
            if (a[0][i] < 10) {
                putchar('0' + a[0][i]);
            } else {
                putchar('A' + a[0][i] - 10);
            }
        }
    }
    
    
    
}cdvs6176;

}
