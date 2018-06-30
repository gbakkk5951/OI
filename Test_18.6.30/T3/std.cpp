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
const int MXN = 3e4 + 10;
struct _Main {
	lld dp[2][MXN];
	int a[MXN];
	void getdp() {
		memset(dp, 63, sizeof(dp));
		int it = 0, mx = 0, now;
		lld val;
		dp[it][0] = 0;
		for (int i = 1; i <= n; i++) {
			it ^= 1;
			lld *dp = this->dp[it];
			lld *ldp = this->dp[it ^ 1];
			now = a[i];
			mx = max(mx, now);
			for (int j = 0; j <= i - 1; j++) {
				if (ldp[j] == LINF) continue;
				val = ldp[j];
				ldp[j] = LINF;
				if (now == mx) {
					dp[j] = min(dp[j], val + now);
				} else
				if (now <= a[j]) {//<= a[j] 不是 <= j
					dp[j] = min(dp[j], val + a[j]);
				} else {
					dp[i] = min(dp[i], val + now);
					dp[j] = min(dp[j], val + mx);
				}
			}
		}
	}
	int n;
	_Main() {
		freopen("c.in", "r", stdin);
		freopen("c.out", "w", stdout);
		lld ans = LINF;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
		}
		getdp();
		for (int i = 1; i <= n; i++) {
			ans = min(ans, dp[n & 1][i]);
		}
		printf("%lld", ans);
		fclose(stdout);
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
