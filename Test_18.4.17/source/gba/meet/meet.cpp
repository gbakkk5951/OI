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
const int MXP = 17;
const int DST = 0, NXT = 1, VAL = 2;
int n;
struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;

struct Tree {
int node[270000];
int tag[270000];	
	void add(int nd, int v, int l, int r) {
		node[nd] += v * (r - l + 1);
		tag[nd] += v;
	}
	void push(int nd, int l, int r) {
		if (tag[nd]) {
			int mid = l + r >> 1;
			add(ls[nd], tag[nd], l, mid);
			add(rs[nd], tag[nd], mid + 1, r);
			tag[nd] = 0;
		}
	}
	void add(int nd, int nl, int nr, int l, int r, int v) {
		if (l <= nl && nr <= r) {
			add(nd, v, nl, nr);
			return;
		}
		push(nd, nl, nr);
		int mid = nl + nr >> 1;
		if (l <= mid) {
			add(ls[nd], nl, mid, l, r, v);
		}
		if (r > mid) {
			add(rs[nd], mid + 1, nr, l, r, v);
		}
		node[nd] = node[ls[nd]] + node[rs[nd]];
	}
	void add(int l, int r, int v) {
		add(1, 1, n, l, r, v);
	}
	int getleft(int nd, int nl, int nr, int l, int r) {
		if (nl == nr) return nl;
		int ret = 0;
		int mid = nl + nr >> 1;
		push(nd, nl, nr);
		if (node[ls[nd]] && l <= mid) {
			ret = getleft(ls[nd], nl, mid, l, r);
		}
		if (ret == 0 && node[rs[nd]] && mid < r) {
			ret = getleft(rs[nd], mid + 1, nr, l, r);
		}
		return ret;
	}
	
	int getright(int nd, int nl, int nr, int l, int r) {
		if (nl == nr) return nl;
		int ret = 0;
		int mid = nl + nr >> 1;
		push(nd, nl, nr);
		if (node[rs[nd]] && mid < r) {
			ret = getright(rs[nd], mid + 1, nr, l, r);
		}
		if (ret == 0 && node[ls[nd]] && l <= mid) {
			ret = getright(ls[nd], nl, mid, l, r);
		}
		return ret;
	}
	int getright(int l, int r) {
		return getright(1, 1, n, l, r);
	}
	int getleft(int l, int r) {
		return getleft(1, 1, n, l, r);
	}
}tree;

struct _Main {
	int f[MXN][MXP];
	int h[MXN];
	lld sum[MXN];
	int mx[MXN][MXP];
	int id[MXN], org[MXN], top[MXN];
	int size[MXN], chose[MXN];
	int idx;
	
	int getlca(int a, int b) {
		if (h[a] < h[b]) swap(a, b);
		for (int I = MXP - 1; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				a = f[a][I];
			}
		}
		if (a == b) return a;
		for (int I = MXP - 1; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {//单组数据，可以不判h
				a = f[a][I];
				b = f[b][I];
			}
		}
		return f[a][0];
	}
	inline lld getdis(int a, int b) {
		return sum[a] + sum[b] - (sum[getlca(a, b)] << 1);
	}
	char jump(int a, lld val) {
		lld now = 0;
		for (int I = MXP - 1; I >= 0; I--) {
			if (h[a] > 1 << I) {
				if (sum[a] - sum[f[a][I]] + now <= val) {
					now += sum[a] - sum[f[a][I]];
					a = f[a][I];
				}
			}
		}
		return now == val;
	}
	int getmx(int a, int b) {
		int ret = 0;
		if (h[a] < h[b]) swap(a, b);
		for (int I = MXP - 1; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				ret = max(ret, mx[a][I]);
				a = f[a][I];
			}
		}
		if (a == b) return ret;
		for (int I = MXP - 1; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {//单组数据，可以不判h
				ret = max(ret, mx[a][I]);
				ret = max(ret, mx[b][I]);
				a = f[a][I];
				b = f[b][I];
			}
		}
		return max(ret, max(mx[a][0], mx[b][0])); // 忘了b上面（直接套求LCA的模板还是有问题的）23333  
	}
	void add(int a, int b, int val) {
		while (top[a] != top[b]) {
			if (h[top[a]] < h[top[b]]) swap(a, b);
			tree.add(id[top[a]], id[a], val);
			a = f[top[a]][0];
		}
		tree.add(min(id[a], id[b]), max(id[a], id[b]), val);
	}
	
	int getpos(int a, int b) {
		int lca = getlca(a, b);
		int ret = 0;
		while (top[a] != top[lca]) {
			ret = tree.getright(id[top[a]], id[a]);
			if (ret) return ret;
			a = f[top[a]][0];
		}
		ret = tree.getright(id[lca], id[a]);
		if (ret) return ret;
		static int stk[MXN];
		int idx = 0;
		while (top[b] != top[lca]) {
			stk[++idx] = b;
			b = f[top[b]][0];
		}
		ret = tree.getleft(id[lca], id[b]);
		if (ret) return ret;
		while (idx) {
			b = stk[idx];
			ret = tree.getleft(id[top[b]], id[b]);
			if (ret) return ret;
			--idx;
		}
		return ret;
	}
	char calc(int sa, int ta, lld xa, int sb, int tb, lld xb) {
		int s = 0, t = 0; 
		add(sb, tb, 1);
		s = org[getpos(sa, ta)];
		t = org[getpos(ta, sa)];
		add(sb, tb, -1);
		//无交边
		if (s == t) return 0;
		if (getdis(sb, s) > getdis(sb, t)) { // 异向
			char ret = 1;
			ret = (xa + getdis(sa, s) < xb + getdis(sb, s));
			if (ret == 0) return 0;
			ret = (xa + getdis(sa, t) > xb + getdis(sb, t));
			if (ret == 0) return 0;
			// 不在一个点上交
			
			lld lca = getlca(s, t);
			lld len = getdis(s, t);
			lld delta, ls, lt;
			xa += getdis(sa, s);
			xb += getdis(sb, t);
			if (xa > xb) {
				swap(s, t);
				swap(xa, xb);
			}
			delta = xb - xa;
			ls = sum[s] - sum[lca] - delta, lt = sum[t] - sum[lca];
			if (ls == lt) {
				ret = 0;
			} else 
			if (ls < lt) {
				ret = ((ls + lt) & 1) || !jump(t, ls + lt >> 1);
			} else 
			if (ls > lt) {
				ret = ((ls + lt) & 1) || !jump(s, delta + (ls + lt >> 1));
			}
			return ret;
		}
		// 同向
		xa += getdis(sa, s);
		xb += getdis(sb, s);
		return getmx(s, t) > abs(xa - xb);
	}
	void dfs(int nd, int fa, int fe) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		mx[nd][0] = edge[fe][VAL];
		sum[nd] = sum[fa] + edge[fe][VAL];
		size[nd] = 1;
		for (int I = 1; 1 << I < h[nd]; I++) {
			mx[nd][I] = max(mx[nd][I - 1], mx[f[nd][I - 1]][I - 1]);
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd, e);
				size[nd] += size[t];
				if (size[t] > size[chose[nd]]) {
					chose[nd] = t;
				}
			}
		}
	}
	void getchain(int nd, int fa, int tp) {
		top[nd] = tp;
		org[id[nd] = ++idx] = nd;
		if (chose[nd]) {
			getchain(chose[nd], nd, tp);
			int t;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				if (t != fa && t != chose[nd]) {
					getchain(t, nd, t);
				}
			}
		}
	}
	int head[MXN], edge[MXN << 1][3];
	int eidx;
	void addedge(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	
	_Main() {
		freopen("meet.in", "r", stdin);
		freopen("meet.out", "w", stdout);
		int Qn;
		int a, b, c;
		int sa, ta, xa, sb, tb, xb;
		read(n); read(Qn);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			addedge(a, b, c); addedge(b, a, c);
		}
		dfs(1, 0, 0);
		getchain(1, 0, 1);
		for (int Q = 1; Q <= Qn; Q++) {
			read(sa); read(ta); read(xa); read(sb); read(tb); read(xb);
			if (calc(sa, ta, xa, sb, tb, xb)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		fclose(stdout);
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
}instance;

}


