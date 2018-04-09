using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace OI {
typedef long long lld;
const int MXN = 100005;
int n;
class ArrayTree {
public:
	lld node[MXN];
	int inline lb(int a) {
		return a & (-a);
	}
	void add(int nd, int val) {
		for (; nd <= n; nd += lb(nd)) {
			node[nd] += val;
		}
	}
	lld query(int nd) {
		lld ret = 0;
		for (; nd; nd -= lb(nd)) {
			ret += node[nd];
		}
		return ret;
	}
}d, di;

struct _Main {
	lld sum[MXN];
	char op[5];
	lld subquery(int r) {
		return d.query(r) * r - di.query(r);
	}
	lld query(int l, int r) {
		return sum[r] - sum[l - 1] + subquery(r) - subquery(l - 1);
	}
	void change(int l, int r, lld c) {
		d.add(l, c); di.add(l, c * (l - 1));
		d.add(r + 1, -c); di.add(r + 1, -c * (r + 1 - 1));
	}
	_Main() {
		int Qn;
		read(n);read(Qn);
		for (int i = 1; i <= n; i++) {
			read(sum[i]);
			sum[i] += sum[i - 1];
		}
		int l, r, c;
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			read(l); read(r);
			if (op[0] == 'C') {
				read(c);
				change(l, r, c);
			} else {
				printf("%d\n", query(l, r));
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
}poj3468;


}
//读优的正负 
