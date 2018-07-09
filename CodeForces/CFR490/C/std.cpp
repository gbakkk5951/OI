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
const int MXN = 4e5 + 10;
struct _Main {
	int head[26];
	int edge[MXN][2], eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	char del[MXN];
	char str[MXN];
	_Main() {
		int n, k;
		read(n); read(k);
		scanf("%s", str + 1);
		for (int i = n; i >= 1; i--) {
			add(str[i] - 'a', i);
		}
		int now = 0;
		for (int i = 1; i <= k; i++) {
			while (head[now] == 0) {
				++now;
			}
			del[edge[head[now]][DST]] = 1;
			head[now] = edge[head[now]][NXT];
		}
		for (int i = 1; i <= n; i++) {
			if (!del[i]) {
				putchar(str[i]);
			}
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
