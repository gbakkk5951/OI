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
typedef pair<lld, int> p;
const int MXN = 1e5 + 10;
struct _Main {
	p dp[MXN][4];
	void push(int dst, int src, lld val) {
		dp[dst][3] = (p) {val, src};
		sort(dp[dst], dp[dst] + 4, greater<p>());
	}
	lld ans;
	int n, m;
	int Tp;
	_Main() {
		ans = -LINF;
		read(Tp); read(n); read(m);
		int a, b, c;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = (p) {-LINF, 0};
			}
		}
		dfs1(1, 0);
		dfs2(1, 0);
		if (m == 2) {
			for (int i = 1; i <= n; i++) {
				ans = max(ans, dp[i][0].first);
				ans = max(ans, dp[i][0].first + dp[i][1].first);
			}
		} else {
			for (int i = 1; i <= n; i++) {
				ans = max(ans, dp[i][0].first + dp[i][1].first);
				if (dp[i][2].first != -LINF) {//防爆
					ans = max(ans, dp[i][0].first + dp[i][1].first + dp[i][2].first);
				}
			}
			ans <<= 1;
		}
		printf("%lld", ans);
	}
	void dfs1(int nd, int fa) {
		int fv;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				dfs1(t, nd);
			} else {
				fv = edge[e][VAL];
			}
		}
		push(fa, nd, max(0LL, dp[nd][0].first) + fv);
	}
	void dfs2(int nd, int fa) {
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
			if (t != fa) {
				if (dp[nd][0].second != t) {
					push(t, nd, max(0LL, dp[nd][0].first) + edge[e][VAL]);
				} else {
					push(t, nd, max(0LL, dp[nd][1].first) + edge[e][VAL]);
				}
				dfs2(t, nd);//忘了递归了...
			}
		}
	}
	int head[MXN], eidx, edge[MXN << 1][3];
	void inline add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
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
