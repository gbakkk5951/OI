using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
namespace OI {
typedef double lf;
typedef long long lld;
const int INF = 2147483647;
const int MXN = 110, MXM = 2010;
const int NXT = 1, DST = 0;
const lf EPS = 1e-5;
int s, t, size;
queue<int> q;
class Dinic {
public:
	int eidx;
	lf totflow;
	int head[MXN], edge[MXM][2];
	lf FLOW[MXM];
	int layer[MXN], now[MXN];
	Dinic() {
		init();
	}
	
	void push(int nd, int lay) {
		if (!layer[nd]) {
			layer[nd] = lay;
			q.push(nd);
		}
	}
	int getlayer() {
		memset(layer, 0, size * sizeof(int));
		push(s, 1);
		while (!q.empty()) {
			int nd;
			nd = q.front();
			q.pop();
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (FLOW[e] > EPS) {
					push(edge[e][DST], layer[nd] + 1);
				}
			}
		}
		return layer[t];
	}
	lf flow(int nd, lf mx) {
		
		if (nd == t) {
			return mx;
		}
		int e;
		lf rem = mx;
		for (e = now[nd]; e; e = edge[e][NXT]) {
			int tt;
			if (FLOW[e] > EPS && layer[tt = edge[e][DST]] > layer[nd]) {
				lf t = flow(tt, min(rem, FLOW[e]));
				if (t > EPS) {
					FLOW[e] -= t;
					FLOW[e ^ 1] += t;
					rem -= t;
					if (rem < EPS) {
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
			totflow += flow(s, INF);
		}
	}
	
	void dir_add(int src, int dst, lf flow) { 
		eidx++;
		edge[eidx][DST] = dst;
		FLOW[eidx] = flow;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void add(int src, int dst, lf flow) {
		dir_add(src, dst, flow);
		dir_add(dst, src, 0);
	}
	void init() {
		totflow = 0; 
		eidx = 1;
		memset(head, 0, size * sizeof(int));
	}
}flow;

struct _Main {
	int id[110];
	int edge[1010][3];
	lf mxflow;
	_Main() {
		int n, m;
		lf mn = 2147483647, mx = 0;
		int a, b, c;
		lf p;
		read(n); read(m); read(p);
		for (int i = 1; i <= n; i++) {
			id[i] = i - 1;
		}
		s = id[1]; t = id[n];
		size = n;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < 3; j++) {
				read(edge[i][j]);
			}
			a = edge[i][0]; b = edge[i][1]; c = edge[i][2];
			mx = max(mx, (lf)c);
			mn = min(mn, (lf)c);
			flow.add(id[a], id[b], c);
		}
		flow.run();
		mxflow = flow.totflow;
		printf("%.0lf\n", mxflow);
		mx = min(mx, mxflow);
		lf l = mxflow ? mn : 0, r = mxflow ? mx : 0;
		while (r - l > EPS) {
			lf mid = (l + r) / 2.0;
			flow.init();
			for (int i = 1; i <= m; i++) {
				a = edge[i][0]; b = edge[i][1]; c = edge[i][2];
				flow.add(id[a], id[b], min((lf)c, mid));
			}
			flow.run();
			if (fabs(flow.totflow - mxflow) < EPS) {
				r = mid;
			} else {
				l = mid;
			}
		}
		printf("%.3lf", round(p * 1000.0 * l) / 1000.0);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}T2;
}
