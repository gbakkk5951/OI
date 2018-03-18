using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 80010;
struct Node {
	Node *s[2], *f;
	int size, val, sig;
}pool[MXN], *null;
Node* node[MXN];
int pidx;
	Node *new_() {
		Node *nd = &pool[pidx++];
		nd->s[0] = nd->s[1] = nd->f = null;
		nd->sig = 0;
		nd->size = 1;
		return nd;
	}
	
class LCT {
public:
	int inline heroot(Node *nd) {
		return nd == nd->f->s[0] || nd == nd->f->s[1];
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
		if (heroot(f)) {
			gf->s[f == gf->s[1]] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s) {
			s->f = f;
		}
		nd->s[pos ^ 1] = f;
		f->f = nd;
		update(f);
		update(nd);
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
	Node *stk[80010];
	int top;
	void push_to(Node *nd) {
		while (nd != null) {
			stk[top++] = nd;
			nd = nd->f;
		}
		while(top) {
			push(stk[--top]);
		}
	}
	void splay(Node *nd) {
		printf("splay\n");
		update(nd);
		Node *f;
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
		printf("splay end\n");
	}
	void access(Node *nd) {
		
		push_to(nd);
		Node *lst = null, *org = nd;
		do {
			splay(nd);
			nd->s[1] = lst;
			lst = nd;
			nd = nd->f;
		} while (nd != null);
		splay(org);
	}
	void makeroot(Node *nd) {
		access(nd);
		nd->sig ^= 1;
	}
	void link(Node *a, Node *b) {
		makeroot(a);
		a->f = b;
	}
	int query(Node *a, Node *b, int rk) {
		makeroot(b); access(a);
		int left;
		while (1) {
			left = a->s[0]->size;
			if (left >= rk) {
				a = a->s[0];
			} else if (left + 1 < rk) {
				rk -= left + 1;
				a = a->s[1];
			} else {
				break;
			}
		}
		splay(a);
		return a->val;
	}
}tree;	
	
struct _Main {
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a ^= lstans;
	}
	void init() {
		lstans = 0;
		pidx = 0;	
		null = new_();
		null->s[0] = null->s[1] = null->f = null;
		null->size = 0;
	}
	int lstans;
	char op[5];
	_Main() {
		int Tn, n, m, Qn;
		int a, b, c;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			init();
			read(n); read(m); read(Qn);
			for (int i = 1; i <= n; i++) {
				node[i] = new_();
				read(node[i]->val);
			}
			for (int i = 1; i <= m; i++) {
				read(a); read(b);
				tree.link(node[a], node[b]);
			}
			for (int Q = 1; Q <= Qn; Q++) {
				scanf("%s", op); read(a); read(b);
				if (op[0] == 'L') {
					printf("lnk %d %d\n", a, b);
					tree.link(node[a], node[b]);
				} else {
					read(c);
					printf("q %d %d %d\n", a, b, c);
					printf("%d\n", lstans = tree.query(node[a], node[b], c));
				}
			}
		}
		
	}
}bzoj3132;

}
