using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <vector>
namespace OI {
const int MXN = 100010;
const int NXT = 1, DST= 0;
typedef long long lld;
lld gcd (lld a, lld b) {
	return b ? gcd(b, a % b) :  a;
}
struct Node {
	Node *s[2];
	int sum;
}pool[4000000], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
int n;
class ChairTree {
public:
	Node *root[MXN << 1];
	ChairTree() {
		if (null == 0) {
			null = new_();
			null->s[0] = null->s[1] = null;
		}
		root[0] = null;
	}
	void insert(int ia, int ib, int val, int add) {
		if (root[ia] == 0) {
			root[ia] = new_();
			root[ia]->sum = root[ib]->sum;
		}
		Node *a = root[ia], *b = root[ib];
		a->sum += add;
		int nl = 1, nr = 2 * n, mid, pos;
//		printf("[%d](%d, %d) = %d\n", ia, nl, nr, a->sum);
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (a->s[pos ^ 1] == null) {
				a->s[pos ^ 1] = b->s[pos ^ 1];
			}
			b = b->s[pos];
			a = a->s[pos] = new_();
			a->sum = b->sum + add;
//			printf("[%d](%d, %d) = %d\n", ia, nl, nr, a->sum);
		}
	}
	int query(Node *a, Node *b, int nl, int nr, int l, int r) {
		int ret = 0;
		if (l <= nl && nr <= r) {
//			printf("(%d, %d) return %d - %d\n", nl, nr, b->sum, a->sum);
			return b->sum - a->sum;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) {
			ret += query(a->s[0], b->s[0], nl, mid, l, r);
		}
		if (mid < r) {
			ret += query(a->s[1], b->s[1], mid + 1, nr, l, r);
		}
		return ret;
	}
}tree;

struct _Main {
	int f[MXN][17], h[MXN], head[MXN], edge[MXN << 1][2];
	int in[MXN], out[MXN]; //in,out为欧拉序
	vector<int> ins[MXN << 1];
	int jump(int a, int h) {
		for (int I = 0; h; I++, h >>= 1) {
			if (h & 1) {
				a = f[a][I];
			}
		}
		return a;
	}
	int getlca(int a, int b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		a = jump(a, h[a] - h[b]);
		if (a == b) return a;
		for (int I = 16; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I]; b = f[b][I];
			}
		}
		return f[a][0];
	}
	void dfs(int nd, int fa, int &idx) {
		in[nd] = ++idx;
//		printf("in %d = %d\n", nd, idx);
		f[nd][0] = fa;
		h[nd] = h[fa] + 1;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) if (edge[e][DST] != fa){
			dfs(edge[e][DST], nd, idx);
		}
		out[nd] = ++idx;
//		printf("out %d = %d\n", nd, idx);
	}
	int eidx;
	void add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	int ques[100010][2];
	_Main() {
		lld sum = 0, fm, g;
		int m;
		int a, b, c, d, lca, s;
	
		read(n); read(m);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		dfs(1, 0, a = 0);
		for (int i = 1; i <= m; i++) {
			read(a); read(b);
			ins[in[a]].push_back(in[b]);
			ins[in[b]].push_back(in[a]);
			ques[i][0] = a; ques[i][1] = b;
		}
		for (int i = 1; i <= 2 * n; i++) {
			if (ins[i].size() == 0) {
				tree.root[i] = tree.root[i - 1];
			}
			for (int j = 0; j < ins[i].size(); j++) {
//				printf("ins (%d) [%d]\n", i, ins[i][j]);
				tree.insert(i, i - (j == 0), ins[i][j], 1);
			}
		}
		for (int i = 1; i <= m; i++) {
			a = ques[i][0]; b = ques[i][1];
			if (h[a] < h[b]) {
				swap(a, b);
			}
			Node *L = tree.root[in[a] - 1], *R = tree.root[out[a]];
			lca = getlca(a, b);
//			printf("[%d, %d]\n", in[a], out[a]);
//			printf("lca %d %d = %d\n", a, b, lca);
			if (b != lca) {
//				printf("A(%d, %d)\n", in[b], out[b]);
				sum += tree.query(L, R, 1, 2 * n, in[b], out[b]);
			} else {
				//上方
//				printf("B(%d, %d)\n", 1, in[b]);
				sum += tree.query(L, R, 1, 2 * n, 1, in[b]);
//				printf("C(%d, %d)\n", out[b], 2 * n);
				sum += tree.query(L, R, 1, 2 * n, out[b], 2 * n);
				//兄弟
				if (a != b) {
					s = jump(a, h[a] - h[b] - 1);
					if (in[b] + 1 <= in[s] - 1) {
//						printf("D(%d, %d)\n", in[b] + 1, in[s] - 1);
						sum += tree.query(L, R, 1, 2 * n, in[b] + 1, in[s] - 1);
					} 
//					printf("E(%d, %d)\n", out[s], out[b]);
					sum += tree.query(L, R, 1, 2 * n, out[s], out[b]);
				}
			}
//			printf("i = %d sum = %d\n", i, sum);
		}
		sum -= m;
		fm = (lld) m * (m - 1) >> 1;
		g = gcd(sum, fm);
		sum /= g; fm /= g;
		printf("%lld/%lld\n", sum, fm);
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
	
}bzoj3772;
}

