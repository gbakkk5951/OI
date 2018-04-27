using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 100010;
const int DST = 0, NXT = 1;
int edge[MXN << 1][2];
int head[MXN];
int eidx;
int n, m, Qn;
struct Node {
	Node *s[2];
	int sum;
};
struct ChairTree {
	Node pool[132000 * 18], *null;
	int pidx;
	Node *new_() {
		Node *nd = &pool[pidx++];
		nd->s[0] = nd->s[1] = null;
		return nd;
	}
	ChairTree() {
		null = new_();
		null->s[0] = null->s[1] = null;
		root[0] = null;//忘了; 
	}
	Node *root[MXN];
	
	int query(int l, int r, int rk) {
		Node *a = root[l - 1], *b = root[r];
		int nl = 1, nr = n, mid, spo;
		while (nl != nr) {
			mid = nl + nr >> 1;
			if (spo = b->s[0]->sum - a->s[0]->sum < rk) {
				nl = mid + 1;
				rk -= b->s[0]->sum - a->s[0]->sum;
			} else {
				nr = mid;
			}
			a = a->s[spo];
			b = b->s[spo];
		}
		return nl;
	}
	void insert(int ia, int pos) {
		Node *a = root[ia] = new_(), *b = root[ia - 1];
		a->sum = b->sum + 1;
		int nl = 1, nr = n, mid, spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = pos > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			a->s[spo ^ 1] = b->s[spo ^ 1];
			a = a->s[spo] = new_();
			b = b->s[spo];
			a->sum = b->sum + 1;
		}
	}
}ctree;

namespace orgsp {
	int h[MXN], f[MXN][17];
	int dfn[MXN], l[MXN], r[MXN], idx;
	int size[MXN];
	int mxp;
	int getkth(int root, int rk) {
//		printf("getkth(%d, %d) = %d\n", root, rk, ctree.query(l[root], r[root], rk));
		return ctree.query(l[root], r[root], rk);
	}
	lld getlca(int a, int b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
//		printf("lca %d %d = ", a, b);
		for (int I = mxp; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				a = f[a][I];
			}
		}
		if (a == b) {
//			printf("%d\n", a);
			return a;
		}
		for (int I = mxp; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I];
				b = f[b][I];
			}
		}
//		printf("%d\n", f[a][0]);
		return f[a][0];
	}
	int getdis(int a, int b) {
		return h[a] + h[b] - (h[getlca(a, b)] << 1);
	}
	void dfs(int nd, int fa) {
		f[nd][0] = fa;
		h[nd] = h[fa] + 1;
		dfn[nd] = ++idx;
		l[nd] = idx;
		ctree.insert(idx, nd);
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
			mxp = max(mxp, I);
		}
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
				size[nd] += size[t];
			}
		}
		r[nd] = idx;
	}
	void init() {
		dfs(1, 0);
	}
}
namespace bigsp {
	lld l[MXN], r[MXN], idx, Idx;
	int h[MXN], f[MXN][17], mxp;
	lld d[MXN][17];
	int root[MXN], up[MXN];//up存的是在原树中的编号
	void update(int nd, int fa, lld dis) {
		f[nd][0] = fa;
		h[nd] = h[fa] + 1;
		d[nd][0] = dis;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
			d[nd][I] = d[nd][I - 1] + d[f[nd][I - 1]][I - 1];
			mxp = max(mxp, I);
		}
	}

	void link(int x, lld fa) {
		int f = lower_bound(r + 1, r + Idx + 1, fa) - r;
		int nd = ++Idx;
		up[nd] = orgsp::getkth(root[f], fa - l[f] + 1); 
		lld dis = 1 + orgsp::getdis(up[nd], root[f]);
//		printf("dis %d %d = %lld\n", f, nd, dis);
		update(nd, f, dis);
		l[nd] = idx + 1;
		r[nd] = idx += orgsp::size[x];
		root[nd] = x;
//		printf("[%d] up = %d, [%lld, %lld], root = %d\n", nd, up[nd], l[nd], r[nd], root[nd]);
	}

	lld getdis(lld a, lld b) {
		lld ret = 0;
		int ia = lower_bound(r + 1, r + Idx + 1, a) - r;
		int ib = lower_bound(r + 1, r + Idx + 1, b) - r;
		if (h[ia] < h[ib]) {
			swap(ia, ib);
			swap(a, b);
		}
//		printf("a = %lld, b = %lld\n", a, b);
//		printf("ia = %d, ib = %d\n", ia, ib);
		if (ia == ib) {
			return orgsp::getdis(orgsp::getkth(root[ia], a - l[ia] + 1), 
								 orgsp::getkth(root[ib], b - l[ib] + 1)
					);
		}
		
		ret += orgsp::getdis(orgsp::getkth(root[ia], a - l[ia] + 1), root[ia]);
		for (int I = mxp; I >= 0; I--) {
			if (h[ia] - (1 << I) >= h[ib] && f[ia][I] != ib) {
				ret += d[ia][I];
				ia = f[ia][I];
			}
		}
		if (h[ia] != h[ib]) { // up[ia] in same big with b
//			printf("h %d = %d, %d = %d\n", ia, h[ia], ib, h[ib]);
			ret++;
			return ret + orgsp::getdis(up[ia], orgsp::getkth(root[ib], b - l[ib] + 1));
		}
//		printf("b = %lld, l[%d] = %lld\n", b, ib, l[ib]);
		ret += orgsp::getdis(orgsp::getkth(root[ib], b - l[ib] + 1), root[ib]);
		for (int I = mxp; I >= 0; I--) {
			
			if (f[ia][I] != f[ib][I]) {
				ret += d[ia][I];
				ret += d[ib][I];
				ia = f[ia][I]; //ia写成a了 
				ib = f[ib][I]; //ib写成b了 
			}
		}
		ret += 1 + 1 + orgsp::getdis(up[ia], up[ib]);
		return ret;
	}
	void init() {
		Idx++;
		l[Idx] = 1;
		r[Idx] = idx = n;
		root[Idx] = 1;
		update(Idx, 0, 0);
	}
}


struct _Main {
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	
	_Main() {
		read(n); read(m); read(Qn);
//		n = 100000; m = 100000; Qn = 100;
		int u, v;
		for (int i = 1; i <= n - 1; i++) {
			read(u); read(v);
//			u = i; v = i + 1;
//			v = i + 1;
//			u = 1;
			add(u, v); add(v, u);

		}
		orgsp::init();
		int x;
		lld f;
		bigsp::init();
		for (int i = 1; i <= m; i++) {
			read(x); read(f);
//			x = 1; f = 1 + (i - 1) * 100000LL;
			bigsp::link(x, f);
		}
		lld a, b;
		for (int Q = 1; Q <= Qn; Q++) {
			read(a); read(b);
			printf("%lld\n", bigsp::getdis(a, b));
		}
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
}bzoj4539;
}
