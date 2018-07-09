using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
//const int MXN = 20;
const lld MOD = 1e9 + 7;
struct _Main {
	//int dp[MXN][MXN];
	_Main() {
		//int n = 15, m = 15;
		lld n, m;
		read(n); read(m);
		if (m & 1) swap(n, m);
		if (n & 1) {
			printf("%lld", (n + (m - 1) % MOD * ((n + 1 >> 1) % MOD)) % MOD);
		} else {
			printf("%lld", ((3 * n >> 1) + (m - 2 >> 1) % MOD * ((n + 1) % MOD)) % MOD);
		}
		/*for (int i = 1; i <= n; i++) {
			dp[i][1] = dp[1][i] = i;
		}
		int cut;
		for (int i = 1; i <= n; i++) {
			printf("dp %d %d = %d\n", 1, i, i);
		}
		for (int i = 2; i <= n; i++) {
			printf("%d %d = %d\n", i, 1, dp[i][1]);
			for (int j = 2; j <= m; j++) {
				for (int k = 1; k <= i; k++) {
					int tmp = 1 + dp[k - 1][j] + dp[i - k][j];
					if (tmp > dp[i][j]) {
						dp[i][j] = tmp;
						cut = k;
					}
				}
				for (int k = 1; k <= j; k++) {
					int tmp = 1 + dp[i][k - 1] + dp[i][j - k];
					if (tmp > dp[i][j]) {
						dp[i][j] = tmp;
						cut = -k;
					}
				}
				printf("%d %d cut %d = %d\n", i, j, cut, dp[i][j]);
			}
		}
		*/	
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
