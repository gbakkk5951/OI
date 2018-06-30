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
const int MXN = 3e6 + 10;
struct _Main {

	lld ans[MXN];
	int cnt[MXN];
	_Main() {
		lld out = 0;
		int n, m, a;
		read(n); read(m);
		read(a);
		++cnt[a];
		if (n < 200000) {
			for (int i = 2; i <= n; i++) {
				read(a);
				++cnt[a];
			}
		} else {
			for (int i = 2; i <= n; i++) {
				a = ((lld)a * a + 7LL * a + 34221LL) % m + 1;
				++cnt[a];
			}
		}
		lld tmp;
		for (int i = 1; i <= m; i++) {
			if (tmp = cnt[i]) {
				for (int j = i; j <= m; j += i) {
					ans[j] += tmp;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			ans[i] += ans[i - 1];
		}
		for (int i = m; i >= 1; i--) {
			cnt[i] += cnt[i + 1];
		}
		for (int i = 1; i <= m; i++) {
			tmp = ans[i];
			for (int j = i; j <= m; j += i) {
				tmp += cnt[j];
			}
			out ^= tmp;
		}
		printf("%lld", out);
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
