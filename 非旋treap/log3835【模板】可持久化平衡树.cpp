using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int INF = 2147483647;
const int MXN = 2e6;
struct Node {
	Node *s[2];
	int id, v, rand, size;
	inline void update() {
		size = s[0]->size + s[1]->size + 1;
	}
}pool[MXN], *null;

Node *now = pool, *end = pool + MXN;

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
	ForeverTreap() {
		null = new_(-1, 0);
		null->s[0] = null->s[1] = null;
		null->size = 0;
	}
	void split(int id, Node *nd, int rank, Node *&l ,Node *&r) {
		if (nd->size == rank) {
			l = nd; r = null;
		}
		nd = nd->id == id ? nd : new_(id, nd);
		if (nd->s[0]->size >= rank) {
			split(id, nd->s[0], rank, l, nd->s[0]);
			nd->update();
		} else {
			split(id, nd->s[1], rank - nd->s[0]->size - 1; nd->s[1], r);
			nd->update();
		}
	}
	Node *merge(int id, Node *l, Node *r) {
		if (l->rand > r->rand) {
			l = l->id == id ? l : new_(id, l);
			l->s[1] = l->s[1] != null ? merge(l->s[1], r) : r; 
			return l;
		} else {
			r = r->id == id ? r : new_(id, r);
			r->s[0] = r->s[0] != null ? merge(l, r->s[0]) : r;
			return r;
		}
	}
}tree;

struct _Main {
	_Main() {
		tree.insert(0, 0, INF);
		tree.insert(0, 0, -INF);
		int Qn, src, op, v;
		read(Qn);
		for (Q = 1; Q <= Qn; Q++) {
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
