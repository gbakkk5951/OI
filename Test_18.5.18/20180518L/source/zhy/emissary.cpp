using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int ADD = 0;
const int MXN = 1e5 + 10;
const int DST = 0, NXT = 1;

int n;
struct ArrayTree {
	int node[MXN];
	void change(int nd, int v) {
		for (; nd <= n; nd += nd & (-nd)) {
			node[nd] += v;
		}
	}
	int query(int nd) {
		int ret = 0;
		for (; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
}tree;
struct Qs {
	int tp, x, y, v;
	bool operator < (const Qs &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return tp < b.tp;
	}
}; 

struct _Main {

	int mxp;
	int qidx;
	Qs q[500000 + 10];
	int ans[50005];
	inline void push(int tp, int x, int y, int v) {
		q[++qidx] = (Qs) {tp, x, y, v};
	}
	void ask(int id, int x1, int x2, int y1, int y2, int xsu = 1) {
		push(id, x2, y2, xsu);
		if (x1 > 1) push(id, x1 - 1, y2, -xsu);
		if (y1 > 1) push(id, x2, y1 - 1, -xsu);
		if (x1 > 1 && y1 > 1) push(id, x1 - 1, y1 - 1, xsu);
	}
	int h[MXN], f[MXN][17];
	int dfn[MXN], l[MXN], r[MXN], dfnidx;
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		l[nd] = dfn[nd] = ++dfnidx;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
			}
		}
		r[nd] = dfnidx;
	}
	int getlca(int a, int b) {//h[a] >= h[b];
		for (int I = mxp; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				a = f[a][I];
			}
		}
		if (a == b) return a;
		for (int I = mxp; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I];
				b = f[b][I];
			}
		}
		return f[a][0];
	}
	int get_son(int high, int low) {
		for (int I = mxp; I >= 0; I--) {
			if (h[low] - (1 << I) > h[high]) {
				low = f[low][I];
			}
		}
		return low;
	}
	Qs tmp[500000 + 10];
	void solve(int l, int r) {
		int mid = l + r >> 1, idx = 0, a1 = 0, q1 = 0, a2 = 0, q2 = 0;
		for (int i = l; i <= mid; i++) {
			if (q[i].tp == 0) {
				a1++;
				tmp[++idx] = q[i];
			} else {
				q1++;
			}
		}
		for (int i = mid + 1; i <= r; i++) {
			if (q[i].tp != 0) {
				q2++;
				tmp[++idx] = q[i];
			} else {
				a2++;
			}
		} 
		if (a1 && q2) {
			sort(tmp + 1, tmp + idx + 1);
			for (int i = 1; i <= idx; i++) {
				//tmp写成q了
				if (tmp[i].tp == 0) {
					tree.change(tmp[i].y, tmp[i].v);
				} else {
					ans[tmp[i].tp] += tree.query(tmp[i].y) * tmp[i].v;
				}
			}
			if (a1 * mxp + idx < n) {//考虑到memset常数小 所以左边的就不除2了
				for (int i = 1; i <= idx; i++) {
					if (tmp[i].tp == 0) {
						tree.change(tmp[i].y, -tmp[i].v);
					}
				}
			} else {
				memset(tree.node + 1, 0, n * sizeof(int));
			}
		}
		if (a1 && q1) solve(l, mid);
		if (a2 && q2) solve(mid + 1, r);
	}
	void ins(int a, int b, int xs = 1) {
		push(0, dfn[a], dfn[b], xs);
		if (a != b) push(0, dfn[b], dfn[a], xs);
	}
	_Main() {
		freopen("emissary.in", "r", stdin);
		freopen("emissary.out", "w", stdout);
		int Qn, m;
		int op, a, b, an = 0, lca, s;
		read(n);
		for (mxp = 1; 1 << mxp + 1 < n; mxp <<= 1);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		dfs(1, 0);
		read(m);
		for (int i = 1; i <= m; i++) {
			read(a); read(b);
			ins(a, b);
		}
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(a); read(b);
			if (op == 1) {//Ins
				ins(a, b);
			} else 
			if (op == 2) {//Del
				ins(a, b, -1);
			} else {//Query
				++an;
				if (a == b) {
					ask(an, 1, n, 1, n);
					ans[an]++;//不走传送点
				} else {
					if (h[a] < h[b]) swap(a, b);
					lca = getlca(a, b);
					if (lca == b) {
						s = get_son(b, a);
						ask(an, l[a], r[a], 1, n);
						ask(an, l[a], r[a], l[s], r[s], -1);
					} else {
						ask(an, l[a], r[a], l[b], r[b]);
					}
				}
			}
		}
		solve(1, qidx);
		for (int i = 1; i <= an; i++) {
			printf("%d\n", ans[i]);
		}
		fclose(stdout);
	}
	int eidx, head[MXN], edge[MXN << 1][2];
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
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
}emissary;
}
