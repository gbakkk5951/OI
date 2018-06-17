#include <cmath>
#include <cstdio>
#include <algorithm>
int n, a, b, c, d;
int main() {
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	scanf("%d %d %d", &n, &a, &b);
	if (b == 0) {
		printf("%d %d\n%d %d", a, b, b, a);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (d = -2000; d <= 2000; ++d) {
		if ((a * d - 1) % b == 0) {
			c = (a * d - 1) / b;
			if (c >= -2000 && c <= 2000) {
				printf("%d %d\n%d %d", a, b, c, d);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
}
