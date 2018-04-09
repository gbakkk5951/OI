using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1500010;
const int INF = 0x3f3f3f3f;
int fa[MXN];
inline int getfa(int a) {
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}
inline void setfa(int a, int b) {
	fa[a] = b;
}

struct Node {
	int val, pos, mx, mxpos, sig;
	Node *s[2], *f;
}pool[MXN], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->val = -1;
	nd->mx = -1;
	nd->s[0] = nd->s[1] = nd->f = null;
	return nd;
}
struct LCT {
	LCT() {
		null = new_();
		null->s[0] = null->s[1] = null->f = null;
	}
	void push(Node *nd) {
		if (nd->sig) {
			swap(nd->s[0], nd->s[1]);
			nd->s[0]->sig ^= 1;
			nd->s[1]->sig ^= 1;
			nd->sig = 0;
		}
	}
	int top;
	Node *stk[MXN];
	void push_to(Node *nd) {
		while (nd != null) {
			stk[++top] = nd;
			nd = nd->f;
		}
		while (top) {
			push(stk[top--]);
		}
	}
	char heroot(Node *nd) {
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
		if (s != null) {
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
	void mkroot(Node *nd) {
		access(nd);
		nd->sig = 1;
	}
	void update(Node *nd) {
		nd->mx = nd->val; nd->mxpos = nd->pos;
		for (int i = 0; i < 2; i++) {
			if (nd->s[i]->mx > nd->mx) {
				nd->mx = nd->s[i]->mx;
				nd->mxpos = nd->s[i]->mxpos;
			}
		}
	}
	void cut(Node *a, Node *b) {
		mkroot(a);
		access(b);
		b->s[0] = a->f = null;
	}
	void link(Node *a, Node *b) {
		mkroot(a);
		a->f = b;
	}
}tree;
Node *node[MXN];
struct Edge {
	int s, t, a, b;
}edge[MXN];
bool cmp(const Edge &a, const Edge &b) {
	return a.a < b.a;
}
struct _Main {
	int n, m;
	void prepro() {
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(edge[i].s); read(edge[i].t); 
			read(edge[i].a); read(edge[i].b);
			if (edge[i].s == edge[i].t) {
				i--; m--;
			}
		}
		for (int i = 1; i <= n; i++) {
			node[i] = new_();
		}
		sort(edge + 1, edge + m + 1, cmp);
		for (int i = 1; i <= m; i++) {
			node[n + i] = new_();
			node[n + i]->pos = i;
			node[n + i]->val = edge[i].b;
		}
	}
	void solve() {
		int a = 0, ans = INF;
		for (int i = 1; i <= m; i++) {
			a = edge[i].a;
			if (addedge(i) && getfa(1) == getfa(n)) {
				ans = min(ans, a + getmx(node[1], node[n])->val);
			}
		}
		if (ans < INF) {
			printf("%d", ans);
		} else {
			printf("-1");
		}
	}
	Node *getmx(Node *a, Node *b) {
		tree.mkroot(a);
		tree.access(b);
		return node[b->mxpos + n];
	}
	_Main() {
		prepro();
		solve();
	}
	char addedge(int id) {
		int a = edge[id].s, b = edge[id].t;
		char lnk = 0;
		if (getfa(a) != getfa(b)) {
			setfa(getfa(a), getfa(b));
			lnk = 1;
		} else {
			Node *nd = getmx(node[a], node[b]);
			if (nd->val > edge[id].b) {
				lnk = 1;
				tree.cut(node[edge[nd->pos].s], nd); //abºÍstÅª»ì 
				tree.cut(node[edge[nd->pos].t], nd);
			}
		}
		if (lnk) {
			tree.link(node[a], node[id + n]);
			tree.link(node[id + n], node[b]);
			return 1;
		}
		return 0;
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
}bzoj3669;
}
