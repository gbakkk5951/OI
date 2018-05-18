using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 7 * 17 << 23 | 1;
const lld PHI = MOD - 1;
const lld G = 3;
const int MXN = 264010;
namespace NTTsp {
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
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : 1;
		}
		return ret;
	}

	void NTT(lld arr[], int len, int pow) {
		static lld w[MXN >> 1];
		lld x, y, wn;
		lld *a, *b;
		mov_ele(arr, len);
		w[0] = 1;
		for (int I = 1; 1 << I <= len; I++) {
			int half = 1 << I - 1;
			wn = I > 1 ? fastpower(G, pow * PHI >> I) : 1;
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
				arr[i] += (arr[i] < 0 ? MOD : 0);
			}
		}
	}
}
lld b1[MXN], b2[MXN], a[MXN];
void getrev(lld org[], lld ans[], int m) {
	using namespace NTTsp;
	lld *b = b1, *c = b2;
	c[0] = fastpower(org[0], -1);
	for (int I = 2; I <= m; I <<= 1) {
		swap(b, c);
		memcpy(a, org, I * sizeof(lld));
		NTT(a, I << 1, 1); 
		NTT(b, I << 1, 1);
		for (int i = 0; i < I << 1; i++) c[i] = b[i] * (2 - a[i] * b[i] % MOD) % MOD;
		NTT(c, I << 1, -1);
		if (I < m) memset(c + I, 0, I * sizeof(lld));
	}
	memcpy(ans, c, m * sizeof(lld));
}

struct _Main {
	int n;
	lld fact[MXN];
	lld h[MXN]; //1 - h;
	lld g[MXN];
	_Main() {
		using namespace NTTsp;
		int mxpow;
		lld ans = 0;
		scanf("%d", &n);
		fact[0] = 1;
		for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
		h[0] = 1;
		for (int i = 1; i <= n; i++) h[i] = (-2 * fastpower(fact[i], -1)) % MOD;
		for (mxpow = 1; mxpow < n + 1; mxpow <<= 1);
		getrev(h, g, mxpow);
		for (int i = 0; i <= n; i++) ans = (ans + g[i] * fact[i]) % MOD;
		ans += ans < 0 ? MOD : 0;
		printf("%lld", ans);
	}
	
}bzoj4555;
}
