using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int INF = 0x3f3f3f3f;
const int MXN = 1650, MXM = 40000;
const int DST = 0, NXT = 1, FLOW = 2, COST = 3;

int s, t;
int size;
class Flow {
public:
	int ans;
	int dis[MXN], fe[MXN], fn[MXN];
	int inq[MXN];
	int edge[MXM][4];
	int head[MXN];
	queue<int> q;
	int eidx;
	Flow() {
		eidx = 1;
	}
	inline void dir_add(int src, int dst, int flow, int cost) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][FLOW] = flow;
		edge[eidx][COST] = cost;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	inline void add(int src, int dst, int flow, int cost) {
		dir_add(src, dst, flow, cost);
		dir_add(dst, src, 0, -cost);
	}
	
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
	int getpath() {
		memset(dis, 63, size * sizeof(int));
		dis[s] = 0;
		push(s);
		while (!q.empty()) {
			int d, t, nd;
			nd = pop();
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (edge[e][FLOW] && (d = dis[nd] + edge[e][COST]) < dis[t = edge[e][DST]]) {
					dis[t] = d;
					fe[t] = e;
					fn[t] = nd;
					push(t);
				}
			}
		}
		return dis[t] < INF; //t与全局变量重名 
	}
	void flow() {
		int cost = 0, flow = INF;
		for (int nd = t; nd != s; nd = fn[nd]) {
			cost += edge[fe[nd]][COST];
			flow = min(flow, edge[fe[nd]][FLOW]);
		}
		ans += cost * flow;
		for (int nd = t; nd != s; nd = fn[nd]) {
			edge[fe[nd]][FLOW] -= flow;
			edge[fe[nd] ^ 1][FLOW] += flow;
		}
	}
	void run() {
		while (getpath()) {
			flow();
		}
	}
}flow;
struct _Main {
	int in[805], out[805], sev;
	int cost[805];
	int idx;
	int node() {
		return idx++;
	}
	
	_Main() {
		int n, m; int a, b, c, d;
		s = node(); t = node(); sev = node();
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(cost[i]);
			in[i] = node(); out[i] = node();
			flow.add(in[i], t, 1, 0);
			flow.add(s, out[i], 1, 0);
			flow.add(sev, in[i], 1, cost[i]);
			flow.add(out[i], sev, 1, 0);
		}
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c);
			if (a > b) swap(a, b); //标号小的引力小不是左边的引力小 
			if (c < cost[b]) flow.add(out[a], in[b], 1, c);
		}
		size = idx;
		flow.run();
		printf("%d", flow.ans);
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
}bzoj1927;
}
