using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <queue>
namespace OI {
const int INF = 0x3f3f3f3f;
const int MXN = 500010;
const int DST = 0, NXT = 1, VAL = 2;
const int DIS = 0, SUM = 1;
struct Node {
	int nd, sum, dis;
};
struct DDL {
	int t, h;
	Node q[MXN];
	void pop() {
		h++;
	}
	Node& front() {
		return q[h];
	}
	void push(const Node &a) {
		while (t > h && q[t - 1].sum <= a.sum) {
			t--;
		}
		q[t++] = a;
	}
	void clear() {
		h = t = 0;
	}
	inline int empty() {
		return t <= h;
	}
};

struct NDC {
	int L, R;
	int ans;
	NDC() {
		ans = -INF;
	}
	int head[MXN];
	int edge[MXN << 1][3];
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int size[MXN];
	int chose, val, tot;
	void getsize(int nd, int fa) {
		int t, mx = 0;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getsize(t, nd);
				size[nd] += size[t];
				mx = max(mx, size[nd]);
			}
		}
		mx = max(mx, tot - size[nd]);
		if (mx < val) {
			val = mx;
			chose = nd;
		}
	}
	int mx[MXN];
	int qh, qt;
	int f[MXN];
	Node q[MXN];
	DDL ddl;
	
	void getans(int nd, int fa, int sum, int dis) {
		int qh = 0, qt = 0;
		f[nd] = fa;
		q[qt++] = (Node){nd, sum, dis};
		int t;
		int nd;
		
		while(qh < qt) {
			nd = q[qh].nd;
			sum = q[qh].sum;
			dis = q[qh].dis;
			if (dis >= L) ans = max(ans, sum);
			if (dis == R) continue;
			if (!ddl.empty() && ddl.front.dis + dis > R - dis) {
				ddl.pop();
			}
			if (L > dis) {
				ddl.push((Node){-1, mx[L - dis], L - dis});
			}
			if (!ddl.empty()) {
				ans = max(ans, sum + q.front().)
			}
			qh++;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				if (t != f[nd]) {
					f[t] = nd;
					q.push((Node){t, sum + edge[e][VAL], dis + 1});
				}
			}
		}
	}
	
	void calc(int nd, int _tot) {
		tot = _tot;
		val = 1e9;
		getsize(nd, -1);
		nd = chose;
		mark[nd] = 1;
		int t, mx = 0;
		memset(mx, 192, (tot + 1) * sizeof(int));
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				getans(t, nd);
			
			}
		}
		
		
		if (mx * 2 < L) return;
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
	
}std;
}

