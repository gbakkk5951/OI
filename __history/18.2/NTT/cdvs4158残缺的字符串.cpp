using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
//#include <ctime>
namespace Protector {
typedef long long lld;
const lld 
    MOD = (479LL << 21) + 1,
//    MOD = (7LL << 52) + 1,
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

void NTT(lld arr[], int len, int rev = 0) {
    lld wn[25];
    lld x, y, w;
    int i, j, k, half;
    mov_ele(arr, len);
    if (rev) {
        for (i = 1; 1 << i <= len; i++) {
            wn[i] = fastpower(G, -PHI >> i);
        }
    } else {
        for (i = 1; 1 << i <= len; i++) {
            wn[i] = fastpower(G, PHI >> i);
        }        
    }
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            w = 1;
            for (k = j; k < j + half; k++) {
                x = arr[k];
                y = mul(arr[k + half], w);   
                arr[k] = (x + y) % MOD;
                arr[k + half] = (x - y) % MOD;
                w = mul(w, wn[i]);
            }
        }
    }
    if (rev) {
        w = fastpower(len, -1);
        for (i = 0; i < len; i++) {
            arr[i] = mul(arr[i], w);
        }
    }
    for (i = 0; i < len; i++) {
        if (arr[i] < 0) {
            arr[i] += MOD;
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
        
        l[1] = 29708 + 19205;
        l[0] = 29708 + 19205; 
        for (j = 0; j < 29708; j++) {
            s[0][j] = 'i';
            s[1][j] = 'z';
        }
        for (j = 29708; j < l[1]; j++) {
            s[0][j] = 'b';
            s[1][j] = 'a';
        }
        
//        float ta = clock();
/*
        scanf("%d%d", &l[1], &l[0]);

        if (l[1] > l[0]) {
            printf("0");
            return;
        }
        scanf("%s%s", s[1], s[0]);
*/
        
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
        NTT(ans, len, 1);
        for (i = l[1] - 1, cnt = 0; i < l[0]; i++) {
            if (ans[i] == 0) {
                cnt++;
            }
        }
    
        
        printf("%d\n", cnt);
        
        for (i = l[1] - 1; i < l[0]; i++) {
            printf("ans[%d] = %d\n", i, ans[i]);
            if (ans[i] == 0) {
                printf("%d ", i - l[1] + 2);
            }
        }
        /*
        printf("%f", clock() - ta);*/
    }
}cdvs4158;

}
