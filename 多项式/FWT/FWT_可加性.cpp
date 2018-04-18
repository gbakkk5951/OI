using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 4100;
const lld MOD = 479 << 21 | 1;
const lld PHI = MOD - 1;
const lld rev2 = MOD + 1 >> 1;

void FWT(lld arr[], int len) {
	for (int I = 1; 1 << I <= len; I++) {
		int half = 1 << I - 1;
		lld *a, *b;
		lld x;
		for (int i = 0; i < len; i += half << 1) {
			a = arr + i; b = arr + i + half;
			for (int j = 0; j < half; j++) {
				a[j] = (a[j] + b[j]) % MOD;
			}
		}
	}
}
void NFWT(lld arr[], int len) {
	for (int I = 1; 1 << I <= len; I++) {
		int half = 1 << I - 1;
		lld *a, *b;
		for (int i = 0; i < len; i += half << 1) {
			a = arr + i; b = arr + i + half;
			for (int j = 0; j < half; j++) {
				a[j] = (a[j] - b[j]) % MOD;
			}
		}
	}
}
struct _Main {
	int n, mxpow;
	lld a[MXN], b[MXN];
	_Main() {
		read(n);
		for (mxpow = 1; mxpow < n; mxpow <<= 1);
		for (int i = 0; i < n; i++) {
			read(a[i]);
		}
		for (int i = 0; i < n; i++) {
			read(b[i]);
		}
		FWT(a, mxpow);
		FWT(b, mxpow);
		for (int i = 0; i < mxpow; i++) {
			a[i] = b[i] = (a[i] + b[i]) % MOD;
			a[i] *= b[i];
			a[i] %= MOD;
		}
		NFWT(a, mxpow);
		for (int i = 0; i < n; i++) {
			a[i] += a[i] < 0 ? MOD : 0;
			printf("%lld\n", a[i]);
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
}bottom_to_up;

}
