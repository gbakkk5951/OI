using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
typedef long long lld;
typedef unsigned long long llu;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 31 | INF;
namespace flow {
const int MXN = 41000, MXM = 550000;
const int DST = 0, NXT = 1, FLOW = 2;
int eidx = 1;
int src, dst;
int size;
int head[MXN], now[MXN];
unsigned int edge[MXM][3];
lld totflow;
void dir_add(int a, int b, int c) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][FLOW] = c;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
void add(int a, int b, int c) {
	dir_add(a, b, c);
	dir_add(b, a, 0);
}
queue<int> q;
int layer[MXN];
void push(int nd, int lay) {
	if (!layer[nd]) {
		layer[nd] = lay;
		q.push(nd);
	}
}
int getlayer() {
	memset(layer, 0, size * sizeof(int));
	push(src, 1);
	int nd;
	while (!q.empty()) {
		nd = q.front();
		q.pop();
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (edge[e][FLOW]) {
				push(edge[e][DST], layer[nd] + 1);
			}
		}
	}
	return layer[dst];
}
lld getflow(int nd, lld mx) {
	if (nd == dst) {
		return mx;
	}
	int e;
	lld rem = mx, t;
	for (e = now[nd]; e; e = edge[e][NXT]) {
		if (edge[e][FLOW] && layer[t = edge[e][DST]] > layer[nd]) {
			t = getflow(t, min((lld)edge[e][FLOW], rem));
			if (t) {
				edge[e][FLOW] -= t;
				edge[e ^ 1][FLOW] += t;
				rem -= t;
				if (rem == 0) {
					break;
				}
			}
		}
	}
	now[nd] = e;
	return mx - rem;
}
void run() {
	while (getlayer()) {
		memcpy(now, head, size * sizeof(int));
		totflow += getflow(src, LINF);
	}
}
}


int n, m;
int xx, yy;
namespace matrix {
const int MXN = 205, MXM = 1005;
const lld MOD = 1e9 + 1;
	int a[MXN][MXN], b[MXN][MXN];
	lld aa[MXM][MXM];
	lld x[MXM][MXM], y[MXM][MXM], c[MXM][MXM];
	lld v0[MXM], v1[MXM], l[MXM], r[MXM];
	void mul(lld v[MXM], lld ma[MXM][MXM], lld sv[MXM]) {
		lld t = 0;
		for (int i = 1; i <= m; i++) {
			t = 0;
			for (int j = 1; j <= m; j++) {
				t += v[j] * ma[i][j];
			}
			sv[i] = t;
		}
	}
	void mul() {//x y 顺序反了 
		mul(v0, y, v1);
		mul(v1, x, l);
		mul(v0, c, r);
	}
	int check() {
		return memcmp(l + 1, r + 1, m * sizeof(lld));//lld ! 
	}
	void recalc() {
		for (int i = xx; i < xx + n; i++) {
			for (int j = yy; j < yy + n; j++) {
				c[i][j] = x[i][j] * y[i][j];
			}
		}
	}
}

struct _Main {
template <typename Type>
	void read(Type arr[], int n) {
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
	}
	void prepro() {
		int Tp;
		read(Tp); read(n); read(m);
		using namespace matrix;
		for (int i = 1; i <= n; i++) {
			read(a[i], n);
		}
		for (int i = 1; i <= n; i++) {
			read(b[i], n);
		}
		for (int i = 1; i <= m; i++) {
			read(x[i], m);
		}
		for (int i = 1; i <= m; i++) {
			read(y[i], m);
		}
		for (int i = 1; i <= m; i++) {
			read(c[i], m);
		}
		read(xx); read(yy);
		//数据类型编号不是测试点编号 
		if (Tp >= 4) for (int I = 1; I <= 3; I++) {
			if (I == 1) {
				for (int i = 1; i <= m; i++) {
					v0[i] = i;
				}
			} else {
				for (int i = 1; i <= m; i++) {
					v0[i] = rand() % 1000 + 1;
				}
			}
			mul();
			if (check()) {
				recalc();
				break;
			}
		}
		for (int i = xx; i < xx + n; i++) {
			for (int j = yy; j < yy + n; j++) {
				c[i][j] %= MOD;
			}
		}
	}
	int legal(int x, int y) {
		return x >= xx && y >= yy;
	}
	int idx;
	int node() {
		return idx++;
	}
	int id[1005][1005];
	void solve() {
		
		using namespace flow;
		int dx[] = {-1, 0}, dy[] = {0, -1};
		int x, y;
		lld sum = 0, t;
		src = node(); dst = node();
		for (int i = xx, x = 1; i < xx + n; i++, x++) {
			for (int j = yy, y = 1; j < yy + n; j++, y++) {
				using namespace matrix;
				id[i][j] = node();
				if ((i + j) & 1) {
					swap(a[x][y], b[x][y]);
				}
				add(src, id[i][j], a[x][y]);
				add(id[i][j], dst, b[x][y]);
				sum += a[x][y] + b[x][y];
			}
		}
		for (int i = xx; i < xx + n; i++) {
			for (int j = yy; j < yy + n; j++) {
				for (int k = 0; k < 2; k++) {
					if (legal(x = i + dx[k], y = j + dy[k])) {
						using namespace matrix;
						t = c[i][j] + c[x][y];
						dir_add(id[i][j], id[x][y], t);
						dir_add(id[x][y], id[i][j], t);
						sum += t;
					}
				}
			}
		}
		size = idx;
		run();
		printf("%lld", sum - totflow);
	}
	_Main() {
		srand(3165771 ^ (unsigned long long) new char);
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
}dloj1050;
}
