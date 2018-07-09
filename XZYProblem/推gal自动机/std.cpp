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
const lld MOD = 1e9 + 9;
const int PHI = MOD - 1;
const int MXN = 1e5 + 10;
int rev[MXN];
lld fastpower(lld base, int pow) {
	lld ret = 1;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}
struct Dp {
	int a, b, c, d, e, f;
	void init(int ci, int len) {
		a = (1 - (ci - 1LL) * rev[len]) % MOD;
		b = ci;
		c = -ci;
		d = (-(ci - 1LL) * rev[len]) % MOD;
		e = ci;
		f = -ci;
	}
}node[270000];
void mul (const Dp &s, const Dp &t, Dp &dst) {
	dst = (Dp) {
		((lld)s.a * t.a + (lld)s.b * t.d) % MOD,
		((lld)s.a * t.b + (lld)s.b * t.e)	% MOD,
		((lld)s.a * t.c + (lld)s.b * t.f + s.c) % MOD,
		((lld)s.d * t.a + (lld)s.e * t.d) % MOD,
		((lld)s.d * t.b + (lld)s.e * t.e) % MOD,
		((lld)s.d * t.c + (lld)s.e * t.f + s.f) % MOD
	};
}
int n;
int c[MXN];
struct Tree {
	inline void update(int nd) {
		mul(node[ls[nd]], node[rs[nd]], node[nd]);
	}
	void build(int nd, int nl, int nr) {
		if (nl == nr) {
			node[nd].init(c[nl], n - nl + 1);
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		update(nd);
	}
	void change(int pos) {
		int nd = 1, nl = 1, nr = n;
		while (nl != nr) {
			int mid = nl + nr >> 1;
			if (pos <= mid) {
				nr = mid;
				nd = ls[nd];
			} else {
				nl = mid + 1;
				nd = rs[nd];
			}
		}
		node[nd].init(c[pos], n - pos + 1);
		while (nd >>= 1) {
			update(nd);
		}
	}
	void query(int nd, int nl, int nr, int left, Dp &ans) {
		if (nl == nr) {
			ans = node[nd];
			return;
		}
		int mid = nl + nr >> 1;
		if (left > mid) {
			query(rs[nd], mid + 1, nr, left, ans);
		} else {
			query(ls[nd], nl, mid, left, ans);
			mul(ans, node[rs[nd]], ans);
		}
	}
	void query(int left, Dp &ans) {
		if (left == 1) ans = node[1];
		else query(1, 1, n, left, ans);
	}
}tree;

struct _Main {
	void init() {
		rev[1] = 1;
		for (int i = 2; i <= n; i++) {
			rev[i] = -MOD / i * rev[MOD % i] % MOD;
		}
		tree.build(1, 1, n);
	}
	Dp ma;
	lld query(int i) {
		if (i == n) {
			return 0;
		}
		lld k, b, ret;
		tree.query(i + 1, ma);
		k = ma.d + ma.e;
		b = ma.f;
		ret = -b * fastpower(k, PHI - 1) % MOD;
		ret += ret < 0 ? MOD : 0;
		return ret;
	}
	_Main() {
		int Qn, op, a, b; 
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(c[i]);
		}
		init();
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			if (op == 1) {
				read(a);
				printf("%lld\n", query(a));
			} else {
				read(a); read(b);
				c[a] = b;
				tree.change(a);
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
