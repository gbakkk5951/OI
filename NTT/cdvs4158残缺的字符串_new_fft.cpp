using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>

namespace Protector {
struct Complex {
    double x, y;
    Complex operator + (const Complex &a) const {
        return (Complex){x + a.x, y + a.y};
    }
    Complex operator - (const Complex &a) const {
        return (Complex){x - a.x, y - a.y};
    }    
    Complex operator * (const Complex &a) const {
        return (Complex){x * a.x - y * a.y, y * a.x + x * a.y};
    }
    Complex operator * (double b) const {
        return (Complex){x * b, y * b};
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

void FFT(lld arr[], int len, int pow = 1) {
    static lld w[550000];
    lld *a, *b;
    lld y, wn;
    int i, j, k, half;
    mov_ele(arr, len);
    w[0] = Complex{1, 0};
    for (i = 1; 1 << i <= len; i++) {
        wn = (Complex){cos(2.0 * PI / (1 << i)), pow * sin(2.0 * PI / (1 << i))};
        half = 1 << i - 1;
        for (j = half; j >= 0; j -= 2) {
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
            arr[i].x /= len;
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
                val[I][1][i].x = s[I][i] == '*' ? 0 : s[I][i] - 'a' + 1 ;
                for (j = 2; j <= 3; j++) {
                    val[I][j][i].x = val[I][j - 1][i].x * val[I][1][i].x;
                }
            }
        }
        for (len = 1; len < l[0] + l[1]; len <<= 1);
        for (I = 0; I < 2; I++) {
            for (i = 1; i <= 3; i++) {
                FFT(val[I][i], len);
            }
        }
        xishu[3] = 1;
        xishu[2] = -2;
        xishu[1] = 1;         
        for (i = 1; i <= 3; i++) {
            for (j = 0; j < len; j++) {
                ans[j] = ans[j] + val[0][i][j] * val[1][4 - i][j] * xishu[i];
            }
        }
        FFT(ans, len, -1);
        for (i = l[1] - 1, cnt = 0; i < l[0]; i++) {
            if (round(ans[i].x) == 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
        
        for (i = l[1] - 1; i < l[0]; i++) {
            if (round(ans[i].x) == 0) {
                printf("%d ", i - l[1] + 2);
            }
        }
    }
}cdvs4158;

}
