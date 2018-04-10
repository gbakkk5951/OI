using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstring>
namespace OI {
const int MXN = 105;
int need;
int tmp[MXN];
struct Poly {
	int low, high;
	int arr[MXN];
	int & operator [] (int id) {
		return arr[id];
	}
	void operator *= (Poly &b) {
		int nh = min(need, high + b.high);
		int nl = low + b.low;
		memset(tmp, 0, (nh + 1) * sizeof(int));//把这个直接放if里面会WA掉 
		if (nl <= nh) {
			for (int i = low; i <= high; i++) {
				for (int j = b.low; j <= b.high && i + j <= need; j++) {
					tmp[i + j] += arr[i] * b[j];
				}
			}
		}
		memcpy(arr, tmp, (nh + 1) * sizeof(int));
		high = nh; low = nl;
	}
}poly[MXN];
struct _Main {
	_Main() {
		int n;
		while (~scanf("%d%d", &n, &need)) {
			for (int i = 1; i <= n; i++) {
				memset(poly[i].arr, 0, (need + 1) * sizeof(int));
				read(poly[i].low); read(poly[i].high);
				for (int j = poly[i].low; j <= poly[i].high; j++) {
					poly[i][j] = 1;
				}
				if (i != 1) poly[i] *= poly[i - 1];
			}
			printf("%d\n", poly[n][need]);
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
}hdu2152;
}
