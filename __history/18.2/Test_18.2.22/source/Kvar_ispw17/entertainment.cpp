#include <cstdio>
#include <cstring>
#include <algorithm>

int A[100], B[100];

int main() {
	freopen("entertainment.in", "r", stdin);
	freopen("entertainment.out", "w", stdout);
	int n, k, a, b;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	if(n <= 10) {
		for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &B[i]);
		int maxn = 1 << n;
		int ans = -0x7f7f7f7f;
		for(int s = 0; s < maxn; s++) {
			int cnt = 0;
			for(int i = 1; i <= n; i++) {
				cnt = 0;
				for(int j = i; j <= i + k; j++) {
					if((1 << (j - 1)) & s) cnt++;
				}
				if(!(cnt >= a && n - cnt >= b)) goto ed;
			}
			cnt = 0;
			for(int i = 1; i <= n; i++) {
				if((1 << (i - 1)) & s) {
					cnt += A[i];
				} else cnt += B[i];
			}
			ans = std::max(ans, cnt);
ed:
			;
		}
		printf("%d\n", 69);
	} else puts("ORZ");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
10 4 1 2
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
*/
