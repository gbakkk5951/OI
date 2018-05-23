using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e4 + 10;
const int DST = 0, NXT = 1;
struct _Main {
	int head[MXN], edge[MXN << 1][2];
	int eidx;
	inline void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int dfn[MXN], low[MXN], dfnidx;
	int stk[MXN], top;
	int nxt[MXN], pre[MXN];
	int instk[MXN];
	int lpid[MXN];
	int lpidx;
	void dfs(int nd, int fa) {
		dfn[nd] = low[nd] = ++dfnidx;
		stk[++top] = nd;
		instk[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t == fa) continue;
			if (!dfn[t]) {
				dfs(t, nd);
				low[nd] = min(low[nd], low[t]);
			} else if (instk[t]) {
				low[nd] = min(low[nd], dfn[t]);
			}
		}
		int lst = nd, id, tp;
		id = (stk[top] != nd || nd * nd % p == nd)? ++lpidx : 0;//自环
		while (top && low[stk[top]] >= dfn[nd]) {
			tp = stk[top];
			nxt[tp] = lst;
			pre[lst] = tp;
			lst = tp;
			lpid[tp] = id;
			instk[tp] = 0;
			--top;
		}
	}
	int vis[MXN];
	int getlen(int nd) {
		int ret = 0;
		for (; !vis[nd]; nd = pre[nd]) {
			ret += vis[nd] = 1;
		}
		return ret;
	}
	int dis[MXN];
	void getdis(int nd, int fa) {
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !lpid[t]) {
				dis[t] = dis[nd] + 1;
				getdis(t, nd);
			}
		}
	}
	int p;
	_Main()	{
		int sum, mx, t;
		while (~scanf("%d", &p)) {
			memset(head, 0, p * sizeof(int));
			memset(vis, 0, p * sizeof(int));
			memset(dis, 0, p * sizeof(int));
			memset(dfn, 0, p * sizeof(int));
			lpidx = sum = mx = eidx = dfnidx = 0;
			for (int i = 0; i <= p - 1; i++) {
				t = i * i % p;
				add(i, t);
				add(t, i);
			}
			for (int i = 0; i <= p - 1; i++) {
				if (!dfn[i]) dfs(i, -1);
			}
			for (int i = 0; i <= p - 1; i++) {
				if (lpid[i]) {
					if (!vis[i]) {
						t = getlen(i);
						sum += t;
						printf("%d ", t);
					}
					getdis(i, -1);
				}
			}
			printf("\nsum = %d\n", sum);
			for (int i = 0; i <= p - 1; i++) {
				mx = max(mx, dis[i]);
			}
			printf("mxdis = %d\n", mx);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}db;
}
