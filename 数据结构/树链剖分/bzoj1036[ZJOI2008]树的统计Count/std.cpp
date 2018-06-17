using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
namespace OI {
const int MXN = 3e4 + 10;
const int DST = 0, NXT = 1;
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
int pos[MXN], id[MXN];
int val[MXN];
int pidx;
struct Tree {
	//vector<int> mx, sum;
	int *mx, *sum;
	int base;
	int l;
	void change(int nd, int val) {
		nd = nd + base - l + 1;
		sum[nd] = mx[nd] = val;
		while ((nd >>= 1) != 1) {
			sum[nd] = sum[ls[nd]] + sum[rs[nd]];
			mx[nd] = max(mx[ls[nd]], mx[rs[nd]]);
		}
	}
	int getsum(int s, int t) {
		s = s + base - l;
		t = t + base - l + 2;
		int ret = 0;
		for (; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1) ret += sum[s ^ 1];
			if ( t & 1) ret += sum[t ^ 1];
		}
		return ret;
	}
	int getmax(int s, int t) {
		s = s + base - l;
		t = t + base - l + 2;
		int ret = -2147483648;
		for (; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1) ret = max(mx[s ^ 1], ret);
			if ( t & 1) ret = max(mx[t ^ 1], ret);
		}
		return ret;
	}
	void build(int s, int t) {
		l = s;
		int len = t - s + 1;
		for (base = 1; base < len + 2; base <<= 1);//神Tmlen - 2
		//sum.resize(base * 2); mx.resize(base * 2);
		sum = (int *)new int[base << 1];
		mx = (int *)new int[base << 1];
		for (int i = 1; i <= len; i++) {
			mx[base + i] = sum[base + i] = val[id[l + i - 1]];
		}
		for (int i = base - 1; i > 1; i--) {
			mx[i] = max(mx[ls[i]], mx[rs[i]]);
			sum[i] = sum[ls[i]] + sum[rs[i]];
		}
	}
}tree[MXN];
struct _Main {
	int size[MXN], tp[MXN], f[MXN], h[MXN], cho[MXN];
	void dfs2(int nd, int fa, int top) {
		id[pos[nd] = ++pidx] = nd;
		tp[nd] = top;
		if (cho[nd]) {
			dfs2(cho[nd], nd, top);
		} else {
			tree[top].build(pos[top], pos[nd]);
			return;
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && t != cho[nd]) {
				dfs2(t, nd, t);
			}
		}
	}
	void dfs1(int nd, int fa) {
		int t;
		h[nd] = h[fa] + 1;
		f[nd] = fa;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs1(t, nd);
				size[nd] += size[t];
				if (size[t] > size[cho[nd]]) {
					cho[nd] = t;//神Tm cho[nd] = t
				}
			}
		}
	}
	void change(int a, int b) {
		tree[tp[a]].change(pos[a], b);
	}
	int getsum(int a, int b) {
		int ret = 0;
		while (tp[a] != tp[b]) {
			if (h[tp[a]] < h[tp[b]]) {
				swap(a, b);
			}
			ret += tree[tp[a]].getsum(pos[tp[a]], pos[a]);
			a = f[tp[a]];
		}
		if (pos[a] > pos[b]) swap(a, b);
		ret += tree[tp[a]].getsum(pos[a], pos[b]);
		return ret;
	}
	int getmax(int a, int b) {
		int ret = -2147483648;
		while (tp[a] != tp[b]) {
			if (h[tp[a]] < h[tp[b]]) {
				swap(a, b);
			}
			ret = max(ret, tree[tp[a]].getmax(pos[tp[a]], pos[a]));
			a = f[tp[a]];
		}
		if (pos[a] > pos[b]) swap(a, b);
		ret = max(ret, tree[tp[a]].getmax(pos[a], pos[b]));
		return ret;
	}
	char op[10];
	_Main() {
		int a, b;
		int n, Qn;
		read(n);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);//神Tm扔循环外面了;
		}
		for (int i = 1; i <= n; i++) {
			read(val[i]);
		}
		dfs1(1, 0);
		dfs2(1, 0, 1);
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			read(a); read(b);
			if (op[1] == 'H') {
				change(a, b);
			} else
			if (op[1] == 'M') {
				printf("%d\n", getmax(a, b));
			} else
			if (op[1] == 'S') {
				printf("%d\n", getsum(a, b));
			}
		}
	}
	int head[MXN], edge[MXN << 1][2];
	int eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
