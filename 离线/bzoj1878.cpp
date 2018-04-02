using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace OI {
const int 
	MXQ = 200005,
	MXN = 50005;

int lst[MXN];

struct Query {
	int l, r, id;
	bool operator < (const Query& b) const {
		return r < b.r;
	}
}query[MXQ];
int org[MXN];
int sorted[MXN];
int id[MXN];
int ans[MXQ];
int n;
class ArrTree {
private:
	int node[MXN];
	int lb(int a) {
		return a & (-a);
	}
public:
	int query(int nd) {
		int ret = 0;
		for (; nd; nd -= lb(nd)) {
			ret += node[nd];
		}
		return ret;
	}
	void add(int nd, int val) {
		for (; nd <= n; nd += lb(nd)) {
			node[nd] += val;
		}
	}
}tree;

struct _Main {
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while (isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
	int lst[MXN];
	int ask(int l, int r) {
		static int nr = 0;
		static int sum = 0;
		while (nr < r) {
			nr ++;
			if (lst[id[nr]]) {
				tree.add(lst[id[nr]], -1);
			} else {
				sum++;
			}
			lst[id[nr]] = nr;
			tree.add(nr, 1);
		}
		return sum - tree.query(l - 1);
	}
	_Main() {
		int Q, Qn;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(org[i]);
		}
		memcpy(sorted, org, (n + 1) * sizeof(int));
	
		sort(sorted + 1, sorted + n + 1);
		for (int i = 1; i <= n; i++) {
			id[i] = lower_bound(sorted + 1, sorted + n + 1, org[i]) - sorted;
		}
		read(Qn);
		for (Q = 1; Q <= Qn; Q++) {
			read(query[Q].l); read(query[Q].r);
			query[Q].id = Q;
		}
		sort(query + 1, query + Qn + 1);
		for (Q = 1; Q <= Qn; Q++) {
			ans[query[Q].id] = ask(query[Q].l, query[Q].r);
		}
		for (Q = 1; Q <= Qn; Q++) {
			printf("%d\n", ans[Q]);
		}
	}
}bzoj1878;

}
