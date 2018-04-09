using namespace std;
int main() {}
#pragma optimize(2)
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
//单Case内没有垃圾回收
const int MXN = 80005;
const int DST = 0, NXT = 1;
struct Node {
	Node *s[2];
	int sum;
}pool[MXN * 17 * 17], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
Node *root[MXN];
int mx;
class ChairTree {
public:
	void build(int ia, int ib, int val) {
		Node *a = root[ia] = new_(), *b = root[ib];
		a->sum = b->sum + 1;
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
			a->sum = b->sum + 1;
		}
	}
}tree;
const int xishu[] = {1, 1, -1, -1};
struct _Main {
	int val[MXN];
	int sorted[MXN];
	int head[MXN];
	int edge[MXN * 2][2];
	int eidx;
	int n;
	int f[MXN][17];
	int h[MXN];
	int fa[MXN], size[MXN];
	void inline add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	int getfa(int nd) {
		return fa[nd] ? fa[nd] = getfa(fa[nd]) : nd;
	}
	void setfa(int a, int b) {
		fa[a] = b;
	}
	void build(int nd, int fa) {
		setfa(nd, getfa(fa));
		size[getfa(nd)] += 1;
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		tree.build(nd, fa, val[nd]);
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (edge[e][DST] != fa) {
				build(edge[e][DST], nd);
			}
		}
	}
	void init() {
		null = new_();
		null->s[0] = null->s[1] = null;
		root[0] = null;
	}
	void inline link(int a, int b) {
		add(a, b); add(b, a);
		if (size[getfa(a)] < size[getfa(b)]) {
			swap(a, b);
		}
		build(b, a);
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
			if (1 << I < h[a] && f[a][I] != f[b][I]) {//只有小于深度才保证被初始化
				a = f[a][I]; b = f[b][I];
			}
		}
		return f[a][0];
	}
	Node *node[4];
	int query(int a, int b, int rk) {
		int lca = getlca(a, b);
		node[0] = root[a]; 
		node[1] = root[b];
		node[2] = root[lca];
		node[3] = root[f[lca][0]];
		int sum, nl = 1, nr = mx, mid, pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			sum = 0;
			for (int i = 0; i < 4; i++) {
				sum += node[i]->s[0]->sum * xishu[i];
			}
			if (pos = sum < rk) {
				rk -= sum;
				nl = mid + 1;
			} else {
				nr = mid;
			}
			for (int i = 0; i < 4; i++) {
				node[i] = node[i]->s[pos];
			}
		}
		return sorted[nl];
	}
	char op[5];
	_Main() {
		int Tn, a, b, c;
		read(Tn);
		Tn = 1;
		int m, Qn;
		for (int T = 1; T <= Tn; T++) {
			init();
			read(n); read(m); read(Qn);
//			n = 8e4, m = 8e4 - 1, Qn = 0;
			for (int i = 1; i <= n; i++) {
				root[i] = null;
			}
			for (int i = 1; i <= n; i++) {
				read(val[i]);
			}
			memcpy(sorted + 1, val + 1, n * sizeof(int));
			sort(sorted + 1, sorted + n + 1);
			mx = unique(sorted + 1, sorted + n + 1) - sorted - 1;
			mx = n;
			for (int i = 1; i <= n; i++) {
				
				val[i] = lower_bound(sorted + 1, sorted + mx + 1, val[i]) - sorted;
				
			}
			for (int i = 1; i <= m; i++) {
				read(a); read(b);
//				a = i; b = i + 1;
				add(a, b); add(b, a);
			}
			for (int i = 1; i <= n; i++) {
				
				if (h[i] == 0) {
					build(i, 0);
				}
			}
			for (int Q = 1; Q <= Qn; Q++) {
				scanf("%s", op);
				read(a); read(b);
				if (op[0] == 'Q') {
					read(c);
					printf("%d\n", lstans = query(a, b, c));
				} else {
					link(a, b);
				}
			}
		}
	}
int lstans;
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a ^= lstans;
	}
}bzoj3123;
}
//第一个输入是测试点编号不是数据组数 
//对于东西比较多的题要在纸上列出功能列表 
//重载build函数导致弄混 
//mid没赋值 
//lstans没归零 
