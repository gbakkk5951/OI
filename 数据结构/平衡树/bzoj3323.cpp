using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
namespace OI {
typedef long long lld;
const lld MOD = 20130426;
const int MXN = 200050;
struct Node {
	lld add, mul, val;
	int size;
	Node *s[2], *f;
}*null;
struct Splay {
Node *root;
Node pool[MXN];
int pidx;
Node *new_(Node *f) {
	Node *nd = &pool[pidx++];
	nd->f = f;
	nd->s[0] = nd->s[1] = null;
	nd->size = 1;
	nd->mul = 1;
	return nd;
}
Splay() {
	null = new_(null);
	null->size = 0;
	null->s[0] = null->s[1] = null->f = null;
}
void update(Node *nd) {
	nd->size = 1;
	for (int i = 0; i < 2; i++) {
		nd->size += nd->s[i]->size;
	}
}
Node *build(int num, Node *f) {
	Node *nd = null;
	if (num > 0) {
		nd = new_(f);
		nd->f = f;
		nd->s[0] = build(num >> 1, nd);
		nd->s[1] = build(num - 1 - (num >> 1), nd);
		update(nd);
	}
	return nd;
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
void splay(Node *nd, Node *rt) {
	update(nd);//删除之后
	Node *f;
	while ((f = nd->f) != rt) {
		if (f->f != rt) {
			if ((nd == f->s[1]) == (f == f->f->s[1])) {
				rotate(f);
			} else {
				rotate(nd);
			}
		}
		rotate(nd);
	}
	if (f == null) {
		root = nd;
	}
}
Node *find(int rk) {
	Node *nd = root;
	while (1) {
		push(nd);
		if (nd->s[0]->size > rk + 1) {
			nd = nd->s[0];
		} else
		if (nd->s[0]->size == rk + 1) {
			return nd;
		} else {
			rk -= nd->s[0]->size + 1;//-=后面的-
			nd = nd->s[1];
		}
	}
}

void inline add(Node *nd, lld v) {
	nd->add = (nd->add + v) % MOD;
	nd->val = (nd->val + v) % MOD;
}
void inline mul(Node *nd, lld v) {
	nd->mul = nd->mul * v % MOD;
	nd->add = nd->add * v % MOD;
	nd->val = nd->val * v % MOD;
}
void push(Node *nd) {
	for (int i = 0; i < 2; i++) {
		if (nd->s[i] != null) {
			if (nd->mul != 1) mul(nd->s[i], nd->mul);
			if (nd->add != 0) add(nd->s[i], nd->add);
		}
	}
	nd->add = 0; nd->mul = 1;
}
void getrange(int l, int r) {
	Node *nl, *nr;
	nl = find(l - 1);
	splay(nl, null);
	nr = find(r + 1);
	splay(nr, nl);
}
void add(int l, int r, lld v) {
	getrange(l, r);
	add(root->s[1]->s[0], v);
}
void mul(int l, int r, lld v) {
	getrange(l, r);
	mul(root->s[1]->s[0], v);
}
void query(Node *nd, lld &tmp, lld &v, lld &ans) {
	push(nd);
	if (nd->s[0] != null) {
		query(nd->s[0], tmp, v, ans);
	}
	if (ans != -1) {
		ans = (ans + tmp * nd->val) % MOD;
		tmp = tmp * v % MOD;	
	} else {
		ans = 0;
	}
	if (nd->s[1] != null) {
		query(nd->s[1], tmp, v, ans);
	}
}
void insert(int rk) {
	Node *nd = root;
	int spo;
	while (1) {
		push(nd);
		if (spo = nd->s[0]->size < rk + 1) {
			rk -= nd->s[0]->size + 1;
		}
		if (nd->s[spo] != null) {
			nd = nd->s[spo];
		} else {
			nd = nd->s[spo] = new_(nd);
			break;
		}
	}
	splay(nd, null);
}
void erase(Node *nd) {
	int spo;
	push(nd);
	while (nd->s[spo = (nd->s[0] == null)] != null) {
		push(nd->s[spo]);
		rotate(nd->s[spo]);
	}
	Node *f = nd->f;
	f->s[nd == f->s[1]] = null;
	splay(f, null);
}
}tree;

struct _Main {
char op[15];
	_Main() {
		int Qn, l, r;
		lld ans, tmp, v;
		tree.root = tree.build(100005, null);
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'a') { // add
				read(l); read(r); read(v);
				tree.add(l, r, v % MOD);
			} else
			if (op[0] == 'q') { //query
				read(v);
				tree.query(tree.root, tmp = 1, v %= MOD, ans = -1);//-1 为哨兵值 
				//ans %= mod;
				//ans += ans < 0 ? MOD : 0;
				printf("%lld\n", ans);
			} else 
			if (op[3]) { //mulx
				read(l); read(r);
				Node *nd = tree.find(r);
				tree.splay(nd, null);
				tree.add(r + 1, r + 1, nd->val);
				tree.erase(nd);
				tree.insert(l);
			} else { //mul
				read(l); read(r); read(v);
				tree.mul(l, r, v % MOD);
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a = a * 10 + t - '0';
		}
	}
}bzoj3323;
}
