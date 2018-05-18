using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

namespace OI {
typedef long long lld;
const lld MOD = (479 << 21) + 1;
const lld G = 3;
const lld PHI = MOD - 1;

lld fastpower(lld base, lld pow) {
    lld ans = 1;
    while (pow) {
        if (pow & 1) {
            (ans *= base) %= MOD; 
        }
        pow >>= 1;
        (base *= base) %= MOD;
    }
    return ans;
}
int getRev(int now, int len) {
    int i, ret = 0;
    for (i = 1; i < len; i <<= 1) {
        ret <<= 1;
        ret |= now & 1;
        now >>= 1;
    }
    return ret;
}
void rev_ele(lld arr[], lld len) {
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

void NTT(lld arr[], lld len, int rev = 0) {
    int i, j, k, t, mid;
    lld x, y, w;
    static lld wn[25];
    rev_ele(arr, len);
    if (rev) {
        for (i = 0; 1 << i <= len; i++) {
            wn[i] = fastpower(G, PHI - (PHI >> i));
        }
    } else {
        for (i = 1; 1 << i <= len; i++) {
            wn[i] = fastpower(G, PHI >> i);
        }
    }
    for (i = 1; 1 << i <= len; i++) {
        mid = 1 << i - 1;
        for (j = 0; j < len; j += (1 << i)) {
            w = 1;
            for (k = j; k < j + mid; k++) {
                x = arr[k] % MOD;
                y = w * arr[k + mid];
                arr[k] = (x + y) % MOD;
                arr[k + mid] = (x - y) % MOD;
                (w *= wn[i]) %= MOD;
            }
        }
    }
    for (i = 0; i < len ; i++) {
        if (arr[i] < 0) {
            arr[i] += MOD;
        }
    }
    if (rev) {
        w = fastpower(len, PHI - 1);
        for (i = 0; i < len; i++) {
            (arr[i] *= w) %= MOD;
        }
    }
}
struct _Main {
char sa[2][100010];
lld a[2][270010];
_Main() {
    int len;
    int i, j, k;
    int jin_wei;
    int la[2];
    scanf("%s%s", sa[0], sa[1]);
    for (i = 0; i < 2; i ++) {
        la[i] = strlen(sa[i]);
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < la[i]; j++) {
            a[i][j] = sa[i][la[i] - j - 1] - '0';
        }
    }
    for (len = 1; len < la[0] + la[1]; len <<= 1);
    NTT(a[0], len);
    NTT(a[1], len);
    for (i = 0; i < len; i++) {
        (a[0][i] *= a[1][i]) % MOD;
    }
    NTT(a[0], len, 1);
    for (i = 0, jin_wei = 0; i < len; i++) {
        a[0][i] += jin_wei;
        jin_wei = a[0][i] / 10;
        a[0][i] %= 10;
    }
    for (i = len; i >= 0; i--) {
        if (a[0][i]) {
            break;
        }
    }
    for (; i >= 0; i--) {
        printf("%d", a[0][i]);
    }
} 
    
    
    
}ntt_main; 


}
