using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 500000, MXE = 9e6;
const int DST = 0, NXT = 1, VAL = 2;
const int MXV = 1e9;
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
int dis[MXN];
int head[MXN], edge[MXE][3];
int ind[MXN];
int id[(int) 1e5 + 10];
int eidx;

void add(int a, int b, int c) {
	++ind[b];
	++eidx;
	edge[eidx][DST] = b;
	edge[eidx][VAL] = c;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
struct SegTree {
	void link(int nd, int nl, int nr, int l, int r, int dst) {
		if (l <= nl && nr <= r) {//nl 和 l, nr 和 r弄反
			add(nd, dst, 1);
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) link(ls[nd], nl, mid, l, r, dst);
		if (r > mid) link(rs[nd], mid + 1, nr, l, r, dst);
	}
	void build(int fa, int nd, int l, int r) {
		int mid = l + r >> 1;
		if (fa) add(nd, fa, 0);
		if (l == r)  {
			id[l] = nd;
			return;
		}
		build(nd, ls[nd], l, mid);
		build(nd, rs[nd], mid + 1, r);
	}
}tree;
int sure[(int)1e5 + 10];
struct _Main {
	int n, s, m;
	int arr[(int) 1e5 + 10];
	int vn;
	_Main() {
		int a, b;
		read(n); read(s); read(m); 
		tree.build(0, 1, 1, n);
		for (vn = 1; vn < n; vn <<= 1);
		vn <<= 1;
		//vn = id[n];//idn不一定最大23333
		for (int i = 1; i <= s; i++) {
			read(a); read(b);
			sure[a] = b;
		}
		for (int i = 1; i <= m; i++) {
			int kn, l, r;
			++vn;
			read(l); read(r); read(kn);
			for (int i = 1; i <= kn; i++) {
				read(arr[i]);
				add(vn, id[arr[i]], 0);
			}
			arr[0] = l - 1; arr[kn + 1] = r + 1;
			for (int j = 1; j <= kn + 1; j++) {
				if (arr[j] - arr[j - 1] > 1) {
					tree.link(1, 1, n, arr[j - 1] + 1, arr[j] - 1, vn);
				}
			}
		}
		fill(dis + 1, dis + vn + 1, 1);//神Tm的arr
		for (int i = 1; i <= n; i++) {
			if (sure[i]) dis[id[i]] = sure[i];
		}
		queue<int> q;
		for (int i = 1; i <= vn; i++) {
			if (ind[i] == 0 && head[i]) q.push(i);
		}
		int nd, t;
		while (!q.empty()) {
			nd = q.front();
			q.pop();
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				if (--ind[t] == 0) {
					q.push(t);
				}
				dis[t] = max(dis[t], dis[nd] + edge[e][VAL]);
				if (dis[t] >= MXV) {
					printf("NIE");
					return;
				}
			}
		} 
		
		for (int i = 1; i <= n; i++) {
			if (sure[i] && sure[i] != dis[id[i]]) {//sure里面没有id
				printf("NIE");
				return;
			}
		}
		for (int i = 1; i <= vn; i++) {
			if (ind[i]) {
				printf("NIE");
				return;
			}
		}
		printf("TAK\n");
		for (int i = 1; i <= n; i++) {
			printf("%d ", dis[id[i]]);
		}
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
}std;
}
