using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {
const int 
	MAXN = 205
;
struct _Main {
	int way[20];
	int now_way[20];
	int vis[20];
	int link[20][20];
	int n;
	int loop, chain;
	void dfs(int nd, int idx) {
		if (idx == n) {
			chain = 1;
			memcpy(way, now_way, sizeof(way));
			if (link[nd][now_way[0]]) {
				loop = 1;
			}
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!vis[i] && link[nd][i] ) {
				vis[i] = 1;
				now_way[idx] = i;
				dfs(i, idx + 1);
				vis[i] = 0;
			}
			if (loop) {
				return;
			}
		}
	}
	void brute() {
		int i, j, k;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &link[i][j]);
			}
		}
		for (i = 0; i < n; i++) {
			vis[i] = 1;
			now_way[0] = i;
			dfs(i, 1);
			if (loop) {
				break;
			}
		}
		if (chain) {
			printf("%d\n", 1 - loop);
			for (i = 0; i < n; i++) {
				printf("%d ", way[i] + 1);
			}
		} else {
			printf("-1");
		}
	}

	_Main() {
		freopen("game.in", "r", stdin);
		freopen("game.out", "w", stdout);
		
		scanf("%d", &n);
		if (n <= 15) {
			brute();
		} else {
			printf("-1");	
		}
		
		fclose(stdout);
	}
	
}game;






}
