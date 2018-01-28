using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

namespace OI {
typedef long long lld;
const lld MOD = 1e9 + 7;
namespace NTT_Space {
const lld
    MOD = (479LL << 21) + 1,
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
        for (k = len >> 1; j & k; k >>= 1) {
            j ^= k;
        }
        j |= k;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
}
void NTT(lld arr[], int len, int pow = 1) {
    static lld w[140000];
    lld *a, *b;
    lld y, wn;
    int i, j, k, half;
    w[0] = 1;
    mov_ele(arr, len);
    for (i = 1; 1 << i <= len; i++) {
        wn = fastpower(G, pow * PHI >> i);
        half = 1 << i - 1;
        for (j = half - 2; j > 0; j -= 2) {
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

}

lld fastpower(lld base, lld pow) {
    lld ret = 1;
    while (pow) {
        if (pow & 1) {
            ret = ret * base % MOD;
        }
        pow >>= 1;
        base = base * base % MOD;
    }
    return ret;
}

struct _Main {
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
    
    
    char str[100010];
    char s2[210000];
    int match[210000];
    lld org[270010];
    lld sum[270010];
    _Main() {
        int n, len;
        int i, j, k;
        int I;
        lld ans = 0;
        scanf("%s", str);
        n = strlen(str);
        for (len = 1; len < n << 1; len <<= 1);
        for (I = 'a'; I <= 'b'; I++) {
            using NTT_Space::NTT;
            for (i = 0; i < n; i++) {
                org[i] = (str[i] == I);
            }
            NTT(org, len);            
            for (i = 0; i < len; i++) {
                sum[i] += org[i] * org[i];
            }
            if (I < 'b') {
                memset(org, 0, len * sizeof(lld));
            } else {
                NTT(sum, len, -1);
            }
        }
        for (i = 0; i < n << 1; i++) {
            ans = (ans + fastpower(2, sum[i] + 1 >> 1) - 1) % MOD;
        }
        for (i = 0; i < n; i++) {
            s2[i << 1] = '#';
            s2[i << 1 | 1] = str[i];  
        }
        s2[n << 1] = '#';
        n = n << 1 | 1;
        k = 0;
        match[0] = 0;
        int mid = 0;
        for (i = 1; i < n; i++) {
            if (i < k && i + match[mid - (i - mid)] < k) {
                match[i] = match[mid - (i - mid)];
                continue;
            }
            for (j = max(k - i, 1); i - j >= 0 && i + j < n && s2[i + j] == s2[i - j]; j++);
            j--;
            match[i] = j;
            if (i + j > k) {
                k = i + j;
                mid = i;
            }
        }
        
        for (i = 0; i < n; i++) {
            ans -= match[i] + 1 >> 1;
        }
        printf("%lld", (ans % MOD + MOD) % MOD);
    }
    
}bzoj3160;

}
