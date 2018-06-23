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
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 505;
struct _Main {
	char dp[MXN][MXN << 1];
	char up[MXN], down[MXN], str[MXN << 1];
	_Main() {
		int Tn, n, m, h;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(n); read(m);
			scanf("%s", str + 1);
			h = n >> 1;
			for (int i = 1; i <= h; i++) {
				up[i] = str[i];
			}
			for (int i = 1; i <= h; i++) {
				down[i] = str[i + h];
			}
			for (int i = 1; i <= h + 1; i++) {
				memset(dp[i], 0, (m + 1) * sizeof(char));
			}
			dp[h + 1][0] = 1;
			for (int i = h; i >= 1; i--) {
				for (int j = 0; j <= m; j++) {
					if (dp[i + 1][j] == 0) continue; 
					if (up[i] == down[i]) {
						dp[i][j] = 1;
						dp[i][j + 2] = 1; 
					} else {
						dp[i][j + 1] = 1;
						dp[i][j + 2] = 1;
					}
				}
			}
			if (dp[1][m] == 0) {
				printf("Impossible\n");
				continue;
			}
			int rem = m, t;
			for (int i = 1; i <= h; i++) {
				for (char c = 'a'; c <= 'z'; c++) {
					if ((t = rem - (up[i] != c) - (down[i] != c)) < 0) continue;
					if (dp[i + 1][t]) {//i + 1
						rem -= (up[i] != c) + (down[i] != c);
						str[i] = str[i + h] = c;
						break;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				putchar(str[i]);
			}
			printf("\n");
		}
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
