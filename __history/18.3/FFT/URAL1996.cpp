using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <complex>
#include <cmath>
namespace OI {
typedef double lf;
typedef complex<lf> com;
const lf pi = acos(-1);
const int MXN = 250050, POWN = 524288 + 5;
namespace FFTsp {
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
		int half;
		static com wn[POWN >> 1];
		com w, x, y;
		com *a, *b;
		mov_ele(arr, len);
		wn[0].imag(0); wn[0].real(1);
		for (int I = 1; 1 << I <= len; I++) {
			half = 1 << I - 1;
			if (I > 1) w.imag(pow * sin(2 * pi / (1 << I))), w.real(cos(2 * pi / (1 << I)));
			for (int i = half - 2; i >= 0; i -= 2) {
				wn[i] = wn[i >> 1];
			}
			for (int i = 1; i < half; i += 2) {
				wn[i] = wn[i - 1] * w;
			}
			for (int j = 0; j < len; j += half << 1) {
				a = arr + j; b = arr + j + half;
				for (int k = 0; k < half; k++) {
					x = a[k];
					y = b[k] * wn[k];
					a[k] = x + y;
					b[k] = x - y;
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
	int la, lb;
	int sa[MXN], sb[MXN];
	int nxt[MXN]; //若下一位匹配失败则跳到
	int match[MXN];
	int cost[MXN];
	void getnxt() {
		int j = 0;
		for (int i = 2; i <= lb; i++) {
			while (j && (sb[j + 1] | 1) != (sb[i] | 1)) {
				j = nxt[j];
			}
			if ((sb[j + 1] | 1) == (sb[i] | 1)) {
				j++;
			}
			nxt[i] = j;
		}
	}
	void getmatch() {
		int now = 0;
		for (int i = 1; i <= la; i++) {
			while (now && (sb[now + 1] | 1) != (sa[i] | 1)) {
				now = nxt[now];
			}
			if ((sb[now + 1] | 1) == (sa[i] | 1)) {
				now++;
			}
			if (now == lb) {
				match[i - lb + 1] = 1;
				now = nxt[now];
			}
		}
	}
	com a[POWN], b[POWN], ans[POWN];
	void getcost() {
		using FFTsp::FFT;
		int mxpow;
		for (mxpow = 1; mxpow < (la + lb); mxpow <<= 1);
		for (int i = 1; i <= lb >> 1; i++) {
			swap(sb[i], sb[lb - i + 1]);
		}
		for (int i = 0; i < la; i++) {
			a[i].real(sa[i + 1] & 1 ^ 1);
		}
		for (int i = 0; i < lb; i++) {
			b[i].real(sb[i + 1] & 1);
		}
		FFT(a, mxpow, 1);
		FFT(b, mxpow, 1);
		for (int i = 0; i < mxpow; i++) {
			ans[i] += a[i] * b[i];
		}
		memset(a, 0, mxpow * sizeof(com));
		memset(b, 0, mxpow * sizeof(com));
		for (int i = 0; i < la; i++) {
			a[i].real(sa[i + 1] & 1); //别把高位算上 
		}
		for (int i = 0; i < lb; i++) {
			b[i].real(sb[i + 1] & 1 ^ 1);
		}
		FFT(a, mxpow, 1);
		FFT(b, mxpow, 1);
		for (int i = 0; i < mxpow; i++) {
			ans[i] += a[i] * b[i];
		}
		FFT(ans, mxpow, -1);
		for (int i = 1; i <= la - lb + 1; i++) {
			cost[i] = round(ans[lb - 1 + i - 1].real());
		}
	}
	
	void getans() {
		for (int i = 1; i <= la - lb + 1; i++) {
			if (match[i]) {
				if (cost[i] < mn) {
					mn = cost[i];
					chose = i;
				}
			}
		}
	}
	int mn, chose;
	_Main() {
		chose = -1;
		mn = 0x3f3f3f3f;
		read(la); read(lb);
		if (lb > la) {
			printf("No");
			return;
		}
		for (int i = 1; i <= la; i++) {
			read(sa[i]);
		}
		for (int i = 1; i <= lb; i++) {
			read(sb[i]);
		}
		getnxt();
		getmatch();
		getcost();
		getans();
		if (chose == -1) {
			printf("No");
		} else {
			printf("Yes\n%d %d", mn, chose);
		}
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
}URAL1996;

}
