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
struct Node {
	int s[2];
	int sum;
}node[MXN * 18];
int null;
int pidx;
int new_() {
	int nd = pidx++;
	node[nd].s[0] = node[nd].s[1] = null;
	return nd;
}
struct ChairTree {
	int root[MXN];
	ChairTree() {
		null = new_();
		node[null].s[0] = node[null].s[1] = null; //null不是0 
		root[0] = null;
	}
	void insert(int ia, int ib, int val) {
		int a  = root[ia] = new_(), b = root[ib];
		node[a].sum = node[b].sum + 1;
		int nl = 1, nr = n, mid, spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			node[a].s[spo ^ 1] = node[b].s[spo ^ 1];
			a = node[a].s[spo] = new_();
			b = node[b].s[spo];
			node[a].sum = node[b].sum + 1;
		}
	}
	int query(int ia, int ib, int val) {
		int a = root[ia], b = root[ib];
		if (val == n) {
			return node[b].sum - node[a].sum;
		}
		int ret = 0;
		int nl = 1, nr = n, mid, spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = val >= mid) {
				ret += node[node[b].s[0]].sum - node[node[a].s[0]].sum;
				if (val > mid) {
					nl = mid + 1;
				} else {
					break;
				}
			} else {
				nr = mid;
			}
			a = node[a].s[spo];
			b = node[b].s[spo];
		}
		return ret;
	}
}ctree;

struct _Main {
	int h[MXN], kl[MXN], kr[MXN], f[MXN][17], arr[MXN];
	int head[MXN], edge[MXN << 1][2], eidx;
	int fa[MXN];
	int getfa(int a) {
		return fa[a] ? fa[a] = getfa(fa[a]) : a;
	}

	void inline add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void dfs(int nd, int fa, int &idx) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		arr[++idx] = nd;
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
	char vis[MXN];
	void merge(int a) {
		vis[a] = 1;
		int t;
		for (int e = head[a]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != f[a][0] ) {
				if (!vis[t]) merge(t);
				fa[t] = a;
			}
		}
	}
	_Main() {
		int a, b, Qn, op, lca;
		read(n); read(Qn);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		dfs(1, 0, a = 0);
		for (int i = 1; i <= n; i++) {
			ctree.insert(i, i - 1, arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			if (op == 1) {//sort
				read(a);
				if (!vis[a]) {
					merge(a);
				}
			} else if (op == 2) {//lca
				read(a); read(b);
				if (h[a] < h[b]) swap(a, b);
				lca = getlca(a, b);
				if (lca != b && vis[lca]) { 
					lca = min(a, b);
				} else if(lca == b && b != 1 && vis[f[b][0]]) { //逻辑结构错误， 第二个的lca == b不能少 
					lca = min(a, b);
				}
				printf("%d\n", lca);
			} else {//geth
				read(a);
				if (a == 1 || vis[f[a][0]] == 0) {
					printf("%d\n", h[a]);
					continue;//忘了continue 
				}
				int top = getfa(a);
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
