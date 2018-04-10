using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef int lld;
const int MX = 300, MXN = 20, MXM = 305;
const int N = 17;
lld tmp[MXN];
struct Poly {
	lld arr[MXM];
	int high;
	lld & operator [] (int id) {
		return arr[id];
	}
	void operator *= (Poly &b) {
		memset(tmp, 0, (min(MX, high + b.high) + 1) * sizeof(lld));
		for (int i = 0; i <= high; i++) {
			if (arr[i] == 0) continue;
			for (int j = 0; j <= b.high && i + j <= MX; j++) {
				tmp[i + j] += arr[i] * b[j];
			}
		}
		high = min(high + b.high, MX);
		memcpy(arr, tmp, (high + 1) * sizeof(lld));
	}
	
}poly[MXN];

struct _Main {
	_Main() {
		int n;
		for (int i = 1; i <= 17; i++) {
			for (int j = 0; j <= MX; j += i * i) {
				poly[i][j] = 1;
				poly[i].high = j;
			}
			if (i > 1) poly[i] *= poly[i - 1];
		}
		while (1) {
			read(n);
			if (n == 0) break;
			printf("%d\n", poly[17][n]);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a = a * 10 + t - '0';
		}
	}
}hdu1398;
}
