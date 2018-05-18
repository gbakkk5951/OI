using namespace std;
int main(){}
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstdlib>
namespace OI {
typedef double lf;
typedef complex<lf> com;
const int MXN = 200005;
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
lf arr[MXN];
struct SegTree {
	SegTree() {
		node = (com *)calloc(530000, 16);
		tag = (com *)calloc(530000, 16);
	}
	com *node, *tag;
	void mul(int nd, const com &val) {
		tag[nd] *= val;
		node[nd] *= val;
	}
	void push(int nd) {
		mul(ls[nd], tag[nd]);
		mul(rs[nd], tag[nd]);
		tag[nd].imag(0); tag[nd].real(1);
	}
	void update(int nd) {
		node[nd] = node[ls[nd]] + node[rs[nd]];
	}
	void build(int nd, int nl, int nr) {
		tag[nd].imag(0); tag[nd].real(1);
		if (nl == nr) {
			node[nd].real(cos(arr[nl]));
			node[nd].imag(sin(arr[nl]));
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		update(nd);
	}
	void change(int nd, int nl, int nr, int l, int r, com &val) {
		if (l <= nl && nr <= r) {
			mul(nd, val);
			return;
		}
		push(nd);
		int mid = nl + nr >> 1;
		if (l <= mid) {
			change(ls[nd], nl, mid, l, r, val);
		}
		if (r > mid) {
			change(rs[nd], mid + 1, nr, l, r, val);
		}
		update(nd);
	}
	lf query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return node[nd].real();
		}
		push(nd);
		lf sum = 0;
		int mid = nl + nr >> 1;
		if (l <= mid) {
			sum += query(ls[nd], nl, mid, l, r);
		}
		if (r > mid) {
			sum += query(rs[nd], mid + 1, nr, l, r);
		}
		return sum;
	}
}tree;

struct _Main {
	_Main() {
		int Tn, n, Qn;
		int op, l, r;
		lf v;
		com tmp;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			printf("Case #%d:\n", T);
			read(n); read(Qn);
			for (int i = 1; i <= n; i++) {
				scanf("%lf", arr + i);
			}
			tree.build(1, 1, n);
			for (int Q = 1; Q <= Qn; Q++) {
				read(op); read(l); read(r);
				if (op == 1) {
					scanf("%lf", &v);
					tmp.real(cos(v)); tmp.imag(sin(v));
					tree.change(1, 1, n, l, r, tmp);
				} else {
					printf("%.3f\n", round(tree.query(1, 1, n, l, r) * 1000.0) / 1000.0);
				}
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
}T1;
}
