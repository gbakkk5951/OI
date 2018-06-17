#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long double LD;
const LD ONE = LD(1);
int n;
LD ans;
LD F(int l, int r) {
	LD ret = 1;
	for (int i = l; i <= r; ++i) ret *= LD(i);
	return ret;
}
int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	scanf("%d", &n);
	if (n == 0) puts("0.6321");
	else {
		for (int i = 1; i <= 10; ++i) {
			if (i & 1) ans += ONE / F(n + 1, n + i);
			else ans -= ONE / F(n + 1, n + i);
		}
		if (ans < LD(0)) ans = -ans;
		if (ans > LD(0.5)) ans = ONE - ans;
		printf("%.4lf", (double) ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
