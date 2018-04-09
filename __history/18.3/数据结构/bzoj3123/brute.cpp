using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {
const int MXN = 80005;
const int DST = 0, NXT = 1;
struct _Main {
	int head[MXN], edge[MXN * 2][2];
	int eidx;
	int h[MXN], f[MXN];
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		f[nd] = fa;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (edge[e][DST] != fa) {
				dfs(edge[e][DST], nd);
			}
		}
	}
	int idx;
	void getlca(int a, int b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		while (h[a] > h[b]) {
			arr[idx++] = val[a];
			a = f[a];
		}		
		while (a != b) {
			arr[idx++] = val[a];
			arr[idx++] = val[b];
			a = f[a]; b = f[b];
 		}
 		arr[idx++] = a;
	}
	int query(int a, int b, int c) {
		idx = 0;
		getlca(a, b);
		sort(arr, arr + idx);
		return arr[c - 1];
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
		a ^= lstans;
	}
	int n;
	int val[MXN];
	int arr[MXN];
	void add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void init() {
		eidx = 0;
		lstans = 0;
		memset(h + 1, 0, n * sizeof(int));
		memset(head + 1, 0, n * sizeof(int));
	}
	int lstans;
	char op[5];
	_Main() {
		int Tn;
		int m, Qn;
		int a, b, c;
		read(Tn);
		
		for (int T = 1; T <= Tn; T++) {
			init();
			read(n); read(m); read(Qn);
			for (int i = 1; i <= n; i++) {
				read(val[i]);
			}
			for (int i = 1; i <= m; i++) {
				read(a); read(b);
				add(a, b); add(b, a);
			}
			for (int i = 1; i <= n; i++) {
				if (h[i] == 0) {
					dfs(i, 0);
				}
			}
			for (int Q = 1; Q <= Qn; Q++) {
				scanf("%s", op);
				read(a); read(b);
				if (op[0] == 'Q') {
					read(c);
					printf("%d\n", lstans = query(a, b, c));
				} else {
					add(a, b);
					add(b, a);
					dfs(a, 0);
				}
			}
		}
		
	}	
	
}brute;
}

