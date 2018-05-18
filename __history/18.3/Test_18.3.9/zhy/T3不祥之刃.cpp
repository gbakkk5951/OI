using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
namespace OI {
typedef long long lld;
const int TAG = 1, MIN = 0;
int arr[500005];
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
class SegTree {
public:
	int node[1050000][2];
	inline void add(int nd, int val) {
		node[nd][MIN] += val;
		node[nd][TAG] += val;
	}
	void push(int nd) {
		add(ls[nd], node[nd][TAG]);
		add(rs[nd], node[nd][TAG]);
		node[nd][TAG] = 0;
	}
	void update(int nd) {
		node[nd][MIN] = min(node[ls[nd]][MIN], node[rs[nd]][MIN]);
	}
	void build(int nd, int nl, int nr) {
		if (nl == nr) {
			node[nd][MIN] = arr[nl];
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
	int query(int nd, int nl, int nr, int l, int r) {
		if (node[nd][MIN] > 1 || l <= nl && nr <= r) {
			return node[nd][MIN];
		}
		int ans = 2, mid = nl + nr >> 1;
		push(nd);
		if (l <= mid) {
			ans = min(ans, query(ls[nd], nl, mid, l, r));
		} 
		if (r > mid) {
			ans = min(ans, query(rs[nd], mid + 1, nr, l, r));
		}
		return ans;
	}
	
}tree;

struct Pupil {
	int pos;
	lld val;
	bool operator > (const Pupil &b) const {
		return val > b.val;
	}
}p[500005];
int pidx;
struct _Main {
	char job[5];
	_Main() {
		int n, M, cnt = 0;
		lld coin = 0;
		read(n); read(M);
		for (int i = 1; i <= n; i++) {
			scanf("%s", job);
			if (job[0] == 'p') {
				read(arr[i]);
			} else {
				arr[i] = 1e6;
				read(p[++pidx].val);
				p[pidx].pos = i;
			}
		}
		tree.build(1, 1, n);
		sort(p + 1, p + pidx + 1, greater<Pupil>());
		for (int i = 1; i <= pidx; i++) {
			if (cnt >= M && p[i].val <= 0) break;
			if (tree.query(1, 1, n, p[i].pos, n) > 1) {
				cnt++;
				coin += p[i].val;
				tree.change(1, 1, n, p[i].pos, n, -1);
			}
		}
		if (cnt < M) {
			coin = -1;
		}
		printf("%lld", coin);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
}T3;

}
// >=都算死， 所以最低合法数量为2 
