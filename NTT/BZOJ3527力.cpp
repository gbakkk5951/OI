using namespace std;
int main() {}
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace OI {
struct Complex;    
typedef Complex com;
struct Complex {
    double x, y;
    com operator + (const com &b) const {
        return (com) {x + b.x, y + b.y};
    }
    com operator * (const com &b) const {
        return (com) {x * b.x - y * b.y, x * b.y + y * b.x};
    }
    com operator - (const com &b) const {
        return (com) {x - b.x, y - b.y};
    }
    com operator / (double b) const {
        return (com) {x / b, y / b};
    }
};
const double PI = acos(-1);
com 
    A[270000],
    B[270000],
    div[270000]
;
void mov_ele(com arr[], int len) {
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
void FFT(com arr[], int len, int pow = 1) {
    static com w[140000];
    com *a, *b;
    com y, wn;
    int i, j, k, half;
    w[0] = (com) {1.0, 0.0};
    mov_ele(arr, len);
    for (i = 1; 1 << i <= len; i++) {
        wn = (com) {cos(2.0 * PI / ( 1 << i)), pow * sin(2.0 * PI / (1 << i))};
        half = 1 << i - 1;
        for (j = half; j > 0; j -= 2) {
            w[j] = w[j >> 1];
        }
        for (j = 1; j < half; j += 2) {
            w[j] = w[j - 1] * wn;
        }
        for (j = 0; j < len; j += half << 1) {
            a = &arr[j]; b = a + half;
            for (k = 0; k < half; k++) {
                y = b[k] * w[k];
                b[k] = a[k] - y;
                a[k] = a[k] + y;
            }
        }
    }
    if (pow == -1) {
        for (i = 0; i < len; i++) {
            arr[i] = arr[i] / len;
        }
    }
}


struct _Main {

_Main() {
    int i, j, k;
    int len, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &A[i].x);
    }
    
    memcpy(B, A, n * sizeof(com));
    for (i = 0; i < n / 2; i++) {
        swap(B[i], B[n - i - 1]);
    }
    for (i = 1; i < n; i++) {
        div[i].x = 1.0 / ((double)i * i);
    }
    
    for (len = 1; len < n << 1; len <<= 1); 
    FFT(A, len);
    FFT(B, len);
    FFT(div, len);
    for (i = 0; i < len; i++) {
        B[i] = B[i] * div[i];
    }
    for (i = 0; i < len; i++) {
        A[i] = A[i] * div[i];
    }
    FFT(A, len, -1);
    FFT(B, len, -1);
    for (i = 0; i < n; i++) {
        printf("%.3f\n", A[i].x - B[n - i - 1].x);
    }
}
    
    
    
}BZOJ3527;


}
