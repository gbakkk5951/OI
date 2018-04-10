using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <complex>
namespace OI {
typedef double lf;
typedef complex<lf> com;
typedef long long lld;
const int MXN = 5000;
const lf PI = acos(-1.0);
namespace FFTsp {
	
	void mov_ele(com arr[], int len) {
		int i, j, k;
		for (i = 1, j = 0; i < len; i++) {
			for (k = len >> 1; k & j; k >>= 1) {
				j ^= k;
			}
			j |= k;
			if (i < j) {
				swap(arr[i], arr[j]);
			}
		}
	}
	
	void FFT(com arr[], int len, int pow) {
		com w[MXN], wn;
		com x, y;
		com *a, *b;
		mov_ele(arr, len);
		w[0] = 1.0;
		for (int I = 1; 1 << I <= len; I++) {
			wn = (com){cos(2.0 * PI / (1 << I)), pow * sin(2.0 * PI / (1 << I))};
			int half = 1 << I - 1;
			for (int i = half - 2; i >= 0; i -= 2) {
				w[i] = w[i >> 1];
			}
			for (int i = 1; i < half; i += 2) {
				w[i] = w[i - 1] * wn;
			}
			for (int i = 0; i < len; i += half << 1) {
				a = arr + i; b = arr + i + half;
				for (int j = 0; j < half; j++) {
					x = a[j];
					y = b[j] * w[j];
					a[j] = x + y;
					b[j] = x - y;
				}
			}
		}
		if (pow == -1) {
			lf tmp = len;
			for (int i = 0; i < len; i++) {
				arr[i] /= tmp;
			}
		}
	}
	
}

struct _Main {
	
	int len, pow;
	com a[MXN];
	_Main() {
		while (1) {
			printf("input len:");
			read(len);
			for (int i = 0; i < len; i++) {
				a[i] = read();
			}
			printf("input pow:");
			read(pow);
			if (pow < len) for (pow = 1; pow < len; pow <<= 1);
			fill(a + len, a + pow, (com){0.0, 0.0});
			using namespace FFTsp;
			FFT(a, pow, +1);
			printf("FFT1: ");
			for (int i = 0; i < pow; i++) {
				printf("(%.2lf, %.2lf) ", a[i].real(), a[i].imag());
			}
			printf("\n");
			FFT(a, pow, -1);
			printf("FFT0: ");
			for (int i = 0; i < pow; i++) {
				printf("(%.2lf, %.2lf) ", a[i].real(), a[i].imag());
			}
			printf("\n");
		}
	}
inline void read(int &a) {
	scanf("%d", &a);
}
lf read() {
	lf a;
	scanf("%lf", &a);
	return a;
}
}xcnASdj5_84;
}
