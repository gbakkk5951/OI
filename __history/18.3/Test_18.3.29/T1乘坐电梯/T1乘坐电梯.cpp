using namespace std;
int main() {}
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <functional>
#include <vector>
namespace OI {
const int MXN = 100010;
typedef long long lld;

struct Edge {
	int dst;
	lld v;
	bool operator > (const Edge &b) const {
		return v > b.v;
	}
};
const int DST = 0, NXT = 1, VAL = 2;


lld LINF;
lld dis[MXN];
lld h, a, b, c;
lld edge[MXN << 1][3];
int head[MXN];
int eidx;
void add(int a, int b, int c) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][VAL] = c;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
priority_queue<Edge, vector<Edge>, greater<Edge> > heap;
void Dijkstra() {
	memset(dis, 63, (a + 1) * sizeof(lld));
	LINF = dis[a];
	dis[0] = 0;
	heap.push(Edge{0, 0});
	Edge tmp;
	int nd, t;
	lld s;
	while (!heap.empty()) {
		tmp = heap.top();
		heap.pop();
		if (tmp.v == dis[nd = tmp.dst]) {
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				if (dis[t = edge[e][DST]] > (s = dis[nd] + edge[e][VAL])) {
					dis[t] = s;
					heap.push((Edge){t, s});
				}
			}
		}
	}
}


struct _Main {
	_Main() {
		lld r, k, ans = 0;
		scanf("%lld%lld%lld%lld", &h, &a, &b, &c);
		if (b < a) swap(a, b);
		if (c < a) swap(a, c);
		if (a == 1) {
			printf("%lld", h);
			return;
		}
		for (int i = 0; i < a; i++) {
			add(i, (i + b) % a, (i + b) / a);
			add(i, (i + c) % a, (i + c) / a);
		}
		Dijkstra();
		r = (h - 1) % a;
		k = (h - 1) / a;
		for (int i = 0; i < a; i++) {
			ans += dis[i] < k ? k - dis[i] : 0;
		}
		for (int i = 0; i <= r; i++) {
			ans += dis[i] <= k;
		}
		printf("%lld", ans);
	}
	
	
}T1;

}
