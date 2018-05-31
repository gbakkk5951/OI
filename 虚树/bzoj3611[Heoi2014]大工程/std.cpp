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
const int DST = 0, NXT = 1;
const int MXN = 1e6 + 10;
int dfn[MXN], dfnidx;
int r[MXN];
bool cmp(int a, int b) {
	return dfn[a] < dfn[b];
}
struct _Main {
	int n;
	int mx[MXN][3];
	int mn[MXN][3];
	int vf[MXN];
	int tp[MXN];
	int vsize[MXN];
	int arr[MXN];
	_Main() {
		int n, Qn, a, b;
		
		read(n);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		dfs1(1, 0);
		dfs2(1, 0, 1);
		read(Qn);
		for (int i = 1; i <= n; i++) {//别忘了初始化
			memset(mn[i], 63, sizeof(mn[i]));
		}
		
		int vn, ovn, lca;
		lld totlen;
		int mnlen, mxlen;
		for (int Q = 1; Q <= Qn; Q++) {
			mnlen = n - 1;
			mxlen = 0;
			totlen = 0;
			read(vn);
			if (vn <= 1) {
				printf("0 0 0\n");
				continue;
			} 
			ovn = vn;
			for (int i = 1; i <= vn; i++) {
				read(arr[i]);
				tp[arr[i]] = 1;
			}
			sort(arr + 1, arr + vn + 1, cmp);
			for (int i = 2; i <= ovn; i++) {
				lca = getlca(arr[i], arr[i - 1]);
				if (!tp[lca]) {
					tp[lca] = 2;
					arr[++vn] = lca;
				}
			}
			sort(arr + 1, arr + vn + 1, cmp);
			static int stk[MXN];
			int top = 0;
			stk[++top] = arr[1];
			for (int i = 2; i <= vn; i++) {
				a = arr[i];
				while (r[stk[top]] < dfn[a]) {
					--top;
				}
				vf[a] = stk[top];
				stk[++top] = a;
			}
			for (int i = vn; i >= 1; i--) {//i++ 还行
				a = arr[i]; b = vf[a];
				vsize[a] += tp[a] == 1;//虚节点不要
				totlen += (lld)vsize[a] * (ovn - vsize[a]) * (h[a] - h[b]);//ovn不是vn 不要把虚点算上
				if (tp[a] == 1) {
					mnlen = min(mnlen, mn[a][0]);
				} else {
					mnlen = min(mnlen, mn[a][0] + mn[a][1]);
				}
				mxlen = max(mxlen, mx[a][0] + mx[a][1]);
				
				vsize[b] += vsize[a];
				mx[b][2] = mx[a][0] + h[a] - h[b];
				sort(mx[b], mx[b] + 3, greater<int>() );
				if (tp[a] == 2) {
					mn[b][2] = mn[a][0] + h[a] - h[b];
				} else {
					mn[b][2] = h[a] - h[b];
				}
				sort(mn[b], mn[b] + 3);
				
				tp[a] = 0;
				vsize[a] = 0;
				memset(mx[a], 0, sizeof(mx[a]));
				memset(mn[a], 63, sizeof(mn[a]));
				vf[a] = 0;//a写成i了
			}
			printf("%lld %d %d\n", totlen, mnlen, mxlen);
		}
	}
	int h[MXN], f[MXN];
	int size[MXN], cho[MXN], top[MXN];
	void dfs2(int nd, int fa, int tp) {
		top[nd] = tp;
		int t;
		if (cho[nd]) dfs2(cho[nd], nd, tp);
		else return;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && t != cho[nd]) {
				dfs2(t, nd, t);
			}
		}
	}
	
	void dfs1(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd] = fa;
		size[nd] = 1;
		dfn[nd] = ++dfnidx;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs1(t, nd);
				size[nd] += size[t];
				if (size[t] > size[cho[nd]]) {
					cho[nd] = t;
				}
			}
		}
		r[nd] = dfnidx;
	}
	
	int getlca(int a, int b) {
		while(top[a] != top[b]) {
			if (h[top[a]] < h[top[b]]) {
				swap(a, b);
			}
			a = f[top[a]];
		}
		return h[a] < h[b] ? a : b;
	}
	
	int head[MXN], edge[MXN << 1][2];
	int eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
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
