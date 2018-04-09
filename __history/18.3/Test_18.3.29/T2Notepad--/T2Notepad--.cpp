using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cstdlib>

namespace OI {
const int MXN = 500050;
struct Node {
	Node *s[2], *f;
	int size;
	char v;
};
struct Splay {
	Node pool[MXN], *null;
	Node *root;
	int pidx;
	Node *new_(int v, Node *f) {
		Node *nd = &pool[pidx++];
		nd->v = v;
		nd->f = f;
		nd->size = 1;
		nd->s[0] = nd->s[1] = null;
		return nd;
	}	
	Splay() {
		null = new_(0, 0);
		null->size = 0;
		null->s[0] = null->s[1] = null->f = null;
		root = null;
	}
	void update(Node *nd) {
		nd->size = 1;
		for (int i = 0; i < 2; i++) {
			nd->size += nd->s[i]->size;
		}
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf != null) {
			gf->s[f == gf->s[1]] = nd;
		}
		int spo = nd == f->s[1];
		s = f->s[spo] = nd->s[spo ^ 1];
		if (s != null) {
			s->f = f;
		}
		f->f = nd;
		nd->s[spo ^ 1] = f;
		update(f);
		update(nd);
	}
	void splay(Node *nd) {
		update(nd);
		Node *f;
		while ((f = nd->f) != null) {
			if (f->f != null) {
				if ((f == f->f->s[1]) == (nd == f->s[1])) {
					rotate(f);
				} else {
					rotate(nd);
				}
			}
			rotate(nd);
		}
		root = nd;
	}
	void insert(int pos, char v) {
		if (root == null) {
			root = new_(v, null);
			return;
		}
		Node *nd = root;
		int spo;
		while (1) {
			if (spo = nd->s[0]->size < pos) {
				pos -= nd->s[0]->size + 1;
			}
			if (nd->s[spo] != null) {
				nd = nd->s[spo];
			} else {
				nd = nd->s[spo] = new_(v, nd);
				break;
			}
		}
		splay(nd);
	}
	int nidx;
	Node *node[MXN];
	void print(int l, int r) {
		nidx = 0;
		print(root, l, r);
		for (int i = 0; i < nidx; i++) {
			splay(node[i]);
		}
	}
	void print(Node *nd, int l, int r) {
		if (nd != null) {
			int s = nd->s[0]->size;
			if (s > l) {
				print(nd->s[0], l, r);
			}
			if (s >= l && s <= r) {
				printf("%c", nd->v);
				node[nidx++] = nd;
			}
			s++;
			if (s <= r) {
				print(nd->s[1], l - s, r - s);
			}
		}
	}

	
}tree;

struct _Main {
	char op[5];
	char in[MXN];
	void insert(int beg) {
		for (int i = 0; in[i]; i++) {
			tree.insert(beg + i, in[i]);
		}
	}
	_Main() {
		int pos, l, r;
		scanf("%s", in);
		insert(0);
		while (~scanf("%s", op)) {
			if (op[0] == 'E') {
				break;
			} else if (op[0] == 'I') {
				scanf("%s", in);
				read(pos);
				insert(pos);
			} else {
				read(l); read(r);
				tree.print(tree.root, l, r);
				printf("\n");
			}
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
}T2;
}
