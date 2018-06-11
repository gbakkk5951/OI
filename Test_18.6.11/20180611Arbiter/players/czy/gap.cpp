#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int n, k, a[N];

namespace force {
	int tmp[N];
	ll ans;
	void sol() {
		for(int len = k ; len <= n ; ++ len) {
			for(int i = 1 ; i + len - 1 <= n ; ++ i) {
				for(int j = i ; j <= i + len - 1 ; ++ j) {
					tmp[j - i + 1] = a[j];
				}
				sort(tmp + 1, tmp + 1 + len);
				int mn = tmp[2] - tmp[1];
				for(int j = 2 ; j <= len ; ++ j) mn = min(mn, tmp[j] - tmp[j - 1]);
				// printf("[%d, %d], mn = %d\n", i, i + len - 1, mn);
				ans = max(ans, (ll) mn * (len - 1));
			}
		}
		printf("%lld\n", ans);
	}
}

void sol() {
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i) scanf("%d", &a[i]);
	force :: sol();
}

int main() {
	freopen("gap.in", "r", stdin);
	freopen("gap.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T --) sol();
}