using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm> 
#include <vector>
namespace OI {
typedef long long lld;
const int INF = 0x3f3f3f3f;
const int MXN = 250050;
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
int node[530000];
int n;
vector <int> id[MXN];
int vid[MXN];
	lld r[MXN], d[MXN], ds[MXN];
	int c[MXN], m[MXN], ms[MXN];


class SegTree {
public:
	
	void insert(int pos, int val, int id_) {
		id[pos].push_back(id_);
		int nd = 1, nl = 1, nr = n, mid;
		node[nd] = min(node[nd], val);
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos > mid) {
				nl = mid + 1;
				nd = rs[nd]; // 没改nd 
			} else {
				nr = mid;
				nd = ls[nd];
			}
			node[nd] = min(node[nd], val);//叶子没赋值 
		}
	}
	void query(int nd, int nl, int nr, int x, int y, int arr[], int &idx) {
		if (nl == nr) {
			int t;
			for (; vid[nl] < id[nl].size() && m[t = id[nl][vid[nl]]] <= y; vid[nl]++) {
				arr[++idx] = t;
			}
			node[nd] = (vid[nl] == id[nl].size()) ? INF : t;
			return;
		}
		int mid = nl + nr >> 1;
		if (node[ls[nd]] <= y) {
			query(ls[nd], nl, mid, x, y, arr, idx);
		}
		if (mid < x && node[rs[nd]] <= y) {
			query(rs[nd], mid + 1, nr, x, y, arr, idx);
		}
		node[nd] = min(node[ls[nd]], node[rs[nd]]);
	}
}tree;
bool cmp(int a, int b) {
	return m[a] < m[b];
}
struct _Main{

	lld pf (lld a) {
		return a * a;
	}
template <typename Type>
	int getrk(Type arr[], int len, Type v) {
		return lower_bound(arr + 1, arr + len + 1, v) - arr;
	}
	int ans;
	void prepro() {
		lld x0, y0, x, y;
		read(x0); read(y0); read(c[0]); read(r[0]); read(n);
		r[0] = pf(r[0]);
		for (int i = 1; i <= n; i++) {
			read(x); read(y);
			d[i] = pf(x - x0) + pf (y - y0);
			read(m[i]); read(c[i]); read(r[i]); 
			r[i] = pf(r[i]);
			ms[i] = m[i]; ds[i] = d[i];
		}
		sort(ms + 1, ms + n + 1);
		sort(ds + 1, ds + n + 1);
		for (int i = 1; i <= n; i++) {
			m[i] = getrk(ms, n, m[i]);
			d[i] = getrk(ds, n, d[i]);
		}
		memset(node, 63, min(530000 - 5, n * 4) * sizeof(int)); //mn没赋初值 
		for (int i = 1; i <= n; i++) {
			tree.insert(d[i], m[i], i);
		}
		for (int i = 1; i <= n; i++) {
			sort(id[i].begin(), id[i].end(), cmp);
		}
	}
	int arr[MXN];
	void solve() {
		for (int i = 0; i <= ans; i++) {
			int x = upper_bound(ds + 1, ds + n + 1, r[arr[i]]) - ds - 1;
			int y = upper_bound(ms + 1, ms + n + 1, c[arr[i]]) - ms - 1;
			if (min(x, y) <= 0) continue;
			if (node[1] <= y) {
				tree.query(1, 1, n, x, y, arr, ans);
			}
		}
	}

	_Main() {
		prepro();
		solve();
		printf("%d", ans);
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
}ezoj1172;

}
