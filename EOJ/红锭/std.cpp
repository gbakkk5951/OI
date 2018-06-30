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
const int MXN = 1e5 + 10;
struct _Main {
	int pos[18];
	lld sum[MXN];
	int a[MXN];
	int ands[MXN];
	_Main() {
		int mxp;
		int n;
		int mx = 0;
		lld ans = 0;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a[i]); mx = max(mx, a[i]);
		}
		for (mxp = 0; 1 << mxp <= mx; mxp++);
		for (int i = 0; i < mxp; i++) {
			pos[i] = n + 1;
			ands[i] = (1 << mxp) - 1;
		}
		for (int i = n; i >= 1; i--) {
			sum[i] = sum[i + 1] + a[i];
			for (int j = 0; j < mxp; j++) {
				ands[j] &= a[i];
			}
			for (int j = 0; j < mxp; j++) {
				ans = max(ans, ands[j] * (sum[i] - sum[pos[j]]));
			}
			for (int j = 0; j < mxp; j++) {
				if (~a[i] >> j & 1) {
					pos[j] = i;
					ands[j] = (1 << mxp) - 1;
				}
			}
		}
		printf("%lld", ans);
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
