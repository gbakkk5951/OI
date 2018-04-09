#pragma GCC optimize(2)
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 20025, MXP = 21;
const lld MOD = 1e9 + 7;
const int BASE = 20005;
int n, k;
lld pow[MXN << 1][MXP];
lld com[MXP][MXP];
lld inline getpow(int base, int p) {
	return pow[base + BASE][p];
}
const int DST = 0, NXT = 1;
int head[MXN], edge[MXN << 1][2];
int eidx;
inline void add(int a, int b) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
int h[MXN], l[MXN], r[MXN];
void dfs(int nd, int fa, int &idx) {
	
	l[nd] = ++idx;
	h[l[nd]] = h[l[fa]] + 1;
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa) {
			dfs(t, nd, idx);
		}
	}
	r[nd] = idx;
}
struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;

struct Node {
	lld as[MXP];
	lld sum, tag;
};
struct SegTree {
	Node node[66000];
	void update(int nd) {
		for (int i = 0; i <= k; i++) {
			node[nd].as[i] = (node[ls[nd]].as[i] + node[rs[nd]].as[i]) % MOD;
		}
		node[nd].sum = node[nd].as[k];
	}
	void add(int nd, int v) {
		node[nd].tag += v;
		lld t;
		for (int i = k; i >= 0; i--) {
			t = 0;
			for (int j = 0; j <= i; j++) {
				t = (t + com[i][j] * node[nd].as[j] % MOD * getpow(v, i - j)) % MOD;
			}
			node[nd].as[i] = t;
		}
		node[nd].sum = node[nd].as[k];
	}
	void push(int nd) {
		int t;
		if (t = node[nd].tag) {
			add(ls[nd], t);
			add(rs[nd], t);
			node[nd].tag = 0;
		}
	}
	void build(int nd, int nl, int nr) {
		memset(node + nd, 0, sizeof(Node));
		if (nl == nr) {
			for (int i = 0; i <= k; i++) {
				node[nd].as[i] = getpow(h[nl], i);
			}
			node[nd].sum = node[nd].as[k];
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		update(nd);
	}
	void change(int nd, int nl, int nr, int l, int r, int v) {
		if (l <= nl && nr <= r) {
			add(nd, v);
			return;
		}
		push(nd);
		int mid = nl + nr >> 1;
		if (l <= mid) {
			change(ls[nd], nl, mid, l, r, v);
		}
		if (r > mid) {
			change(rs[nd], mid + 1, nr, l, r, v);
		}
		update(nd);
	}
	lld query() {
		return node[1].sum;
	}
}tree;
lld ans[MXN];
void getans(int nd, int fa) {
	ans[nd] = tree.query();
	int t;
	int mark = 0;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa) {
			if (!mark) {
				tree.change(1, 1, n, 1, n, 1);
				mark = 1;
			}
			tree.change(1, 1, n, l[t], r[t], -2);			
			getans(t, nd);
			tree.change(1, 1, n, l[t], r[t], +2);
		}
	}
	if (mark) tree.change(1, 1, n, 1, n, -1);
}

struct _Main {
	void pprepro() {
		for (int i = 1; i <= 40015; i++) {
			pow[i][0] = 1;
			for (int j = 1; j < MXP; j++) {
				pow[i][j] = pow[i][j - 1] * (i - BASE) % MOD;
			}
		}
		for (int i = 0; i < MXP; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
			}
		}
	}
	void prepro() {
		memset(head, 0, (n + 1) * sizeof(int));
		eidx = 0;
		int a, b;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		int idx;
		dfs(1, 0, idx = 0);
		tree.build(1, 1, n);
	}
	void solve() {
		while (~scanf("%d%d", &n, &k)) {
			prepro();
			getans(1, 0);
			for (int i = 1; i <= n; i++) {
				printf("%lld\n", ans[i] < 0 ? ans[i] + MOD : ans[i]);
			}
			printf("\n");
		}
	}
	_Main() {
		pprepro();
		solve();
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
}T3;
}
