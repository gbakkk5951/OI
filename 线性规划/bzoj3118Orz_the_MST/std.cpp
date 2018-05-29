using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cmath>

namespace OI {
typedef double lf;
const int MXN = 1005, MXM = 4005;
const int DST = 0, NXT = 1, ID = 2;
lf A[MXM][MXN];
struct _Main {
	int vn, en;
	int n, m;//行、列
	void pivot(int x, int y) {
		lf rate = -1.0 / A[x][y];
		for (int j = 0; j <= m; j++) {
			A[x][j] *= rate;
		}
		A[x][y] = -rate;
		swap(bid[x], ubid[y]);
		for (int i = 0; i <= n; i++) {
			if (i != x && fabs(A[i][y]) > EPS) {
				rate = A[i][y];
				A[i][y] = 0;
				for (int j = 0; j <= m; j++) {
					A[i][j] += rate * A[x][j];
				}
			}
		}
	}
	void simplex() {
		int cho, cholim;
		lf tmp, lim;
		while (1) {
			cho = 0;
			for (int j = 1; j <= m; j++) {
				if (A[0][j] > EPS) {
					cho = j; break;
				}
			}
			if (cho == 0) break;
			lim = 1e300;
			for (int i = 1; i <= n; i++) {
				if (A[i][cho] < -EPS) {
					tmp = -A[i][0] / A[i][cho];
					if (tmp < lim) {
						tmp = lim;
						cholim = i;
					}
				}
			}
			pivot(cholim, cho);
		}
	}
	
	
	_Main() {
		read(vn); read(en);
		for (int e = 1; e <= en; e++) {
			read(a[e]); read(b[e]); read(v[e]); 
			read(intr[e]); read(dc[e]); read(ac[e]);
			if (intr[e]) add(a[e], b[e]), add(b[e], a[e]);
		}
		intitree();
		initchart();
		simplex();
		printf("%lld", (lld)round(A[0][0]));
	}
	int a[MXN], b[MXN], v[MXN], intr[MXN], dc[MXN], ic[MXN];
	inline void addlim(int te, int ute) {
		++m;
		A[0][m] = v[te] - v[ute];
		A[te][m] = -1.0;
		A[ute][m] = -1.0;
	}
	void initchart() {
		int a, b;
		n = en;
		for (int e = 1; e <= en; e++) {
			if (intr[e]) {
				A[e][0] = ic[e];
				continue;
			} else {
				A[e][0] = dc[e];
			}
			
			a = this->a[e], b = this->b[e];
			if (h[a] < h[b]) swap(a, b);
			while (h[a] > h[b]) {
				addlim(edge[fe[a]][ID], e);
				a = f[a];
			}
			while (a != b) {
				addlim(edge[fe[a]][ID], e);
				addlim(edge[fe[b]][ID], e);
				a = f[a]; b = f[b];
			}
		}
	}
	int f[MXN], fe[MXN], h[MXN];
	void inittree(int nd = 1, int fa = 0) {
		f[nd] = fa;
		h[nd] = h[fa] + 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				fe[t] = e;
				inittree(t, nd);
			}
		}
	}
	int eidx;
	int head[305], edge[305 << 1][3];
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		edge[eidx][ID] = c;
		head[a] = eidx;
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
