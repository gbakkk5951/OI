using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
namespace OI {
typedef double lf;
const int MXN = 1e6 + 100;
const int INF = 5e8;
const lf ALPHA = 0.78;
struct P {
	int x[2];
	inline int & operator [] (int dim) {
		return x[dim];
	}
};
struct Node {
	Node *s[2];
	int mx[2], mn[2];
	P p;
	int size;
	void update() {
		size = 1 + s[0]->size + s[1]->size;
		for (int i = 0; i < 2; i++) {
			mx[i] = max(s[0]->mx[i], s[1]->mx[i]);
			mx[i] = max(mx[i], p[i]);
			mn[i] = min(s[0]->mn[i], s[1]->mn[i]);
			mn[i] = min(mn[i], p[i]);
		}
	}
}pool[MXN], *null;
int pidx;
Node *new_(P a) {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	for (int i = 0; i < 2; i++) {
		nd->p[i] = nd->mx[i] = nd->mn[i] = a[i];
	}
	nd->size = 1;
	return nd;
}
struct Cmp {
	int dim;
	bool operator () (Node *a, Node *b) {
		return a->p[dim] < b->p[dim];
	}
}cmp;
inline int getdis(P a, P b) {
	return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
int astar(Node *nd, P a) {
	int ret = 0;
	for (int i = 0; i < 2; i++) {
		ret += nd->mn[i] <= a[i] && nd->mx[i] >= a[i] ? 
			0 : min(abs(a[i] - nd->mn[i]), abs(a[i] - nd->mx[i]));
		//忘了+ abs
	}
	return ret;
}
struct KDTree{
	Node *root;
	Node *arr[MXN];
	int idx;
	KDTree() {
		null = new_((P) {0, 0});
		null->size = 0;
		for (int i = 0; i < 2; i++) {
			null->mn[i] = INF;
			null->mx[i] = -INF;
		}
		null->s[0] = null->s[1] = null;
	}

	Node* insert(Node *nd, P a, int dim) {
		int spo = a[dim] > nd->p[dim];
		if (nd->s[spo] == null) {
			nd->s[spo] = new_(a);
		} else {
			if (nd->s[spo]->size + 1 > (nd->size + 1) * ALPHA) {
				collect(nd);
				arr[++idx] = new_(a);
				nd = build(1, idx, dim);
				idx = 0;
			} else {
				nd->s[spo] = insert(nd->s[spo], a, dim ^ 1);
			}
		}
		nd->update();
		return nd;
	}
	void insert(P a) {
		if (root == 0) {
			root = new_(a);
		} else {
			root = insert(root, a, 0);
		}
	}
	Node* build(int l, int r, int dim) {
		int mid = l + r >> 1;
		cmp.dim = dim;
		nth_element(arr + l, arr + mid, arr + r + 1, cmp);
		Node *nd = arr[mid];
		if (l < mid) {
			nd->s[0] = build(l, mid - 1, dim ^ 1);
		} 
		if (r > mid) {
			nd->s[1] = build(mid + 1, r, dim ^ 1);
		}
		nd->update();
		return nd;
	}
	void collect(Node *nd) {
		arr[++idx] = nd;
		for (int i = 0; i < 2; i++) {
			if (nd->s[i] != null) {
				collect(nd->s[i]);
				nd->s[i] = null;
			}
		}
	}
	int calc(Node *nd, P a, int now = INF) {
		for (int i = 0; i < 2; i++) {
			if (nd->s[i] != null) {
				now = min(now, getdis(nd->s[i]->p, a));
			}
		}
		for (int i = 0; i < 2; i++) {
			if (nd->s[i]->size <= 1) continue;
			if (astar(nd->s[i], a) < now) {
				now = calc(nd->s[i], a, now);
			}
		}
		return now;
	}
}tree;
struct _Main {
	
	_Main() {
		int n, Qn, op;
		P a;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(a[0]); read(a[1]);
			tree.arr[i] = new_(a);
		}
		if (n) {
			tree.root = tree.build(1, n, 0);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(a[0]); read(a[1]);
			if (op == 1) {//插入
				tree.insert(a);
			} else {//查询
				printf("%d\n", tree.calc(tree.root, a, getdis(tree.root->p, a)));
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
}std;
}
