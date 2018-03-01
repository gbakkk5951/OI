using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace Protector {
typedef long long lld;
const lld 
    MOD = (7LL << 52) + 1,
    PHI = MOD - 1,
    G = 3
;
lld mul(lld a, lld b) {
    return (a * b - (lld)((double)a / MOD * b) * MOD) % MOD;
}

lld fastpower(lld base, lld pow) {
    lld ret = 1;
    pow = (pow % PHI + PHI) % PHI;
    while (pow) {
        if (pow & 1) {
            ret = mul(ret, base);
        }
        pow >>= 1;
        base = mul(base, base);
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

void NTT(lld arr[], int len, int rev = 1) {
    static lld w[550000];
    lld *a, *b;
    lld y, wn;
    int i, j, k, half;
    mov_ele(arr, len);
    w[0] = 1;
    for (i = 1; 1 << i <= len; i++) {
        wn = fastpower(G, rev * PHI >> i);
        half = 1 << i - 1;
        for (j = half; j >= 0; j -= 2) {
            w[j] = w[j >> 1];
        }
        for (j = 1; j < half; j += 2) {
            w[j] = mul(w[j - 1], wn);
        }
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j]; b = a + half;
            for (k = 0; k < half; k++) {
                y = mul(b[k], w[k]);   
                b[k] = (a[k] - y) % MOD;
                a[k] = (a[k] + y) % MOD;
            }
        }
    }
    if (rev == -1) {
        wn = fastpower(len, -1);
        for (i = 0; i < len; i++) {
            arr[i] = mul(arr[i], wn);
            if (arr[i] < 0) {
                arr[i] += MOD;
            }
        }
    }
}

struct _Main {
    int l[2];
    char s[2][300010];
    lld val[2][4][1050010];
    lld ans[1050010];
    int xishu[4];
    _Main() {
        int i, j, k, I, len, cnt;

        scanf("%d%d", &l[1], &l[0]);

        if (l[1] > l[0]) {
            printf("0");
            return;
        }
        scanf("%s%s", s[1], s[0]);

        
        for (i = 0; i < (l[1] >> 1); i++) {
            swap(s[1][i], s[1][l[1] - i - 1]);
        }
        for (len = 1; len < l[0] + l[1]; len <<= 1);
        for (I = 0; I < 2; I++) {
            for (i = 0; i < l[I]; i++) {
                val[I][1][i] = s[I][i] == '*' ? 0 : s[I][i] - 'a' + 1 ;
                for (j = 2; j <= 3; j++) {
                    val[I][j][i] = val[I][j - 1][i] * val[I][1][i];
                }
            }
        }
        for (len = 1; len < l[0] + l[1]; len <<= 1);
        for (I = 0; I < 2; I++) {
            for (i = 1; i <= 3; i++) {
                NTT(val[I][i], len);
            }
        }
        for (i = 1; i <= 3; i++) {
            for (j = 0; j < len; j++) {
                val[0][i][j] = mul(val[0][i][j], val[1][4 - i][j]);
            }
        }
        xishu[3] = 1;
        xishu[2] = -2;
        xishu[1] = 1;         
        for (i = 1; i <= 3; i++) {
            for (j = 0; j < len; j++) {
                ans[j] += val[0][i][j] * xishu[i];
            }
        }
        NTT(ans, len, -1);
        for (i = l[1] - 1, cnt = 0; i < l[0]; i++) {
            if (ans[i] == 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
        
        for (i = l[1] - 1; i < l[0]; i++) {
            if (ans[i] == 0) {
                printf("%d ", i - l[1] + 2);
            }
        }
    }
}cdvs4158;

}
