using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 200010;
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
struct SegTree {
	lld node[530000], tag[530000];
	void add(int nd, int v, int nl, int nr) {
		tag[nd] += v;
		node[nd] += (nr - nl + 1LL) * v;
	}
	void push(int nd, int nl, int nr) {
		if (tag[nd]) {
			int mid = nl + nr >> 1;
			add(ls[nd], tag[nd], nl, mid);
			add(rs[nd], tag[nd], mid + 1, nr);
			tag[nd] = 0;
		}
	}
	void update(int nd) {
		node[nd] = node[ls[nd]] + node[rs[nd]];
	}
	void change(int nd, int nl, int nr, int l, int r, int v) {
		if (l <= nl && nr <= r) {
			add(nd, v, nl, nr);
			return;
		}
		push(nd, nl, nr);
		int mid = nl + nr >> 1;
		if (l <= mid) {
			change(ls[nd], nl, mid, l, r, v);
		}
		if (r > mid) {
			change(rs[nd], mid + 1, nr, l, r, v);
		}
		update(nd);
	}
	lld query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return node[nd];
		}
		push(nd, nl, nr);
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
}tree, t2;

struct _Main {
	
	int arr[MXN << 1];
	int n;
	lld ans;
	_Main() {
		freopen("counter.in", "r", stdin);
		freopen("counter.out", "w", stdout);
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		memmove(arr + n + 1, arr + 1, n * sizeof(int));
		for (int i = 1; i <= n; i++) {
			if (arr[i] != 1 && i != 1) {
				tree.change(1, 1, n, arr[i], arr[i], t2.query(1, 1, n, 1, arr[i] - 1));
			}
			if (arr[i] != n && i != n) {
				t2.change(1, 1, n, arr[i], arr[i], 1);
			} 
		}
		if (arr[n] != 1) ans += tree.query(1, 1, n, 1, arr[n] - 1);
		
		for (int i = n + 1; i <= (n << 1) - 1; i++) {
			if (arr[i] != n) tree.change(1, 1, n, arr[i] + 1, n, -1);
			if (arr[i] != 1) {
				ans += tree.query(1, 1, n, 1, arr[i] - 1);
				tree.change(1, 1, n, arr[i], arr[i], arr[i] - 1);	
			}
		}
		printf("%lld", ans);
		fclose(stdout);
	}
	
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}counter;

}


