using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cmath>
namespace OI {
typedef double lf;
const int MXN = 105;
const lf EPS = 5e-7;
struct _Main {
	lf x[MXN], y[MXN];
	lf d[MXN][MXN];
	int n;
	char eq(lf a, lf b) {
		return !(fabs(a - b) > EPS);
	}
	inline lf pf(lf a) {
		return a * a;
	}
	void solve() {
		int p0 = 1, p1 = 0, p2 = 0;
		lf d0, d1, d2, y1, y1f, x2, y2, d0f, d1f, d2f;
		for (int i = 2; i <= n; i++) {
			if (!eq(d[i][p0], 0.0)) {
				p1 = i;
				y1 = y[p1] = d[p0][p1];
				y1f = pf(y1);
				break;
			}
		}
		for (int i = p1 + 1; i <= n; i++) {
			d0 = d[i][p0];
			d1 = d[i][p1]; 
			if (eq(d0 + d1, y1) || eq (abs(d1 - d0), y1)) continue;
			d0f = pf(d0);
			d1f = pf(d1); 
			p2 = i;
			y2 = y[p2] = (d1f - d0f - y1f) / (-2.0);
			x2 = x[p2] = sqrt(d0f - pf(y2));
			break;
		}
		if (p2 == 0) {//共线
			for (int i = p1 + 1; i <= n; i++) {
				d0 = d[i][p0];
				d1 = d[i][p1]; 
				if (eq(d0 + d1, y1)) {//中间
					y[i] = d0;
				} else if (eq(d0 - d1, y1)) {//上边
					y[i] = d0;
				} else {//下边
					y[i] = -d0;
				}
			}
		} else {//不共线
			for (int i = p1 + 1; i <= n; i++) {
				if (i == p2) continue;
				d0f = pf(d[i][p0]);
				d1f = pf(d[i][p1]); 
				d2f = pf(d[i][p2]);
				y[i] = (d1f - d0f - y1f) / (-2.0);
				x[i] = sqrt(d1f - pf(y[1]));
				if (!eq(sqrt(pf(x[i] - x2) + pf(y[i] - y2)), d2) ) {//sqrt为了防止爆EPS
					x[i] = -x[i];
				}
			}
		} 
		
	}
	_Main() {
		freopen("restore.in", "r", stdin);	
		freopen("restore.out", "w", stdout);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%lf", &d[i][j]);
			}
		}
		solve();
		for (int i = 1; i <= n; i++) {
			printf("%.10lf %.10lf\n", x[i], y[i]);
		}
		fclose(stdout);
	}
}restore;

}
