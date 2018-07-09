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
const int MXN = 2e5 + 10;
struct _Main {
lld ans[MXN];
int aidx;
int v[MXN];
	lld dp[MXN];
	int son[MXN];
	void dfs0(int nd, int fa) {
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				dfs0(t, nd);
				if (dp[t] > dp[son[nd]]) {
					son[nd] = t;
				}
			}
		}
		dp[nd] += dp[son[nd]] + v[nd];
	}
	void dfs1(int nd, int fa, lld val) {
		val += v[nd];
		if (int s = son[nd]) {
			dfs1(s, nd, val);
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				int t = edge[e][DST];
				if (t != s && t != fa) {
					dfs1(t, nd, 0);
				}
			}
		} else {
			ans[++aidx] = val;
		}
	}
	int n, k;
	_Main() {
		int a, b;
		read(n); read(k);
		for (int i = 1; i <= n; i++) {
			read(v[i]);
		}
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		dfs0(1, 0);
		dfs1(1, 0, 0);
		k = min(k, aidx);
		nth_element(ans + 1, ans + k, ans + aidx + 1, greater<lld>());
		lld ret = 0;
		for (int i = 1; i <= k; i++) {
			ret += ans[i];
		}
		printf("%lld", ret);
	}
	int eidx, head[MXN], edge[MXN << 1][2];
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
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
