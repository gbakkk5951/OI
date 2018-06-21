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
const int MXN = 2e5 + 10;
struct _Main {
	int c[MXN];
	int lstc[MXN];
	int size[MXN], csize[MXN];
	int head[MXN], edge[MXN << 1][2];
	int tcsize[MXN];
	int eidx;
	lld ans;
	inline lld calc(lld a) {
		return a * (a - 1LL) >> 1;
	}
	void dfs(int nd, int fa) {
		int cf = lstc[c[nd]];
		lstc[c[nd]] = nd;
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
				size[nd] += size[t];
				ans -= calc(size[t] - csize[nd]);
				csize[nd] = 0;
			}
		}
		if (cf) {
			csize[cf] += size[nd];
		} else {
			tcsize[c[nd]] += size[nd];
		}
		lstc[c[nd]] = cf;
		csize[nd] = 0;
	}
	_Main() {
		int n, Qn, Tn = 0, a, b;
		while (~scanf("%d", &n)) {
			++Tn;
			eidx = 0;
			ans = calc(n) * n;
			for (int i = 1; i <= n; i++) {
				read(c[i]);
			}
			for (int i = 1; i <= n - 1; i++) {
				read(a); read(b);
				add(a, b); add(b, a);
			}
			dfs(1, 0);//神Tm写在后面了
			for (int i = 1; i <= n; i++) {
				ans -= calc(size[1] - tcsize[i]);
				tcsize[i] = 0;
			}
			eidx = 0;
			memset(head + 1, 0, n * sizeof(int));
			printf("Case #%d: %lld\n", Tn, ans);
		}
	}
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
