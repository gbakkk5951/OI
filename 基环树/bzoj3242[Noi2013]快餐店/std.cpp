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
const int MXN = 1e5 + 10;
const int DST = 0, NXT = 1, VAL = 2;
struct _Main {
	lld ans;
	int n;
	int lpl;
	int nev[MXN], pev[MXN];
	int lpa[MXN], lpid[MXN];
	lld mx[MXN][3];
	lld pmx[MXN], nmx[MXN];//1到i,i到lpl 之间最长路径
	lld psum[MXN], nsum[MXN];//到1最长的路， 到k最长的路;
	_Main() {
		int a, b, c, t;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		tarjan(1, 0);
		lpa[0] = lpa[lpl];
		lpa[lpl + 1] = lpa[1];
		for (int i = 1; i <= lpl; i++) {
			for (int e = head[lpa[i]]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				if (t == lpa[i - 1]) {
					pev[i] = edge[e][VAL];
				} else
				if (t == lpa[i + 1]) {
					nev[i] = edge[e][VAL];
				}
			}
		}
		for (int i = 1; i <= lpl; i++) {
			getdp(lpa[i], 0);
		}
		lld mxv = 0, sum = 0;
		for (int i = 1; i <= lpl; i++) {
			a = lpa[i];
			psum[i] = max(psum[i - 1], sum + mx[a][0]);
			pmx[i] = max(pmx[i - 1], sum + mx[a][0] + mxv);
			mxv = max(mxv, -sum + mx[a][0]);
			sum += nev[i];
		}
		mxv = sum = 0;
		for (int i = lpl; i >= 1; i--) {
			a = lpa[i];
			nsum[i] = max(nsum[i + 1], sum + mx[a][0]);
			nmx[i] = max(nmx[i + 1], sum + mx[a][0] + mxv);
			mxv = max(mxv, -sum + mx[a][0]);
			sum += pev[i];
		}
		lld mn = 1e18, tmp;
		for (int i = 1; i <= lpl - 1; i++) {
			tmp = max(pmx[i], nmx[i + 1]);
			tmp = max(tmp, psum[i] + nsum[i + 1] + nev[lpl]);//nev的下标应该是链位置而不是原点的编号
			mn = min(mn, tmp);
		}
		mn = min(mn, pmx[lpl]);
		ans = max(ans, mn);
		printf("%.1f", ans / 2.0);
	}
	void getdp(int nd, int fa) {
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !lpid[t]) {
				getdp(t, nd);
				mx[nd][2] = mx[t][0] + edge[e][VAL];//神Tm mx[nd][3]
				sort(mx[nd], mx[nd] + 3, greater<lld>());//greater<int>还行
			}
		}
		ans = max(ans, mx[nd][0] + mx[nd][1]);
	}
	
	int dfn[MXN], dfnidx, low[MXN];
	int vis[MXN], instk[MXN], stk[MXN], top;
	void tarjan(int nd, int fa) {
		low[nd] = dfn[nd] = ++dfnidx;
		vis[nd] = instk[nd] = 1;
		stk[++top] = nd;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!vis[t]) {
				tarjan(t, nd);
				low[nd] = min(low[nd], low[t]);
			} else if (t != fa && instk[t]) {
				low[nd] = min(low[nd], dfn[t]);
			}
		}
		if (low[nd] == dfn[nd]) {
			if (stk[top] == nd) {
				instk[stk[top--]] = 0;
			} else {
				do {
					instk[t = lpa[++lpl] = stk[top--]] = 0;
					lpid[t] = lpl;
				} while(t != nd);
			}
		}
	}
	
	int eidx, head[MXN], edge[MXN << 1][3];
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
