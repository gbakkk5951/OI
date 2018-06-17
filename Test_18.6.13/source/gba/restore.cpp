using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cassert>
namespace OI {
typedef double lf;
const int MXN = 105;
const lf EPS = 5e-7;
struct _Main {
	lf x[MXN], y[MXN];
	lf d[MXN][MXN];
	lf dis(int a, int b) {
		return sqrt(pf(x[a] - x[b]) + pf(y[a] - y[b]));
	}
	int n;
	char eq(lf a, lf b) {
		return !(fabs(a - b) > EPS);
	}
	inline lf pf(lf a) {
		return a * a;
	}
	void solve() {
		int p0 = 1, p1 = 0, p2 = 0;
		lf d0, d1, d2, y1, y1f, x2, y2, d0f, d1f;
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
			y2 = y[p2] = (d1f - d0f - y1f) / (-2.0 * y1);
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
			for (int i = p0 + 1; i <= n; i++) {
				if (i == p2 || i == p1) continue;
				d0f = pf(d[i][p0]);
				d1f = pf(d[i][p1]); 
				d2 = d[i][p2];//神Tm算了没用的d2f，但没算d2, //改了之后没撤pf
				y[i] = (d1f - d0f - y1f) / (-2.0 * y1);
				x[i] = sqrt(d0f - pf(y[i]));
				lf t1 = dis(i, p2);
				x[i] = -x[i];
				lf t2 = dis(i, p2);
				if (fabs(t1 - d2) < fabs(t2 - d2)) {//sqrt为了防止爆EPS
					//改了之后没算d2 gg
					//Emmm精度设太高了，得取较精确的......
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
