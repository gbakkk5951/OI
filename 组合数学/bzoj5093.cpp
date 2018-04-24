using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 119 << 23 | 1;
const lld PHI = MOD - 1;
const lld G = 3;
const int MXN = 540000;
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	pow += pow < 0 ? PHI : 0;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}
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
	lld *a, *b, x, y, wn;
	int half;
	mov_ele(arr, len);
	w[0] = 1;
	for (int I = 1; 1 << I <= len; I++) {
		half = 1 << I - 1;
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
		}
	}
}
struct _Main {
	lld s[MXN], tmp[MXN];
	lld ans;
	lld n;
	lld k;
	void getstirling() {
		tmp[0] = 1;
		for (lld i = 1; i <= k; i++) {
			tmp[i] = tmp[i - 1] * fastpower(i, -1) % MOD;
		}
		memcpy(s, tmp, (k + 1) * sizeof(lld));
		tmp[0] = 0;
		for (lld i = 1; i <= k; i++) {
			tmp[i] = tmp[i] * fastpower(i, k) % MOD; //ÍüÁË³Ëtmp[i] 
		}
		for (lld i = 1; i <= k; i++) {
			s[i] = (i & 1) ? -s[i] : s[i];
		}
		int mxpow;
		for (mxpow = 1; mxpow <= k << 1; mxpow <<= 1);
		NTT(s, mxpow, 1);
		NTT(tmp, mxpow, 1);
		for (int i = 0; i < mxpow; i++) {
			s[i] = s[i] * tmp[i] % MOD;
		}
		NTT(s, mxpow, -1);
	 }
	lld calc() {
		lld ret = 0, mul = 1;
		for (int i = 1; i <= k; i++) {
			mul = mul * ((n - 1) - i + 1) % MOD;
			ret = (ret + s[i] * mul % MOD * fastpower(2, (n - 1) - i)) % MOD;
		}
		return ret;
	}
	_Main() {
		read(n); read(k);
		ans = n * fastpower(2, ((n - 1) * (n - 2) >> 1) % PHI) % MOD;
		getstirling();
		ans = ans * calc() % MOD;
		ans += ans < 0 ? MOD : 0;
		printf("%lld", ans);
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
}bzoj5093;

}


