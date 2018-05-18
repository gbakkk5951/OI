using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
namespace OI {
typedef long long lld;
const int 
	NXT = 1,
	DST = 0,
	MXN = 110000
;

struct Node {
	Node *s[2];
	int sum;
};

struct _Main {
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
	int n;
	Node pool[MXN * 18];
	int pidx;
	Node *root[MXN];
	Node *null;
	Node *new_() {
		Node *nd = &pool[pidx++];
		nd->s[0] = nd->s[1] = null;
		return nd;
	}
	void insert(int id, Node *b, int val) {
		Node *a = root[id] = new_();
		a->sum = b->sum + 1;
		int nl = 1, nr = n, mid, pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos = (val > mid)) {
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
	
	int f[MXN][18];
	int h[MXN];
	int head[MXN], edge[MXN <<1][2];
	lld val[MXN];
	lld sorted[MXN];
	int rk[MXN];
	int eidx;
	void add(int src, int dst) {
		eidx++;
		edge[eidx][NXT] = head[src];
		edge[eidx][DST] = dst;
		head[src] = eidx;
	}
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		int t;
		for (int I = 1; 1 << I <= h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		insert(nd, root[fa], rk[nd]);
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != fa) {
				dfs(t, nd);
			}
		}
	}
	int find(Node *r[], int xishu[], int len, int need) {
		int nl = 1, nr = n, mid;
		int lsum;
		int pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			lsum = 0;
			for (int i = 0; i < len; i++) {
				lsum += r[i]->s[0]->sum * xishu[i];
			}
			if (pos = (lsum < need)) {
				nl = mid + 1;
				need -= lsum;
			} else {
				nr = mid;
			}
			for (int i = 0; i < len; i++) {
				r[i] = r[i]->s[pos];
			}
		}
		return nl;
	}  
	int getlca(int a, int b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		for (int I = 17; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				a = f[a][I];
			}
		}
		if (a == b) {
			return a;
		}
		for (int I = 17; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I];
				b = f[b][I];
			}
		}
		return f[a][0];
	}
	Node *asknode[4];
	int xishu[4];
	_Main() {
		int Qn;
		int a, b, c;
		int lca;
		xishu[0] = 1; xishu[1] = 1; xishu[2] = -1; xishu[3] = -1;
		
		root[0] = null = new_();
		null->s[0] = null->s[1] = null;
		
		read(n); read(Qn);

		for (int i = 1; i <= n; i++) {
			read(val[i]);
		}
		
		memcpy(sorted, val, (n + 1) * sizeof(lld));
		sort(sorted + 1, sorted + n + 1);
		for (int i = 1; i <= n; i++) {
			rk[i] = lower_bound(sorted + 1, sorted + n + 1, val[i]) - sorted;
		}
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); 
			add(a, b); add(b, a);
		}
		dfs(1, 0);
		for (int Q = 1; Q <= Qn; Q++) {
			read(a); read(b); read(c);
			lca = getlca(a, b);
			asknode[0] = root[a]; asknode[1] = root[b];
			asknode[2] = root[lca]; asknode[3] = root[f[lca][0]];
			printf("%lld\n", sorted[find(asknode, xishu, 4, c)]);
		}
	}
}spoj;
}

