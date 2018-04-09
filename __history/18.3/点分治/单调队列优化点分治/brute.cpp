using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 5000010;
const int INF = 0x3f3f3f3f;
struct ZKW {
	int base;
	int node[1050000];
	void init(int n) {
		for (base = 1; base - 2 < n; base <<= 1);
		memset(node, 192, (base * 2 + 1) * sizeof(int));
	}
	void change(int nd, int val) {
		for (nd = nd + base; nd; nd >>= 1) {
			node[nd] = node[nd] > val ? node[nd] : val;
		}
	}
	int query(int s, int t) {
		int a = -INF, b = -INF;
		for (s = s + base - 1, t = t + base + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
			a = (~s & 1) && node[s ^ 1] > a ? node[s ^ 1] : a;
			b = ( t & 1) && node[t ^ 1] > b ? node[t ^ 1] : b;
		}
		return a > b ? a : b;
	}
}tree;
int DIS = 0, SUM = 1;
const int DST = 0, NXT = 1, VAL = 2; 
struct NDC {
	NDC() {
		ans = -INF;
	}
	int L, R;
	int ans;
	int head[MXN], edge[MXN << 1][3];
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int tot;
	int val, chose;
	int size[MXN];
	int mark[MXN];
	void getsize(int nd, int fa) {
		size[nd] = 1;
		int t, mx = 0;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getsize(t, nd);
				size[nd] += size[t]; 
				mx = mx < size[t] ? size[t] : mx;
			}
		}
		mx = max(mx, tot - size[nd]);
		if (val > mx) {
			val = mx;
			chose = nd;
		}
	}
	int node[MXN][2];
	void getnode(int nd, int fa, int sum, int dis, int &idx) {
		if (dis >= L) {
			ans = max(ans, sum);
		}
//		printf("%d sum = %d, dis = %d\n", nd, sum, dis);		
		if (dis == R) return;
		node[idx][DIS] = dis;
		node[idx][SUM] = sum;
		idx++;
		int t;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getnode(t, nd, sum + edge[e][VAL], dis + 1, idx);
				size[nd] += size[t];
			}
		}
	}
	void calc(int nd, int _tot) {
		tot = _tot;
		val = INF;
		getsize(nd, -1);
		nd = chose;
//		printf("root = %d\n", nd);
		mark[nd] = 1;
		tree.init(tot);
		int t, idx;
		int L = this->L, R = this->R;
		R = min(R, tot);
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				getnode(t, nd, edge[e][VAL], 1, idx = 0); 
				for (int i = 0; i < idx; i++) {
					if (node[i][DIS] < R) {
						if (node[i][DIS] >= L) {
							ans = max(ans, node[i][SUM] + tree.query(1, R - node[i][DIS]));
						} else {
							ans = max(ans, node[i][SUM] + tree.query(L - node[i][DIS], R - node[i][DIS]));
						}
					}
				}
				for (int i = 0; i < idx; i++) {
					if (node[i][DIS] < R) {
						tree.change(node[i][DIS], node[i][SUM]);
					}
				}
			}
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && size[t] > L) {
				calc(t, size[t]);
			}
		}
	}
}ndc;

struct _Main {
	int n;
	void prepro() {
		read(n); read(ndc.L); read(ndc.R);
		int a, b, c;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			ndc.add(a, b, c);
			ndc.add(b, a, c);
		}
	}
	void solve() {
		ndc.calc(1, n);
		printf("%d", ndc.ans < -5e7 ? -INF : ndc.ans);
	}
	_Main() {
		prepro();
		solve();
	}
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
}brute;
}

