#pragma GCC optimize(2)
using namespace std;
int main() {}
#include <cstring>
#include <vector>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int MXN = 1e5 + 10;
struct _Main {
	vector<int> son[MXN];
	int f[MXN], h[MXN], bl[MXN], wh[MXN];
	void inline add(int a, int b) {
		son[a].push_back(b);
		son[b].push_back(a);
	}
	int n, Qn;
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd] = fa;
		for (int e = 0; e < son[nd].size(); e++) {
			if (son[nd][e] != fa) {
				dfs(son[nd][e], nd);
			} else {
				son[nd].erase(son[nd].begin() + e);
				--e;
			}
		}
	}
	int getans(int u, int v, int l, int r) {
		int ret = 0;
		int hu, hv;
		if (h[u] < h[v]) {
			swap(u, v);
		}
		hu = h[u]; hv = h[v];
		while (hu > hv && ret < mxb) {
			if (l <= wh[u] && wh[u] <= r) {
				ret = max(ret, bl[u]);
			}
			u = f[u];
			--hu;
		}
		while (u != v && ret < mxb) {
			if (l <= wh[u] && wh[u] <= r) {
				ret = max(ret, bl[u]);
			}
			if (l <= wh[v] && wh[v] <= r) {
				ret = max(ret, bl[v]);
			}
			u = f[u]; v = f[v];
		}
		if (l <= wh[u] && wh[u] <= r) {
			ret = max(ret, bl[u]);
		}
		return ret;
	} 
	void setb(int nd, int val) {
		bl[nd] = val;
		for (int i = 0; i < son[nd].size(); i++) {
			setb(son[nd][i], val);
		}
	}
	void setw(int nd, int val) {
		wh[nd] = val;
		for (int i = 0; i < son[nd].size(); i++) {
			setw(son[nd][i], val);
		}
	}
	char op[100005][10];
	int a[100005], b[100005], l[100005], r[100005];
	int mxw, mnw, mxb;
	_Main() {
		freopen("rabit.in", "r", stdin);
		freopen("rabit.out", "w", stdout);
		int qn = 0;
		int u, v;
		read(n); read(Qn);
		mxb = 0; mnw = 1e9 + 10; mxw = -1;
		for (int i = 1; i <= n - 1; i++) {
			read(u); read(v);
			add(u, v);
		}
		dfs(1, 0);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op[Q]);
			read(a[Q]); read(b[Q]);
			if (op[Q][0] == 'Q') {
				read(l[Q]); read(r[Q]);
				++qn;
			}
		}
		if (qn > 0) for (int Q = 1; Q <= Qn; Q++) {
			if (op[Q][0] == 'Q') {
				if (l[Q] > mxw || r[Q] < mnw || l[Q] > r[Q]) {
					printf("0\n");
					continue;
				}
				printf("%d\n", getans(a[Q], b[Q], l[Q], r[Q]));
				if (--qn == 0) break;
			} else
			if (op[Q][6] == 'B') {
				setb(a[Q], b[Q]);
				mxb = max(mxb, b[Q]);
			} else {
				setw(a[Q], b[Q]);
				mxw = max(mxw, b[Q]);
				mnw = min(mnw, b[Q]);
			}
		}
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
}rabit;
}
