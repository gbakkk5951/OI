using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
namespace OI {
typedef long long lld;
typedef double lf;
const lf PI = acos(-1.0);
const lf EPS = 1e-8;
const int MXN = 1e3 + 5;
struct Swp {
	lf deg;
	int x, y;
	int fst, sec;
	bool operator < (const Swp &b) const {
		if (deg != b.deg) return deg < b.deg;
		return fst < b.fst;
	}
}q[MXN * MXN];

int x[MXN], y[MXN];
int cmp(int a, int b) { //以到(1, 0)的投影为依据，降序排序;
	return x[a] > x[b];
}

struct _Main{
	lld ans[MXN];
	int rk[MXN], va[MXN]; //从大到小排序
	lld xs[MXN], ys[MXN];
	int mark[MXN];
	int gcd(int a, int b) {
		while (b) {
			swap(a, b);
			b %= a;
		}
		return a;
	}
	void update(int l, int r) {
		for (int i = l; i <= r; i++) {
			xs[i] = xs[i - 1] + x[va[i]];
			ys[i] = ys[i - 1] + y[va[i]];
		}
		for (int i = l; i <= r; i++) {
			ans[i] = max(ans[i], xs[i] * xs[i] + ys[i] * ys[i]);
		}
		//改成2重或1重会不会快一些
		//2重会快，1重不会
	}
	int l[MXN], r[MXN];
	int n;
template <typename Type>
	Type inline pf (Type a) {
		return a * a;
	}
	inline lf getdeg(lf x, lf y) {
		return y < 0 ? 2 * PI - acos(x / sqrt(pf(x) + pf(y))) : acos(x / sqrt(pf(x) + pf(y)));
	}
	int qidx;
	int si[MXN];
	int size[MXN];
	int buksiz[MXN], buk[MXN];
	
	_Main() {
		lld ans1 = 0, ans2 = 0, tmp;
		lld xq, yq;
		read(n);
		read(xq); read(yq);
		for (int i = 1; i <= n; i++) {
			read(x[i]); read(y[i]);
		}
		for (int i = 1; i <= n; i++) {
			tmp = x[i] * xq + y[i] * yq;
			ans1 += tmp > 0 ? tmp : 0;
		}
		printf("%lld\n", ans1);
		Swp *nd; int g;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (x[i] == x[j] && y[i] == y[j]) continue;
				nd = &q[++qidx];
				nd->x = x[i] - x[j];
				nd->y = y[i] - y[j];
				//左旋90*
				swap(nd->x, nd->y);
				nd->x = -nd->x;
				//最简化
				g = gcd(abs(nd->x), abs(nd->y));
				nd->x /= g;
				nd->y /= g;
				
				nd->fst = j;
				nd->sec = i;
				nd->deg = getdeg(nd->x, nd->y);
			}
		}
		sort(q + 1, q + qidx + 1);//这玩意儿 Greater 个P啊
		
		for (int i = 1; i <= n; i++) {
			va[i] = i;
		}
		sort(va + 1, va + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			rk[va[i]] = i;
		}
		update(1, n);
		int rgn; // 区间个数
		int ed;//同一个fst的范围ed
		int mxsiz;
		for (int ql = 1, qr; ql <= qidx; ql = qr + 1) {
			for (qr = ql; qr + 1 <= qidx && q[qr + 1].x == q[qr].x && q[qr + 1].y == q[qr].y; qr++);
			rgn = 0;
			for (int st = ql; st <= qr; st = ed + 1) {
				for (ed = st; ed + 1 <= qr && q[ed + 1].fst == q[ed].fst; ed++);
				size[q[st].fst] = ed - st + 1;
				if (!mark[q[st].fst]) {
					++rgn;
					l[rgn] = rk[q[st].fst];
					r[rgn] = rk[q[st].fst];
					for (int j = st; j <= ed; j++) {
						l[rgn] = min(l[rgn], rk[q[j].sec]);//sec写成fst
						r[rgn] = max(r[rgn], rk[q[j].sec]);
						mark[q[j].sec] = 1;
					}
				}
			}
		
			for (int i = 1; i <= rgn; i++) {
				mxsiz = 0;
				for (int j = l[i]; j <= r[i]; j++) {
					si[j] = size[va[j]];
					mxsiz = max(mxsiz, si[j]);
					++buksiz[si[j]];
				}
				for (int j = mxsiz - 1; j >= 0; j--) {
					buksiz[j] += buksiz[j + 1];
				}
				for (int j = l[i]; j <= r[i]; j++) {
					buk[--buksiz[si[j]]] = va[j];
				}
				memset(buksiz, 0, (mxsiz + 1) * sizeof(int));
				memcpy(va + l[i], buk, (r[i] - l[i] + 1) * sizeof(int));
				for (int j = l[i]; j <= r[i]; j++) {
					rk[va[j]] = j;
				}
				update(l[i], r[i]);
			}
			for (int i = ql; i <= qr; i++) {
				mark[q[i].sec] = 0;
				size[q[i].fst] = 0;
			}
			
		}
		for (int i = 1; i <= n; i++) {
			ans2 = max(ans2, ans[i]);
		}
		printf("%lld\n", ans2);
		for (int i = 1; i <= n; i++) {
			printf("%lld ", ans[i]);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : 1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
