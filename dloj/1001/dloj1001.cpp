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
int n;
struct ZKW {
	int base;
	int node[270000];
	void build() {
		for (base = 4; base - 2 < n; base <<= 1);
	}
	void change(int s, int t) {
		if (s > t) return; 
		for (s = s + base - 1, t = t + base + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1) node[s ^ 1] = 1;
			if ( t & 1) node[t ^ 1] = 1;
		}
	}
	int query(int nd) {
		int ret = 0;
		for (nd += base; nd && !ret; nd >>= 1) {
			ret |= node[nd];
		}
		return ret;
	}
}stree;
struct Node {
	Node *s[2];
	int sum;
}pool[MXN * 18], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
struct ChairTree {
	Node *root[MXN];
	ChairTree() {
		null = new_();
		null->s[0] = null->s[1] = null; //null不是0 
		root[0] = null;
	}
	void insert(int ia, int ib, int val) {
		Node *a = root[ia] = new_(), *b = root[ib];
		a->sum = b->sum + 1;
		int nl = 1, nr = n, mid, spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = val > mid) {
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
	int query(int ia, int ib, int val) {
		Node *a = root[ia], *b = root[ib];
		if (val == n) {
			return b->sum - a->sum;
		}
		int ret = 0;
		int nl = 1, nr = n, mid, spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = val >= mid) {
				ret += b->s[0]->sum - a->s[0]->sum;
				if (val > mid) {
					nl = mid + 1;
				} else {
					break;
				}
			} else {
				nr = mid;
			}
			a = a->s[spo];
			b = b->s[spo];
		}
		return ret;
	}
}ctree;

struct _Main {
	int h[MXN], kl[MXN], kr[MXN], f[MXN][17], arr[MXN], id[MXN];
	int head[MXN], edge[MXN << 1][2], eidx;
	void inline add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void dfs(int nd, int fa, int &idx) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		arr[id[nd] = ++idx] = nd;
		kl[nd] = idx + 1;
		int t;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != fa) {
				dfs(t, nd, idx);
			}
		}
		kr[nd] = idx;
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
		return f[a][0];
	}
	_Main() {
//		freopen ("data0.in", "r", stdin);
//		freopen ("data0.out", "w", stdout);
		int a, b, Qn, op, lca;
		read(n); read(Qn);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		dfs(1, 0, a = 0);
		stree.build();
		for (int i = 1; i <= n; i++) {
			ctree.insert(i, i - 1, arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			if (op == 1) {//sort
				read(a);
				stree.change(kl[a] - 1, kr[a]);
			} else if (op == 2) {//lca
				read(a); read(b);
				if (h[a] < h[b]) swap(a, b);
				lca = getlca(a, b);
				if (lca != b && stree.query(id[lca])) { 
					lca = min(a, b);
				} else if(lca == b && b != 1 && stree.query(id[f[b][0]])) { //逻辑结构错误， 第二个的lca == b不能少 
					lca = min(a, b);
				}
				printf("%d\n", lca);
			} else {//geth
				read(a);
				if (a == 1 || stree.query(id[f[a][0]]) == 0) {
					printf("%d\n", h[a]);
					continue;//忘了continue 
				}
				int top = a;
				for (int I = 16; I >= 0; I--) {
					if (1 << I < h[top] && stree.query(id[f[top][I]])) {
						top = f[top][I];
					}
				}
				printf("%d\n", h[top] + ctree.query(kl[top] - 1, kr[top], a));
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
}dloj1001;
}
