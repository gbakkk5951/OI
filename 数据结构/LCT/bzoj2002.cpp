using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int MXN = 200010;
struct Node {
	Node *s[2], *f;
	int size, sig;
}pool[MXN], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = nd->f = null;
	nd->size = 1;
	return nd;
}
Node *node[MXN];
int dis[MXN];
class LCT {
public:
	void update(Node *nd) {
		nd->size = 1;
		for (int i = 0; i < 2; i++) {
			nd->size += nd->s[i]->size;
		}
	}
	int heroot(Node *nd) {
		return nd == nd->f->s[1] || nd == nd->f->s[0];
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (heroot(f)) {
			gf->s[f == gf->s[1]] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s) {
			s->f = f;
		}
		f->f = nd;
		nd->s[pos ^ 1] = f;
		update(f);
		update(nd);
	}
	void splay(Node *nd) {
		Node *f;
		update(nd);
		while (heroot(nd)) {
			if (heroot(f = nd->f)) {
				if ((nd == f->s[1]) == (f == f->f->s[1])) {
					rotate(f);
				} else {
					rotate(nd);
				}
			}
			rotate(nd);
		}
	}
	void push(Node *nd) {
		if (nd->sig) {
			swap(nd->s[0], nd->s[1]);
			for (int i = 0; i < 2; i++) {
				nd->s[i]->sig ^= 1;
			}
			nd->sig = 0;
		}
	}
	Node *stk[MXN];
	int top;
	void push_to(Node *nd) {
		while (nd != null) {
			stk[top++] = nd;
			nd = nd->f;
		}
		while (top) {
			push(stk[--top]);
		}
	}
	void access(Node *nd) {
		Node *lst = null, *org = nd;
		push_to(nd);
		while (nd != null) {
			splay(nd);
			nd->s[1] = lst;
			lst = nd;
			nd = nd->f;
		}
		splay(org);
	}
	void mkroot(Node *nd) {
		access(nd);
		nd->sig ^= 1;
	}
	LCT() {
		null = new_();
		null->size = 0;
		null->s[0] = null->s[1] = null->f = null;
	}
	void link(Node *a, Node *b) {
		mkroot(a);
		a->f = b;
	}
	void cut(Node *a, Node *b) {
		mkroot(a);
		access(b);
		a->f = b->s[0] = null;
	}
}tree;

struct _Main {
	int n;
	int query(int pos) {
		tree.mkroot(node[n]);
		tree.access(node[pos]);
		return node[pos]->size - 1;
	}
	int inline dst(int a) {
		return min(a + dis[a], n);
	}
	void change(int pos, int val) {
		int org = dst(pos);
		dis[pos] = val;
		int now = dst(pos);
		if (now != org) {
//			printf("cut %d %d, link %d %d\n", pos, org, pos, now);
			tree.cut(node[pos], node[org]);
			tree.link(node[pos], node[now]);
		}
	}
	_Main() {
		int Qn;
		int op, a, b;
		read(n); 
		for (int i = 0; i <= n; i++) {
			node[i] = new_();
		}
		for (int i = 0; i < n; i++) {
			read(dis[i]); 
			tree.link(node[i], node[dst(i)]);
			
//			printf("%d to %d\n", i, dst(i));
		}
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			/*for (int i = 0; i <= n; i++) {
				printf("[%d = %lld] ls = %lld, rs = %lld, f = %lld\n", i, node[i] - pool, node[i]->s[0] - pool, node[i]->s[1] - pool,
					node[i]->f - pool);
			}*/
			read(op); read(a);
			if (op == 1) {
				printf("%d\n", query(a));
			} else {
				read(b);
				change(a, b);
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
}bzoj2002;
}
