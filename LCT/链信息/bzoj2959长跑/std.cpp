using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cctype>
namespace OI {
struct Node;
const int MXN = 1.5e5 + 10;
int fa[MXN];
int getfa(int a) {
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}
inline void setfa(int a, int fa) {
	OI::fa[a] = fa;
}
int low[MXN];
int getlow(int a) {
	return low[a] ? low[a] = getlow(low[a]) : a;
}
inline void setlow(int a, int low) {
	OI::low[a] = low;
}
Node *node[MXN];
struct Node {
	Node *s[2], *f;
	int sig, sum, val, id;
	inline void update() {
		sum = val + s[0]->sum + s[1]->sum;
	}
	inline void push() {
		if (sig) {
			swap(s[0], s[1]);
			s[0]->sig ^= 1;
			s[1]->sig ^= 1;
			sig = 0;
		}
	}
	Node *& fa() {
		return f = node[getlow(f->id)];
	}
	void rotate() {
		Node *gf = f->fa();
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
}pool[MXN], *null;
int pidx;
Node *new_(int val, int id) {
	Node *nd = &pool[pidx++];	
	nd->val = val;
	nd->id = id;
	nd->s[0] = nd->s[1] = nd->f = null;
	return nd;
}
struct LCT {
	LCT() {
		null = new_(0, 0);
		null->s[0] = null->s[1] = null->f = null;
		node[0] = null;
	}
}lct;
void splay(Node *nd) {
	Node *f = nd->fa(), *gf;
	int a, b;
	nd->update();
	while ((a = nd == f->s[1]) || nd == f->s[0]) {
		gf = f->fa();
		if ((b = f == gf->s[1]) || f == gf->s[0]) {
			(a == b ? f : nd)->rotate();
		}
		nd->rotate();
		f = nd->fa();
	}
}
void push_to(Node *nd) {
	static Node *stk[MXN];
	int top = 0;
	while (nd != null) {
		stk[++top] = nd;
		nd = nd->fa();
	}
	while (top) {
		stk[top--]->push();
	}
}
void access(Node *nd) {
	Node *lst = null, *org = nd;
	push_to(nd);
	while (nd != null) {
		splay(nd);
		nd->s[1] = lst;
		lst = nd;
		nd = nd->fa();
	}
	splay(org);//org 写成nd 会卡null环
}
inline void mkrt(Node *nd) {
	access(nd);
	nd->sig = 1;
}
void dfs(Node *nd, Node *f, int low) {
	setlow(nd->id, low);
	f->val += nd->val;
	for (int i = 0; i < 2; i++) {
		if (nd->s[i] != null) {
			dfs(nd->s[i], f, low);
		}
	}
}
int val[MXN];
struct _Main {
	_Main() {
		int n, Qn, op, a, b, fa, fb, la, lb;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(val[i]);
			node[i] = new_(val[i], i);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(a); read(b);
			if (op == 1) { //加边
				la = getlow(a); lb = getlow(b);
				if (la != lb) {
					fa = getfa(a);
					fb = getfa(b);
					mkrt(node[la]);
					access(node[lb]);
					if (fa == fb) {
						splay(node[la]);
						dfs(node[la]->s[1], node[la], la);
					} else {
						node[la]->f = node[lb];
						setfa(fa, fb);
					}
				} 
			} else
			if (op == 2) { //改点权
				la = getlow(a);
				access(node[la]);
				node[la]->val += -val[a] + b;
				val[a] = b;
			} else { //查询
				la = getlow(a); lb = getlow(b);
				if (la != lb) {
					fa = getfa(a);
					fb = getfa(b);
					if (fa == fb) {
						mkrt(node[la]);
						access(node[lb]);
						printf("%d\n", node[lb]->sum);
					} else {
						printf("-1\n");
					}
				} else {
					printf("%d\n", node[la]->val);
				}
			}
		}
	}
template <typename  Type>
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
