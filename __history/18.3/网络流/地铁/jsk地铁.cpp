using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <queue>
namespace OI {
const int INF = 0x3f3f3f3f;
const int MXN = 110, MXM = 6500;
struct Edge{
	int nxt, flow, cost, dst;
};
int size;
int s, t;
class Flow {
public:
	int totflow, totcost;
	Edge ed[MXM];
	int inq[MXN], head[MXN];
	int dis[MXN], fn[MXN], fe[MXN];
	queue<int>q;
	int eidx;
	inline void push(int nd) {
		if (!inq[nd]) {
			inq[nd] = 1;
			q.push(nd);
		}
	}
	inline int pop() {
		int nd = q.front();
		q.pop();
		inq[nd] = 0;
		return nd;
	}
	inline void dir_add(int src, int dst, int flow, int cost) {
		eidx++;
		ed[eidx].dst = dst;
		ed[eidx].flow = flow;
		ed[eidx].cost = cost;
		ed[eidx].nxt = head[src];
		head[src] = eidx;
	}
	inline void add(int src, int dst, int flow, int cost) {
		if (flow == 0) return;
		dir_add(src, dst, flow, cost);
		dir_add(dst, src, 0, -cost);
	}
	int getpath() {
		memset(dis, 63, size * sizeof(int));
		dis[s] = 0;
		push(s);
		while (!q.empty()) {
			int nd, t, a;
			nd = pop();
			for (int e = head[nd]; e; e = ed[e].nxt) {
				if (ed[e].flow && (a = dis[nd] + ed[e].cost) < dis[t = ed[e].dst]) {
					dis[t] = a;
					fn[t] = nd;
					fe[t] = e;
					push(t);
				}
			}
		}
		return dis[t] < INF;
	}
	void flow() {
		int cost = 0, flow = INF;
		for (int nd = t; nd != s; nd = fn[nd]) {
			cost += ed[fe[nd]].cost;
			flow = min(flow, ed[fe[nd]].flow);
		}
		totflow += flow;
		totcost += flow * cost;
		for (int nd = t; nd != s; nd = fn[nd]) {
			ed[fe[nd]].flow -= flow;
			ed[fe[nd] ^ 1].flow += flow;
		}
	}
	void run() {
		while (getpath()) {
			flow();
		}
		for (int e = head[s]; e; e = ed[e].nxt) {
			if (ed[e].flow) {
				totcost = INF;
				break;
			}
		}
	}
	void clear() {
		eidx = 1;
		memset(head, 0, size * sizeof(int));
		totflow = totcost = 0; //记得清零 
	}
}flow;

struct _Main {
	int delta[55]; //入 - 出
	int link[2555][2];
	int os, ot, in[55], out[55];
	void clear() {
		memset(delta, 0, sizeof(delta));
	}
	int idx;
	inline int node() {
		return idx++;
	}
	void addlim(int a, int b, int mn, int mx) {
		flow.add(a, b, mx - mn, 0);
		flow.add(a, t, mn, 0);
		flow.add(s, b, mn, 0);
	}
	_Main() {
//		freopen("data0.in", "r", stdin);
		int Tn;
		s = node(); t = node();
		os = node(); ot = node();
		for (int i = 1; i <= 50; i++) {
			in[i] = node();
			out[i] = node();
		}
		size = idx;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			clear();
			int n, m, low, a, b;
			read(n); read(m); read(low);
			for (int i = 1; i <= m; i++) {
				read(a); read(b);
				link[i][0] = a; link[i][1] = b;
				delta[a]--;
				delta[b]++;
			}
			int l = 0, r = 0;
			for (int i = 1; i <= n; i++) {
				r = max(r, abs(delta[i]));
			}
			
			while (l < r) {
				int mid = l + r >> 1;
//				printf("l = %d, r = %d\n", l, r);
				flow.clear();
				flow.add(ot, os, INF, 0);
				for (int i = 1; i <= n; i++) {
					flow.add(in[i], out[i], INF, 0);
					if (delta[i] > mid) {
//						printf("A in %d -> ot [%d, %d]\n", i, delta[i] - mid, delta[i] + mid);
						addlim(in[i], ot, delta[i] - mid, delta[i] + mid);
					} else if (delta[i] < - mid) {
//						printf("B os -> out %d [%d, %d]\n", i, -mid - delta[i], mid - delta[i]);
						addlim(os, out[i], -mid - delta[i], mid - delta[i]);
					} else {
//						flow.add(os, out[i], delta[i] + mid, 0);
//						flow.add(in[i], ot, mid - delta[i], 0);						
						flow.add(os, out[i], mid - delta[i], 0);
						flow.add(in[i], ot, delta[i] + mid, 0);
//						printf("in %d -> ot [%d, %d]\n", i, 0, delta[i] + mid);
//						printf("os -> out %d [%d, %d]\n", i, 0, mid - delta[i]);
					}
				}
				for (int i = 1; i <= m; i++) {
//					printf("out %d -> in %d\n", link[i][0], link[i][1]);
					flow.add(out[link[i][0]], in[link[i][1]], 1, 1);
				}
				flow.run();
//				printf("mid = %d cost = %d flow = %d\n", mid, flow.totcost, flow.totflow);
				
				if (flow.totcost > m - low) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			printf("Case %d: %d\n", T, l);
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
}jsk;
}

