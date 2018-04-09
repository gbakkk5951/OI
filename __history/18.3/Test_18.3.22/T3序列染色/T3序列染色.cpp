using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cstring>
namespace OI {
typedef long long lld;
const int mod = 1e9 + 7;
struct _Main {
	char str[1002005];
	int dp[2001][2001][2];
	int n, k;

	_Main() {
		scanf("%d%d%s", &n, &k, str + 1);
		if (n > 2000 || k > (n >> 1)) {
			printf("0\n");
			return;
		}
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < k && j < i; j++) {
				if (str[i] != 'W') {
					if (dp[i - 1][j][0] > 0) {
						dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i - 1][j][0]) % mod;	
					}
					if (dp[i - 1][j][1] > 0) {
						dp[i][0][1] = (dp[i][0][1] + dp[i - 1][j][1]) % mod;
					}
				}
				if (str[i] != 'B') {
					if (dp[i - 1][j][0] > 0) {
						dp[i][0][0] = (dp[i][0][0] + dp[i - 1][j][0]) % mod;
					}
					if (dp[i - 1][j][1] > 0) {
						dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i - 1][j][1]) % mod;
					}
				}
			}
			if (k < i) {
				if (dp[i - 1][k][1]) {
					if (str[i] == 'X') {
						dp[i][k][1] = (dp[i][k][1] + 2 * dp[i - 1][k][1] % mod) % mod;
					} else {
						dp[i][k][1] = (dp[i][k][1] + dp[i - 1][k][1]) % mod;
					}
				}
				if (dp[i - 1][k][0]) {
					if (str[i] != 'W') {
						dp[i][0][1] = (dp[i][0][1] + dp[i - 1][k][0]) % mod;
					}
					if (str[i] != 'B') {
						dp[i][1][1] = (dp[i][1][1] + dp[i - 1][k][0]) % mod;
					}
				}
			}
		}
		printf("%d", dp[n][k][1] % mod);
	}
}T3;	
}
