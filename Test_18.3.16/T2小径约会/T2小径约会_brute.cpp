using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
const int MXN = 100010;
const int DST = 0, NXT = 1, VAL = 2;
struct _Main {
	int head[MXN], edge[MXN << 1][3];
	int eidx;
	void add(int src, int dst, int val) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		edge[eidx][VAL] = val;
		head[src] = eidx;
	}
	int l, r;
	int juhua() {
		int mx = 0;
		for (int e = 1; e <= eidx; e++) {
			mx = max(mx, edge[e][VAL]);
		}
		return mx;
	}
	int h[MXN];
	int fv[MXN];
	int f[MXN];
	int arr[MXN];
	int getarr(int a, int b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		int idx = 0;
		while (h[a] > h[b]) {
			arr[idx++] = fv[a];
			a = f[a];
		}
		while (a != b) {
			arr[idx++] = fv[a];
			arr[idx++] = fv[b];
			a = f[a]; b = f[b];
		}
		return idx;
	}
	void dfs(int nd, int fa) {
		f[nd] = fa;
		h[nd] = h[fa] + 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (edge[e][DST] != fa) {
				fv[edge[e][DST]] = edge[e][VAL];
				dfs(edge[e][DST], nd);
			}
		}
	}
	int n;
	int brute() { // l >= 3
		dfs(1, 0);
		int len;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				len = getarr(i, j);
				if (len >= l && len <= r) {
					sort(arr, arr + len);
					if (len & 1) {
						ans = max(ans, arr[len >> 1]);
					} else {
						ans = max(ans, arr[len + 1 >> 1]);
					}
				}
			}
		}
		return ans;
	}
	_Main() {
		read(n); read(l); read(r);
		int a, b, c;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		if (l <= 2) {
			printf("%d", juhua());
		} else {
			printf("%d", brute());
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
}T2;
}
