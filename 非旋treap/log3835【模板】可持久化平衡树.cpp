using namespace std;
int main() {return 0;}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int INF = 2147483647;
const int MXN = 100;
struct Node {
	Node *s[2];
	int id, v, rand, size;
	inline void update() {
		size = s[0]->size + s[1]->size + 1;
	}
}pool[MXN], *null;

Node *now = pool;
Node *end = now + MXN;

Node *new_(int id, int v) {
	if (now == end) {
		now = (Node *)new Node[1024];
		end = now + 1024;
	}
	now->s[0] = now->s[1] = null;
	now->id = id;
	now->v = v;
	now->size = 1;
	now->rand = rand();
	return now++;
}

Node *new_(int id, Node *org) {
	if (now == end) {
		now = (Node *)new Node[1024];
		end = now + 1024;
	}
	memcpy(now, org, sizeof(Node));
	now->id = id;
	return now++;
}

struct ForeverTreap {
	Node *root[100010];
	ForeverTreap() {
		null = new_(-1, 0);
		null->s[0] = null->s[1] = null;
		null->size = 0;
		root[0] = null;
	}
	void split(int id, Node *nd, int rank, Node *&l ,Node *&r) {
		Node **ll = &l, **lr = &r;
		while (nd->size != rank) {
			nd = nd->id == id ? nd : new_(id, nd);
			if (nd->s[0]->size >= rank) {
				nd->size -= rank;
				nd = nd->s[0];
				*lr = nd;
				lr = &nd->s[0];
			} else {
				nd->size = rank;
				rank -= nd->s[0]->size + 1;
				nd = nd->s[1];
				*ll = nd;
				ll = &nd->s[1];
			}
		}
		*ll = nd; *lr = null;
	}
	Node *merge(int id, Node *l, Node *r) {
		Node *ret;
		Node **lst = &ret;
		while (1) {
			if (l->rand > r->rand) {
				l = l->id == id ? l : new_(id, l);
				l->size += r->size;
				*lst = l;
				if (l->s[1] == null) {
					l->s[1] = r;
					break;
				} else {
					lst = &l->s[1];
					l = l->s[1];
				}
			} else {
				r = r->id == id ? r : new_(id, r);
				r->size += l->size;
				*lst = r;
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
	int getrank(int id, int v) { //¿¿¿¿-INF ¿¿ +1
		Node *nd = root[id];
		int ret = 0;
		while (nd != null) {
			if (nd->v < v) {
				ret += nd->s[0]->size + 1;
				nd = nd->s[1];
			} else {
				nd = nd->s[0];
			}
		}
		return ret;
	}
	int getnum(int id, int rank) {
		Node *nd = root[id];
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
	void insert(int id, int v) {
		Node *l, *r, *nd = new_(id, v);
		int pos = getrank(id, v);
		split(id, root[id], pos - 1, l, r);
		nd = l == null ? nd : merge(id, l, nd); //l == null¿¿¿¿¿nd ¿¿¿ l
		root[id] = r == null ? nd : merge(id, nd, r);
	}
	void erase(int id, int v) {
		Node *l, *r, *nd;
		int pos = getrank(id, v);
		if (getnum(id, pos) == v) {
			split(id, root[id], pos - 1, l, r);
			split(id, r, 1, nd, r);
			root[id] = merge(id, l, r); //¿¿¿¿¿¿¿, ¿¿¿INF
		}
	}
	inline int getpre(int id, int v) {
		return getnum(id, getrank(id, v) - 1);
	}
	inline int getnxt(int id, int v) {
		return getnum(id, getrank(id, v + 1));
	}
}tree;

struct _Main {
	_Main() {
		int Qn, src, op, v;
		tree.insert(0, INF);
		tree.insert(0, -INF);
		read(Qn);
		printf("Qn = %d\n", Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(src); read(op); read(v);
			tree.root[Q] = tree.root[src];
			switch (op) {
				case 1: {
					tree.insert(Q, v);
					break;
				}
				case 2: {
					tree.erase(Q, v);
					break;
				}
				case 3: {
					printf("%d\n", tree.getrank(Q, v));
					break;
				}
				case 4: {
					printf("%d\n", tree.getnum(Q, v));
					break;
				}
				case 5: {
					printf("%d\n", tree.getpre(Q, v));
					break;
				}
				case 6: {
					printf("%d\n", tree.getnxt(Q, v));
					break;
				}
			}
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
}log3835;
}
