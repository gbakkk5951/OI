using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>


namespace OI {
typedef long long lld;


namespace NTT_Space {
const lld
    MOD = 1004535809,
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
    static lld w[8200];
    lld *a, *b;
    lld wn, y;
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
            arr[i] = wn * arr[i] % MOD;
        }
    }
}

}

lld fastpower(lld base, lld pow, lld mod) {
    lld ret = 1;
    while (pow) {
        if (pow & 1) {
            ret = ret * base % mod;
        }
        pow >>= 1;
        base = base * base % mod;
    }
    return ret;
}
void get_factor(int arr[], int &idx, int num) {
    int i;
    for (i = 2 ; i * i <= num; i++) {
        if (num % i == 0) {
            arr[++idx] = i;
            do {
                num /= i;
            } while (num % i == 0);
        }
    }
    if (num > 1) {
        arr[++idx] = num;
    }
} 
int get_root(int mod) {
    static int arr[50];
    int cnt = 0;
    int phi = mod - 1;
    int i, j, k;
    get_factor(arr, cnt, phi);
    for (i = 2; i < mod; i++) {
        for (j = 1; j <= cnt; j++) {
            if (fastpower(i, phi / arr[j], mod) == 1) {
                break;
            }
        }
        if (j == cnt + 1) {
            break;
        }
    }
    return i == mod ? -1 : i;
}

void mul(lld a[], lld b[], int len) {
    int i;
    using NTT_Space::MOD;
    for (i = 0; i < len; i++) {
        a[i] = a[i] * b[i] % MOD; 
    }
}
void zhengli(lld arr[], int phi) {
    int i;
    using NTT_Space::MOD;
    for (i = phi; i < phi << 1; i++) {
        arr[i - phi] = (arr[i - phi] + arr[i]) % MOD;
        arr[i] = 0;
    }
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
    
    int ind[8010];
    int arr[8010];
    lld base[17010];
    lld ans [17010];
    _Main() {
        int i, j, k;
        int pow, mod, n;
        int x, g, phi;
        int len;
        lld tmp;
        read(pow); read(mod); read(x); read(n);
        for (i = 1; i <= n; i++) {
            read(arr[i]);
            if (arr[i] == 0) {
                n--;
                i--;
            }
        }
        g = get_root(mod);
        phi = mod - 1;
        tmp = 1;
        for (i = 0; i < phi; i++) {
            ind[tmp] = i;
            tmp = tmp * g % mod;
        }
        for (i = 1; i <= n; i++) {
            base[ind[arr[i]]] = 1;
        }
        ans[ind[1]] = 1;
        for (len = 1; len < phi << 1; len <<= 1);
        while (pow) {
            using NTT_Space::NTT;
            NTT(base, len);
            if (pow & 1) {
                NTT(ans, len);
                mul(ans, base, len);
                NTT(ans, len, -1);
                zhengli(ans, phi);
            }
            if (pow >>= 1) {
                mul(base, base, len);
                NTT(base, len, -1);
                zhengli(base, phi);           
            }
        }
        using NTT_Space::MOD;
        printf("%lld", (ans[ind[x]] % MOD + MOD) % MOD);
    }
    
    
    
    
}BZOJ2992;

}
