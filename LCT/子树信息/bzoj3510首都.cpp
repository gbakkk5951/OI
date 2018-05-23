using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
int ans;
int fa[MXN];
int getfa(int a) {
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}

struct Node {
	Node *s[2], *f;
	int vsum, sum, sig, id;
	Node();
	void update() {
		sum = s[0]->sum + s[1]->sum + vsum + 1;
	}
	void rotate() {
		Node *gf = f->f;
		int spo = f == gf->s[1];
		if (spo || f == gf->s[0]) gf->s[spo] = this;//这个要判,不是判null 而是为了LCT判
		spo = this == f->s[1];
		(f->s[spo] = s[spo ^ 1])->f = f; 
		s[spo ^ 1] = f;//忘了  ^ 1
		f->f = this;
		f->update();
		update();
		f = gf;
	}
	void push() {
		if (sig) {
			swap(s[0], s[1]);
			s[0]->sig ^= 1;
			s[1]->sig ^= 1;
			sig = 0;
		}
	}
};
Node *null = (Node*)calloc(1, sizeof(Node));
Node::Node() {
	s[0] = s[1] = f = null;
	sum = 1;
}
Node node[MXN];
struct LCT {
	LCT() {
		null->s[0] = null->s[1] = null->f = null;
		null->id = -1;
	}
	void splay(Node *nd) {
		int a, b;
		Node *f = nd->f, *gf;
		nd->update();
		while (f != null && ((a = nd == f->s[1]) || nd == f->s[0])) {
			gf = f->f;
			if (gf != null && ((b = f == gf->s[1]) || f == gf->s[0])) {
				(a == b ? f : nd)->rotate();
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
	void mkrt(Node *nd) {
		access(nd);
		nd->sig = 1;
	}
	Node* getnxt(Node *nd) {
		splay(nd);
		nd = nd->s[1];
		nd->push();
		while (nd->s[0] != null) {
			nd = nd->s[0];
			nd->push();
		}
		splay(nd);
		return nd;
	}
}lct;

struct _Main {
	char op[5];
	void merge(int a, int b) {
		Node *na = node + a, *nb = node + b, *nr, *nxt;
		int ra, rb;
		lct.access(na);
		lct.access(nb);
		if (na->sum < nb->sum) {
			swap(na, nb);
			swap(a, b);
		}
		ra = getfa(a);
		rb = getfa(b);
		ans ^= ra;
		ans ^= rb;
		fa[rb] = fa[b] = ra;
		nr = node + ra;
		lct.mkrt(nb);
		nb->f = na;
		na->vsum += nb->sum;
		na->sum += nb->sum;
		lct.access(nb);
	//	lct.push_to(nr);//如果是别的点或许没被push到,但这是根节点,所以无所谓
		while (nr->id != b) {
			nxt = lct.getnxt(nr);
			if (nxt->sum - nr->sum > nr->sum || nxt->sum - nr->sum == nr->sum && nxt->id < nr->id) {
				fa[nr->id] = nxt->id;
				fa[nxt->id] = 0;
				nr = nxt;
			} else {
				break;
			}
		}
		//忘了mkrt
		lct.mkrt(nr);
		ans ^= nr->id;
	}
	int n;
	_Main() {
		int Qn;
		int x, y;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			node[i].id = i;
			ans ^= i;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'A') {
				read(x); read(y);
				merge(x, y);
			} else
			if (op[0] == 'Q') {
				read(x);
				printf("%d\n", getfa(x));
			} else 
			if (op[0] == 'X') {
				printf("%d\n", ans);
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
}bzoj3510;
}
