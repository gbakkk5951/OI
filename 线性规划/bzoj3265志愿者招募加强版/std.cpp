using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
namespace OI {
typedef long long lld;
typedef double lf;
const lf EPS = 1e-6;
const int MXN = 1e3 + 5, MXM = 1e4 + 5;
struct _Main {
	int n, m;
	lf A[MXM][MXN];
	void pivot(int x, int y) {
		lf rate = -1.0 / A[x][y];
		for (int j = 0; j <= n; j++) {
			A[x][j] *= rate;
		}
		A[x][y] = -rate;
		for (int i = 0; i <= m; i++) {
			if (i != x && fabs(A[i][y]) > EPS) {
				rate = A[i][y];
				A[i][y] = 0;
				for (int j = 0; j <= n; j++) {
					A[i][j] += rate * A[x][j];
				}
			}
		}
		
	}
	lld simplex() {
		int cho, limcho;
		lf tmp, lim;
		while (1) {
			cho = 0;
			for (int j = 1; j <= n; j++) {
				if (A[0][j] > EPS) {
					cho = j; break;
				}
			}
			if (cho == 0) break;
			lim = 1e18;
			for (int i = 1; i <= m; i++) {
				if (A[i][cho] < -EPS) {
					tmp = - A[i][0] / A[i][cho];
					if (tmp < lim) {
						lim = tmp;
						limcho = i;
					}
				}
			}
			pivot(limcho, cho);	
		}
	
		return A[0][0];
	}
	_Main() {
		int k, st, ed, c, a;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(a); A[0][i] = a;
		}
		for (int j = 1; j <= m; j++) {
			read(k);
			while (k--) {
				read(st); read(ed);
				fill(A[j] + st, A[j] + ed + 1, -1.0);
			}
			read(a);
			A[j][0] = a;
		}
		printf("%lld\n", (lld)round(simplex()));
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
}std;
}
