using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
namespace OI {
typedef long long lld;
const int MXN = 100010;
struct LS {
	inline int operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	inline int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;

lld mod;
int arr[MXN];
struct SegTree {
	int sum[270000], sig[270000];
	void mul(int nd, int val) { // 若sig初值为0，可能挂掉 ? 
		sum[nd] = (lld)sum[nd] * val % mod;
		sig[nd] = (lld)sig[nd] * val % mod;
	}
	void push(int nd) {
		if (sig[nd] > 1) {
			mul(ls[nd], sig[nd]);
			mul(rs[nd], sig[nd]);
			sig[nd] = 1;
		}
	}
	void change(int nd, int nl, int nr, int l, int val) {
		if (l <= nl) {
			mul(nd, val);
			return;
		}
		push(nd);
		int mid = nl + nr >> 1;
		if (l <= mid) {
			change(ls[nd], nl, mid, l, val);
			mul(rs[nd], val);
		} else {
			change(rs[nd], mid + 1, nr, l, val);
		}
		update(nd);
	}
	void update(int nd) {
		sum[nd] = sum[ls[nd]] + sum[rs[nd]];
		sum[nd] >= mod && (sum[nd] %= mod);
	}
	void build(int nd, int nl, int nr) {
		sig[nd] = 1; //赋初值
		if (nl == nr) {
			sum[nd] = arr[nl] % mod; //没有%的话若n=1可能会挂
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		update(nd);
	}
	int query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return sum[nd];
		}
		push(nd);//没push
		int ret = 0;
		int mid = nl + nr >> 1;
		if (l <= mid) {
			ret += query(ls[nd], nl, mid, l, r);
		}
		if (r > mid) {
			ret += query(rs[nd], mid + 1, nr, l, r);
		}
		return ret >= mod ? ret % mod : ret;
	}
}tree;
struct Rg {
	int l, r, id;
	bool operator < (const Rg &b) const {
		return l < b.l;
	}
}rg[MXN];
int ans[MXN];
struct _Main {
	int n;
	_Main() {
		int k, Qn;
		read(n); read(Qn); read(k); read(mod);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		tree.build(1, 1, n);
		for (int Q = 1; Q <= Qn; Q++) {
			rg[Q].id = Q;
			read(rg[Q].l); read(rg[Q].r);
		}
		sort(rg + 1, rg + Qn + 1);
		int r = n;
		for (int Q = Qn; Q; Q--) {
			while(r > rg[Q].l) {
				tree.change(1, 1, n, r--, k);
			}
			ans[rg[Q].id] = tree.query(1, 1, n, rg[Q].l, rg[Q].r);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%d\n", ans[Q]);
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
}dloj1004;
}
