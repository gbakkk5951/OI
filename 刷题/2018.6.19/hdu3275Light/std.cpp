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
const int DST = 0, NXT = 1;
const int MXN = 1e5 + 10;
struct _Main {
	char mark[MXN];
	char str[MXN];
	int n, Qn, Tn;
	_Main() {
		int k;
		while (1) {
			read(n); read(k);
			if (n == 0 && k == 0) break;
			int ans = 0, mx = 0;
			char op = 0;
			scanf("%s", str + 1);
			for (int i = 1; i <= n; i++) {
				op ^= mark[i];
				mark[i] = 0;
				if ((str[i] - '0') ^ op == 0) {
					if (k == 0) {
						ans = -1;
						break;
					}
					if (i + k - 1 > n) {
						if (mx > i) memset(mark + i + 1, 0, mx - i);
						ans = -1;
						break;
					}
					++ans;
					op ^= 1;
					mark[mx = i + k] = 1;
				}
			}
			mark[n + 1] = 0;//这个忘了
			printf("%d\n", ans);
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
