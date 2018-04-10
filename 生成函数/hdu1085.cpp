using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef int lld;
const int MXN = 3, MXM = 8005;
lld tmp[MXM];
int mx;
struct Poly {
	lld arr[MXM];
	int high;
	lld & operator [] (int id) {
		return arr[id];
	}
	void operator *= (Poly &b) {
		memset(tmp, 0, (high + b.high + 1) * sizeof(lld));
		for (int i = 0; i <= high; i++) {
			if (arr[i] == 0) continue;
			for (int j = 0; j <= b.high; j++) {
				tmp[i + j] |= b[j];
			}
		}
		high += b.high;//Ã»¼Ó 
		memcpy(arr, tmp, (high + 1) * sizeof(lld));//Ã»³Ësizeof 
	}
}poly[MXN];
struct _Main {
	_Main() {
		int a[3], v[3] = {1, 2, 5};
		while (~scanf("%d%d%d", a, a + 1, a + 2)) {
			if (a[0] + a[1] + a[2] == 0) break;
			for (int i = 0; i < MXN; i++) {
				memset(poly[i].arr, 0, (poly[i].high + 1) * sizeof(int));
			}
			for (int i = 0; i < MXN; i++) {
				for (int j = 0; j <= a[i]; j++) {
					poly[i][poly[i].high = j * v[i]] = 1;
				}
				if (i) poly[i] *= poly[i - 1];
			}
			for (int i = 1; ; i++) {
				if (poly[2][i] == 0) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
}hdu1085;
}
