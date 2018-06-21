using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
namespace OI {
typedef long long lld;

map<lld, vector<int> > mp;//后缀

struct Tree {
	vector<int> node;
	int mx;
	void resize(int n) {
		mx = n;
		node.resize(n + 1);
	}
	void add(int nd, int v) {//从0开始用
		for (++nd; nd <= mx; nd += nd & (-nd)) {
			node[nd] += v;
		}
	}
	int query(int nd) {
		int ret = 0;
		for (++nd; nd > 0; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
}tree[19];
lld sum;
struct _Main {
	void insert(lld val) {
		val -= sum;
		mp[val].push_back(val & (1 << 18) - 1);
		for (int i = 1; i <= 18; i++) {
			tree[i].add(val & (1 << i) - 1, 1);
		}
	}
	void erase(lld val) {
		val -= sum;
		vector<int> *v = &mp[val];
		for (int i = 0; i < v->size(); i++) {
			for (int j = 1; j <= 18; j++) {
				tree[j].add((*v)[i] & (1 << j) - 1, -1);
			}
		}
		v->clear();
	}
	int query(int k) {
		++k;
		int L = 1 << k - 1, R = (1 << k) - 1;
		L = (L - sum) & (1 << k) - 1;
		R = (R - sum) & (1 << k) - 1;
		if (L <= R) {
			return tree[k].query(R) - tree[k].query(L - 1);
		}
		return tree[k].query((1 << k) - 1) - tree[k].query(L - 1) + tree[k].query(R);
	}
	void add(int val) {
		sum += val;
	}
	char op[10];
	_Main() {
		for (int i = 1; i <= 18; i++) {
			tree[i].resize (1 << i);
		}
		int Qn;
		lld a;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op); read(a);
			if (op[0] == 'I') {
				insert(a);
			} else
			if (op[0] == 'D') {
				erase(a);
			} else 
			if (op[0] == 'Q') {
				printf("%d\n", query(a));
			} else
			if (op[0] == 'A') {
				add(a);
			}
		}
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
}bitcoin;
}
