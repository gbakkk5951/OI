using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
namespace OI {
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
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 155, MXM = 3e3 + 10;
struct Flow {
	int src, dst;
	Flow() {
		init();
	}
	void init() {
		eidx = 1;
		memset(head, 0, sizeof(head));
	}
	int getflow(int nd, int mxflow) {
		if (nd == dst) {
			return mxflow;
		}
		int rem = mxflow;
		for (int e = now[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (edge[e][FLOW] && lay[t] > lay[nd]) {
				t = getflow(t, min(edge[e][FLOW], rem));
				if (t) {
					rem -= t;
					edge[e][FLOW] -= t;
					edge[e ^ 1][FLOW] += t;
					if (rem == 0) {
						now[nd] = e;
						return mxflow;
					}
				}
			}
		}
		now[nd] = 0;
		return mxflow - rem;
	}
	int lay[MXN];
	int q[MXN];
	int getlayer() {
		memset(lay, 0, sizeof(lay));
		int h = 1, ta = 0;
		q[++ta] = src;
		lay[src] = 1;
		while (h <= ta) {
			int nd = q[h++];
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				int t = edge[e][DST];
				if (edge[e][FLOW] && !lay[t]) {
					lay[t] = lay[nd] + 1;
					q[++ta] = t;
				}
			}
		}
		return lay[dst];
	}
	int eidx, head[MXN], now[MXN], edge[MXM << 1][3];
	int run() {
		int ret = 0;
		while (getlayer()) {
			memcpy(now, head, sizeof(now));
			ret += getflow(src, INF);
		}
		return ret;
	}
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
}flow;
struct _Main {
	int a[MXM], b[MXM], c[MXM];
	int f[MXN], fv[MXN];
	int edge[MXN << 1][3], head[MXN], eidx;
	int n, m;
	void init() {
		flow.init();
		for (int i = 1; i <= m; i++) {
			flow.dir_add(a[i], b[i], c[i]);
			flow.dir_add(b[i], a[i], c[i]);
		}
	}
	char vis[MXN];
	void getnear(int nd) {
		vis[nd] = 1;
		for (int e = flow.head[nd]; e; e = flow.edge[e][NXT]) {
			int t = flow.edge[e][DST];
			if (flow.edge[e][FLOW] && !vis[t]) {
				getnear(t);
			}
		}
	}
	void buildtree() {
		fill(f + 2, f + n + 1, 1);
		for (int i = 2; i <= n; i++) {
			init();
			flow.src = i;
			flow.dst = f[i];
			fv[i] = flow.run();
			getnear(i);
			for (int j = i + 1; j <= n; j++) {
				if (vis[j] && f[j] == f[i]) {
					f[j] = i;
				}
			}
			memset(vis, 0, sizeof(vis));
		}
		for (int i = 2; i <= n; i++) {
			add(i, f[i], fv[i]);
			add(f[i], i, fv[i]);
		}
	}
	int dfs(int nd, int fa, int c, int nc) {
		int ret = 0;
		ret += c <= nc;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				ret += dfs(t, nd, min(c, edge[e][VAL]), nc);
			}
		}
		return ret;
	}
	_Main() {
		int Tn, Qn, x;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m);
			for (int i = 1; i <= m; i++) {
				read(a[i]); read(b[i]); read(c[i]);
			}
			buildtree();
			read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				read(x);
				int ans = 0;
				for (int i = 1; i <= n; i++) {
					ans += dfs(i, 0, INF, x);//i不是1 23333
				}
				ans >>= 1;
				printf("%d\n", ans);
			}
			printf("\n");
			memset(head + 1, 0, n * sizeof(int));
			eidx = 0;
		}
	}
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
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
