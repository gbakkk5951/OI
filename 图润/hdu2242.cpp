using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 10010, MXM = 20010;
const int DST = 0, NXT = 1;
int ans, tot;
struct Graph {
	int head[MXN], edge[MXM << 1][2], sum[MXN], mxn;
	int eidx;
	Graph() {
		eidx = 1;
	}
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int stk[MXN], top;
	int dfn[MXN], low[MXN], idx;
	void tarjan(int nd, int fe) {
		dfn[nd] = low[nd] = ++idx;
		stk[top++] = nd;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (e != (fe ^ 1)) { // ^ 运算符比 != 小 
				t = edge[e][DST];
				if (!dfn[t]) {
					tarjan(t, e);
				}
				low[nd] = min(low[nd], low[t]);
			}
		}
		if (dfn[nd] == low[nd]) {
			do {
				low[stk[--top]] = low[nd];
			} while (stk[top] != nd); //自己没弹出
		}
	}
	int vis[MXN];
	void getans(int nd) {
		int t;
		vis[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!vis[t]) {
				getans(t);
				ans = min(ans, abs(tot - sum[t] - sum[t]));
				sum[nd] += sum[t];
			}
		}
	}
	void clear() {
		idx = 0;
		eidx = 1;
		memset(vis, 0, (mxn + 1) * sizeof(int));
		memset(head, 0, (mxn + 1) * sizeof(int));
		memset(dfn, 0, (mxn + 1) * sizeof(int));
	}
}G, tree;	
struct _Main {
	int n;
	int num[MXN], id[MXN];
	_Main() {
		int n, m, a, b, idx, cnt, self;
		while (~scanf("%d%d", &n, &m)) {
			G.clear(); tree.clear();
			G.mxn = n; idx = 0;
			cnt = 0, self = 0;
			tot = 0;
			for (int i = 1; i <= n; i++) read(num[i]), tot += num[i];
			for (int i = 1; i <= m; i++) {
				read(a); read(b);
				if (a == b) {
					self = 1;
					continue;
				}
				++a, ++b;
				G.add(a, b);
				G.add(b, a);
			}
			for (int i = 1; i <= n; i++) {
				if (G.dfn[i] == 0) {
					cnt++;
					G.tarjan(i, 0);
				}
			}
			
			memset(id, 0, (n + 1) * sizeof(int));
			for (int i = 1; i <= n; i++) {
				if (id[G.low[i]]) {
					tree.sum[id[G.low[i]]] += num[i];	
				} else {
					tree.sum[id[G.low[i]] = ++idx] = num[i];
				}
			}
			tree.mxn = idx;
			for (int i = 1; i <= n; i++) {
				for (int e = G.head[i]; e; e = G.edge[e][NXT]) {
					int t = G.edge[e][DST];
					if (G.low[t] != G.low[i]) {
						tree.add(id[G.low[t]], id[G.low[i]]);//已经有双向边了
					}
				}
			}
			
			if (cnt == 1 && idx > 1 || cnt == 2 && (self || n > 2)) {
				if (cnt == 1) {
					ans = 1e9;
					tree.getans(1);
				} else {
					tree.getans(1);
					for (int i = 2; i <= idx; i++) {
						if (!tree.vis[i]) {
							ans = abs(tree.sum[1] - tree.sum[i]);
							break;
						}
					}
				}
				printf("%d\n", ans);
			} else {
				printf("impossible\n");	
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
}hdu2242;
}
