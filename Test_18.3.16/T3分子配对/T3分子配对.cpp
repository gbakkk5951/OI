using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int MXN = 200010;
typedef long long lld;
typedef double lf;
struct Snode {
	Snode *s[2], *f, *nxt;
	lf m[2], v;
	int rand, pos;
	void mark(lf l, lf r) {
		m[0] = l, m[1] = r, v = (l + r) /2.0;
	}
};
int sa[MXN]; int rk[MXN]; int h[MXN];
class SuffixTreap {
	typedef Snode Node;
public:
	Node pool[MXN];
	int pidx;
	Node* new_(int pos, Node *f = 0) {
		Node *nd = &pool[pidx++];
		nd->nxt = lst;
		lst = nd;
		nd->f = f;
		nd->pos = pos;
		nd->rand = rand();
		return nd;
	}
	Node *root, *lst;
	int *str, len;
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf) {
			gf->s[f == gf->s[1]] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s) {
			s->f = f;
		}
		f->f = nd;
		nd->s[pos ^ 1] = f;
	}
	int cmp (int pos, Node *nd) {
		if (str[pos] != str[nd->pos]) {
			return str[pos] > str[nd->pos];
		}
		return lst->v > nd->nxt->v; //忘了->nxt 
	}
	void insert(int pos) {
		Node *nd = root;
		while (1) {
			int spo = cmp(pos, nd);
			if (nd->s[spo]) {
				nd = nd->s[spo];
			} else {
				nd = nd->s[spo] = new_(pos, nd);
				break;
			}
		}
		while (nd->f && nd->rand < nd->f->rand) {
			rotate(nd);
		}
		lf m[2] = {0, 1};
		Node *f = nd->f;
		if (f) {
			int spo = nd == f->s[1];
			m[spo] = f->m[spo];
			m[spo ^ 1] = f->v;
		} else {
			root = nd;
		}
		remark(nd, m[0], m[1]);
	}
	void remark(Node *nd, lf l, lf r) {
		if (nd) {
			nd->mark(l, r);
			remark(nd->s[0], l, nd->v);
			remark(nd->s[1], nd->v, r);
		}
	}
	void getsa(Node *nd, int &idx) {
		if (nd) {
			getsa(nd->s[0], idx);
			sa[idx++] = nd->pos;
			getsa(nd->s[1], idx);
		}
	}
	void getrk() {
		for (int i = 1; i <= len; i++) {
			rk[sa[i]] = i;
		}
	}
	void geth() {
		int i, j, k;
		for (i = 1, k = 0; i < len; i++) {
			j = sa[rk[i] - 1];
			for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
			h[rk[i]] = k;
		}
	}
	void build(int *_str, int _len) {
		str = _str; len = _len;
		root = new_(len);
		root->mark(0, 1);
		for (int i = len - 1; i >= 1; i--) {
			insert(i);
		}
		int idx;
		getsa(root, idx = 1);
		getrk();
		geth();
	}	
	
}stree;
struct Node {
	Node *s[2];
	int sum;
}pool[MXN*19], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	nd->sum = 1;
	return nd;
}
Node *root[MXN];
int len;
class ChairTree {
public:
	ChairTree() {
		null = new_();
		null->sum = 0;
		null->s[0] = null->s[1] = null;
		root[0] = null;
	}
	void insert(int ia, int ib, int val) {
		Node *a = root[ia] = new_();
		Node *b = root[ib];
		a->sum = b->sum + 1;
		int nl = 1; int nr = len; int mid;
		int spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			a->s[spo ^ 1] = b->s[spo ^ 1];
			a = a->s[spo] = new_();
			b = b->s[spo];
			a->sum = b->sum + 1;
		}
	}
	int query(Node *a, Node *b, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return b->sum - a->sum;
		}
		int mid = nl + nr >> 1;
		int sum = 0;
		if (l <= mid) { // 又不小心写成了nl
			sum += query(a->s[0], b->s[0], nl, mid, l, r);
		}
		if (mid < r) {
			sum += query(a->s[1], b->s[1], mid + 1, nr, l, r);
		}
		return sum;
	}
}tree;

int st[MXN][18];
void getst() {
	for (int i = 1; i <= len; i++) {
		st[i][0] = h[i];
	}
	for (int I = 1; 1 << I < len; I++) {
		for (int i = 1; i <= len; i++) {
			st[i][I] = st[i][I - 1];
			if (i - (1 << I - 1) >= 1) {
				st[i][I] = min(st[i][I], st[i - (1 << I - 1)][I - 1]);
			}
		}
	}
}
struct _Main {

	int query(int l, int r) {
		if (l == r) return (n - 1);
		r--;
		int ql = rk[l], qr = rk[l];
		for (int I = 17; I >= 0; I--) {
			if (ql > (1 << I) && st[ql][I] >= r - l + 1) {
				ql -= 1 << I;
			}
		}
		for (int I = 17; I >= 0; I--) {
			if (qr + (1 << I) <= len && st[qr + (1 << I)][I] >= r - l + 1) {
				qr += 1 << I;
			}
		}
		int sum = 0;
		if (l - (r - l + 2) >= 1) {
			sum += tree.query(root[ql - 1], root[qr], 1, len, n + 1, n + l - (r - l + 2));
		}
		if (r + 2 <= len) {
			sum += tree.query(root[ql - 1], root[qr], 1, len, n + r + 2, len);
		}
		return sum;
	}
	//以rk为root插入pos
	int arr[MXN];
	int n;
	_Main() {
		int Qn;
		read(n);
		for (int i = 0; i < n; i++) {
			read(arr[i]);
		}
		for (int i = n - 1; i >= 1; i--) {
			arr[i] -= arr[i - 1];
		}
		arr[n] = -0x3f3f3f3f + 1;
		len = 2 * n;
		for (int i = n + 1; i <= len - 1; i++) {
			arr[i] = -arr[i - n];
		}
		arr[len] = -0x3f3f3f3f;
		
		stree.build(arr, len);
		/*
		for (int i = 1; i <= len; i++) {
			printf("rk = %d\n", rk[sa[i]]);
			for (int j = sa[i]; j <= len; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n%d\n", h[i]);
		}*/
		for (int i = 1; i <= len; i++) {
			tree.insert(i, i - 1, sa[i]);
		}
		getst();
		int l, r;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(l); read(r);
			printf("%d\n", query(l, r));
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
}T3;
}
