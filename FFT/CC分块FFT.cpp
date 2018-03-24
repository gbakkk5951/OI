using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
namespace OI {
typedef double lf;
typedef long long lld;
const lf pi = acos(-1.0);
const int SQN = 500, MXN = 100005, MX = 30005;
lld ans;
struct com {
	lf real, imag;
	com operator * (const com &b) const {
		return (com){real * b.real - imag * b.imag, real * b.imag + imag * b.real};
	}
	void operator /= (lf b) {
		real /= b;
	}
	com operator + (const com &b) const {
		return (com){real + b.real, imag + b.imag};
	}
	com operator - (const com &b) const {
		return (com){real - b.real, imag - b.imag};
	}
};

namespace FFTSpace {
void mov_ele(com arr[], int len) {
	int i, j = 0, k;
	for (i = 1; i < len; i++) {
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
	static com w[32769];
	com wn, x, y;
	int half;
	com *a, *b;
	w[0].real = 1, w[0].imag = 0;
	mov_ele(arr, len);
	for (int I = 1; 1 << I <= len; I++) {
		half = 1 << I - 1;
		wn.real = cos(2.0 * pi / (1 << I));
		wn.imag = pow * sin(2.0 * pi / (1 << I));
		for (int i = (1 << I - 1) - 2; i > 0; i -= 2) {
			w[i] = w[i >> 1];
		}
		for (int i = 1; i < 1 << I - 1; i += 2) {
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
		for (int i = 0; i < len; i++) {
			arr[i] /= len;
		}
	}
}
}

struct _Main {
	int sq;
	int st[MXN], ed[MXN], id[MXN];
	int cnt[MX];
	int arr[MXN];
	int idx;
	int n;
	int mxbit, mx;
	com c1[65537], c2[65537];
	void maincalc() {
		for (int i = 2; i < id[n]; i++) {
			memset(c1, 0, mxbit * sizeof(com));
			memset(c2, 0, mxbit * sizeof(com));
			for (int j = 1; j < st[i]; j++) {
				c1[arr[j]].real += 1;
			}
			for (int j = ed[i] + 1; j <= n; j++) {
				c2[arr[j]].real += 1;
			}
			using FFTSpace::FFT;
			FFT(c1, mxbit, 1);
			FFT(c2, mxbit, 1);
			for (int j = 0; j < mxbit; j++) {
				c1[j] = c1[j] * c2[j];
			}
			FFT(c1, mxbit, -1);
			for (int j = st[i]; j <= ed[i]; j++) {
				ans += round(c1[arr[j] * 2].real);
			}
		}
	}
	void init() {
		sq = min(n, (int)ceil(sqrt(10 * mx * (log(mx) + 1))));
		idx = 1;
		for (int i = 1; i <= n; i++) {
			id[i] = idx;
			if (i % sq == 0) {
				ed[idx] = i;
				st[++idx] = i + 1;
			}
		}
		ed[id[n]] = n;
		st[id[1]] = 1;
		ed[0] = st[0] = n + 1;
	}
	void precalc() {
		int t;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= ed[id[i]]; j++) {
				t = arr[i] - (arr[j] - arr[i]);
				if (t >= 1 && t <= mx) {
					ans += cnt[t];
				}
			}
			cnt[arr[i]]++;
		}
		memset(cnt, 0, (mx + 1) * sizeof(int));
		for (int i = n; i >= 1; i--) {
			for (int j = i - 1; j >= st[id[i]]; j--) {
				t = arr[i] + arr[i] - arr[j];
				if (t >= 1 && t <= mx) {
					ans += cnt[t];
				}
			}
			if (i == st[id[i]]) {
				for (int j = st[id[i]]; j <= ed[id[i]]; j++) {
					cnt[arr[j]]++;
				}
			}
		}
	}

	_Main() {
		read(n);
//		n = 1e5;
//		n = (rand() << 15 | rand()) % 100000 + 1;
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
//			arr[i] = (rand() << 15 | rand()) % 30000 + 1;
			mx = max(mx, arr[i]);
		}
		for (mxbit = 1; mxbit <= 2 * mx; mxbit <<= 1);
		init();
		precalc();
		maincalc();
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
}CC;

}
