using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
namespace OI {
typedef long long lld;
struct _Main {
	
	lld v[2][25];
	int mn[2];
	int cnt[2];
	_Main() {
		freopen("entertainment.in", "r", stdin);
		freopen("entertainment.out", "w", stdout);
		lld ans = -0x3f3f3f3f3f3f3f3f; lld sum;
		int n;
		int f;
		scanf("%d%d%d%d", &n, &f, &mn[0], &mn[1]);
		int i, j, k, I;
		for (j = 0; j < 2; j++) {
			for (i = 0; i < n; i++) {
				scanf("%lld", &v[j][i]);
			}
		}
		for (I = 0; I < 1 << n; I++) {

			for (j = 0; j <= n - f; j++) {
				for (i = 0; i < 2; i++) {
					cnt[i] = 0;
				}
				for (k = j; k < j + f; k++) {
					cnt[(I >> k) & 1]++;
				}
				for (i = 0; i < 2; i++) {
					if (cnt[i] < mn[i]) {
						break;
					}
				}
				if (i < 2) {
					break;
				}
			}
			if (j > n - f) {
				sum = 0;
				for (i = 0; i < n; i++) {
					sum += v[(I >> i) & 1][i];
				}
				ans = max(ans, sum);
			} 
		}
		printf("%lld", ans);
		fclose(stdout);
	}

}entertainment;
}
