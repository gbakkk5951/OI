using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 264000;
const lld MOD = 119 << 23 | 1;
const lld PHI = MOD - 1;
const lld G = 3;
const lld REV2 = MOD + 1 >> 1;
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	pow += pow < 0 ? PHI : 0;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD: ret;
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
		mov_ele(arr, len);
		static lld w[MXN >> 1];
		lld x, y, wn, *a, *b;
		w[0] = 1;//又忘了 
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
	
	lld c[MXN];
	lld t1[MXN];
	void getrev(lld org[], lld ans[], int len) {
		using NTTsp::NTT;
		
		static lld t1[MXN], t2[MXN], t3[MXN];
		lld *a, *b, *c;
		a = t1; b = t2; c = t3;
		
		c[0] = fastpower(org[0], -1);
		for (int I = 1; 1 << I <= len; I++) {
			swap(b, c);
			
			memcpy(a, org, (1 << I) * sizeof(lld));
			memset(a + (1 << I), 0, (1 << I) * sizeof(lld));
			memset(b + (1 << I), 0, (1 << I) * sizeof(lld));
			
			NTT(b, 1 << I + 1, 1);
			NTT(a, 1 << I + 1, 1);
			
			for (int i = 0; i < 1 << I + 1; i++) {//神TM I++ 
				c[i] = b[i] * ((2 - a[i] * b[i]) % MOD) % MOD;
			}
			
			NTT(c, 1 << I + 1, -1);
			
			memset(c + (1 << I), 0, (1 << I) * sizeof(lld));
		}
		memcpy(ans, c, len * sizeof(lld));
	}
	void getsqrt(lld org[], lld ans[], int len) {
		using NTTsp::NTT;
		
		static lld t1[MXN], t2[MXN], t3[MXN];
		lld *a, *b, *c;
		a = t1; b = t2; c = t3;
		c[0] = 1; // org[0] == 1;
		for (int I = 1; 1 << I <= len; I++) {
			swap(b, c);
			
			memcpy(a, org, (1 << I) * sizeof(lld));
			
			getrev(b, c, 1 << I);//c 暂时存 1 / b;
			NTT(a, 1 << I + 1, 1);
			NTT(b, 1 << I + 1, 1);
			NTT(c, 1 << I + 1, 1); 
			for (int i = 0; i < 1 << I + 1; i++) {
				c[i] = (c[i] * a[i] + b[i]) % MOD * REV2 % MOD; 
			}
			NTT(c, 1 << I + 1, -1);
			memset(c + (1 << I), 0, (1 << I) * sizeof(lld));
		}
		memcpy(ans, c, len * sizeof(lld));
	}
	
	_Main() {
		using NTTsp::NTT;
		
		int n, m, mxpow, a;
		read(m); read(n);
		for (int i = 1; i <= m; i++) {
			read(a);
			if (a <= n) c[a]++;
		}
		for (mxpow = 1; mxpow <= n; mxpow <<= 1);
		t1[0] = 1;
		for (int i = 1; i <= n; i++) {
			t1[i] = -4 * c[i] % MOD;
			t1[i] += c[i] < 0 ? MOD : 0;
		}

		getsqrt(t1, t1, mxpow);

		t1[0] = 1 + t1[0];
		
		getrev(t1, t1, mxpow);

		for (int i = 0; i < mxpow << 1; i++) {
			t1[i] = t1[i] * 2 % MOD;
		}
		
		for (int i = 1; i <= n; i++) {
			printf("%lld\n", (t1[i] + MOD) % MOD);
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
	
}bzoj3625;

}


