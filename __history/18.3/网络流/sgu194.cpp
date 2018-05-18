using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
namespace OI {
typedef long long lld;
const int MXN = 210, MXM = 80500;
const int DST = 0, NXT = 1, FLOW = 2, ID = 3, INF = 0x3f3f3f3f;
int eflow[40050];
int s, t;
int size;
class Dinic {
public:
	int head[MXN], now[MXN];
	int edge[MXM][4];
	int eidx;
	void dir_add(int src, int dst, int flow, int id) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][FLOW] = flow;
		edge[eidx][ID] = id;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void add(int src, int dst, int flow, int id) {
		dir_add(src, dst, flow, id);
		dir_add(dst, src, 0, 0);
	}
	int layer[MXN];
	queue<int> q;
	void push(int nd, int lay) {
		if (layer[nd] == 0) {
			q.push(nd);
			layer[nd] = lay;
		}
	}
	int getlayer() {
		memset(layer, 0, size * sizeof(int));
		push(s, 1);
		while (!q.empty()) {
			int nd = q.front();
			q.pop();
			for (int i = head[nd]; i; i = edge[i][NXT]) {
				if (edge[i][FLOW]) {
					push(edge[i][DST], layer[nd] + 1);
				}
			}
		}
		return layer[t];
	}
	int flow(int nd, int mx) {
		if (nd == t) {
			return mx;
		}
		int t, rem = mx, e;
		for (e = now[nd]; e; e = edge[e][NXT]) {
			if (edge[e][FLOW] && layer[t = edge[e][DST]] > layer[nd]) {
				t = flow(t, min(rem, edge[e][FLOW]));
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
	Dinic() {
		eidx = 1;
	}
	bool run() {
		while (getlayer()) {
			memcpy(now, head, size * sizeof(int));
			flow(s, INF);
		}
		for (int e = head[s]; e; e = edge[e][NXT]) {
			if (edge[e][FLOW]) {
				return 0;
			}
		}
		/*for (int e = head[t]; e; e = edge[e][NXT]) {
			if (edge[e ^ 1][FLOW]) {
				return 0;
			}
		}*/
		for (int e = 2; e <= eidx; e++) {
			eflow[edge[e][ID]] += edge[e ^ 1][FLOW];
		}
		return 1;
	}
}dinic;
struct _Main {
	int idx;
	inline int node() {
		return idx++;
	}
	int id[MXN];
	lld in[MXN], out[MXN];
	_Main() {
		int n, m, mx, mn, a, b;
		s = node(); t = node();
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			id[i] = node();
		}
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(mn); read(mx);
			eflow[i] = mn;
//			printf("eflow %d = %d\n", i, mn);
			out[a] += mn;
			in[b] += mn;
			if (mx - mn) {
				dinic.add(id[a], id[b], mx - mn, i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (in[i] > out[i]) {
				dinic.add(s, id[i], in[i] - out[i], 0);
			} else if (out[i] > in[i]) {
				dinic.add(id[i], t, out[i] - in[i], 0);
			}
		}
		size = idx;
		if (dinic.run()) {
			printf("YES\n");
			for (int i = 1; i <= m; i++) {
				printf("%d\n", eflow[i]);
			}
		} else {
			printf("NO");
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
}sgu194;



}
