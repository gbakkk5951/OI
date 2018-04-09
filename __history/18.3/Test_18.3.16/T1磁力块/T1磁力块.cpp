using namespace std;
int main() {}
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <vector>
namespace OI {
const int MXN = 250005; 
typedef long long lld;
lld d[MXN], ds[MXN], r[MXN];
int m[MXN], ms[MXN], c[MXN];
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
struct SNode {
	SNode *s[2];
	int sum, id;
}pool[(int)2e7];
vector <int> idv[MXN];

int pidx;
SNode *new_() {
	return &pool[pidx++];
}
struct Node {
	SNode *root;
}node[530000];
struct _Main {
	int arr[MXN], ans, idx; //¿¼ÂÇÖØ¸´£¬ idx ¿ÉÄÜ < ans 
	char vis[MXN];
	int n;
	lld pf(lld a) {
		return a * a;
	}
	void subinsert(SNode *nd, int y, int id) {
		int mid, spo, nl = 1, nr = n;
		nd->sum++;
		while (nl != nr) {
			mid = nl + nr >> 1;
			if (spo = y > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (nd->s[spo] == 0) {
				nd->s[spo] = new_();
			}
			nd = nd->s[spo];
			nd->sum++;
		}
		if (id) {
			if (nd->id == 0) {
				nd->id = id;
			}	
			idv[nd->id].push_back(id);
		}
		
		
	}
	void insert(int x, int y, int id) {
		int nl = 1, nr = n, nd = 1, mid;
		while (1) {
			if (node[nd].root == 0) {
				node[nd].root = new_();
			}
			subinsert(node[nd].root, y, id * (nl == nr));
			if (nl == nr) {
				break;
			}
			mid = nl + nr >> 1;
			if (x <= mid) {
				nr = mid;
				nd = ls[nd];
			} else {
				nl = mid + 1;
				nd = rs[nd];
			}
		}
	}
	int subgot(SNode *nd, int nl, int nr, int y) {
		if (nd && nd->sum) {
			int ret = 0;
			if (nl == nr) {
				if (nd->id) {
					ans += nd->sum;
					for (int i = 0; i < nd->sum; i++) {
						arr[++idx] = idv[nd->id][i];
					}
				}
				int ret = nd->sum;
				nd->sum = 0;
				return ret;
			}
			int mid = nl + nr >> 1;
			ret += subgot(nd->s[0], nl, mid, y);
			if (mid < y) {
				ret += subgot(nd->s[1], mid + 1, nr, y);
			}
			nd->sum = (nd->s[0] ? nd->s[0]->sum : 0) + (nd->s[1] ? nd->s[1]->sum : 0);
			return ret;
		}
		return 0;
	}
	void got(int nd, int nl, int nr, int x, int y) {
		int mid = nl + nr >> 1;
		if (nr <= x) {
			if (subgot(node[nd].root, 1, n, y) == 0) {
				return;
			}
		}
		got(ls[nd], nl, mid, x, y);
		if (mid < x) {
			got(rs[nd], mid + 1, nr, x, y);
		}
	}
	void prepro() {
		lld x0, y0, x, y;
		read(x0); read(y0);
		read(c[0]); read(r[0]); r[0] = pf(r[0]);
		read(n);
		for (int i = 1; i <= n; i++) {
			read(x); read(y);
			d[i] = pf(x - x0) + pf(y - y0);
			read(m[i]);
			read(c[i]); 
			read(r[i]); r[i] = pf(r[i]);
			ms[i] = m[i];
			ds[i] = d[i];
		}
		sort(ms + 1, ms + n + 1);
		sort(ds + 1, ds + n + 1);
		for (int i = 1; i <= n; i++) {
			m[i] = lower_bound(ms + 1, ms + n + 1, m[i]) - ms;
			d[i] = lower_bound(ds + 1, ds + n + 1, d[i]) - ds;
		}
		for (int i = 1; i <= n; i++) {
			insert(d[i], m[i], i);
		}
	}
	void solve() {
		for (int i = 0; i <= idx; i++) {
			int x = upper_bound(ds + 1, ds + n + 1, r[arr[i]]) - ds - 1;
			int y = upper_bound(ms + 1, ms + n + 1, c[arr[i]]) - ms - 1;
			if (min(x, y) <= 0) {
				continue;
			}
			got(1, 1, n, x, y);
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
}T1;	
	
}
