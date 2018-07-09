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
const int MXN = 5e3 + 10;
struct _Main {
	char ind[MXN];
	int head[MXN], edge[MXN][2], eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int a[MXN], b[MXN];
	int stk[MXN], top;
	int dfn[MXN], low[MXN], dfnidx;
	char instk[MXN];
	void tarjan(int nd, int fa) {
		dfn[nd] = low[nd] = ++dfnidx;
		instk[nd] = 1;
		stk[++top] = nd;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t = edge[e][DST];
//			if (t != fa) {//这玩意只有在无向图才能用
				if (!dfn[t]) {
					tarjan(t, nd);
					low[nd] = min(low[nd], low[t]);
				} else if (instk[t]) {
					low[nd] = min(low[nd], dfn[t]);
				}
//			}
		}
		if (low[nd] == dfn[nd]) {
			do {
				low[stk[top]] = low[nd];
				instk[stk[top]] = 0;
			} while (stk[top--] != nd);
		}
	}
	_Main() {
		int n, m, s;
		int ans = 0;
		read(n); read(m); read(s);
		for (int i = 1; i <= m; i++) {
			read(a[i]); read(b[i]);
			add(a[i], b[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) {
				tarjan(i, 0);
			}
		}
		eidx = 0;
		memset(head + 1, 0, n * sizeof(int));
		for (int i = 1; i <= m; i++) {
			int la = low[a[i]], lb = low[b[i]];
			if (la != lb) {
				add(la, lb);
				ind[lb] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			int l = low[i];
			if (l == dfn[i]) {
				if (l != low[s] && ind[l] == 0) {
					++ans;
				}
			}
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
