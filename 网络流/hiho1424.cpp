using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
namespace OI {
const int INF = 0x3f3f3f3f;
const int DST = 0, NXT = 1, FLOW = 2, COST = 3;
const int MXM = 3200, MXN = 110;
int size;
int s, t;
class Flow {
public:
	int eidx;
	int totflow, totcost;
	int head[MXN], edge[MXM][4];
	int inq[MXN], dis[MXN], fe[MXN], fn[MXN];
	queue<int>q;
	inline int pop() {
		int nd = q.front();
		q.pop();
		inq[nd] = 0;
		return nd;
	}
	inline void push(int nd) {
		if (!inq[nd]) {
			q.push(nd);
			inq[nd] = 1;
		}
	}
	int getpath() {
		memset(dis, 63, size * sizeof(int));
		dis[s] = 0;
		push(s);
		while (!q.empty()) {
			int nd, t, a;
			nd = pop();
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (edge[e][FLOW] && (a = dis[nd] + edge[e][COST]) < dis[t = edge[e][DST]]) {
					dis[t] = a;
					push(t);
					fn[t] = nd;
					fe[t] = e;
				}
			}
		}
		return dis[t] < INF;
	}
	void flow() {
		int cost = 0, flow = INF;
		for (int nd = t; nd != s; nd = fn[nd]) {
			cost += edge[fe[nd]][COST];
			flow = min(flow, edge[fe[nd]][FLOW]);
//			printf("%d from %d cost = %d\n", nd, fn[nd], edge[fn[nd]][COST]);
		}
//		printf("flow = %d, cost = %d\n", flow, flow * cost);
		totcost += flow * cost;
		totflow += flow;
		for (int nd = t; nd != s; nd = fn[nd]) {
			edge[fe[nd]][FLOW] -= flow;
			edge[fe[nd] ^ 1][FLOW] += flow;
		}
	}
	void dir_add(int src, int dst, int flow, int cost) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][FLOW] = flow;
		edge[eidx][COST] = cost;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void add(int src, int dst, int flow, int cost) {
		dir_add(src, dst, flow, cost);
		dir_add(dst, src, 0, -cost);
	}
	Flow() {
		eidx = 1;
	}
	void run() {
		while (getpath()) {
			flow();
		}
	}
	
	void clear() {
		eidx = 1;
		memset(head, 0, size * sizeof(int));
		totflow = totcost = 0;
	}
}flow;

struct _Main {
	int map[MXN][MXN];
	int hn[MXN], ln[MXN], hl[MXN], hh[MXN], ll[MXN], lh[MXN];
	int hid[MXN], lid[MXN];
	int bn;
	int idx;
	int n;
	inline int node() {
		return idx++;
	}
	void count() {
		bn = 0;
		for (int i = 1; i <= n; i++) {
			hn[i] = 0;
			for (int j = 1; j <= n; j++) {
				hn[i] += map[i][j];
				bn += map[i][j];
			} 
		}
		for (int i = 1; i <= n; i++) {
			ln[i] = 0;
			for (int j = 1; j <= n; j++) {
				ln[i] += map[j][i];
			}
		}
	}
	void clear() {
		idx = 0;
		flow.clear();
	}
	_Main() {
		int a, b, c, d, os, ot;
		while (~scanf("%d", &n)) {
			clear();
			s = node(); t = node();
			os = node(); ot = node();
			flow.add(ot, os, INF, 0);
			for (int i = 1; i <= n; i++) {
				hid[i] = node(); lid[i] = node();
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					read(map[i][j]);
				}
			}
			count();
			flow.add(s, os, 2 * bn, 0);
			for (int i = 1; i <= n; i++) {
				flow.add(os, hid[i], hn[i], 0);
				flow.add(os, lid[i], ln[i], 0);
			}
			
			for (int i = 1; i <= n; i++) {
				read(hl[i]); read(hh[i]);
			}
			for (int i = 1; i <= n; i++) {
				read(ll[i]); read(lh[i]);
			}
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				if (hh[i] > hl[i]) flow.add(hid[i], ot, hh[i] - hl[i], 0);
				if (lh[i] > ll[i]) flow.add(lid[i], ot, lh[i] - ll[i], 0);
				if (hl[i]) flow.add(hid[i], t, hl[i], 0), sum += hl[i];
				if (ll[i]) flow.add(lid[i], t, ll[i], 0), sum += ll[i];
			}
			flow.add(ot, t, 2 * bn - sum, 0);
			for (int i = 1; i <= n * n >> 1; i++) {
				read(a); read(b); read(c); read(d);
				
				if (map[a][b] == map[c][d]) continue;
				
				if (a == c) { // 同行
					if (map[a][b]) {
						flow.add(lid[b], lid[d], 1, 1);
					} else {
						flow.add(lid[d], lid[b], 1, 1);
					}
				} else { // 同列
					if (map[a][b]) {
						flow.add(hid[a], hid[c], 1, 1);
					} else {
						flow.add(hid[c], hid[a], 1, 1);
					}
				}
			}
			size = idx;
			flow.run();
			int ans;
			if (flow.totflow < 2 * bn) {
				ans = -1;
			} else {
				ans = flow.totcost;
			}
			printf("%d\n", ans);
		}
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
}hiho1424;
}

