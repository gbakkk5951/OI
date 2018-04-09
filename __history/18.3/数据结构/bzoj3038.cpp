using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>

namespace OI {
typedef long long lld;
const int MXN = 100005;
struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
lld mx[263000], sum[263000], arr[MXN];
class SegTree {
public:
	void change(int nd, int nl, int nr, int l, int r) {
		if(nl == nr) {
			mx[nd] = sum[nd] = sqrt(sum[nd]);
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid && mx[ls[nd]] > 1) {
			change(ls[nd], nl, mid, l, r);
		}
		if (r > mid && mx[rs[nd]] > 1) {
			change(rs[nd], mid + 1, nr, l, r);
		}
		update(nd);
	}
	void update(int nd) {
		sum[nd] = sum[ls[nd]] + sum[rs[nd]];
		mx[nd] = max(mx[ls[nd]], mx[rs[nd]]);
	}
	lld query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return sum[nd];
		}
		int mid = nl + nr >> 1;
		lld ret = 0;
		if (l <= mid) {
			ret += query(ls[nd], nl, mid, l, r);
		}
		if (mid < r) {
			ret += query(rs[nd], mid + 1, nr, l, r);
		}
		return ret;
	}
	void build(int nd, int nl, int nr) {
		if (nl == nr) {
			mx[nd] = sum[nd] = arr[nl];
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		update(nd);
	}
}tree;
struct _Main {
	_Main() {
		int l, r, op, Qn, n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		tree.build(1, 1, n);
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(l); read(r);
			if (l > r) swap(l, r);
			if (op == 0) {
				tree.change(1, 1, n, l, r);
			} else {
				printf("%lld\n", tree.query(1, 1, n, l, r));
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}bzoj3038;
}
