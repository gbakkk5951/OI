using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
int mod;
const int MXN = 100005;
void exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}
struct _Main {
	int sum[MXN];
	int pow[MXN];
	_Main() {
		int n, Qn, k, mod, x, y, a, b, l, r;
		scanf("%d%d%d%d", &n, &Qn, &k, &mod);
		int pw = 1;
		pow[0] = 1;
		exgcd(k, mod, pow[1], y);
		pow[1] %= mod;
		pow[1] += mod;
		pow[1] %= mod;
		for (int i = 2; i <= n; i++) {
			pow[i] = pow[i - 1] * pow[1] % mod;
		}
		for (int i = 1; i <= n; i++) {
			pw *= k;
			scanf("%d", &sum[i]);
			sum[i] = ((lld)sum[i] * pw + sum[i - 1]) % mod;
		}
		lld ans;
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%d%d", &l, &r);
			ans = (pow[l] * (sum[r] - sum[l - 1]) % mod + mod) % mod;
			printf("%d\n", ans);
		}
	}

}dloj1004;


}
