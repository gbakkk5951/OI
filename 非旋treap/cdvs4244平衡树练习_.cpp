using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e5 + 10;
struct Node {
	Node *s[2];
	int size, v, rand;
	void inline update() {
		size = s[0]->size + s[1]->size + 1;
	}
}pool[MXN], *null;
int pidx;

inline Node *new_(int v) {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	nd->rand = rand();
	nd->v = v;
	nd->size = 1;
	return nd;
}

struct Treap {
	Node *root;
	
	Treap() {
		null = new_(0);
		null->s[0] = null->s[1] = null;
		null->size = 0;
		root = null;
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
			nd->update();
			l = nd;
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
	
	int getrank(int v) {
		int ret = 0;
		Node *nd = root;
		while (nd != null) {
			if (nd->v >= v) {
				nd = nd->s[0];
			} else {
				ret += nd->s[0]->size + 1;//s[1]¿É»¹ĞĞ 
				nd = nd->s[1];
			}
		}
		return ret + 1;
	}
	
	int getnum(int rank) {
		Node *nd = root;
		while (1) {
			if (nd->s[0]->size >= rank) {
				nd = nd->s[0];
			} else
			if (nd->s[0]->size + 1 == rank) {
				break;
			} else {
				rank -= nd->s[0]->size + 1;
				nd = nd->s[1];
			}
		}
		return nd->v;
	}
	
	void insert(int v) {
		Node *nd = new_(v), *l, *r;
		int rank = getrank(v);
		split(root, rank - 1, l, r);
		nd = l != null ? merge(l, nd) : nd;
		root = r != null ? merge(nd, r) : nd;
	}
	
	void erase(int v) {
		Node *l, *nd, *r;
		int rank = getrank(v);
		split(root, rank - 1, l, r);
		split(r, 1, nd, r);
		root = r != null ? (l != null ? merge(l, r) : r) : l;
	}
	
	int inline getpre(int v) {
		return getnum(getrank(v) - 1);
	}
	
	int inline getnxt(int v) {
		return getnum(getrank(v + 1));
	}
	
}tree;
struct _Main {
	_Main() {
		int op, x;
		int Qn, n;
		read(n);
		read(Qn);
		for (int i = 1; i <= n; i++) {
		    read(x);
		    tree.insert(x);
		}
		
		for (int Q = 1; Q <= Qn; Q++) {
			read(x);
			printf("%d ", tree.getnum(tree.getrank(x)) == x);
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
}cdvs4543;

}
