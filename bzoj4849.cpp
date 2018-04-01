using namespace std;
int main() {}
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
namespace OI {
typedef long long lld;
const int INF = 0x3f3f3f3f;
const int MXN = 100010;
const int DST = 0, NXT = 1, COST = 2, FLOW = 3;
struct _Main {
	lld ans;
	int n, m;
	int head[MXN], deg[MXN];
	int edge[MXN << 1][4]; 
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][COST] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
		deg[a]++;
	}
	int root, rval;
	int size[MXN];
	void findroot(int nd, int fa) {
		int mx = 0, t;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				findroot(t, nd);
				size[nd] += size[t];
				mx = max(mx, size[t]);
			}
		}
		mx = max(mx, n - size[nd]);
		if (deg[nd] == 2 && mx < rval) {
			root = nd;
			rval = mx;
		} 
	}
	int h[MXN], f[MXN], fe[MXN], s[MXN][2], se[MXN][2], cst[MXN], cho[MXN];
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd] = fa;
		int sidx = 0, t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t == fa) {
				fe[nd] = e;
			} else {
				dfs(t, nd);
				s[nd][sidx] = t;
				se[nd][sidx] = e;
				sidx++;
			}
		}
		update(nd);
	}
	int getv(int e) {
		return edge[e ^ 1][FLOW] ? -edge[e][COST] : edge[e][COST];
	}
	void update(int nd) {
		cho[nd] = cont[nd] ? -1 : -2;
		cst[nd] = cont[nd] ? 0 : INF;
		int t;
		for (int i = 0; i < 2 && s[nd][i]; i++) {
			if (cho[s[nd][i]] != -2 && (t = getv(se[nd][i]) + cst[s[nd][i]]) < cst[nd]) {
				cst[nd] = t;
				cho[nd] = i;
			}
		}
	}
	void flow(int e) {
		if (edge[e ^ 1][FLOW]) {
			edge[e ^ 1][FLOW]--;
			ans -= edge[e ^ 1][COST];
		} else {
			edge[e][FLOW]++;
			ans += edge[e][COST];
		}
	}
	void push(int a) {
		int v, lca = -1;
		int nd, dis = 0;
		if (cont[a]) {
			lca = a;
		} else for (nd = a; nd != 0; nd = f[nd]) {
			if (cho[nd] != -2) {
				if (lca == -1 || dis + cst[nd] < v) {
					v = dis + cst[nd];
					lca = nd;
				}
			}
			dis += getv(fe[nd]);
		}
		nd = a;
		while (h[nd] > h[lca]) {
			flow(fe[nd]);
			nd = f[nd];
		}
		while (cho[nd] != -1) {
			flow(se[nd][cho[nd]]);
			nd = s[nd][cho[nd]];
		}
		cont[nd]--;
		while (nd != 0) {
			update(nd);
			nd = f[nd];
		}
		while (a != 0) {
			update(a);
			a = f[a];
		}
	}
	void prepro() {
		int tp, a, b, c;
		eidx = 1;
		/*read(tp); */read(n); read(m);
		for (int i = 2; i <= n; i++) {
//			read(a); read(b); read(c);
//			add(a, b, c); add(b, a, c);
			add(i, i >> 1, 1);
			add(i >> 1, i, 1);
		}
		for (int i = 1; i <= n; i++) {
			read(cont[i]);
		}
		for (int i = 1; i <= m; i++) {
			read(pos[i]);
		}
		if (n <= 2) {
			root = 1;
		} else {
			rval = 1e5;
			findroot(1, 0);
		}
		dfs(root, 0);
	}
	int cont[MXN];
	int pos[MXN];
	void solve() {
		for (int i = 1; i <= m; i++) {
			push(pos[i]);
			printf("%lld ", ans);
		}
	}
	_Main() {
		prepro();
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
}dloj1048;
}
