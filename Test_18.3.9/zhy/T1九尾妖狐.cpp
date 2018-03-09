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
const lld LINF = 9223372036854775807LL;
const lld LARGE = 461168601842700LL;
const int DST = 0, NXT = 1, FLOW = 2;
const int MXE = 550200, MXN = 100100;
int src, dst, size;
class Dinic {
public:
	lld ans;
	lld edge[MXE][3];
	int head[MXN];
	int eidx;
	Dinic() {
		eidx = 1;
	}
	void dir_add(int src, int dst, lld flow) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][FLOW] = flow;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void add(int src, int dst, lld flow) {
		dir_add(src, dst, flow);
		dir_add(dst, src, 0);
	}
	lld getflow(int nd, lld mx) {
		if (nd == dst) {
			return mx;
		}
		lld t, rem = mx;
		int e;
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
	queue<int>q;
	int layer[MXN];
	int now[MXN];
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
	void run() {
		while (getlayer()) {
			memcpy(now, head, size * sizeof(int));
			ans += getflow(src, LINF);
		}
	}
}dinic;

struct _Main {
	int n, m;
	int idx;
	int node() {
		return idx++;
	}
	int idp[10005], idd[10005];
	int ta[10005], tb[10005];
	void calc() {
		lld sum = 0, a, b;
		for (int i = 1; i <= n; i++) {
			read(a); read(b);
//			a = ta[i]; b = tb[i];
			sum += max(a, b);
		}
		printf("%lld", sum);
	}
	_Main() {
		lld a, b, c, d, e;
		lld ans = 0;
		src = node();
		dst = node();
//		n = 1000; m = 0;
		read(n); read(m);
//		for (int i = 1; i <= n; i++) {
//			ta[i] = rand(); tb[i] = rand();
//		}
		if (m == 0) {
			calc();
			return;
		}
		for (int i = 1; i <= n; i++) {
			read(a); read(b);
//			a = ta[i]; b = tb[i];
			idp[i] = node();
			idd[i] = node();
			dinic.add(idd[i], idp[i], LINF);
			dinic.add(src, idd[i], b + LARGE);
			dinic.add(idp[i], dst, a + LARGE);
			ans += b; 
			ans += a;
			ans += LARGE;
		}
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c); read(d); read(e);
			int D = node(), P = node();
			ans += e;
			ans += c;
			ans += d;
			dinic.add(src, D, c + e);
			dinic.add(D, idp[a], LINF);
			dinic.add(D, idp[b], LINF);
			dinic.add(P, dst, d + e);
			dinic.add(idd[a], P, LINF);
			dinic.add(idd[b], P, LINF);
		}
		size = idx;
		dinic.run();
		ans -= dinic.ans;
		printf("%lld", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f; 
	}
}T1;

}
