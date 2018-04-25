using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <pair>
namespace OI {
struct P;
typedef set<P>::iterator it;
typedef double lf;
typedef long long lld;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int MXN = 5e4 + 10;
const lf EPS = 1e-6;
lld ans[MXN];
lld op[MXN], x[MXN], y[MXN];
int end[MXN], app[MXN]; //消失点、结束点
const int CMP_RATE = 1, CMP_XY = 0;
int cmpmod;

struct P {
	lld x, y;
	lf rate;
	bool operator < (const P & b) const {
		if (cmpmod == CMP_XY) {
			if (x != b.x) {
				return x < b.x;
			}
			return y < b.y;
		}
		// CMP_RATE
		return  rate > b.rate;
	}
	P operator - (const P &b) const {
		return (P) {x - b.x, y - b.y, 0};
	}
	lld operator * (const P &b) const {
		return x * b.y - b.x * y;
	}
};


struct Convex {
	set<P> tree;
	void update(const P &nd, it &dst) {
		P tmp = *dst;
		tree.erase(dst);
		tmp.rate = (lf)(tmp.y - nd.y) / (tmp.x - nd.x);
		dst = tree.insert(tmp).first;
	}
	it getpre(it nd) {
		return nd == tree.begin() ? tree.end() : --nd;
	}
	it getnxt(it nd) {
		return ++nd;
	}
	void poppre(P &nd, it &pre) {
		it ppre;
		while ((ppre = getpre(pre)) != tree.end()) {
			if ((nd - *pre) * (*pre - *ppre) <= 0) {
				tree.erase(pre);
				pre = ppre;
			} else {
				break;
			}
		}
		if (pre.x == nd.x) {
			tree.erase(pre);
			pre = ppre;
		}
	}
	void popnxt(P &nd, it &nxt) {
		it nnxt;
		while ((nnxt = getnxt(nxt)) != tree.end()) {
			if ((*nnxt - *nxt) * (*nxt - nd) <= 0) {
				tree.erase(nxt);
				nxt = nnxt;
			} else {
				break;
			}
		}
	}
	void insert(lld x, lld y) {
		cmpmod = CMP_XY;
		
		P nd = (P) {x, y, 0};
		it nxt = tree.lower_bound(nd);
		if (nxt != tree.end() && nxt->x == x) return;
		it pre = getpre(nxt);
		if (nxt != tree.end() && pre != tree.end()
			&& ((*nxt - nd) * (nd - *pre) <= 0)
			) {
			return;
		}
		if (pre != tree.end()) poppre(nd, pre);
		if (nxt != tree.end()) popnxt(nd, nxt);
		
		if (pre != tree.end()) update(nd, pre);
		if (nxt != tree.end()) update(nd, nxt);
		
		if (nxt != tree.end()) {
			nd.rate = (lf)(x - nxt->x) / (y - nxt->y);
		} else {
			nd.rate = -INF;
		}
		tree.insert(nd);
	}
	P find(lf rate) {
		if (tree.empty()) return (P){-LINF, 0, 0};
		cmpmod = CMP_RATE;
		return *tree.lower_bound((P){0, 0, rate});
	}
}up, low;
lld mxx, mnx, mxy, mny;

void insert(lld x, lld y) {
	mxx = max(mxx, x);
	mnx = min(mnx, x);
	mxy = max(mxy, y);
	mny = min(mny, y);
	up.insert(x, y});
	low.insert(x, -y});
}
lld getans(lld x, lld y) {
	if (x == 0) {
		return y * (y < 0 ? mny : mxy);
	} 
	if (y == 0) {
		return x * (x < 0 ? mnx : mxx);
	}
	P tmp;
	if (y > 0) {
		tmp = up.find((lf)-x / y);
	} else
	if (y < 0) {
		tmp = low.find((lf)-x / -y);
	}
	if (tmp.x == -LINF) return -LINF;
	return x * tmp.x + y * tmp.y;
}
int qsum[MXN], asum[MXN];
void fenzhi(int l, int r) {
	int q1, q2, a1, a2;
	int mid = l + r >> 1;
	q1 = qsum[mid] - qsum[l - 1];
	q2 = qsum[r] - qsum[mid];
	a1 = asum[mid] - asum[l - 1];
	a2 = asum[r] - asum[mid];
	if (a1 && q2) {
		up.tree.clear();
		low.tree.clear();
		mxx = mxy = -INF;
		mnx = mny = INF; //LINF 会乘爆
		for (int i = l; i <= mid; i++) {
			if (op[i] == 1) {
				if (end[i] >= r) {
					insert(x[i], y[i]);
				}
			}
		}
		for (int i = r; i > mid; i--) {
			if (op[i] == 0) {
				ans[i] = max(ans[i], getans(x[i], y[i]));
			} else
			if (op[i] == -1) {
				if (app[i] <= mid) {
					insert(x[i], y[i]);
				}
			}
		}
	}
	if (q1 && a1) {
		fenzhi(l, mid);
	}
	if (q2 && a2) {
		fenzhi(mid + 1, r);
	}
}


map <pair<int, int>, int> id;
struct _Main {
	void clear() {
		id.clear();
		memset(ans + 1, 192, Qn * sizeof(lld));
	}
	int Qn;
	_Main() {
		while (1) {
			read(Qn);
			if (Qn == 0) break;
			clear();
			for (int Q = 1; Q <= Qn; Q++) {
				read(op[Q]); read(x[Q]); read(y[Q]);
				if (op[Q] == 1) {
					id[make_pair(x[Q], y[Q])] = Q;
				} else
				if (op[Q] == -1) {
					end[app[Q] = id[make_pair(x[Q], y[Q])]] = Q;
				}
			}
			for (int Q = 1; Q <= Qn; Q++) {
				asum[Q] = asum[Q - 1] + (op[Q] == 1);
			}
			for (int Q = 1; Q <= Qn; Q++) {
				qsum[Q] = qsum[Q - 1] + (op[Q] == 0);
			}
			fenzhi(1, Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				if (op[Q] == 0) {
					printf("%lld\n", ans[Q]);
				}
			}
		}
	}
	
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}instance;

}


