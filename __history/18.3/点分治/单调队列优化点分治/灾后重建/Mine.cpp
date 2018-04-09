using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
//#define debug
namespace OI {
typedef double lf;
const lf INF = 1e14;
const int MXN = 100010;
const lf EPS = 1e-5;
lf l, r;
int L, R, n;

const int DST = 0, NXT = 1, VAL = 2;
int head[MXN], edge[MXN << 1][3];
int eidx;
lf ev[MXN << 1];
void add(int a, int b, int c) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][VAL] = c;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
int mark[MXN];
int tot;
int val, chose;
int size[MXN];
void getsize(int nd, int fa) {
	size[nd] = 1;
	int t, mx = 0;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			getsize(t, nd);
			size[nd] += size[t];
			mx = max(mx, size[t]);
		}
	}
	mx = max(mx, tot - size[nd]);
	if (mx < val) {
		chose = nd;
		val = mx;
	}
}
int h[MXN];
lf sum[MXN];
char flag;
int geth(int nd, int fa, lf now) {
	sum[nd] = now;
	#ifdef debug
	printf("sum %d = %lf h = %d\n", nd, now, h[nd]);
	#endif
	int ret = h[nd], t;
	if (h[nd] >= L && now > -EPS) {
		flag = 1;
		return 0;
	}
	if (h[nd] != R) for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			h[t] = h[nd] + 1;
			ret = max(ret, geth(t, nd, now + ev[e]));
			if (flag) return 0;
		}
	}
	return ret;
}
int root[MXN];
int mxh[MXN];
void getroot(int nd, int _tot, int &idx) {
	tot = _tot;
	val = 1e9;
	getsize(nd, 0);
	nd = chose;
	getsize(nd, 0);
	mark[nd] = 1;
	h[nd] = 0;
	mxh[nd] = geth(nd, 0, -INF);
	if (mxh[nd] * 2 < L) {
		return;
	}
	root[++idx] = nd;
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (!mark[t] && size[t] > L) {
			getroot(t, size[t], idx);
		}
	}
}

vector <int> kid[MXN];
lf v[MXN];
void update(int nd, int fa) {
	v[h[nd]] = max(v[h[nd]], sum[nd]);
	int t;
	if (h[nd] != R) for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			update(t, nd);
		}
	}
}

struct DDDL {
	int h, t;
	int q[MXN];
	void init() {
		h = t = 0;
	}
	void push(int nd) {
		while (h < t && v[q[t - 1]] < v[nd]) {
			t--;
		}
		q[t++] = nd;
	}
	void pop() {
		h++;
	}
	int front() {
		return q[h];
	}
	char empty() {
		return h == t;
	}
}dddl;
vector <int> q;
void push(int nd) {
	q.push_back(nd);
}
void bfs(int nd) {
	q.clear();
	push(nd);
	int l = L - 1, t, hd = 0;
	while (hd != q.size()) {
		nd = q[hd];
		#ifdef debug
		printf("nd = %d sum = %lf\n", nd, sum[nd]);
		#endif
		hd++;
		if (dddl.front() + h[nd] > R) {
			dddl.pop();
		}
		if (l - 1 >= 1 && h[nd] + l - 1 >= L) {
			dddl.push(--l);
		}
		int tp = dddl.front();
		if (!dddl.empty() && sum[nd] + v[tp] > -EPS) {
			#ifdef debug
			printf("tp = %d\n", tp);
			#endif
			flag = 1;
			return;
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (h[t] == h[nd] + 1 && !mark[t] && h[nd] + 1 < R) {
				push(t);
			}
		}
	}
}
void calc(int nd) {
	mark[nd] = 1;
	int t, tmp;
	int mxh = OI::mxh[nd];
	for (int i = 1; i <= mxh; i++) {
		kid[i].clear();
	}
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (!mark[t]) {
			h[t] = 1;
			tmp = geth(t, nd, ev[e]);
			if (flag) return;
			kid[tmp].push_back(t);
		}
	}

	
	for (int i = 1; i <= mxh; i++) {
		for (int j = 0; j < kid[i].size(); j++) {
			dddl.init();
			for (int k = i; k >= L - 1; k--) {
				dddl.push(k);
			}
			bfs(kid[i][j]);
			if (flag) return;
			#ifdef debug
			printf("upd %d\n", kid[i][j]);
			#endif
			update(kid[i][j], nd);
		}
	}
	#ifdef debug
	printf("fill %d\n", mxh);
	#endif
	fill(v, v + mxh + 1, -INF);
	#ifdef debug
	printf("root = %d\n", nd);
	for (int i = 1; i <= mxh; i++) {
		printf("v %d = %lf\n", i, v[i]);
	}
	#endif
}
struct _Main {
	int val[MXN];
	lf mx;
	int ridx;
	void prepro() {
		read(n); read(L); read(R);
		int a, b, c;
		for (int i = 2; i <= n; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
			val[i - 1] = c; 
		}
		sort(val + 1, val + n);
		for (int i = n - 1; i >= n - L; i--) {
			mx += val[i];
		}
		mx /= L;
		getroot(1, n, ridx = 0);
	}
	void solve() {
		lf l = 0, r = mx, mid;
		if (L == 1) l = mx;
		while (r - l > EPS) {
			fill(v, v + n + 1, -INF);
			memset(mark, 0, (n + 1) * sizeof(int));
			mid = (l + r) / 2.0;
			#ifdef debug
			printf("[%lf, %lf]\n", l, r);
			#endif
			for (int e = 1; e <= eidx; e++) {
				ev[e] = edge[e][VAL] - mid;
			}
			flag = 0;
			for (int i = 1; i <= ridx; i++) {
				#ifdef debug
				printf("root = %d\n", root[i]);
				#endif
				calc(root[i]);
				if (flag) {
					break;
				}
			}
			if (flag) {
				l = mid;
			} else {
				r = mid;
			}
		}
		printf("%.3lf", round(l * 1000.0) / 1000.0);
	}
	_Main() {
//		freopen("data0.in", "r", stdin);
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
}Mine;
}
