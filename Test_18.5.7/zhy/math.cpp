using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
namespace OI {
struct _Main {
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}
	_Main() {
		freopen("math.in", "r", stdin);
		freopen("math.out", "w", stdout);
		int arr[20], got[20];
		int ok[20][20];
		int n, cop, ans = 0;
		read(n);
		for (int i = 0; i < n; i++) {
			read(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ok[i][j] = gcd(arr[i], arr[j]) == 1;
			}
		}
		for (int I = 1; I < 1 << n; I++) { //非空从1开始
			cop = 1;
			for (int j = 0; j < n; j++) {
				if (got[j] = I >> j & 1) for (int k = j - 1; k >= 0; k--) {
					if (got[k] && !ok[j][k]) {
						cop = 0;
						break;
					}
				}
				if (!cop) break;
			}
			ans += cop;
		}
		printf("%d", ans);
		fclose(stdout);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}math;

}
