using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
typedef double lf;
lf com[17][17];
lf fr[17];
lf kp[17], bp[17];
struct Node {
	Node *s[2], *f;
	lf val[17], sum[17];
	int sig;
	void modify(int tp, lf k, lf b);
	void update();
	inline void push();
	inline void swap();
	void rotate();
}pool[MXN], *null;
int pidx;
Node* new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = nd->f = null;
	return nd;
}
void Node::modify(int tp, lf k, lf b) {
	memset(val, 0, sizeof(val));
	if (tp == 3) {//kx +ｂ
		val[0] = b; val[1] = k;
		return;
	}
	kp[0] = bp[0] = 1.0;
	for (int i = 1; i <= 16; i++) {
		kp[i] = kp[i - 1] * k;
		bp[i] = bp[i - 1] * b;
	}
	lf mul;
	if (tp == 1) {// sin
		lf sym = 1.0;
		for (int i = 1; i <= 16; i += 2) {
			mul = sym * fr[i];
			for (int j = 0; j <= i; j++) {
				val[j] += mul * com[i][j] * kp[j] * bp[i - j];
			}
			sym = -sym;
		}
	} else
	if (tp == 2) {// exp
		for (int i = 0; i <= 16; i++) {
			mul = fr[i];
			for (int j = 0; j <= i; j++) {
				val[j] += mul * com[i][j] * kp[j] * bp[i - j];
			}
		}
	} 
	//神tm 两个写混了
}
void Node::update() {
	for (int i = 0; i <= 16; i++) {
		sum[i] = val[i] + s[0]->sum[i] + s[1]->sum[i];
	}
}
inline void Node::push() {
	if (sig) {
		s[0]->swap();
		s[1]->swap();
		sig = 0;
	}
}
inline void Node::swap() {
	std::swap(s[0], s[1]);
	sig ^= 1;//^= 1 不是 = 1
}
void Node::rotate() {
	Node *gf = f->f;
	int spo;
	if ((spo = f == gf->s[1]) || f == gf->s[0]) gf->s[spo] = this;//神Tm写成了=f
	spo = this == f->s[1];
	(f->s[spo] = s[spo ^ 1])->f = f;
	(s[spo ^ 1] = f)->f = this;
	f->update();
	update();
	f = gf;
}
struct LCT {
	LCT() {
		null = new_();
		null->s[0] = null->s[1] = null->f = null;
	}
	
}lct;
void splay(Node *nd) {
	Node *f = nd->f, *gf, *orgf = f;
	int a, b;
	while ((a = nd == f->s[1]) || nd == f->s[0]) {
		gf = f->f;
		if ((b = f == gf->s[1]) || f == gf->s[0]) {
			(a == b ? f : nd)->rotate();
		}
		nd->rotate();
		f = nd->f;
	}
	if (f == orgf) {
		nd->update();
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
void mkrt(Node *nd) {
	access(nd);
	nd->swap();
}

Node *node[MXN];

struct _Main {
char op[25];
	void link(int u, int v) {
		mkrt(node[u]);
		node[u]->f = node[v];
	}
	void cut(int u, int v) {
		mkrt(node[u]); access(node[v]);
		node[u]->f = node[v]->s[0] = null;
	}
	void modify(int u, int f, lf a, lf b) {
		access(node[u]);
		node[u]->modify(f, a, b);
	}
	void query(int u, int v, lf x) {
		lf ans = 0, xp = 1.0; 
		if (u == v) {
			for (int i = 0; i <= 16; i++) {
				ans += xp * node[u]->val[i];
				xp *= x;
			}
			printf("%.8le\n", ans);
			return;
		}
		mkrt(node[u]);
		access(node[v]);
		if (node[u]->f == null) {
			printf("unreachable\n");
		} else {
			for (int i = 0; i <= 16; i++) {
				ans += xp * node[v]->sum[i];
				xp *= x;
			}
			printf("%.8le\n", ans);
		}
	}
	_Main() {
		int n, Qn;
		lf a, b, x;
		int u, v, f;
		
		for (int i = 0; i <= 16; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
			}
		}
		fr[0] = 1.0;
		for (int i = 1; i <= 16; i++) {
			fr[i] = fr[i - 1] / i;
		}
		
		read(n); read(Qn);
		scanf("%s", op);
		for (int i = 0; i < n; i++) { //编号0到n-1 ...
			node[i] = new_();
			read(f);
			scanf("%lf%lf", &a, &b);
			node[i]->modify(f, a, b);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'a') {//加边
				read(u); read(v);
				link(u, v);
			} else
			if (op[0] == 'd') {//断边
				read(u); read(v);
				cut(u, v);
			} else
			if (op[0] == 'm') {//修改
				read(u); read(f); scanf("%lf%lf", &a, &b);
				modify(u, f, a, b);
			} else
			if (op[0] == 't') {//询问
				read(u); read(v); scanf("%lf", &x);
				query(u, v, x);
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
}bzoj5020;
}
