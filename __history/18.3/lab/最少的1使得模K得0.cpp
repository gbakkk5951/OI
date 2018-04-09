using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
namespace OI {
typedef long long lld;
const int MXN = 1e6 + 5;
char vis[MXN];
struct _Main {
	int dis[MXN];
	int dp[MXN];
	int a[MXN];
	_Main() {
		int k = 10;
		freopen ("data.out", "w", stdout);
		for (int mod = 1; mod <= 2000; mod++) {
			if (mod % 2 == 0 || mod % 5 == 0) continue;
			k = 1;
			memset(vis, 0, mod * sizeof(int));
			memset(dis, 63, mod * sizeof(int));
			int cnt = 0;
			while (!vis[k]) {
				dis[k] = 1;
				vis[k] = 1;
				a[cnt++] = k;
				k = k * 10 % mod;
			}
			for (int i = 1; i <= mod - 1; i++) {
				for (int j = 0; j < cnt; j++) {
					int t = (i + a[j]) % mod;
					dis[t] = min(dis[t], dis[i] + 1);
				}
			}
//			printf("%d\n", dis[0]);
			printf("%d %d %d\n", mod, cnt, dis[0]);			
		}

	}
}MN1;
}
