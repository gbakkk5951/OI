using namespace std;
int main() {}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
namespace OI {
const int MXN = 80005;
const char FAIL[] = "invalid request!" ;
const int NXT = 1, DST = 0;
int n, mx;
struct Node {
	Node *s[2];
	int sum;
}pool[MXN * 18 * 2 + MXN * 18 * 18 * 2];
int pidx;
Node *null;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
class ChairTree {
public:
	Node *root[MXN];
	ChairTree() {
		if (null == 0) {
			null = new_();
			null->s[0] = null->s[1] = null;
		}
		root[0] = null;
	}
	
	void insert(int ia, int ib, int val, int add) {
		Node *a = root[ia] = new_(), *b = root[ib];
		a->sum = b->sum + add;
		int nl = 1, nr = mx, mid, pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			a->s[pos ^ 1] = b->s[pos ^ 1];
			a = a->s[pos] = new_();
			b = b->s[pos];
			a->sum = b->sum + add;
		}
	}
}org;
class SegTree {
public:
	Node *root;
	SegTree() {
		root = new_();
	}
	void insert(int val, int add) {
		Node *nd = root;
		nd->sum += add;
		int nl = 1, nr = mx, mid, pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (nd->s[pos] == 0) {
				nd->s[pos] = new_();
			}
			nd = nd->s[pos];
			nd->sum += add;
		}
	}
};
class ArrayTree {
public:
	SegTree node[MXN * 2];
	int lb(int a) {
		return a & (-a);
	}
	void change(int nd, int val, int add) {
		for ( ; nd <= 2 * n; nd += lb(nd)) {
			node[nd].change(val, add);
		}
	}
	void query(int nd, Node *arr[], int &idx) {
		for ( ; nd; nd -= lb(nd)) {
			arr[idx++] = node[nd].root;
		}
	}
}cg;


struct _Main {
	int sorted[160005];
	int val[160005];
	int aug[160005][3];
	
	int out[MXN], in[MXN], f[MXN][16], h[MXN];
	int eidx;
	int head[MXN];
	int edge[MXN << 1][2];
	int dfn[MXN << 1];
	void dfs(int nd, int fa, int &idx) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		in[nd] = ++idx;
		dfn[idx] = nd;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != fa) {
				dfs(t, nd, idx);
			}
		}
		out[nd] = ++idx;
		dfn[idx] = -nd;
	}
	void add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	int aug[MXN][3];
	void change(int nd, int val) {
		cg.change(in[nd], this->val[nd], -1);
		cg.change(out[nd], this->val[nd], +1);
		cg.change(in[nd], val, +1);
		cg.change(out[nd], val, -1);
		this->val[nd] = val;
	}
	void getrank(int &val) {
		val = lower_bound(sorted + 1, sorted + mx + 1, val) - sorted;
	}
	int getlca(int a, int b) {
		if (h[a] < h[b]) swap(a, b);
		for (int I = 16; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				a = f[a][I];
			}
		}
		if (a == b) return a;
		for (int I = 16; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I];
				b = f[b][I];
			}
		}
		return a;
	}
	Node *node[80];
	int xishu[80];
	int query(int a, int b, int rk) {
		int lca = getlca(a, b);
		node[0] = org.root[in[a]]; xishu[0] = 1;
		node[1] = org.root[in[b]]; xishu[1] = 1;
		node[2] = org.root[in[lca]]; xishu[2] = -1;
		node[3] = org.root[in[lca] - 1]; xishu[3] = -1;
		int idx = 4, lst = 4;
		cg.query(in[a], node, idx);
		cg.query(in[b], node, idx);
		for (int i = lst; i < idx; i++) {
			xishu[i] = 1;
		}
		lst = idx;
		cg.query(in[lca], node, idx);
		cg.query(in[lca] - 1, node, idx);
		for (int i = lst; i < idx; i++) {
			xishu[i] = -1;
		}
		int nl = 1, nr = mx, mid, pos, sum;
		while (nl < nr) {
			sum = 0;
			for (int i = 0; i < idx; i++) {
				while (node[i] == null && i < idx) {
					swap(node[idx - 1], node[i]);
					swap(xishu[idx - 1], xishu[i]);
					idx--;
				}
				sum += node[i]->s[0]->sum * xishu[i];
			}
			if (pos = sum < pos) {
				rk -= sum;
				nl = mid + 1;
			} else {
				nr = mid;
			}
			for (int i = 0; i < idx; i++) {
				node[i] = node[i]->s[pos];
			}
		}
		return sorted[nl];
	}
	_Main() {
		int i, j, k;
		int Qn;
		int a, b;
		read(n); read(Qn);
		for(int i = 1; i <= n; i++) {
			read(val[i]);
		}
		mx = n;
		memcpy(sorted + 1, val + 1, n * sizeof(int));
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			for (int i = 0; i < 3; i++) {
				read(aug[Q][i]);
			}
			if (aug[Q][0] == 0) {
				sorted[++mx] = aug[Q][2];
			}
		}
		sort(sorted + 1, sorted + mx + 1);
		mx = unique(sorted + 1, sorted + mx + 1) - sorted - 1;
		for (int i = 1; i <= n; i++) {
			getrank(val[i]);
		}
		dfs(1, 0, *new int);
		for (int i = 1; i <= 2 * n; i++) {
			org.insert(i, i - 1, abs(dfn[i]), dfn[i] > 0 ? 1 : -1);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			if (aug[Q][0] == 0) {
				getrank(aug[Q][2]);
				change(aug[Q][1], aug[Q][2]);
			} else {
				printf("%d\n", query(aug[Q][1], aug[Q][2], aug[Q][0]));
			}
		}
	}
template <typename Type>	
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}bzoj1146;
}
