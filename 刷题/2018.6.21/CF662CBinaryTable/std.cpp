using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const int DST = 0, NXT = 1;
const int MXN = (1 << 20) + 10;
void Xor(lld arr[], int len) {
	lld *a, *b, x, y;
	for (int I = 1; 1 << I <= len; I++) {
		int half = 1 << I - 1;
		for (int j = 0; j < len; j += half << 1) {
			a = arr + j; b = arr + j + half;
			for (int k = 0; k < half; k++) {
				x = a[k]; y = b[k];
				a[k] = x + y;
				b[k] = x - y;
			}
		}
	}
}
void NXor(lld arr[], int len) {
	lld *a, *b, x, y;
	for (int I = 1; 1 << I <= len; I++) {
		int half = 1 << I - 1;
		for (int j = 0; j < len; j += half << 1) {
			a = arr + j; b = arr + j + half;
			for (int k = 0; k < half; k++) {
				x = a[k]; y = b[k];
				a[k] = x + y >> 1;
				b[k] = x - y >> 1;
			}
		}
	}
}
struct _Main {
	lld a[MXN];
	lld b[MXN];
	int num[100050];
	_Main() {
		int n, m, Qn, Tn;
		int len;
		char t;
		read(n); read(m);
		len = 1 << n;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				while (!isdigit(t = getchar()));
				num[j] |= t - '0' << i;
			}
		}
		for (int i = 1; i <= m; i++) {
			++a[num[i]];
		}
		for (int i = 0; i < len; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				cnt += i >> j & 1;
			}
			b[i] = min(cnt, n - cnt);
		}
		Xor(a, len);
		Xor(b, len);
		for (int i = 0; i < len; i++) {
			a[i] *= b[i];
		}
		NXor(a, len);
		int ans = 1e9;
		for (int i = 0; i < len; i++) {
			ans = min(ans, (int)a[i]);
		}
		printf("%d", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
