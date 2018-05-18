using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <queue>

namespace OI {
const int 
	NXT = 1,
	DST = 0,
	MAXN = 110,
	MAXE = 6010,
	FLOW = 2,
	INF = 0x3f3f3f3f
;
int src, dst;
int size;
class Dinic {
public:
	int tot_flow;
	int head[MAXN];
	int now[MAXN];
	int edge[MAXE][3];
	int layer[MAXN];
	int eidx;
	queue <int> q;
	Dinic() {
		eidx = 1;
	}
	int getFlow(int nd, int mx_flow) {
		if (nd == dst) {
			return mx_flow;
		}
		int i, t, use = 0;
		for (i = now[nd]; i; i = edge[i][NXT]) {
			if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
				t = getFlow(t, min(mx_flow - use, edge[i][FLOW]));
				if (t) {
					use += t;
					edge[i][FLOW] -= t;
					edge[i ^ 1][FLOW] += t;
					if (use == mx_flow) {
						break;
					}
				}
			}
		}
		now[nd] = i;
		return use;
	}
	void push(int nd, int l) {
		if (!layer[nd]) {
			layer[nd] = l;
			q.push(nd);
		} 
	}
	int getLayer() {
		memset(layer, 0, size * sizeof(int));
		push(src, 1);
		int i, nd, t;
		while (!q.empty()) {
			nd = q.front();
			t = layer[nd] + 1;
			q.pop();
			for (i = head[nd]; i; i = edge[i][NXT]) {
				if (edge[i][FLOW]) {
					push(edge[i][DST], t);
				}
			}
		}
		return layer[dst];
	}
	void run() {
		while (getLayer()) {
			memcpy(now, head, size * sizeof(int));
			tot_flow += getFlow(src, INF);
		}
	}
	void clear() {
		memset(head, 0, size * sizeof(int));
		tot_flow = 0;
		eidx = 1;
	}
	void dir_add(int src, int dst, int flow) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][FLOW] = flow;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void add(int src, int dst, int flow) {
//		printf("add %d %d\n", src, dst);
		dir_add(src, dst, flow);
		dir_add(dst, src, 0);
	}
}netflow;

struct _Main {
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
	int node_idx;
	int node() {
		return ++node_idx;
	}
	int id[55][105];
	int head[MAXN];
	int edge[MAXE][2];
	int eidx;
	int mxf[55];
	int cnt[55];
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void link(int b1, int f1, int b2, int f2) {
		int a, b;
		if ((a = id[b1][f1]) == 0) {
			a = id[b1][f1] = node();
			mxf[b1] = max(mxf[b1], f1);
			cnt[b1]++;
		}
		if ((b = id[b2][f2]) == 0) {
			b = id[b2][f2] = node();
			mxf[b2] = max(mxf[b2], f2);
			cnt[b2]++;
		}
//		printf("lk %d %d\n", a, b);
		add(a, b);
		add(b, a);
	}
	int vis[105];
	void dfs(int idx, int b) {
		if (idx > mxf[b]) {
			netflow.clear();
			int use = 0;
			for (int i = 1; i <= mxf[b]; i++) {
				int a = id[b][i];
				if (a == 0) continue;
				if (vis[a]) {
					for (int e = head[a]; e; e = edge[e][NXT]) {
						int *v = &vis[edge[e][DST]];
						if (*v == 0) {
							*v = 1;
							use++;
						}
					}
				} else {
					vis[a] = 2;
					use++;
				}
			}
			for (int i = 0; i < n; i++) {
				if (i == b) {
					continue;
				}
				if ((i - (b < i)) & 1) {
					for (int j = 1; j <= mxf[i]; j++) {
						int a = id[i][j];
						int t;
						if (a == 0 || vis[a]) continue;
						netflow.add(src, a, 1);
						for (int e = head[a]; e; e = edge[e][NXT]) {
							if (!vis[t = edge[e][DST]]) {
								netflow.add(a, t, 1);
							}
						}
					}
				} else {
					for (int j = 1; j <= mxf[i]; j++) {
						int a = id[i][j];
						if (a == 0 || vis[a]) continue;
						netflow.add(a, dst, 1);
					}
				}
			}	
			netflow.run();
			ans = max(ans, sum - use - netflow.tot_flow);
//			printf("%d - %d - %d\n", sum, use, netflow.tot_flow);
//			printf("\n");
			for (int i = 1; i <= mxf[b]; i++) {
				int a = id[b][i];
				if (vis[a] == 1) {
					for (int e = head[a]; e; e = edge[e][NXT]) {
						vis[edge[e][DST]] = 0;
					}
				} else {
					vis[a] = 0;
				}
			}
			return;
		}
		for (; id[b][idx] == 0; idx++);
		for (int j = 0; j < 2; j++) {
			vis[id[b][idx]] = j;
			dfs(idx + 1, b);
		}
	}
	int n;
	int ans;
	int sum;
	_Main() {
		
		freopen("guard.in", "r", stdin);
		freopen("guard.out", "w", stdout);
		int i, j, k;
		int a, b, c;
		int chose = -1;
		int val = 10000;
		read(n);
		while (~scanf("%d%d%d", &b, &c, &a)) {
//			printf("a = %d, b = %d, c = %d\n", a, b, c);
			if (a == 0) {
				break;
			}
			a--;
			link(a, b, (a + 1) % n, c);
		}
		for (i = 0; i < n; i++) {
			sum += mxf[i];
		}
		src = node();
		dst = node();
		size = node_idx + 1;
		for (i = 0; i < n; i++) {
			if (cnt[i] < val || (cnt[i] == val && mxf[i] < mxf[chose]) ) {
				chose = i;
				val = cnt[i];
			}
		}
		
		if (n & 1) {
			dfs(1, chose);
//			printf("chose %d\n", chose);
		} else {
			for (i = 0; i < n; i++) {
				for (j = 1; j <= mxf[i]; j++) {
					if ((a = id[i][j]) == 0) {
						continue;
					}	
					if (i & 1) {
						netflow.add(src, a, 1);
						for (k = head[a]; k; k = edge[k][NXT]) {
							netflow.add(a, edge[k][DST], 1);
						}
					} else {
						netflow.add(a, dst, 1);
					}
				}
			}
			netflow.run();
			ans = sum - netflow.tot_flow;
		}
		printf("%d", ans);
		fclose(stdout);
	}


}guard;

}

