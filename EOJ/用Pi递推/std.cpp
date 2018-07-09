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
const lld LMOD = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MXN = 1e6 + 10;
struct _Main {
	int n;
	int ans;
	lld f[MXN], fr[MXN], rev[MXN];
	inline int com(int n, int m) {
		return f[n] * fr[m] % LMOD * fr[n - m] % LMOD;
	}
	_Main() {
		read(n);
		lf sum;
		int picnt;
		ans = 1;//一路减1
		rev[1] = f[0] = f[1] = fr[0] = fr[1] = 1;
		for (int i = 2; i <= n; i++) {
			rev[i] = -MOD / i * (lld)rev[MOD % i] % LMOD + LMOD;
			f[i] = (lld)f[i - 1] * i % LMOD;
			fr[i] = (lld)fr[i - 1] * rev[i] % MOD;
		}
		for (sum = PI, picnt = 1; n - sum > 4; sum += PI, ++picnt) {//减掉的PI
			int one = ceil(n - sum - 4);
			for (int one = ceil(n - sum - 4); n - one - sum > 0 && !(n - one - sum + PI < 4); one++) {
				if (n - sum - one > 3) {
					ans = (ans + com(one + picnt, one)) % MOD;
				} else {
					ans = (ans + com(one + picnt - 1, one)) % MOD;
				}
			}
		}
		for (int one = 0; !(n - one - sum + PI < 4); one++) {
			ans = (ans + com(one + picnt - 1, one)) % MOD;
		}
		printf("%d", ans);
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
