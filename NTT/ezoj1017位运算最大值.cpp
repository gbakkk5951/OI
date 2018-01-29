using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <cstring>
namespace OI {
typedef long long lld;
const int MAXN = (1 << 20) + 3;
const int
    XOR = 2,
    AND = 1,
    OR = 3
;
 
namespace FWT {
void XOR(lld arr[], int len){
    lld *a, *b;
    lld x;
    int i, j, k, half;
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j]; b = a + half;
            for (k = 0; k < half; k++) {
                x = a[k];
                a[k] = x + b[k];
                b[k] = x - b[k];
            }
        }
    }
}
 
void REV_XOR(lld arr[], int len){
    lld *a, *b;
    lld x;
    int i, j, k, half;
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j]; b = a + half;
            for (k = 0; k < half; k++) {
                x = a[k];
                a[k] = (x + b[k]) >> 1;
                b[k] = (x - b[k]) >> 1;
            }
        }
    }
}
void AND(lld arr[], int len) {
    lld *a;
    int i, j, k, half;
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j];
            for (k = 0; k < half; k++) {
                a[k] = a[k] + a[half + k];
            }
        }
    }
} 
void REV_AND(lld arr[], int len) {
    lld *a;
    int i, j, k, half;
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j];
            for (k = 0; k < half; k++) {
                a[k] = a[k] - a[half + k];
            }
        }
    }
} 
 
 
void OR(lld arr[], int len) {
    lld *a;
    int i, j, k, half;
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j + half]; 
            for (k = 0; k < half; k++) {
                a[k] = a[k] + a[k - half];
            }
        }
    }
}
void REV_OR(lld arr[], int len) {
    lld *a;
    int i, j, k, half;
    for (i = 1; 1 << i <= len; i++) {
        half = 1 << i - 1;
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j + half]; 
            for (k = 0; k < half; k++) {
                a[k] = a[k] - a[k - half];
            }
        }
    }
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
    lld cnt[MAXN];
    _Main() {
        int i, j, k, mx = 0, len;
        int n, oper, a, ans = 0;
        int T, Tn;
        read(Tn);
        for (T = 1; T <= Tn; T++) {
            mx = 0;
            read(n); read(oper);
            for (i = 1; i <= n; i++) {
                read(a); 
                cnt[a]++;
                mx = max(mx, a);
            }
            for (len = 1; len <= mx; len <<= 1);
            switch (oper) {
                case XOR: {
                    FWT::XOR(cnt, len);
                    for (i = 0; i < len; i++) {
                        cnt[i] *= cnt[i];
                    }
                    FWT::REV_XOR(cnt, len);
                    for (i = len - 1; i >= 0; i--) {
                        if (cnt[i]) {
                            ans = i;
                            break;
                        }
                    }
                    break;
                }
                case AND: {
                    using namespace FWT;
                    FWT::AND(cnt, len);
                    for (i = 0 ; i < len; i++) {
                        cnt[i] *= cnt[i];
                    }
                    FWT::REV_AND(cnt, len);
                    for (i = mx; i >= 0; i--) {
                        if (cnt[i] > 1) {
                            ans = i;
                            break;
                        }
                    }
                    break;
                }
                case OR: {
                    using namespace FWT;
                    FWT::OR(cnt, len);
                    for (i = 0; i < len; i++) {
                        cnt[i] *= cnt[i];
                    }
                    FWT::REV_OR(cnt, len);
                    for (i = len - 1; i >= 0; i--) {
                        if (cnt[i]) {
                            ans = i;
                            break;
                        }
                    }
                    break;
                }
            }
            printf("%d\n", ans);
            if (T < Tn) {
                memset(cnt, 0, len * sizeof(lld));
            }
        }
    }
     
}ezoj1017;
 
}
