using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 5e4 + 10;
struct Node {
	Node *s[2], *f;
	lld lsum, rsum, ans, sum, val, tag, size;
	int sig;
	inline void push();
	inline void add(lld v);
	inline void swap();
	void update();
	void rotate();
}pool[MXN], *null;

inline void Node::add(lld v) {
	tag += v;
	val += v;
	sum += size * v;
	ans += ((size + 3) * size + 2) * size / 6 * v;//忘了乘v
	v *= (1 + size) * size >> 1;
	lsum += v;
	rsum += v;
}
void Node::update() {
	size = s[0]->size + 1 + s[1]->size;
	sum = s[0]->sum + val + s[1]->sum;
	ans = s[0]->ans + s[1]->ans
		+ s[0]->rsum * (s[1]->size + 1)
		+ s[1]->lsum * (s[0]->size + 1)
		+ (s[0]->size + 1) * (s[1]->size + 1) * val;
	rsum = s[0]->rsum 
		 + (s[0]->size + 1) * (val + s[1]->sum)
		 + s[1]->rsum;
	lsum = s[1]->lsum 
		 + (s[1]->size + 1) * (val + s[0]->sum)
		 + s[0]->lsum;
}
inline void Node::push() {
	if (sig) {
		s[0]->swap();
		s[1]->swap();
		sig = 0;
	}
	if (tag) {
		if (s[0] != null) s[0]->add(tag);
		if (s[1] != null) s[1]->add(tag);
		tag = 0;
	}
}
void Node::rotate() {
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
inline void Node::swap() {
	sig ^= 1;
	std::swap(s[0], s[1]);
	std::swap(lsum, rsum);
}

int pidx;
inline Node *new_(int val) {
	Node *nd = &pool[pidx++];
	nd->val = val;
	nd->s[0] = nd->s[1] = nd->f = null;
	return nd;
}

struct LCT {
	LCT() {
		null = new_(0);
		null->s[0] = null->s[1] = null->f = null;
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
	void cut(int a, int b) {
		if (a == b) return;
		mkrt(node[a]);
		access(node[b]);
		node[a]->f = null;
		if (node[b]->s[0] == node[a]) {
			node[b]->s[0] = null;
		}
	}
	void link(int a, int b) {
		if (a == b) return;
		mkrt(node[a]);
		access(node[b]);
		if (node[a]->f == null) {
			node[a]->f = node[b];
		}
	}
	void add(int a, int b, lld c) {
		if (a == b) {
			access(node[a]);
			node[a]->val += c;
			return;
		}
		mkrt(node[a]);
		access(node[b]);
		if (node[a]->f != null) {
			node[b]->add(c);
		}
	}
	lld gcd (lld a, lld b) {
		while (b) {
			swap(a, b);
			b %= a;
		}
		return a;
	}
	int n;
	void query(int a, int b) {
		if (a == b) {
			access(node[a]);//标记
			printf("%lld/1\n", node[a]->val);
			return;
		}
		mkrt(node[a]);
		access(node[b]);
		if (node[a]->f == null) {
			printf("-1\n");
			return;
		}
		lld fz, fm, g;
		fz = node[b]->ans;
		fm = node[b]->size * (node[b]->size + 1) >> 1;
		g = gcd(fz, fm);
		printf("%lld/%lld\n", fz / g, fm / g);
	}
	_Main() {
		int Qn, op, a, b, c;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(a);
			node[i] = new_(a);
		}
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			link(a, b);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(a); read(b);
			if (op == 1) { //删边
				cut(a, b);
			} else
			if (op == 2) {//加边
				link(a, b);
			} else
			if (op == 3) {//链加
				read(c);
				add(a, b, c);
			} else {//询问
				query(a, b);
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
