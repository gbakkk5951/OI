using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {

struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
struct Node {
	int id[2][205];
	int xl, xr, sum[2];
};
int cl[205][205];
int n;
class Tree {
public:
	Node node[517];
	void init(int nd) {
		int idx = 0;
		int x = node[nd].xl;
		for (int i = 1; i <= n; i++) {
			if (i > 1 && cl[x][i] != cl[x][i - 1]) {
				idx++;
			}
			node[nd].id[0][i] = idx;
		}
		memcpy(node[nd].id[1], node[nd].id[0], (n + 1) * sizeof(int));
	}
	void reid(int nd) {
		static int new_id[805];
		int idx = 0;
		int *t;
		memset(new_id, 192, (4 * n + 2) * sizeof(int));
		for (int I = 0; I < 2; I++) {
			for (int i = 1; i <= n; i++) {
				if (new_id[*(t = &node[nd].id[I][i])] < 0) {
					new_id[*t] = idx++;
				}
				*t = new_id[*t];
			}
		}
	}
	int fa[815];
	char vis[815];
	int getfa(int nd) {
		return fa[nd] >= 0 ? fa[nd] = getfa(fa[nd]) : nd;
	}
	int id[4][815];
	void merge(int l, int r, int nd) {
		int xl = node[nd].xl, xr = node[nd].xr;
		memcpy(id[0], node[l].id[0], (n + 1) * sizeof(int));
		memcpy(id[1], node[l].id[1], (n + 1) * sizeof(int));
		memcpy(id[2], node[r].id[0], (n + 1) * sizeof(int));
		memcpy(id[3], node[r].id[1], (n + 1) * sizeof(int));
		
		for (int I = 0; I < 2; I++) {
			for (int i = 1; i <= n; i++) {
				id[I][i] += 2 * n;
			}
		}
		memset(fa, 192, (4 * n + 2) * sizeof(int));
		memset(vis, 0, (4 * n + 2) * sizeof(char));
		int ml = node[l].xr;
		int mr = node[r].xl;
		int f1, f2, a, b;
		for (int i = 1; i <= n; i++) {
			if (cl[ml][i] == cl[mr][i]) {
				a = id[1][i], b = id[2][i];
				if ((f1 = getfa(a)) != (f2 = getfa(b))) {
					fa[f1] = f2;
				}
			} 
		}
		for (int I = 0; I < 4; I += 3) {
			for (int i = 1; i <= n; i++) {
				vis[id[I][i] = getfa(id[I][i])] = 1;
			}
		}
		for (int I = 1; I < 3; I++) {
			for (int i = 1; i <= n; i++) {
				id[I][i] = getfa(id[I][i]);
			}
		}
		for (int i = 0; i < 2; i++) {
			node[nd].sum[i] = 0;
		}
		
		for (int I = 1; I < 3; I++) {
			for (int i = 1; i <= n; i++) {
				int t;
				if (!vis[t = id[I][i]]) {
					vis[t] = 1;
					node[nd].sum[cl[ml + I - 1][i]]++;
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			node[nd].sum[i] += node[l].sum[i] + node[r].sum[i];
		}
		memcpy(node[nd].id[0], id[0], (n + 1) * sizeof(int));
		memcpy(node[nd].id[1], id[3], (n + 1) * sizeof(int));
		reid(nd);
	}
	void build(int nd, int l, int r) {
		node[nd].xl = l;
		node[nd].xr = r;
		if (l == r) {
			init(nd);
			return;
		}
		int mid = l + r >> 1;
		build(ls[nd], l, mid);
		build(rs[nd], mid + 1, r);
		merge(ls[nd], rs[nd], nd);
	}
	void update(int nd, int nl, int nr, int pos) {
		if (nl == nr) {
			init(nd);
			return;
		}
		int mid = nl + nr >> 1;
		if (pos <= mid) {
			update(ls[nd], nl, mid, pos);
		} else {
			update(rs[nd], mid + 1, nr, pos);
		}
		merge(ls[nd], rs[nd], nd);
	}
	void count(int &w, int &b) {
		w = node[1].sum[0];
		b = node[1].sum[1];
		memset(vis, 0, (2 * n + 1) * sizeof(char));
		for (int I = 0; I < 2; I++) { 
			for (int i = 1; i <= n; i++) {
				int t;
				if (!vis[t = node[1].id[I][i]]) {
					vis[t] = 1;
					if (cl[1 + I * (n - 1)][i] == 0) {
						w++;
					} else {
						b++;
					}
				}
			}
		}
	}
}tree;

struct _Main {
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
	_Main() {
		int Q, Qn;
		read(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				read(cl[i][j]);
			}
		}
		tree.build(1, 1, n);
		read(Qn);
		int a, b;
		int w;
		for (Q = 1; Q <= Qn; Q++) {
			read(a); read(b);
			cl[a][b] ^= 1;
			tree.update(1, 1, n, a);
			tree.count(w, b);
			printf("%d %d\n", b, w);
		}
	}
}bzoj1453;

}
//变量重名, 对参数的赋值要格外小心
//getfa按照无0写的，但实际上用到了0标号 
