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
const int MXN = 855, MXM = 8510;
struct Flow {
	int src, dst;
	void init() {
		memset(head, 0, sizeof(head));
		eidx = 1;
	}
	int getlay() {
		memset(lay, 0, sizeof(lay));//忘了
		static int q[MXN];
		int qh = 1, qt = 0;
		q[++qt] = src;
		lay[src] = 1;
		while (qh <= qt) {
			int nd = q[qh++];
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				int t = edge[e][DST];
				if (edge[e][FLOW] && !lay[t]) {
					lay[t] = lay[nd] + 1;
					q[++qt] = t;
				}
			}
		}
		return lay[dst];
	}
	int getflow(int nd, int mx) {
		if (nd == dst) {
			return mx;
		}
		int rem = mx;
		for (int e = now[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (edge[e][FLOW] && lay[t] > lay[nd]) {
				//getflow(nd, xx)海星
				t = getflow(t, min(rem, edge[e][FLOW]));
				if (t) {
					edge[e][FLOW] -= t;
					edge[e ^ 1][FLOW] += t;
					rem -= t;
					if (rem == 0) {
						now[nd] = e;
						return mx;
					}
				}
			}
		}
		now[nd] = 0;
		return mx - rem;
	}
	int run() {
		int ret = 0;
		while (getlay()) {
			memcpy(now, head, sizeof(head));
			ret += getflow(src, INF);
		}
		return ret;
	}
	int head[MXN], now[MXN], edge[MXM << 1][3], eidx;//二倍边数
	int lay[MXN];
	void dir_add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][FLOW] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
}flow;
struct _Main {
	int a[MXM], b[MXM], c[MXM];
	int n, m;
	int f[MXN];
	char vis[MXN];
	void getnear(int nd) {
		vis[nd] = 1;
		for (int e = flow.head[nd]; e; e = flow.edge[e][NXT]) {
			int t = flow.edge[e][DST];
			if (!vis[t] && flow.edge[e][FLOW]) {
				getnear(t);
			}
		}
	}
	set<int> tree;
	void buildtree() {
		fill(f + 2, f + n + 1, 1);
		for (int i = 2; i <= n; i++) {
			flow.init();
			for (int j = 1; j <= m; j++) {
				//神Tm都写成i了
				flow.dir_add(a[j], b[j], c[j]);
				flow.dir_add(b[j], a[j], c[j]);
			}
			flow.src = i;
			flow.dst = f[i];
			tree.insert(flow.run());
			getnear(i);
			for (int j = i + 1; j <= n; j++) {
				if (vis[j] && f[j] == f[i]) {
					f[j] = i;
				}
			}
			memset(vis + 1, 0, n * sizeof(char));
		}
	}
	_Main() {
		read(n); read(m);
		for (int i = 1; i <= m; i++) {//神Tm <= n
			read(a[i]); read(b[i]); read(c[i]);
		}
		buildtree();
		printf("%d", (int)tree.size());
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
