using namespace std;
int main() {}
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
namespace OI {
typedef long long lld;
const int INF = 0x3f3f3f3f;
const int MXN = 3e5 + 10;
const int DST = 0, NXT = 1;

int dfn[MXN]; 
char cmp(int a, int b) {
	return dfn[a] < dfn[b];
}
struct _Main {
	int org[MXN];
	int arr[MXN];
	int vf[MXN];
	int vsize[MXN];//有虚树节点的边之下的size
	int tp[MXN];
	int near[MXN], dis[MXN];
	int ans[MXN];
	_Main() {
		int a, b, n, Qn;
		read(n); 
		memset(dis, 63, (n + 1) * sizeof(int));
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		getlog(n - 1);
		dfs(1, 0);
		read(Qn);
		int ovn, vn, lca;
		for (int Q = 1; Q <= Qn; Q++) {
			read(vn); ovn = vn;
			for (int i = 1; i <= vn; i++) {
				read(arr[i]);
				tp[arr[i]] = 1;
			}
			memcpy(org, arr, (vn + 1) * sizeof(int));
			sort(arr + 1, arr + vn + 1, cmp);
			for (int i = 2; i <= ovn; i++) {
				lca = getlca(arr[i], arr[i - 1]);
				if (!tp[lca]) {
					tp[lca] = 2;
					arr[++vn] = lca;
				}
			}
			if (!tp[1]) {
				tp[1] = 2;
				arr[++vn] = 1;
			}
			sort(arr + 1, arr + vn + 1, cmp);
			//找vf
			static int stk[MXN];
			int top = 0;
			stk[++top] = arr[1];
			for (int i = 2; i <= vn; i++) {
				a = arr[i];
				while (r[stk[top]] < dfn[a]) {//while 不是if
					--top;
				}
				vf[a] = stk[top];
				stk[++top] = a;
			}
			
			//第一遍Dp
			int td;
			for (int i = vn; i >= 1; i--) {
				a = arr[i]; b = vf[a];
				if (tp[a] == 1) {
					near[a] = a;
					dis[a] = 0;
				}
				td = h[a] - h[b] + dis[a];
				if (td < dis[b] || td == dis[b] && near[a] < near[b]) {
					dis[b] = td;//因为第二遍Dp从2开始，所以不怕
					near[b] = near[a];
				}
			}
			//第二遍Dp
			for (int i = 2; i <= vn; i++) {
				a = arr[i];
				b = vf[a];
				td = h[a] - h[b] + dis[b];
				if (td < dis[a] || td == dis[a] && near[b] < near[a]) {
					dis[a] = td;
					near[a] = near[b];
				}
			}
			
			for (int i = 1; i <= vn; i++) {
				a = arr[i];
			}
		
			//计算答案
			int thr;//threshold 阈值
			for (int i = vn; i >= 1; i--) {
				a = arr[i]; b = vf[a];//vf[b]还行
				if (near[a] <= near[b]) {
					thr = -dis[b] + dis[a] + h[a] + h[b] + 1 >> 1;
				} else {
					thr = (-dis[b] + dis[a] + h[a] + h[b] >> 1) + 1;
				}
				thr = h[a] - thr;//深度 转 相对高度
				thr = max(thr, 0);
				thr = min(thr, h[a] - h[b] - 1);
				top = jump(a, thr);
				ans[near[a]] += size[top] - vsize[a];
				vsize[b] += size[top];
				tp[a] = vf[a] = vsize[a] = near[a] = 0;
				dis[a] = INF;
			}
			
			//输出答案
			for (int i = 1; i <= ovn; i++) {
				printf("%d ", ans[org[i]]);
				ans[org[i]] = 0;
			}
			printf("\n");
		}
		
	}
	int jump(int a, int dh) {
		for (int I = log[dh]; I >= 0; I--) {
			if (1 << I <= dh) {
				a = f[a][I];
				dh -= 1 << I;
			}
		}
		return a;
	}
	int getdis(int a, int b) {
		return h[a] + h[b] - 2 * getlca(a, b);
	}
	int getlca(int a, int b) {
		if (h[a] < h[b]) swap(a, b);
		for (int I = log[h[a] - h[b]]; I >= 0; I = log[h[a] - h[b]]) {//改成log会快还是慢？
			a = f[a][I];
		}
		if (a == b) return a;
		for (int I = log[h[a] - 1]; I >= 0; I--) {
			if (f[a][I] != f[b][I]) {
				a = f[a][I]; b = f[b][I];
			}
		}
		return f[a][0];
	}
	
	int log[MXN];
	void getlog(int mx) {
		log[0] = -1;
		for (int i = 2; i <= mx; i++) {
			log[i] = log[i - 1] + (i == 1 << log[i - 1] + 1);
		}
	}
	
	int h[MXN], f[MXN][19], r[MXN], size[MXN], dfnidx;
	void dfs(int nd, int fa) {
		dfn[nd] = ++dfnidx;
		h[nd] = h[fa] + 1;
		f[nd][0] = fa;
		size[nd] = 1;
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
				size[nd] += size[t];
			}
		}
		r[nd] = dfnidx;
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
