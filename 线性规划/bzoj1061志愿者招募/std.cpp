using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
namespace OI {
typedef long long lld;
typedef double lf;
const int MXN = 1e3 + 5, MXM = 1e4 + 5;
const lf EPS = 1e-4;
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
	lf init() {
		return 0;
	}
	lf simplex() {
		if (init() < -EPS) return -1;
		int cho, limcho;
		lf lim, tmp;
		
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
				if (A[i][cho] < -EPS) {//不要fabs 不要 < EPS
					tmp = -A[i][0] / A[i][cho];
					if (tmp < lim) {
						lim = tmp;
						limcho = i;
					}
				}
			}
			if (lim > 1e17) return 1e18;
			pivot(limcho, cho);
		}
		return A[0][0];
	}
	_Main() {
		int a, s, t, c;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(a); A[0][i] = a;
		}
		for (int i = 1; i <= m; i++) {
			read(s); read(t); read(c);
			for (int j = s; j <= t; j++) {
				A[i][j] = -1.0;
			}
			A[i][0] = c;
		}
		printf("%lld", (lld)round(simplex()));
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
