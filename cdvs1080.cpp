using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
namespace OI {
const int MXN = 100005;
int arr[MXN];
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

struct SegTree {
	int node[270000];
	void init (int nd, int nl, int nr) {
		if (nl == nr) {
			node[nd] = arr[nl];
			return;
		}
		int mid = nl + nr >> 1;
		init(ls[nd], nl, mid);
		init(rs[nd], mid + 1, nr);
		node[nd] = node[ls[nd]] + node[rs[nd]];
	}
	void change(int nd, int nl, int nr, int pos, int v) {
		if (nl == nr) {
			node[nd] += v;
			return;
		}
		int mid = nl + nr >> 1;
		if (pos <= mid) change(ls[nd], nl, mid, pos, v);
		else change(rs[nd], mid + 1, nr, pos, v);
		node[nd] = node[ls[nd]] + node[rs[nd]];
	}
	
	int query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return node[nd];
		}
		int mid = nl + nr >> 1;
//		int ret = 0;
//		if (l <= mid) ret += query(ls[nd], nl, mid, l, r);
//		if (r > mid) ret += query(rs[nd], mid + 1, nr, l, r);
//		return ret;
		return (l <= mid ? query(ls[nd], nl, mid, l, r) : 0)
			 + (r > mid ? query(rs[nd], mid + 1, nr, l, r) : 0);
	}
}tree;
struct _Main {
	_Main() {
		srand(time(0));
		int n, Qn;
		int op, pos, v, l, r, p = 0;
		float t1;
		n = 1e5;
//		read(n); 
//		for (int i = 1; i <= n; i++) {
//			read(arr[i]);
//		}
		tree.init(1, 1, n);
//		read(Qn);
		Qn = 5000000;
		t1 = clock();
		for (int Q = 1; Q <= Qn; Q++) {
//			read(op);
//			op = 2;
//			if (op == 1) {
//				read(pos); read(v);
//				tree.change(1, 1, n, pos, v);
//			} else {
//				read(l); read(r);
				l = rand();
				r = n - rand();
				p += tree.query(1, 1, n, l, r);
//				printf("%d\n", tree.query(1, 1, n, l, r));
//			}
		}
		if (p != 0) printf("???");
		printf("uses %lfms\n", clock() - t1);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : 1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}cdvs1080;
}
