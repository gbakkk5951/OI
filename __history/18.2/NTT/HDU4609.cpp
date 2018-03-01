using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = (479 << 21) + 1;
const lld PHI = MOD - 1;
const lld G = 3;
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
        for (k = 1; len >> k & j; k++) {
            j ^= len >> k;
        }
        j |= len >> k;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
}

void NTT (lld arr[], int len, int rev = 0) {
    lld wn[20];
    lld x, y, w;
    int i, j, k, mid;
    mov_ele(arr, len);
    if (rev) {
        for (i = 1; 1 << i <= len; i++) {
            wn[i] = fastpower(G, - PHI >> i);
        }
    } else {
        for (i = 1; 1 << i <= len; i++) {
            wn[i] = fastpower(G, PHI >> i);
        }
    }
    for (i = 1; 1 << i <= len; i++) {
        mid = 1 << i - 1;
        for (j = 0; j < len; j += 1 << i) {
            w = 1;   
            for (k = j; k < j + mid; k++) {
                x = arr[k];
                y = arr[k + mid] * w % MOD;
                arr[k] = (x + y) % MOD;
                arr[k + mid] = (x - y) % MOD;
                w = w * wn[i] % MOD;
            }
        }
    }
    if (rev) {
        w = fastpower(len, -1);
        for (i = 0; i < len; i++) {
            arr[i] = arr[i] * w % MOD;
        }
    }
    for (i = 0; i < len; i++) {
        if (arr[i] < 0) {
            arr[i] += MOD;
        }
    }
}




lld cnt[100010];
lld sum[270000];

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
    
    _Main() {
        int T, Tn;
        read(Tn);
        for (T = 1; T <= Tn; T++) {
            
            lld tot = 0, ok = 0, He = 0;
            int mx = 0;     
            int i, j, k;
            int len, n;
            int a;
            read(n);
            for (i = 1; i <= n; i++) {
                read(a);
                cnt[a]++;
                mx = max(mx, a);
            }
            for (len = 1; len < (mx << 1) + 2; len <<= 1);
            memcpy(sum, cnt, (mx + 2) * sizeof(lld));
            NTT(sum, len);
            for (i = 0; i < len; i++) {
                sum[i] = sum[i] * sum[i] % MOD;
            }
            NTT(sum, len, 1);
            for (i = 1; i <= mx; i++) {
                sum[i << 1] -= cnt[i];
                sum[i] >>= 1;
                sum[i] += sum[i - 1]; 
            }
            for (i = 1; i <= mx; i++) {
                He += cnt[i] * sum[i];
            }
            tot = n * (n - 1LL) * (n - 2LL) / 6;
            ok = tot - He;
            printf("%.7f\n", round((double)ok / tot * 1e7) / 1e7 );
            if (T != Tn) {
                memset(cnt, 0, (mx + 2) * sizeof(lld));
                memset(sum, 0, (mx * 2 + 2) * sizeof(lld));
            }   
        }
    }
}HDU4609;


}

