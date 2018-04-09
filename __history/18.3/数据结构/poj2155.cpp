using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace OI {
const int MXN = 1005;
int n;
class ArrayTree {
public:
	int node[MXN][MXN];
	inline int lb(int a) {
		return a & (-a);
	}
	int query(int x, int y) {
		int ret = 0;
		for (int a = x; a; a -= lb(a)) {
			for (int b = y; b; b -= lb(b)) {
				ret += node[a][b];
			}
		}
		return ret;
	}
	void add(int x, int y, int add) {
		for (int a = x; a <= n; a += lb(a)) {
			for (int b = y; b <= n; b += lb(b)) {
				node[a][b] += add;
			}
		}
	} 
	void clear() {
		for (int i = 1; i <= n; i++) {
			memset(node[i] + 1, 0, sizeof(int) * n);
		}
	}		
}tree;

struct _Main {
	
	int query(int x, int y) {
		return tree.query(x, y) & 1;
	}
	void change(int x1, int y1, int x2, int y2) {
		tree.add(x1, y1, 1);
		tree.add(x2 + 1, y1, -1);
		tree.add(x1, y2 + 1, -1);
		tree.add(x2 + 1, y2 + 1, 1);
	}
	char op[5];
	_Main() {
		int Tn, Qn;
		int x1, x2, y1, y2, x, y;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			tree.clear();
			read(n); read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				scanf("%s", op);
				if (op[0] == 'C') {
					read(x1); read(y1); read(x2); read(y2);
					change(x1, y1, x2, y2);
				} else {
					read(x); read(y);
					printf("%d\n", query(x, y));
				}
			}
			printf("\n");
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
}poj2155;

}
