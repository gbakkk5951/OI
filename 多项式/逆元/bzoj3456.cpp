using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 479 << 21 | 1;
const lld PHI = MOD - 1;
const lld G = 3;
const int MXN = 264000;
namespace NTTsp {
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		pow %= PHI;
		pow += pow < 0 ? PHI : 0;
		while (pow) {
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : 0;
		}
		return ret;
	}
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
	void NTT(lld arr[], int len, int pow) {
		static lld w[MXN >> 1];
		lld x, y, wn;
		lld *a, *b;
		w[0] = 1;
		mov_ele(arr, len);
		for (int I = 1; 1 << I <= len; I++) {
			int half = 1 << I - 1;
			wn = fastpower(G, pow * PHI >> I);
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
				arr[i] = arr[i] * wn % MOD;
			}
		}
	}
	lld t1[MXN], t2[MXN], a[MXN];
	void getrev(lld org[], lld ans[], int m) {
		lld *b = t1, *c = t2;
		c[0] = fastpower(org[0], -1);
		for (int I = 2; I <= m; I <<= 1) {
			memcpy(a, org, I * sizeof(lld));
			swap(b, c);
			NTT(a, I << 1, +1);
			NTT(b, I << 1, +1);
			for (int i = 0; i < I << 1; i++) {
				c[i] = b[i] * (2 - a[i] * b[i] % MOD) % MOD;
			}
			NTT(c, I << 1, -1);
			if (I != m) memset(c + I, 0, I * sizeof(lld));//I 写成m 
		}
		memcpy(ans, c, m * sizeof(lld));
	}
}
struct _Main {
	lld fact[MXN]; //fact i = (i - 1) !
	int n;
	lld a[MXN], b[MXN], c[MXN];
	/*
	void mul(lld a[], lld b[], int len) {
		using namespace NTTsp;
		NTT(a, len, +1);
		NTT(b, len, +1);
		for (int i = 0; i < len; i++) {
			a[i] = a[i] * b[i] % MOD;
		}
		NTT(a, len, -1);
		for (int i = 0; i < len; i++) {
			printf("a[%d] = %lld\n", i, a[i]);
		}
	}*/
	
	_Main() {
		using namespace NTTsp;
		int mxpow;
		lld ans, p;
		read(n);
		fact[1] = 1;
		for (int i = 2; i <= n + 1; i++) {
			fact[i] = fact[i - 1] * (i - 1) % MOD;
		}
		for (int i = 0; i <= n; i++) {
			p = fastpower(2, i * (i - 1LL) >> 1);//指数爆int了 
			a[i] = p * fastpower(fact[i], -1) % MOD;
			c[i] = p * fastpower(fact[i + 1], -1) % MOD;
		}
		for (mxpow = 1; mxpow <= n; mxpow <<= 1);
		getrev(c, b, mxpow);
		NTT(a, mxpow << 1, +1);
		NTT(b, mxpow << 1, +1);
		
		
		for (int i = 0; i < mxpow << 1; i++) {
			b[i] = b[i] * a[i] % MOD;
		}
		NTT(b, mxpow << 1, -1);
		ans = b[n] * fact[n] % MOD;
		ans += ans < 0 ? MOD : 0;
		printf("%lld", ans);
	}
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
}bzoj3456;
}
