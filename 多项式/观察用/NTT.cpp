using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <complex>
namespace OI {
typedef long long lld;
const int MXN = 5000;
namespace NTTsp {
	const lld MOD = 479 << 21 | 1; // 29LL << 57, 7LL << 52
	const lld PHI = MOD - 1;
	const lld G = 3;
	void mov_ele(lld arr[], int len) {
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
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		pow += pow < 0 ? PHI : 0;
		while (pow) {
			if (pow & 1) ret = ret * base % MOD;
			if (pow >>= 1) base = base * base % MOD;
		}
		return ret;
	}
	void NTT(lld arr[], int len, int pow) {
		static lld w[MXN];
		lld wn;
		lld x, y;
		lld *a, *b;
		mov_ele(arr, len);
		w[0] = 1;
		for (int I = 1; 1 << I <= len; I++) {
			wn = fastpower(G, pow * PHI >> I);
			int half = 1 << I - 1;
			for (int i = half - 2; i > 0; i -= 2) {
				w[i] = w[i >> 1];
			}
			for (int i = 1; i < half; i += 2) {
				w[i] = w[i - 1] * wn % MOD;
			}
			for (int i = 0; i < len; i += half << 1) {
				a = arr + i; b = arr + i + half;
				for (int j = 0; j < half; j++) {
					x = a[j];
					y = b[j] * w[j];
					a[j] = (x + y) % MOD;
					b[j] = (x - y) % MOD;
				}
			}
		}
		if (pow == -1) {
			wn = fastpower(len, -1);
			for (int i = 0; i < len; i++) {
				arr[i] = arr[i] * wn % MOD + (arr[i] < 0 ? MOD : 0);
			}
		}
	}
	
}

struct _Main {
	
	lld len, pow;
	lld a[MXN];
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
			memset(a + len, 0, (pow - len) * sizeof(lld));
			using namespace NTTsp;
			NTT(a, pow, +1);
			printf("FFT1: ");
			for (int i = 0; i < pow; i++) {
				printf("%lld ", a[i]);
			}
			printf("\n");
			NTT(a, pow, -1);
			printf("FFT0: ");
			for (int i = 0; i < pow; i++) {
				printf("%lld ", a[i]);
			}
			printf("\n");
		}
	}
inline void read(lld &a) {
	scanf("%lld", &a);
}
lld read() {
	lld a;
	scanf("%lld", &a);
	return a;
}
}xcnASdj5_84;
}
