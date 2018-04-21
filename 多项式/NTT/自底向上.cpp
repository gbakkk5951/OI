using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1050000;
const lld MOD = 479 << 21 | 1;
const int PHI = MOD - 1;
const lld G = 3;
const lld REV2 = MOD + 1 >> 1;
lld tmp[MXN];

	lld fastpower(lld base, int pow) {
		lld ret = 1;
		pow += pow < 0 ? PHI : 0;
		while (pow) {
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : base;
		}
		return ret;
	}
void mov_ele(lld arr[], int len) {
	for (int i = 0; i < len; i += 2) {
		tmp[i >> 1] = arr[i];
	}
	for (int i = 1; i < len; i += 2) {
		tmp[i + len >> 1] = arr[i];
	}
	memcpy(arr, tmp, len * sizeof(lld));
}

void NTT(lld arr[], int len) {
	static lld w[MXN >> 1];
	lld x, y, wn, *a, *b;
	w[0] = 1;
	for (int I = len; I >= 2; I >>= 1) {
		int half = I >> 1;
		/*
		wn = fastpower(G, PHI >> I);
		for (int i = half - 2; i > 0; i -= 2) {
			w[i] = w[i >> 1];
		}
		for (int i = 1; i < len; i += 2) {
			w[i] = w[i - 1] * wn % MOD;
		}
		*/
		for (int i = 0; i < len; i += half << 1) {
			a = arr + i; b = arr + i + half;
			mov_ele(a, half << 1);
			/*for (int j = 0; j < half; j++) {
				x = a[j];
				y = b[j] * w[j];
				a[j] = (x + y) % MOD;
				b[j] = (x - y) % MOD;
			}*/
		}
	}
	/*
		for (int I = 1; 1 << I <= len; I++) {
			int half = 1 << I - 1;
			wn = fastpower(G, PHI >> I);
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
	*/
	
}
void NNTT(lld arr[], int len) {
	static lld w[MXN >> 1];
	lld x, y, wn, *a, *b;
	w[0] = 1;
	for (int I = len; I >= 2; I >>= 1) {
		int half = I >> 1;
		/*
		wn = fastpower(G, PHI >> I);
		for (int i = half - 2; i > 0; i -= 2) {
			w[i] = w[i >> 1];
		}
		for (int i = 1; i < len; i += 2) {
			w[i] = w[i - 1] * wn % MOD;
		}
		*/
		for (int i = 0; i < len; i += half << 1) {
			a = arr + i; b = arr + i + half;
7			mov_ele(a, half << 1);
			/*for (int j = 0; j < half; j++) {
				x = a[j];
				y = b[j] * w[j];
				a[j] = (x + y) % MOD * REV2 % MOD;
				b[j] = (x - y) % MOD * REV2 % MOD;
			}*/
		}
	}
	/*
		for (int I = 1; 1 << I <= len; I++) {
			int half = 1 << I - 1;
			wn = fastpower(G, -PHI >> I);
			for (int i = half - 2; i > 0; i -= 2) {
				w[i] = w[i >> 1];
			}
			for (int i = 1; i < half; i += 2) {
				w[i] = w[i - 1] * wn % MOD;
			}
			for (int i = 0; i < len; i += half << 1) {
				a = arr + i; b = arr + i + half;
	//			mov_ele(a, half << 1);
				for (int j = 0; j < half; j++) {
					x = a[j];
					y = b[j] * w[j];
					a[j] = (x + y) % MOD * REV2 % MOD;
					b[j] = (x - y) % MOD * REV2 % MOD;
				}
			}
		}
	*/
	
}

struct _Main {
	lld arr[MXN];
	char num[100000];
	_Main() {
		int n, mxpow;
		while (~scanf("%s", num)) {
			n = strlen(num);
			for (mxpow = 1; mxpow < n; mxpow <<= 1);
			for (int i = 0; i < n; i++) {
				arr[i] = num[n - i - 1] - '0';
			}
			NTT(arr, mxpow);
			NNTT(arr, mxpow);
			for (int i = 0; i < mxpow; i++) {
				arr[i] += arr[i] < 0 ? MOD : 0;
				printf("%lld ", arr[i]);
			}
		}
	}
	
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}instance;

}


