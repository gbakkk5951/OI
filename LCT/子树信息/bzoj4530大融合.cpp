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
	Node *s[2], *f;
	int vsum, sum, sig;
	inline void update() {
		sum = s[0]->sum + s[1]->sum + vsum + 1;
	}
	inline void rotate() {
		Node *gf = f->f;
		int a;
		if ((a = f == gf->s[1]) || f == gf->s[0]) gf->s[a] = this; //不一定能改儿子
		int spo = this == f->s[1];
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
	Node();
};
Node *null = (Node *)calloc(1, sizeof(Node));
Node::Node() {
	s[0] = s[1] = f = null;
	sum = 1;
}
Node node[MXN];
struct LCT {
	LCT() {
		null->s[0] = null->s[1] = null->f = null;
	}
	void splay(Node *nd) {
		int a, b;
		Node *f, *gf;
		nd->update();
		f = nd->f;
		while (f != null && ((a = nd == f->s[1]) || nd == f->s[0])) { //因为null 的 链接 会被赋值
			gf = f->f;
			if (gf != null && ((b = f == gf->s[1]) || f == gf->s[0])) {
				if (a == b) {
					f->rotate();
				} else {
					nd->rotate();
				}
			}
			nd->rotate();
			f = nd->f;
		}
	}
	void access(Node *nd) {
		Node *lst = null, *org = nd;
		push_to(nd);
		while (nd != null) {
			splay(nd);
			nd->vsum += nd->s[1]->sum;
			nd->vsum -= lst->sum;
			nd->s[1] = lst;
			lst = nd;
			nd = nd->f;
		}
		splay(org);
	}
	
	void push_to(Node *nd) {
		static Node *stk[MXN];//忘了加static 怕不是要卡爆
		int top = 0;
		while (nd != null) {
			stk[++top] = nd;
			nd = nd->f;
		}
		while (top) {
			stk[top--]->push();
		}
	}
	
	void mkrt(Node *a) {
		access(a);
		a->sig ^= 1;
	}
	
	void link(Node *a, Node *b) {
		mkrt(a);
		access(b);
		a->f = b;
		b->vsum += a->sum;
		b->sum += a->sum;
	}
}lct;

struct _Main {

	char op[5];
	_Main() {
		int n, Qn, a, b;
		read(n); read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op); read(a); read(b);
			if (op[0] == 'A') {
				lct.link(&node[a], &node[b]);
			} else {
				lct.mkrt(&node[b]);
				lct.access(&node[a]);
				printf("%lld\n", (lld)node[b].sum * (node[a].sum - node[b].sum));
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
}bzoj4530;

}
