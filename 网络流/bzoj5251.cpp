using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXM = 5000;
const int MXN = 210;
const int DST = 0, NXT = 1, FLOW = 2;

int dst;
struct Flow {
	int size;
	int vis[MXN << 1], head[MXN << 1];
	int edge[MXM][3];
	int eidx;
	void dir_add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][FLOW] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void add(int a, int b, int c) {
		dir_add(a, b, c); dir_add(b, a, c);
	}
	void clear() {
		eidx = 0;
		memset(head, 0, size * sizeof(int));
	}
	void run(int src) {
		memset(vis, 0, size * sizeof(int));
		dfs(src);
	}
	int dfs(int nd) {
		if (nd == dst) return 1;
		vis[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (edge[e][FLOW]) {
				t = edge[e][DST];
				if (!vis[t]) {
					if (dfs(t)) {
						return 1;
					}
				}
			}
		}
		return 0;
	}
	void getvis() {
		getvis(dst);
	}
	void getvis(int nd) {
		vis[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (edge[e ^ 1][FLOW]) {
				t = edge[e][DST];
				if (!vis[t]) {
					getvis(t);
				}
			}
		}
	}
	void operator = (const Flow & b) {
		eidx = b.eidx;
		memcpy(head, b.head, b.size * sizeof(int));
		memcpy(edge, b.edge, (eidx + 1) * sizeof(int));
	}
}f[MXN];
struct _Main {
	int nid[MXN], mid[MXN];
	int idx;
	inline int node() {
		return idx++;
	}
	_Main() {
		int Tn, C, b;
		read(Tn); read(C);
		for (int T = 1; T <= Tn; T++) {
			f[0].clear();
			idx = 0;
			read(n); read(m);
			dst = node();
			for (int i = 1; i <= m; i++) {
				mid[i] = node();
			}
			f[0].size = idx; 
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a = a * 10 + t - '0';
		}
	}
	
}bzoj5251;
}
