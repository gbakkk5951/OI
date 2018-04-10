using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
namespace OI {
typedef int lld;
const int MXN = 125;
lld tmp[MXN];
struct Poly {
	int high;
	lld arr[MXN];
	lld & operator [] (int idx) {
		return arr[idx];
	}
	void operator *= (Poly &b) {
		memset(tmp, 0, (min(high + b.high, 120) + 1) * sizeof(lld));
		for (int i = 0; i <= high; i++) {
			if (arr[i] == 0) continue;
			for (int j = 0; j <= b.high && (i + j) <= 120; j++) {
				tmp[i + j] += arr[i] * b[j];
			}
		}
		high = min(high + b.high, 120);
		memcpy(arr, tmp, (high + 1) * sizeof(lld));
	}
}poly[MXN];
struct _Main {
	_Main() {
		for (int i = 1; i <= 120; i++) {
			for (int j = 0; j <= 120; j += i) {
				poly[i][j] = 1;
				poly[i].high = j;
			}
		}
		for (int i = 2; i <= 120; i++) {
			poly[i] *= poly[i - 1];
		}
		int n;
		while (~scanf("%d", &n)) {
			printf("%d\n", poly[120][n]);
		}
	}
}hdu1028;
}
