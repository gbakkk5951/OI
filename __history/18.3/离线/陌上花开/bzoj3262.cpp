using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdlib>
namespace OI {
const int MXN = 100010;
const int MXV = 200010;
int ans[MXN];
int n, mxv;
struct Tree {
	int node[MXV];
	void change(int nd, int val) {
		for (; nd <= mxv; nd += nd & (-nd)) {
			node[nd] += val;
		}
	}
	int query(int nd) {
		int sum = 0;
		for (; nd; nd -= nd & (-nd)) {
			sum += node[nd];
		}
		return sum;
	}
}tree;
struct Node {
	int x, y, z, cnt, mark, size;
	inline bool operator < (const Node &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return z < b.z;
	}
	inline bool operator == (const Node &b) const {
		return x == b.x && y == b.y && z == b.z;
	}
}q[MXN];
inline bool cmp (const Node &a, const Node &b) {
	if (a.y != b.y) return a.y < b.y;
	if (a.z != b.z) return a.z < b.z;
	return a.x < b.x;
}
struct _Main {
	Node arr[MXN];
	void merge(int l, int mid, int r) {
		int s = l, t = mid + 1, idx = 0;
		while (s <= mid && t <= r) {
			if (cmp(q[s], q[t])) {
				arr[idx++] = q[s++];
			} else {
				arr[idx++] = q[t++];
			}
		}
		if (s <= mid) {
			memmove(q + r - (mid - s), q + s, (mid - s + 1) * sizeof(Node));
		}
		memcpy(q + l, arr, idx * sizeof(Node));
	}
	void cdq(int l, int r) {
		int mid = l + r >> 1;
		if (l < mid) cdq(l, mid);
		if (mid + 1 < r) cdq(mid + 1, r);
		for (int i = l; i <= r; i++) {
			q[i].mark = i <= mid;
		}
//		sort(q + l, q + r + 1, cmp);
		merge(l, mid, r);
		/*
		printf("\n");
		for (int i = l; i <= r; i++) {
			printf("%d × (%d, %d, %d)\n", q[i].size, q[i].x, q[i].y, q[i].z);
		}		
		printf("\n");
		*/
		for (int i = l; i <= r; i++) {
			if (q[i].mark) {
				tree.change(q[i].z, q[i].size);
			} else {
				q[i].cnt += tree.query(q[i].z);
			}
		}
		if (l != 1 || r != n) for (int i = l; i <= r; i++) {
			if (q[i].mark) {
				tree.change(q[i].z, -q[i].size);
			}
		}
	}
	void prepro() {
		read(n); read(mxv);
		for (int i = 1; i <= n; i++) {
			read(q[i].x); read(q[i].y); read(q[i].z);
		}
		sort(q + 1, q + n + 1);
		for (int i = 1; i <= n; i += q[i].size) {
			for (int j = i; j <= n && q[j] == q[i]; j++) {
				q[i].size++;
			}
		}
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			if (q[i].size) {
				swap(q[i], q[++idx]);
			}
		}
		orgn = n;
		n = idx;
		/*for (int i = 1; i <= n; i++) {
			printf("%d × (%d, %d, %d)\n", q[i].size, q[i].x, q[i].y, q[i].z);
		}*/
	}
	int orgn;
	void solve() {
		if (n != 1) cdq(1, n);
		for (int i = 1; i <= n; i++) {
			ans[q[i].cnt + q[i].size - 1] += q[i].size;
		}
		for (int i = 0; i < orgn; i++) {//应该用原n 
			printf("%d\n", ans[i]);
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
}bzoj3262;
}
