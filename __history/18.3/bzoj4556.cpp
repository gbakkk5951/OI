using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
namespace OI {
typedef long long lld;
typedef double lf;
const int MXN = 100010;
const int INF = 0x3f3f3f3f;
int lrand() {
	return rand() << 15 | rand();
}
struct SNode {
	SNode *s[2], *f, *nxt;
	int pos, rand;
	lf m[2], v;
	void mark(lf a, lf b) {
		m[0] = a, m[1] = b, v = (a + b) /2.0;
	}
};
int h[MXN], sa[MXN], rank[MXN];
int len;
class SuffixTreap {
	typedef SNode Node;
public:
	Node pool[MXN];
	int pidx;
	int len, *str;
	Node *root, *lst;
	Node *new_(int pos, Node *f = 0) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		nd->pos = pos;
		nd->rand = lrand();
		nd->nxt = lst;
		lst = nd;
		return nd;
	}
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
	int cmp(int pos, Node *nd) {
		if (str[pos] != str[nd->pos]) {
			return str[pos] > str[nd->pos];
		}
		return lst->v > nd->nxt->v;
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
		
		while (nd->f && nd->rand > nd->f->rand) {
			rotate(nd);
		}
		lf m[2] = {0, 1};
		Node *f;
		if (f = nd->f) {
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
			sa[++idx] = nd->pos;
//			printf("sa %d = %d\n", idx, nd->pos);
			getsa(nd->s[1], idx);
		}
	}
	void getrank() {
		for (int i = 1; i <= len; i++) {
			rank[sa[i]] = i;
		}
	}
	void geth() {
		int j, k = 0;
		for (int i = 1; i <= len - 1; i++) {
			j = sa[rank[i] - 1];
			for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
			h[rank[i]] = k;
		}
	}
	void build(int *_str, int _len) {
		str = _str; len = _len;
		int t;
		root = new_(len);
		root->mark(0, 1);
		for (int i = len - 1; i >= 1; i--) {
			insert(i);
		}
		getsa(root, t = 0);
		getrank();
		/*
		printf("sa: ");
		for (int i = 1; i <= len; i++) {
			printf("%d ", sa[i]);
		}
		printf("\nrk: ");
		for (int i = 1; i <= len; i++) {
			printf("%d ", rank[i]);
		}
		*/
		geth();
//		printf("build finish");
	}
}stree;
struct Node {
	Node *s[2];
	int sum;
}pool[MXN * 18], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
Node *root[MXN];
class ChairTree {
public:
	ChairTree() {
		null = new_();
		null->s[0] = null->s[1] = null;
		root[0] = null;
	}
	int query(Node *a, Node *b, int nl, int nr, int l, int r) {
//		printf("q(%d, %d, %d, %d, %d, %d)\n", a - pool, b - pool, nl, nr, l, r);
		if (l <= nl && nr <= r) {
			return b->sum - a->sum;
		}
		int mid = nl + nr >> 1;
		int sum = 0;
		if (l <= mid) { //不要把nl与mid去比较 
			sum += query(a->s[0], b->s[0], nl, mid, l, r);
		}
		if (mid < r) {//不要把nr与mid去比较
			sum += query(a->s[1], b->s[1], mid + 1, nr, l, r);
		}
		return sum;
	}
	void insert(int ia, int ib, int val) {
		Node *a = root[ia] = new_(), *b = root[ib];
		a->sum = b->sum + 1;
		int nl = 1, nr = len, mid, pos;
		while (nl < nr ) {
			mid = nl + nr >> 1;
			if (pos = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			a->s[pos ^ 1] = b->s[pos ^ 1];
			a = a->s[pos] = new_();
			b = b->s[pos];
			a->sum = b->sum + 1;
		}
	}
}tree;
int st[MXN][17];
void getst() {
	for (int i = 2; i <= len; i++) {
		st[i][0] = h[i];
	}
	for (int I = 1; 1 << I <= len; I++) {
		for (int i = (1 << I) + 1; i <= len; i++) {
			st[i][I] = min(st[i][I - 1], st[i - (1 << I - 1)][I - 1]);
//			printf("st %d %d = %d\n", i, I, st[i][I]);
		}
	}
}
//str数组从1开始用
struct _Main {
	int str[MXN];
	int readstr(int *str) {
		int idx = 0, t;
		while (!isalpha(t = getchar()));
		do {
			str[++idx] = t;
		} while (isalpha(t = getchar()));
		return idx;
	}
	int getans(int a, int b, int c, int d) {
		int l = 0, r = min(d - c + 1, b - a + 1), mid;
		int tl, tr;
		while (l < r) {
			mid = (l + r >> 1) + 1;
//			printf("mid = %d\n", mid);
			tl = tr = rank[c];
			for (int I = 16; I >= 0; I--) {
				if (tl - (1 << I) > 0 && st[tl][I] >= mid) {
					tl -= 1 << I;
				}
			}
			for (int I = 16; I >= 0; I--) {
				if (tr + (1 << I) <= len && st[tr + (1 << I)][I] >= mid) {
					tr += 1 << I;
				}
			}
//			printf("tl = %d, tr = %d\n", tl, tr);
			if (tree.query(root[tl - 1], root[tr], 1, len, a, b - mid + 1) > 0) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}
	_Main() {
	
//		srand(time(0));
		int a, b, c, d;
		int Qn;
		/*
		len = 100000; Qn = 10000;
		for (int i = 1; i <= len; i++) {
			str[i] = rand() % 2;
		}*/
		
		read(a); read(Qn);	
		len = readstr(str);
		str[++len] = -INF;

		/*
		for (int i = 1; i <= len; i++) {
			printf("%d ", str[i]);
		}
		printf("\n");
		*/
		stree.build(str, len);
		/*
		for (int i = 1; i <= len; i++) {
			for (int j = sa[i]; j <= len; j++) {
				printf("%d ", str[j]);
			}
			printf("\n%d\n", h[i]);
		}*/
		getst();
		for (int i = 1; i <= len; i++) {
			tree.insert(i, i - 1, sa[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
//			a = lrand() % (len - 1) + 1; b = lrand() % (len - 1) + 1; c = lrand() % (len - 1) + 1; d = lrand() % (len - 1) + 1;
//			if (a > b) swap(a, b);
//			if (c > d) swap(c, d);
//			printf("Q %d %d %d %d\n", a, b, c, d);
			read(a); read(b); read(c); read(d);
			printf("%d\n", getans(a, b, c, d));
//			getans(a, b, c, d);
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
}bzoj4556;
}
//主席树空间其实应该在log上取整的基础上+1 
