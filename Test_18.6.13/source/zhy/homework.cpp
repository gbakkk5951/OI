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
		Lf ans = /*(Lf)1.0 - (Lf)1.0 / exp((Lf)1.0)*/ 0;
		scanf("%d", &n);
		for (int i = 10000; i >= n; i--) {
		//	printf("%Lf\n", ans);
			ans = (ans - 1.0) / -(i + 1.0);
			//ans = (Lf)1.0 - ((Lf) i) * ans;
		}
		printf("%.4Lf", ans);
		fclose(stdout);
	}
}brute;
}
