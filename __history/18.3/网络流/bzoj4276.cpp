using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>

namespace OI {
typedef long long lld;
const int 
	INF = 0x3f3f3f3f,
	DST = 0,
	NXT = 1,
	FLOW = 2,
	COST = 3,
	MXN = 26000,
	MXE = 400000
;
int src, dst;
int size;
class NetFlow{
public:
	int cost;
	int edge[MXE][4];
	int head[MXN];
	int eidx;
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
	int fn[MXN], fe[MXN];
	int dis[MXN];
	int inq[MXN];
	queue<int> q;
	int SPFA() {
		memset(dis, 192, size * sizeof(int));
		dis[src] = 0; q.push(src);
		int nd, e, a, b;
		while (!q.empty()) {
			nd = q.front();
			q.pop();
			inq[nd] = 0;
			for (e = head[nd]; e; e = edge[e][NXT]) {
				if (edge[e][FLOW] && (a = dis[nd] + edge[e][COST]) > dis[b = edge[e][DST]]) {
					dis[b] = a;
					fn[b] = nd; fe[b] = e;
					if (!inq[b]) {
						q.push(b);
						inq[b] = 1;
					}
				}
			}
		}
		return dis[dst] > -INF;
	}
	void getFlow() {
		int flow = INF;
		int cost = 0;
		for (int nd = dst; nd != src; nd = fn[nd]) {
			flow = min(flow, edge[fe[nd]][FLOW]);
			cost += edge[fe[nd]][COST];
		}
		this->cost += cost * flow;
		for (int nd = dst; nd != src; nd = fn[nd]) {
			edge[fe[nd]][FLOW] -= flow;
			edge[fe[nd] ^ 1][FLOW] += flow;
		}
	}
	void run() {
		while(SPFA()) {
			getFlow();
		}
	}
	
	NetFlow() {
		eidx = 1;
	}
	
}costflow;
int idx;
int node() {
	return ++idx; 
}
struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;

struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
class Tree {
	public:
	int id[17000];
	void init(int nd, int nl, int nr) {
		id[nd] = node();
		if (nl == nr) {
			costflow.add(id[nd], dst, 1, 0);
			return;
		}
		int mid = nl + nr >> 1;
		init(ls[nd], nl, mid);
		init(rs[nd], mid + 1, nr);
		costflow.add(id[nd], id[ls[nd]], mid - nl + 1, 0);
		costflow.add(id[nd], id[rs[nd]], nr - mid, 0);
	}
	void build(int nd, int nl, int nr, int l, int r, int from) {
		if (l <= nl && nr <= r) {
			costflow.add(from, id[nd], 1, 0);
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) {
			build(ls[nd], nl, mid, l, r, from);
		}
		if (r >= mid + 1) {
			build(rs[nd], mid + 1, nr, l, r, from);
		}
	}
		
	
}tree;
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
	int l[5001], r[5001], c[5001];
	_Main() {
		src = node(); dst = node();
		
		int n;
		int ml = 5000;
		int mr = 0;
		read(n);
		for (int i = 1; i <= n; i++) {
			int id = node();
			read(l[i]); read(r[i]); read(c[i]);
			r[i]--;
			ml = min(ml, l[i]);
			mr = max(mr, r[i]);
		}
		tree.init(1, ml, mr);
		for (int i = 1; i <= n; i++) {
			int id = node();
			costflow.add(src, id, 1, c[i]);
			tree.build(1, ml, mr, l[i], r[i], id);			
		}
		size = idx + 1;
		costflow.run();
		printf("%d", costflow.cost);
	}
}bzoj4276;

}
