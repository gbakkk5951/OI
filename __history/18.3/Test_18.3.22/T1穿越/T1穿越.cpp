using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
namespace OI {
typedef long long lld;
const int DST = 0, NXT = 1, FLOW = 2;
const int MXN = 2600, MXM = 60000;
int src, dst;
int size;
int tot;

struct Dinic {
	int totflow;
	int edge[MXM][3];
	int eidx;
	int head[MXN], now[MXN], layer[MXN];
	void dir_add(int src, int dst, int flow) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][FLOW] = flow;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void add(int src, int dst, int flow) {
		dir_add(src, dst, flow);
		dir_add(dst, src, 0);
	}
	queue<int>q;
	void push(int nd, int lay) {
		if (layer[nd] == 0) {
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
	int getflow(int nd, int mx) {
		if (nd == dst) {
			return mx;
		}
		int e, t, rem = mx;
		for (e = now[nd]; e; e = edge[e][NXT]) {
			if (edge[e][FLOW] && layer[t = edge[e][DST]] > layer[nd]) {
				t = getflow(t, min(edge[e][FLOW], rem));
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
			totflow += getflow(src, tot);
		}
	}
	Dinic() {
		eidx = 1;
	}
}dinic;
struct Edge {
	int src, dst, mxt, flow;
	bool operator < (const Edge &b) const {
		return mxt < b.mxt;
	}
}edge_[MXM];
struct _Main {
	int ecnt;
	void add(int src, int dst, int mxt, int flow) {
		ecnt++;
		edge_[ecnt] = (Edge){src, dst, mxt, flow};
	}
	int nidx;
	int node() {
		return nidx++;
	}
	int edge[405][2];
	int head[51];
	int eidx;
	void add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;  
	}
	int dis[51];
	int id[51][51];
	int a[205], b[205];
	int s, t;
	_Main() {
		int n, m;
		read(n); read(m); read(tot); read(s); read(t); //读入顺序WA了竟然能过样例 
		for (int i = 1; i <= m; i++) {
			read(a[i]); read(b[i]);
			add(a[i], b[i]); add(b[i], a[i]);
		}
		getdis();
		for (int i = 0; i < tot; i++) {
			for (int j = 1; j <= n; j++) {
				id[j][i] = node();
				if (i) {
					add(id[j][i - 1], id[j][i], i, (j == t) ? tot : (tot - i));
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			int src = a[i], dst = b[i];
			for (int I = 0; I < 2; I ++) {
				for (int j = 0; j < tot; j++) {
					if (dis[src] + j + 1 < dis[dst] + tot) {
						int t = dis[src] + j + 1 - dis[dst];
						add(id[src][j], id[dst][t], t, 1);
					} else {
						break;
					}
				}
				swap(src, dst);
			}
		}
		sort(edge_ + 1, edge_ + ecnt + 1);
		int ans = 0, qh = 1;
		for (ans = 0; ans < tot - 1; ans++) {
			while (qh <= ecnt && edge_[qh].mxt <= ans) {
				dinic.add(edge_[qh].src, edge_[qh].dst, edge_[qh].flow);
				size = max(size, edge_[qh].dst + 1);
				size = max(size, edge_[qh].src + 1);
				qh++;
			}
			src = id[s][0];
			dst = id[t][ans];
			dinic.run();
			if (dinic.totflow >= tot) {
				break;
			}
		}
		ans += dis[t] - 1; // for dis[s] == 1; He src or dst, Da s or t 
		printf("%d", ans);
	}
	queue<int>q;
	void push(int nd, int lay) {
		if (dis[nd] == 0) {
			dis[nd] = lay;
			q.push(nd);
		}
	}
	void getdis() {
		push(s, 1);
		int nd;
		while (!q.empty()) {
			nd = q.front();
			q.pop();
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				push(edge[e][DST], dis[nd] + 1);
			}
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
}T1;
}
