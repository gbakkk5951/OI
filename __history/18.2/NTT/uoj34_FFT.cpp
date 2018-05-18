using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>

namespace Protector {

struct Complex {
    double x[2];
    Complex operator + (const Complex &b) const {
        return Complex{x[0] + b.x[0], x[1] + b.x[1]};
    }
    Complex operator - (const Complex &b) const {
        return Complex{x[0] - b.x[0], x[1] - b.x[1]};
    }    
    Complex operator * (const Complex &b) const {
        return Complex{x[0] * b.x[0] - x[1] * b.x[1], x[0] * b.x[1] + x[1] * b.x[0]};
    }
};
typedef Complex lld;
const double PI = acos(-1.0);


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
void FFT(lld arr[], int len, int rev = 1) {
    static lld w[140000];
    lld *a, *b;
    lld x, wn;
    int i, j, k, half;
    mov_ele(arr, len);
    w[0] = Complex{1, 0};  
    for (i = 1; 1 << i <= len; i++) {
        wn = Complex{cos(2.0 * PI / (1 << i)), rev * sin(2.0 * PI / (1 << i))};
        half = 1 << i - 1;
        for (j = half; j > 0; j-= 2) {
            w[j] = w[j >> 1];
        }
        for (j = 1; j < half; j += 2) {
            w[j] = w[j - 1] * wn;
        }
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j]; b = a + half;
            for (k = 0; k < half; k++) {
                x = b[k] * w[k];
                b[k] = a[k] - x;
                a[k] = a[k] + x;
            }
        }
    }
    if (rev == -1) {
        for (i = 0; i < len; i++) {
            arr[i].x[0] /= len;
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
            read(a[i].x[0]);
        }
        for (i = 0; i <= m; i++) {
            read(b[i].x[0]);
        }
        FFT(a, len);
        FFT(b, len);
        for (i = 0; i < len; i++) {
            a[i] = a[i] * b[i];
        }
        FFT(a, len, -1);
        for (j = 0; j <= n + m; j++) {
            printf("%lld ", (long long)round(a[j].x[0]));
        }
    }
    
}uoj34;


}
