using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
namespace OI {
const int MOD = 1e4 + 7;
const int REV = (MOD + 1 >> 1) * (((MOD << 2) + 1) / 3 % MOD) % MOD;
struct _Main {
	_Main() {
		int t, n = 0;
		while (!isdigit(t = getchar()));
		for (int i = 0; isdigit(t); t = getchar(), i++) {
			n = (n * 10 + t - '0') % MOD;
		}
		n %= MOD;
		printf("%d", n * (n + 1) % MOD * (n + 2) % MOD * REV % MOD);
	}
}bzoj3028;
}
