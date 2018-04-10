using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <set>
namespace OI {
typedef set<int>::iterator ite;
const int MXN = 100010;
const int DST = 0, NXT = 1, VAL = 2;
struct _Main {
	int edge[MXN << 1][3];
	int mark[MXN];
	int head[MXN];
	int idx, eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	set<int> tree;
	int ans;
	void init() {
		memset(mark, 0, (n + 1) * sizeof(int));
		memset(head, 0, (n + 1) * sizeof(int));
		eidx = idx = 0;
		tree.clear();
		ans = 0;
	}
	int f[MXN][17], h[MXN], dfn[MXN], id[MXN], sum[MXN];
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		id[dfn[nd] = ++idx] = nd;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				sum[t] = sum[nd] + edge[e][VAL];
				dfs(t, nd);
			}
		}
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
			if ((1 << I) < h[a] && f[a][I] != f[b][I]) {//多组数据直接这个... 
				a = f[a][I]; b = f[b][I];
			}
		}
		return f[a][0];
	}
	int getdis(int a, int b) {
		return sum[a] + sum[b] - (sum[getlca(a, b)] << 1);
	}
	ite getnxt(ite nd) {
		if (++nd == tree.end()) {
			nd = tree.begin();
		}
		return nd;
	}
	ite getpre(ite nd) {
		if (nd == tree.begin()) {
			nd = tree.end();
		}
		return --nd;
	}
	void push(int _nd) {
		if (mark[_nd]) {
			return;
		}
		mark[_nd] = 1;
		tree.insert(dfn[_nd]);
		ite nd = tree.find(dfn[_nd]), nxt = getnxt(nd), pre = getpre(nd);
		ans -= getdis(id[*nxt], id[*pre]);
		ans += getdis(id[*nxt], id[*nd]);
		ans += getdis(id[*pre], id[*nd]);
	}
	void pop(int _nd) {
		if (!mark[_nd]) {
			return;
		}
		mark[_nd] = 0;	
		ite nd = tree.find(dfn[_nd]), nxt = getnxt(nd), pre = getpre(nd);
		ans += getdis(id[*nxt], id[*pre]);
		ans -= getdis(id[*nxt], id[*nd]);
		ans -= getdis(id[*pre], id[*nd]);
		tree.erase(nd);
	}
	int n;
	_Main() {
		int Tn, Qn, a, b, c, x, op;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			init();
			printf("Case #%d:\n", T);
			read(n); read(Qn);
			for (int i = 1; i <= n - 1; i++) {
				read(a); read(b); read(c);
				add(a, b, c); add(b, a, c);
			}
			dfs(1, 0);
			for (int Q = 1; Q <= Qn; Q++) {
				read(op); read(x);
				if (op == 1) push(x);
				else pop(x);
				printf("%d\n", ans >> 1);
			}
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
}hdu5296;
}
