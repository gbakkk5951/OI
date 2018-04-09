using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 100010, MXM = 1000010;
struct Node {
	Node *s[2], *f;
	int id, val, mx, pos, sig;
}pool[MXN + MXM], *null;
int pidx;
Node *new_(int id, int val) {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = nd->f = null;
	nd->id = id; nd->val = val; nd->pos = nd->mx = -1;
	return nd;
}
Node *vn[MXN], *en[MXM];

class LCT {
public:
	LCT() {
		null = new_(-1, -1);
		null->mx = -1;
		null->s[0] = null->s[1] = null->f = null;
	}
	int heroot(Node *nd) {
		return nd == nd->f->s[0] || nd == nd->f->s[1];
	}
	void inline update(Node *nd) {
		nd->mx = nd->val;
		nd->pos = nd->id;
		for (int i = 0; i < 2; i++) {
			if (nd->s[i]->mx > nd->mx) {
				nd->mx = nd->s[i]->mx;
				nd->pos = nd->s[i]->pos;
			}
		}
	}
	void inline rotate(Node *nd) {
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
		update(nd);
		Node *f;
		while (heroot(nd)) {
			if (heroot(f = nd->f)) {
				if ((nd == f->s[1]) == (f  == f->f->s[1])) {
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
	Node *stk[MXN + MXM];
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
	void link(Node *a, Node *b) {
		mkroot(a);
		a->f = b;
	}
	void cut(Node *a, Node *b) {
		mkroot(a);
		access(b);
		a->f = b->s[0] = null;
	}
}lct;
struct Edge {
	int a, b, val;
	bool operator < (const Edge &dst) const {
		if (a != dst.a) {
			return a < dst.a;
		}
		return b < dst.b;
	}
}edge[MXM];
int fa[MXN];
int getfa(int a) {
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}
void setfa(int a, int b) {
	fa[a] = b;
}
struct _Main {
	char del[MXM];
	int q[MXN][3];
	int ans[MXN];
	_Main() {
		int n, Qn, m;
		int a, b, c, d, e;
		Node *tmp;
		read(n); read(m); read(Qn);
		memset(ans + 1, -1, Qn * sizeof(int));

		for (int i = 1; i <= m; i++) {
			read(edge[i].a); read(edge[i].b); read(edge[i].val);
			if (edge[i].a > edge[i].b) {
				swap(edge[i].a, edge[i].b);
			}
		}
		sort(edge + 1, edge + m + 1);//一开始写成了 edge + n + 1 
		for (int Q = 1; Q <= Qn; Q++) {
			for (int i = 0; i < 3; i++) {
				read(q[Q][i]);
			}
			if (q[Q][0] == 2) {
				a = q[Q][1]; b = q[Q][2];
				if (a > b) {
					swap(a, b);
				}
				q[Q][1] = lower_bound(edge + 1, edge + m + 1, (Edge){a, b, 0}) - edge;
				del[q[Q][1]] = 1;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			vn[i] = new_(-1, -1);
		}
		for (int i = 1; i <= m; i++) {
			en[i] = new_(i, edge[i].val);
		}
		for (int i = 1; i <= m; i++) {
			if (!del[i]) {
				insert(i); //不能直接调用addedge函数，因为初始图不一定是树 
			}
		}
		for (int Q = Qn; Q >= 1; Q--) {
			if (q[Q][0] == 2) {
				e = q[Q][1];
				insert(e);
			} else {
				if (q[Q][1] != q[Q][2]) {
					tmp = findmx(q[Q][1], q[Q][2]);
					ans[Q] = tmp->mx;
				} else {
					ans[Q] = 0;
				}
			}
		}
		for (int Q = 1; Q <= Qn; Q++) {
			if (ans[Q] >= 0) {
				printf("%d\n", ans[Q]);
			}
		}
	}
	Node *findmx(int a, int b) {
		lct.mkroot(vn[a]);
		lct.access(vn[b]);
		return en[vn[b]->pos];
	}
	void deledge(int e) {
		lct.cut(en[e], vn[edge[e].a]);
		lct.cut(en[e], vn[edge[e].b]);
	}
	void addedge(int e) {
		lct.link(en[e], vn[edge[e].a]);
		lct.link(en[e], vn[edge[e].b]);	
	}
	void insert(int e) {
		
		if (getfa(edge[e].a) != getfa(edge[e].b)) {
			addedge(e);
			setfa(getfa(edge[e].a), getfa(edge[e].b));
		} else {
			Node *tmp = findmx(edge[e].a, edge[e].b);
			if (tmp->mx > edge[e].val) {
				deledge(tmp->id);
				addedge(e);				
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
}bzoj2594;
}

