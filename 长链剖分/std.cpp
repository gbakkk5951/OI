using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const lf EPS = 1e-5;
const int MXN = 1e5 + 10;
struct SegTree {
	lf node[270000];
	lf tag[270000];
	void add(int nd, lf v) {
		node[nd] += v;
		tag[nd] += v;
	}
	void update(int nd) {
		node[nd] = max(node[ls[nd]], node[rs[nd]]);
	}
	void push(int nd) {
		if (fabs(tag[nd]) > EPS) {
			add(ls[nd], tag[nd]);
			add(rs[nd], tag[nd]);
			tag[nd] = 0;
		}
	}
	void pushmx(int nd, int nl, int nr, int pos, lf v) {
		while (nl != nr) {
			push(nd);
			node[nd] = max(node[nd], v);
			int mid = nl + nr >> 1;
			if (pos <= mid) {
				nd = ls[nd]; nr = mid;
			} else {
				nd = rs[nd]; nl = mid + 1;
			}
		}
		node[nd] = max(node[nd], v);
	}
	lf getmx(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return node[nd];
		}
		int mid = nl + nr >> 1;
		push(nd);
		lf ret = -LINF;
		if (l <= mid) ret = max(ret, getmx(ls[nd], nl, mid, l, r));
		if (r > mid) ret = max(ret, getmx(rs[nd], mid + 1, nr, l, r));
		return ret;
	}
	void add(int nd, int nl, int nr, int l, int r, lf val) {
		if (l <= nl && nr <= r) {
			add(nd, val);
			return;
		}
		int mid = nl + nr >> 1;
		push(nd);
		if (l <= mid) add(ls[nd], nl, mid, l, r, val);
		if (r > mid) add(rs[nd], mid + 1, nr, l, r, val);
		update(nd);
	}
	void clear(int nd, int nl, int nr) {
		node[nd] = tag[nd] = 0;
		if (nl == nr) {
			return;
		}
		int mid = nl + nr >> 1;
		clear(ls[nd], nl, mid);
		clear(rs[nd], mid + 1, nr);
	}
}tree;

struct _Main {
	int L, R;
	int n;
	int idx;
	int id[MXN];
	int dep[MXN], son[MXN], end[MXN], se[MXN];
	int a[MXN], b[MXN], c[MXN];
	lf ans;
	void dfs0(int nd, int fa) {
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				dfs0(t, nd);
				if (dep[t] > dep[son[nd]]) {
					son[nd] = t;
					se[nd] = e;
				}
			}
		}
		dep[nd] = dep[son[nd]] + 1;
	}
	void dfs1(int nd, int fa) {
		id[nd] = ++idx;
		if (son[nd]) {
			dfs1(son[nd], nd);
			end[nd] = end[son[nd]];
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				int t = edge[e][DST];
				if (t != fa && t != son[nd]) {
					dfs1(t, nd);
				}
			}
		} else {
			end[nd] = idx;
		}
	}
	lf tmp[MXN];
	void dfs2(int nd, int fa, lf fv) {
		if (son[nd]) {
			dfs2(son[nd], nd, val[se[nd]]);
		}
		//WAWAWA
		int l, r;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa && t != son[nd]) {
				dfs2(t, nd, val[e]);
				//以nd为LCA
				for (int i = id[t]; i <= end[t]; i++) {
					l = max(id[nd], id[nd] + L - (i - id[t] + 1));
					r = min(end[nd], id[nd] + R - (i - id[t] + 1));
					tmp[i] = tree.getmx(1, 1, n, i, i);
					if (l <= r) {
						ans = max(ans, tree.getmx(1, 1, n, l, r) + tmp[i]);
					}
				}
				//加入链
				for (int i = id[t]; i <= end[t]; i++) {
					tree.pushmx(1, 1, n, id[nd] + i - id[t] + 1, tmp[i]);
				}
			}
		}
		//以nd为端点
		l = id[nd] + L;
		r = min(end[nd], id[nd] + R);
		if (l <= r) {
			ans = max(ans, tree.getmx(1, 1, n, l, r));
		}
		tree.add(1, 1, n, id[nd], end[nd], fv);
	}
	_Main() {
		read(n);
		read(L); read(R);
		for (int i = 1; i <= n - 1; i++) {
			read(a[i]); read(b[i]); read(c[i]);
			add(a[i], b[i], 0);
			add(b[i], a[i], 0);
		}
		dfs0(1, 0);
		dfs1(1, 0);
		lf l = 0, r = 1e6;
		while (r - l > EPS) {
			ans = -1;
			lf mid = (l + r) / 2.0;
			eidx = 0;
			memset(head + 1, 0, n * sizeof(int));
			for (int i = 1; i <= n - 1; i++) {
				add(a[i], b[i], c[i] - mid); add(b[i], a[i], c[i] - mid);
			}
			tree.clear(1, 1, n);
			dfs2(1, 0, 0);
			if (ans > 0) {
				l = mid;
			} else {
				r = mid;
			}
		}
		printf("%.3lf", l);
	}
	int head[MXN], edge[MXN << 1][2], eidx;
	lf val[MXN << 1];
	void add(int a, int b, lf v) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
		val[eidx] = v;
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}//Satan
