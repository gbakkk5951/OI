using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace OI {
const int MXN = 5e5 + 10;

struct Node {
	Node *s[2];
	int size, val, rand;
	void inline update() {
		size = s[0]->size + s[1]->size + 1;
	}
}pool[MXN], *null;
int pidx;

Node *new_(int v = 0) {
	Node *nd = &pool[pidx++];
	nd->val = v;
	nd->s[0] = nd->s[1] = null;
	nd->size = 1;
	nd->rand = rand();
	return nd;
}
struct Tree {
	Node *root;
	Tree() {
		null = new_(-1000);
		null->size = 0;
		null->s[0] = null->s[1] = null;
		root = null;
	}
	int getrank(int v) {
		Node *nd = root;
		int ret = 0;
		while (nd != null) {
			if (nd->val >= v) {
				nd = nd->s[0];
			} else {
				ret += nd->s[0]->size + 1;
				nd = nd->s[1];
			}
		}
		return ret + 1;
	}
	void split(Node *nd, int rank, Node *&l, Node *&r) {
		if (nd->size == rank) {
			l = nd; r = null;
		} else
		if (nd->s[0]->size >= rank) {
			split(nd->s[0], rank, l, nd->s[0]);
			nd->update();
			r = nd;
		} else {
			split(nd->s[1], rank - nd->s[0]->size - 1, nd->s[1], r);
			l = nd;
			nd->update();
		}
		
	}
	Node *merge(Node *l, Node *r) {
		if (l->rand > r->rand) {
			l->s[1] = l->s[1] != null ? merge(l->s[1], r) : r;
			l->update();
			return l;
		} else {
			r->s[0] = r->s[0] != null ? merge(l, r->s[0]) : l;
			r->update();
			return r;
		}
	}
	inline void insert(int v) {
		Node *l, *r, *nd = new_(v);
		int pos = getrank(v);
		split(root, pos - 1, l, r);
		nd = l != null ? merge(l, nd) : nd;
		root = r != null ? merge(nd, r) : nd;
	}
	Node *find(int a) {
		Node *nd = root;
		while (nd != null) {
			if (nd->val < a) {
				nd = nd->s[1];
			} else
			if (nd->val == a) {
				break;
			} else {
				nd = nd->s[0];
			}
		}
		return nd;
	}
}tree;
struct _Main {
	_Main() {
		srand(151956741 ^ (unsigned long long) new char);
		int n, Qn, a;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(a);
			tree.insert(a);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(a);
			printf("%d ", tree.find(a) != null);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}cdvs4244;
}
