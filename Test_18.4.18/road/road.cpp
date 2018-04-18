using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int DST = 0, NXT = 1, VAL = 2;
const int MXN = 10015;
struct Edge {
	int dst, val;
	bool operator < (const Edge &b) const {
		return val > b.val;
	}
};
priority_queue<Edge> heap;
struct _Main {
	int dis1[1005][1005];
	int dis2[MXN];
	int fe[MXN];
	int del[MXN << 1];
	void getdis(int src, int *dis) {
		memset(dis, 63, (n + 1) * sizeof(int));
		dis[src] = 0;
		heap.push((Edge){src, 0});
		while (!heap.empty()) {
			int nd = heap.top().dst;
			if (heap.top().val > dis[nd]) {
				heap.pop();
				continue;
			}
			heap.pop();
			int t;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				if (dis[t] > dis[nd] + (del[e] ^ 1) * edge[e][VAL]) {
					dis[t] = dis[nd] + (del[e] ^ 1) * edge[e][VAL];
					fe[t] = e;
					heap.push((Edge) {t, dis[t]});
				}
			}
		}
	}
	int head[MXN];
	int edge[MXN << 1][3];
	void add(int a, int b, int c) {
		static int eidx = 1;
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	
	int n, d, m;
	int ans;
	int now[5];
	int vis[5];
	void dfs(int nd) {
		if (nd == d + 1) {
			
			int res = 0;
			memset(del, 0, (m * 2 + 5) * sizeof(int));
			for (int i = 1; i <= d; i++) {
				getdis(now[i], dis2);
				res += dis2[n - now[i] + 1];
				for (int e = n - now[i] + 1; e != now[i]; e = edge[fe[e] ^ 1][DST]) {
					del[fe[e]] = del[fe[e] ^ 1] = 1;
				}
			}
			ans = min(ans, res);
			return;
		}
		for (int i = 1; i <= d; i++) {
			if (!vis[i]) {
				vis[i] = 1;
				now[nd] = i;
				dfs(nd + 1);
				vis[i] = 0;
			}
		}
	}
	_Main() {
//		freopen("road.in", "r", stdin);
//		freopen("road.out", "w", stdout);
		int a, b, c;
		read(n); read(m); read(d);
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
			ans += c;
		}
		for (int i = 1; i <= d; i++) {
			getdis(i, dis2);
			if (dis2[n - i + 1] > ans) {
				printf("-1");
				fclose(stdout);
				return;
			}
		}
		
		if (n <= 1000 && m <= 1000) {
			for (int i = 1; i <= n; i++) {
				getdis(i, dis1[i]);
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					
					int res = dis1[i][j];
					if (res >= ans) continue;
					for (int k = 1; k <= d; k++) {
						res += min(dis1[k][i] + dis1[n - k + 1][j], dis1[n - k + 1][i] + dis1[k][j]);
					}
					ans = min(res, ans);
				}
			}
		}
		dfs(1); 
		printf("%d", ans);
		fclose(stdout);
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
}instance;

}


