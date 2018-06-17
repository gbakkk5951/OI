using namespace std;
int main() {}
#include <cstdio>
#include <cmath>
namespace OI {
struct _Main {
typedef long double Lf;
	_Main() {
		freopen("homework.in", "r", stdin);
		freopen("homework.out", "w", stdout);
		int n;
		Lf ans = (Lf)1.0 - 1.0 / exp(1);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			ans = (Lf)1 - ((Lf) i) * ans;
		}
		printf("%.4Lf", ans);
		fclose(stdout);
	}
}brute;
}
