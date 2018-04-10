using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
namespace OI {
typedef long long lld;
typedef set<int>::iterator ite;
const int MXN = 100005;
const int DST = 0, NXT = 1, VAL = 2;
set<int> tree;
struct _Main {
	int id[MXN], dfn[MXN];
	int f[MXN][17], h[MXN];
	lld sum[MXN];
	int head[MXN], edge[MXN << 1][3];
	int idx;
	void dfs(int nd, int fa) {
		id[dfn[nd] = ++idx] = nd;
		f[nd][0] = fa;
		h[nd] = h[fa] + 1;
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
		if (h[a] < h[b]) {
			swap(a, b);
		}
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
	lld getdis(int a, int b) {
		return sum[a] + sum[b] - 2LL * sum[getlca(a, b)];
	}
	lld ans;
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
		tree.insert(dfn[_nd]);
		if (tree.size() == 0) {
			return;
		}
		ite nd = tree.find(dfn[_nd]);
		ite pre = getpre(nd);
		ite nxt = getnxt(nd);
		ans -= getdis(id[*pre], id[*nxt]);
		ans += getdis(id[*pre], id[*nd]);
		ans += getdis(id[*nd], id[*nxt]);
	}
	void pop(int _nd) {
		ite nd = tree.find(dfn[_nd]);
		if (tree.size() <= 2) {
			tree.erase(nd);
			ans = 0;
			return;
		}
		ite pre = getpre(nd);
		ite nxt = getnxt(nd);
		ans -= getdis(id[*pre], id[*nd]);
		ans -= getdis(id[*nxt], id[*nd]);
		ans += getdis(id[*pre], id[*nxt]);
		tree.erase(nd);
	}
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int mark[MXN];
	_Main() {
		int n, Qn, x, a, b, c;
		read(n); read(Qn);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		} 
		dfs(1, 0);
		for (int Q = 1; Q <= Qn; Q++) {
			read(x);
			if (mark[x]) pop(x); 
			else push(x);
			mark[x] ^= 1;//Ã»È¡Ïûmark 
			printf("%lld\n", ans);
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
}bzoj3991;
}
