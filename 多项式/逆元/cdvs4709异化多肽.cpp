#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {}


namespace OI {
typedef long long lld;
const lld MOD = 1917 << 19 | 1;
const lld PHI = MOD - 1;
const lld G = 5;
const int MXN = 270000;
/*
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}

lld fact[50000], fcnt;
void divphi() {
	lld rem = PHI;
	for (int i = 2; i * i <= PHI; i++) {
		if (rem % i == 0) {
			fact[fcnt++] = i;
			if (i * i != PHI) fact[fcnt++] = PHI / i;
		}
	}
}
char isroot(int a) {
	for (int i = 0; i < fcnt; i++) {
		if (fastpower(a, fact[i]) == 1) {
			return 0;
		}
	}
	return 1;
}
*/
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	pow += pow < 0 ? PHI : 0;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}
namespace NTTsp {

	void mov_ele(lld arr[], int len) {
		for (int i = 1, j = 0, k; i < len; i++) {
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
		lld x, y, wn, *a, *b;
		mov_ele(arr, len);
		w[0] = 1;
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
}

struct _Main {
	lld f[MXN];
	void getrev(lld org[], lld ans[], int len) {
		static lld t1[MXN], t2[MXN], a[MXN];
		lld *b = t1, *c = t2;
		c[0] = fastpower(org[0], -1);
		for (int I = 1; 1 << I <= len; I++) {
			swap(b, c);
			memcpy(a, org, (1 << I) * sizeof(lld));
			//memset(a + (1 << I), 0, (1 << I) * sizeof(lld)); 只有一次不用清空
			using NTTsp::NTT;
			NTT(a, 1 << I + 1, 1);
			NTT(b, 1 << I + 1, 1);
			for (int i = 0; i < 1 << I + 1; i++) {
				c[i] = b[i] * (2 - a[i] * b[i] % MOD) % MOD;
			}
			NTT(c, 1 << I + 1, -1);
			memset(c + (1 << I), 0, (1 << I) * sizeof(lld));
		}
		memcpy(ans, c, len * sizeof(lld));
	}
	_Main() {
		/*
		divphi();
		for (int i = 2; i < MOD; i++) {
			if (isroot(i)) {
				printf("G = %d\n", i);
				break;
			}
		}*/

		int n, m, a, mxpow;
		read(n); read(m);
		f[0] = 1;
		for (int i = 1; i <= m; i++) {
			read(a); 
			f[a] -= a <= n ? 1 : 0;
		}
		for (mxpow = 1; mxpow <= n; mxpow <<= 1);
		getrev(f, f, mxpow);
		printf("%lld", (f[n] % MOD + MOD) % MOD);
		fclose(stdout);
		
		
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
}cogs2259;

}
