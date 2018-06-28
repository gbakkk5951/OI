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
const int MXN = 1010, MXM = 2010;
struct Flow {
	Flow() {
		init();
	}
	int head[MXN], now[MXN], lay[MXN], edge[MXM + MXN << 1][3], eidx;
	int src, dst;
	void init() {
		eidx = 1;
		memset(head, 0, sizeof(head));
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
	int getlay() {
		memset(lay, 0, sizeof(lay));
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
				t = getflow(t, min(edge[e][VAL], rem));
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
			memcpy(now, head, sizeof(now));
			ret += getflow(src, INF);
		}
		return ret;
	}
}flow;
struct _Main {
	int a[MXM], b[MXM], v1[MXM], v2[MXM];//MXM写成MXN了
	int deg[MXN];//入度 - 出度
	int n, m;
	void build(int mx) {
		flow.init();
		flow.src = 0, flow.dst = n + 1;
		for (int i = 1; i <= n; i++) {
			if (deg[i] > 0) {
				flow.add(0, i, deg[i] >> 1);
			} else
			if (deg[i] < 0) {
				flow.add(i, n + 1, -deg[i] >> 1);
			}
		}
		for (int i = 1; i <= m; i++) {
			if (v2[i] <= mx) {
				flow.add(b[i], a[i], 1);
			}
		}
	}
	_Main() {
		int low = -INF, high = -INF, need = 0;
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(a[i]); read(b[i]); read(v1[i]); read(v2[i]);
			if (v1[i] > v2[i]) {
				swap(a[i], b[i]);
				swap(v1[i], v2[i]);
			}
			--deg[a[i]]; ++deg[b[i]];
			low = max(low, v1[i]);
			high = max(high, v2[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (deg[i] & 1) {
				printf("NIE");
				return;
			}
			need += deg[i] > 0 ? deg[i] : 0;
		}
		int l = low, r = high + 1;
		while (l < r) {
			int mid = l + r >> 1;
			build(mid);
			if (flow.run() << 1 == need) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if (l == high + 1) {
			printf("NIE");
			return;
		}
		printf("%d", l);
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
