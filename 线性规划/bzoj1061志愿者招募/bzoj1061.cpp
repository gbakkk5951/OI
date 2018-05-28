using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef double lf;
const int MXN = 1e3 + 5, MXM = 1e4 + 5;
const lf EPS = 1e-6;
struct _Main {
	int n, m;
	lf a[MXM][MXN];
	lf C[MXM];
	lf A[MXM];
	void pivot(int x, int y) {
		
		
	}
	lf init() {
		return 0;
	}
	lf simplex() {
		if (init() < -EPS) return -1;
		int cho, limcho;
		lf lim, tmp;
		while (1) {
			cho = 0;
			for (int i = 1; i <= n; i++) {
				if (c[i] > EPS) {
					cho = i; break;
				}
			}
			if (cho == 0) break;
			lim = 1e18; 
			for (int j = 1; j <= m; j++) {
				if (a[j][cho] > EPS) {
					tmp = -c[i] / a[i][cho];
					if (tmp < lim) {
						lim = tmp;
						limcho = j;
					}
				}
			}
			if (lim > 1e17) return 1e18;
			pivot(limcho, cho);
		}
		
	}
	_Main() {
		
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
}bzoj1061;
}
