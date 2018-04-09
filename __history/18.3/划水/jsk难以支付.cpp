using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace OI {
const int MXN = 2000005;
int dp[2000010];
int val[51];

struct _Main {
	_Main() {
		int n, got;
		memset(dp, 63, sizeof(dp));
		dp[0] = 0;
		scanf("%d%d", &got, &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &val[i]);
		}
		int t;
		for (int i = 0; i <= MXN; i++) {
			if (dp[i] > got) {
				printf("%d", i);
				break;
			}
			for (int j = 1; j <= n; j++) {
				if ((t = i + val[j]) <= MXN) {
					dp[t] = min(dp[t], dp[i] + 1);
				}
			}
		}
	}
}jsk;
}

