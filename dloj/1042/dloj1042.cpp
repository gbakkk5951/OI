using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int PW = 17;
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
lld pow[PW];
struct Node {
	int cnt[PW][2];
	int tag;
};
int arr[100010];

struct SegTree {
	Node node[270000];
	void add(int nd, int val) {
		node[nd].tag ^= val;
		for (int i = 0; i < PW; i++) {
			if (val & 1) swap(node[nd].cnt[i][0], node[nd].cnt[i][1]);
			val >>= 1;
		}
	}
	void setval(int nd, int val) {
		for (int i = 0; i < PW; i++) {
			int t = val & 1;
			node[nd].cnt[i][t] = 1;
			node[nd].cnt[i][t ^ 1] = 0;
			val >>= 1;
		}
	}
	void push(int nd) {
		int t;
		if (t = node[nd].tag) {
			add(ls[nd], t);
			add(rs[nd], t);
			node[nd].tag = 0;
		}
	}
	void update(int nd) {
		for (int i = 0; i < PW; i++) {
			for (int j = 0; j < 2; j++) {
				node[nd].cnt[i][j] = node[ls[nd]].cnt[i][j] + node[rs[nd]].cnt[i][j];
			}
		}
	}
	lld calc(int nd) {
		lld ret = 0;
		for (int i = 0; i < PW; i++) {
			ret += node[nd].cnt[i][1] * pow[i];
		}
		return ret;
	}
	void build(int nd, int nl, int nr) {
		if (nl == nr) {
			setval(nd, arr[nl]);
			return;
		}
		int mid = nl + nr >> 1;
		build(ls[nd], nl, mid);
		build(rs[nd], mid + 1, nr);
		update(nd);
	}
	void change(int nd, int nl, int nr, int l, int r, int val) {
		if (l <= nl && nr <= r) {
			add(nd, val);
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
	
	lld query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return calc(nd);
		}
		push(nd);//ÍüÁËpush 
		int mid = nl + nr >> 1;
		lld ret = 0;
		if (l <= mid) {
			ret += query(ls[nd], nl, mid, l, r);
		}
		if (r > mid) {
			ret += query(rs[nd], mid + 1, nr, l, r);
		}
		return ret;
	}
}tree;

struct _Main {	
	int Qn, n;
	void prepro() {
		pow[0] = 1;
		for (int i = 1; i < PW; i++) {
			pow[i] = pow[i - 1] << 1;
		}
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		tree.build(1, 1, n);
	}
	void solve() {
		int op, l, r, v;
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(l); read(r);
			if (op == 1) {
				printf("%lld\n", tree.query(1, 1, n, l, r));
			} else {
				read(v);
				tree.change(1, 1, n, l, r, v);
			}
		}
	}
	_Main() {
		prepro();
		solve();
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
}dloj1042;
}
