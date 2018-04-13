using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
typedef unsigned long long llu;
const int MOD = 100;
struct _Main {
	int fastpower(int base, llu pow) {
		int ret = 1;
		while (pow) {
			ret = (pow & 1) ? ret * base % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : base;
		}
		return ret;
	}
	_Main() {
		int Qn;
		llu n;//n√ª”√llu 
		while (1) {
			read(Qn);
			if (Qn == 0) break;
			for (int Q = 1; Q <= Qn; Q++) {
				read(n);
				printf("Case %d: %d\n", Q, (fastpower(4, n - 1) + fastpower(2, n - 1)) % MOD);
			}
			printf("\n");
		}
		
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
}hdu2065;
}
