using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 5e5 + 10;
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
		Node **ll = &l, **lr = &r;
		while (nd->size != rank) {
			if (nd->s[0]->size >= rank) {
				nd->size -= rank;
				*lr = nd;
				lr = &nd->s[0];
				nd = nd->s[0];
			} else {
				nd->size = rank;
				rank -= nd->s[0]->size + 1; //忘了改Rank 
				*ll = nd;
				ll = &nd->s[1];
				nd = nd->s[1];
			}			
		}
		*ll = nd; *lr = null;
	}
	

	Node *merge(Node *l, Node *r) {
		Node *ret = 0;
		Node **lst = &ret;
		while (1) {
			if (l->rand > r->rand) {
				*lst = l;
				l->size += r->size;
				if (l->s[1] == null) {
					l->s[1] = r;
					break;
				} else {
					lst = &l->s[1];
					l = l->s[1];
				}
			} else {
				*lst = r;
				r->size += l->size;
				if (r->s[0] == null) {
					r->s[0] = l;
					break;
				} else {
					lst = &r->s[0];
					r = r->s[0];
				}
			}
		}
		return ret;
	}

	int getrank(int v) {
		int ret = 0;
		Node *nd = root;
		while (nd != null) {
			if (nd->v >= v) {
				nd = nd->s[0];
			} else {
				ret += nd->s[0]->size + 1;//s[1]可还行 
				nd = nd->s[1];
			}
		}
		return ret + 1;
	}
	
	Node *find(int v) {
		Node *nd = root;
		while (nd != null) {
			if (nd->v == v) {
				break;
			} else
			if (nd->v > v) {
				nd = nd->s[0];
			} else {
				nd = nd->s[1];
			}
		}
		return nd;
	}
	
	void insert(int v) {
		Node *nd = new_(v), *l, *r;
		int rank = getrank(v);
		split(root, rank - 1, l, r);
		nd = l != null ? merge(l, nd) : nd;
		root = r != null ? merge(nd, r) : nd;
	}

	
}tree;
struct _Main {
	_Main() {
		int Qn, n;
		int x;
		srand(168796531 ^ (unsigned long long) new char);
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(x);
			tree.insert(x);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(x);
			printf("%d ", tree.find(x) != null);
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
