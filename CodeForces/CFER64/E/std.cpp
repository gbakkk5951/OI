using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <functional>
namespace OI {
const int MXN = 3e5 + 10;
const int DST = 0, NXT = 1;
struct _Main {
	int a[MXN], b[MXN];
	int n, m;
	int stk[MXN], top;
	int low[MXN], dfn[MXN];
	int dfnidx;
	void tarjan(int nd, int fa) {
		low[nd] = dfn[nd] = ++dfnidx;
		stk[++top] = nd;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				if (!dfn[t]) {
					tarjan(t, nd);
					low[nd] = min(low[nd], low[t]);
				} else {
					low[nd] = min(low[nd], dfn[t]);
				}
			}
		}
		if (low[nd] == dfn[nd]) {
			do {
				low[stk[top]] = low[nd];//low[nd] 不是 nd
			} while (stk[top--] != nd);
		}
	}
	int dp[MXN][3];
	int ans;
	void dfs(int nd, int fa) {
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
				dp[nd][2] = dp[t][0] + 1;
				sort(dp[nd], dp[nd] + 3, greater<int>());
			}
		}
		ans = max(ans, dp[nd][0] + dp[nd][1]);
	}
	_Main() {
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(a[i]); read(b[i]);
			add(a[i], b[i]); add(b[i], a[i]);
		}
		tarjan(1, 0);
		eidx = 0;
		memset(head + 1, 0, n * sizeof(int));
		for (int i = 1; i <= m; i++) {//n和ｍ同阶但不相等
			if (low[a[i]] != low[b[i]]) {
				add(low[a[i]], low[b[i]]);
				add(low[b[i]], low[a[i]]);
			}
		}
		dfs(1, 0);
		printf("%d", ans);
	}
	int head[MXN], edge[MXN << 1][2], eidx;
	void inline add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
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
}std;
}
