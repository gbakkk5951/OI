using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstdio>
namespace OI {
typedef long long lld;
const int DST = 0, NXT = 1, VAL = 2;
const int MXN = 250010;

int dfn[MXN];
bool cmp (int a, int b) {
	return dfn[a] < dfn[b];
}
struct _Main {
	int f[MXN][18], h[MXN], dfncnt; 
	int r[MXN];
	lld mncst[MXN];
	void dfs(int nd, int fa, lld mnval) {
		mncst[nd] = mnval;
		f[nd][0] = fa;
		h[nd] = h[fa] + 1;
		dfn[nd] = ++dfncnt;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd, min((lld)edge[e][VAL], mnval));
			}
		}
		r[nd] = dfncnt;
	}
	lld dp[MXN];
	int arr[MXN];
	int tp[MXN];
	int vf[MXN];
	_Main() {
		int n, Qn, a, b, c, vn, ovn;
		read(n);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		dfs(1, 0, 1LL << 62);
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(vn);
			for (int i = 1; i <= vn; i++) {
				read(arr[i]);
				tp[arr[i]] = 1;
			}
			sort(arr + 1, arr + vn + 1, cmp);
			ovn = vn;
			for (int i = 2; i <= ovn; i++) {
				int lca = getlca(arr[i], arr[i - 1]);
				if (tp[lca] == 0) {
					arr[++vn] = lca;
					tp[lca] = 2;
				}	
			}
			if (tp[1] == 0) {
				arr[++vn] = 1;
				tp[1] = 2;
			}
			sort(arr + 1, arr + vn + 1, cmp);
			static int stk[MXN];
			int top = 0;
			stk[++top] = 1;
			for (int i = 2; i <= vn; i++) {
				a = arr[i];
				while (r[stk[top]] < dfn[a]) {
					top--;
				}
				vf[a] = stk[top];
				stk[++top] = a;
			}
			for (int i = vn; i >= 1; i--) {
				a = arr[i];
				if (tp[a] == 2) {
					dp[a] = min(dp[a], mncst[a]);
				} else {
					dp[a] = mncst[a];
				}
				dp[vf[a]] += dp[a];//dp不是mncst
				dp[a] = tp[a] = 0;
			}
			printf("%lld\n", dp[0]);
			dp[0] = 0;
		}
	}
	
	int getlca(int a, int b) {
		if (h[a] < h[b]) swap(a, b);
		for (int I = 17; I >= 0; I--) {
			if (h[a] - (1 << I) >= h[b]) {
				a = f[a][I];
			}
		}
		if (a == b) return a;
		for (int I = 17; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I];
				b = f[b][I];
			}
		}
		return f[a][0];
	}
	
	int head[MXN], edge[MXN << 1][3];
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
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
