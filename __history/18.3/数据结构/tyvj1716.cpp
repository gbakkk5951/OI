using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 2051;
int n, m;
template <typename Type>
class SubArrayTree {
public:
	Type node[MXN][MXN];
	int lb(int a) {
		return a & (-a);
	}
	void add(int x, int y, int add) {
		for (int i = x; i <= n; i += lb(i)) {
			for (int j = y; j <= m; j += lb(j)) {
				node[i][j] += add;
			}
		}
	}
	lld query(int x, int y) {
		lld ret = 0;
		for (int i = x; i; i -= lb(i)) {
			for (int j = y; j; j -= lb(j)) {
				ret += node[i][j];
			}
		}
		return ret;
	}
	
};

class ArrayTree {
	public:
	SubArrayTree<int> d;
	SubArrayTree<lld> di, dj, dij;
	void change(int x, int y, int add) {
		d.add(x, y, add);
		di.add(x, y, add * (x - 1));
		dj.add(x, y, add * (y - 1));
		dij.add(x, y, add * (x - 1) * (y - 1));
	}
	lld query(int x, int y) {
		return x * y * d.query(x, y) - y * di.query(x, y) - x * dj.query(x, y) + dij.query(x, y);
	}
}tree;

struct _Main {
	void change(int x1, int y1, int x2, int y2, int add) {
		tree.change(x1, y1, add);
		tree.change(x1, y2 + 1, -add);
		tree.change(x2 + 1, y1, -add);
		tree.change(x2 + 1, y2 + 1, add);
	}
	lld query(int x1, int y1, int x2, int y2) {
		lld ret = 0;
		ret += tree.query(x2, y2);
		ret -= tree.query(x1 - 1, y2);
		ret -= tree.query(x2, y1 - 1);
		ret += tree.query(x1 - 1, y1 - 1);
		return ret;
	}
	char op[5];
	_Main() {
		read(n); read(m);
		int x1, x2, y1, y2, c;
		while (~scanf("%s", op)) {
			read(x1); read(y1); read(x2); read(y2);
			if (op[0] == 'L') {
				read(c);
				change(x1, y1, x2, y2, c);
			} else if (op[0] == 'k') {
				printf("%lld\n", query(x1, y1, x2, y2));
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
}tyvj1716;

}

//x1~2和y1~2很容易弄混， 要小心 
//卡空间23333 
