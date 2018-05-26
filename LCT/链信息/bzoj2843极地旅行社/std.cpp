using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
namespace OI {
const int MXN = 3e4 + 10;

struct Node {
	Node *s[2], *f;
	int sum, val, sig;
	inline void update() {
		sum = val + s[0]->sum + s[1]->sum;
	}
	void rotate() {
		Node *gf = f->f;
		int spo;
		if ((spo = f == gf->s[1]) || f == gf->s[0]) gf->s[spo] = this;
		spo = this == f->s[1];
		(f->s[spo] = s[spo ^ 1])->f = f;
		s[spo ^ 1] = f;
		f->f = this;
		f->update();
		update();
		f = gf;
	}
	inline void push() {
		if (sig) {
			swap(s[0], s[1]);
			s[0]->sig ^= 1;
			s[1]->sig ^= 1;
			sig = 0;
		}
	}
}pool[MXN], *null;
int pidx;

Node* new_(int val) {
	Node *nd = &pool[pidx++];
	nd->val = val;
	nd->s[0] = nd->s[1] = nd->f = null;
	return nd;
} 
struct LCT {
	LCT() {
		null = new_(0);
		null->s[0] = null->s[1] = null->f = null;
		null->sum = 0; null->val = -1;
	}
}lct;
void splay(Node *nd) {
	Node *f = nd->f, *gf;
	int a, b;
	nd->update();
	while ((a = nd == f->s[1]) || nd == f->s[0]) {
		gf = f->f;
		if ((b = f == gf->s[1]) || f == gf->s[0]) {
			(a == b ? f : nd)->rotate();
		}
		nd->rotate();
		f = nd->f;
	}
}
void push_to(Node *nd) {
	static Node *stk[MXN];
	int top = 0;
	while (nd != null) {
		stk[++top] = nd;
		nd = nd->f;
	}
	while (top) {
		stk[top--]->push();
	}
}
void access(Node *nd) {
	push_to(nd);
	Node *org = nd, *lst = null;
	while (nd != null) {
		splay(nd);
		nd->s[1] = lst;
		lst = nd;
		nd = nd->f;
	}
	splay(org);
}
void mkrt(Node *nd) {
	access(nd);
	nd->sig ^= 1;
}
Node *node[MXN];
struct _Main {
	char op[15];
	_Main() {
		int n, Qn;
		int a, b;
		read(n); 
		for (int i = 1; i <= n; i++) {
			read(a);
			node[i] = new_(a);
		}
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op); read(a); read(b);
			if (op[0] == 'b') {//连边
				mkrt(node[a]);
				access(node[b]);
				if (node[a]->f != null) {
					printf("no\n");
				} else {
					node[a]->f = node[b];
					printf("yes\n");
				}
			} else
			if (op[0] == 'p') {//改权值
				access(node[a]);
				node[a]->val = b;
			//	node[a]->update(); //其实不用
			} else { //查询
				if (a == b) {
					printf("%d\n", node[a]->val);
				} else {
					mkrt(node[a]);
					access(node[b]);
					if (node[a]->f == null) {
						printf("impossible\n");
					} else {
						printf("%d\n", node[b]->sum);
					}
				}
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
