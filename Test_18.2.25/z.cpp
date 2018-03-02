using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
namespace OI {


struct _Main {
	int d[300];
	int need[300][300];
	int need_cnt[300];
	int vis[300];
	int val[300];
	_Main(){
		freopen("z.in", "r", stdin);
		freopen("z.out", "w", stdout);
		int i, j, k, I;
		int n;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &need_cnt[i]);
			for (j = 0; j < need_cnt[i]; j++) {
				scanf("%d", &need[i][j]);
				need[i][j] -= 1;
			}
		}
		int ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &val[i]);
		}
		if (n <= 20) {
			int sum = 0;
			int cnt = 0;
			int cnt0;
			for (I = 0; I < (1 << n); I++) {
				for (i = 0; i < n; i++) {
					vis[i] = 0;
				}
				sum = cnt = cnt0 = 0;
				for (i = 0; i < n; i++) {
					if (I & (1 << i)) {
						cnt0++;
						sum += val[i];
						for (j = 0; j < need_cnt[i]; j++) {
							if (!vis[need[i][j]]) {
								cnt++;
								vis[need[i][j]] = 1;
							}
						}
					}
				}
				if (cnt == cnt0) {
					ans = min(ans, sum);
				}
			}	
		} else {
			for (i = 0; i < n; i++) {
				ans += val[i];
			}
			ans = min(ans, 0);
		}
		printf("%d", ans);
		fclose(stdout);
	}	
	
}z;

}
