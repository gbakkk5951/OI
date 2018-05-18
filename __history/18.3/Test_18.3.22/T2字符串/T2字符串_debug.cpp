using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
typedef double lf;
const int INF = 0x3f3f3f3f;
const int MXN = 100010;
struct SNode {
	SNode *s[2], *f, *nxt;
	lf m[2], v;
	int rand, pos;
	void mark(lf l, lf r) {
		m[0] = l, m[1] = r, v = (l + r) / 2.0;
	}
};
int sa[MXN << 1], h[MXN << 1], rk[MXN << 1];
struct SuffixTreap {
	typedef SNode Node;
	Node pool[MXN << 1];
	int pidx;
	Node *lst;
	Node *new_(int pos, Node *f = 0) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		nd->rand = rand();
		nd->pos = pos;
		nd->nxt = lst;
		lst = nd;
		return nd;
	}
	Node *root;
	int len, *str;
	int cmp(int pos, Node *nd) {
		if (str[pos] != str[nd->pos]) {
			return str[pos] > str[nd->pos];
		} 
		return lst->v > nd->nxt->v;
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf) {
			gf->s[gf->s[1] == f] = nd;
		}
		int spo = nd == f->s[1];
		s = f->s[spo] = nd->s[spo ^ 1];
		if (s) {
			s->f = f;
		}
		f->f = nd;
		nd->s[spo ^ 1] = f;
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
		while (nd->f && nd->f->rand < nd->rand) {
			rotate(nd);
		}
		Node *f;
		lf m[2] = {0, 1};
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
			sa[idx++] = nd->pos;
			getsa(nd->s[1], idx);
		}
	}
	void getrk() {
		for (int i = 0; i < len; i++) {
			rk[sa[i]] = i;
		}
	}
	void geth() {
		int i, j, k;
		for (i = 0, k = 0; i < len - 1; i++) {
			j = sa[rk[i] - 1];
			for (k ? k-- : 0; str[j + k] == str[i + k]; k++);
			h[rk[i]] = k;
		}
	}
	void build(int *_str, int _len) {
		srand(2333397llu ^ (unsigned long long) new char);
		len = _len; str = _str;
		root = new_(len - 1);
		root->mark(0, 1);
		for (int i = len - 2; i >= 0; i--) {
			insert(i);
		}
		int t = 0;
		getsa(root, t);
		getrk();
		geth();
	}
}stree;
int st[MXN << 1][18];
int n, len, need;
int mxbit;
void getst() {
	for (mxbit = 0; 1 << (mxbit + 1) <= len; mxbit++);
	for (int i = 0; i < len; i++) {
		st[i][0] = h[i];
	}
	for (int I = 1; I <= mxbit; I++) {
		for (int i = (1 << I) - 1; i < len; i++) { //不得使用超出范围的pow
			st[i][I] = min(st[i][I - 1], st[i - (1 << I - 1)][I - 1]);
		}
	}
}
struct Node {
	Node *s[2];
	int sum, id;
}pool[MXN * 18 * 2], *null;
int pidx;
Node *new_(int id) {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	nd->id = id;
	return nd;
}
struct ChairTree {
	Node *root[MXN << 1];
	ChairTree() {
		null = new_(0);
		null->s[0] = null->s[1] = null;
		root[0] = null;
	}
	void insert(int ia, int ib, int pos, int add) { //第一次ia != ib 之后ia = ib
		if (root[ia] == 0) {
			root[ia] = new_(ia);
			root[ia]->sum = root[ib]->sum;
		}
		Node *a = root[ia], *b = root[ib];
		a->sum += add;
		int nl = n, nr = len - 1, mid, spo;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (spo = pos > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (a->s[spo ^ 1] == null) {
				a->s[spo ^ 1] = b->s[spo ^ 1];
			}
			b = b->s[spo];
			if (a->s[spo] == null|| a->s[spo]->id != ia) {
				a->s[spo] = new_(ia);
				a->s[spo]->sum = b->sum;
			}
			a = a->s[spo];
			a->sum += add;
		}
	}
	int query(Node *nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r || nd->sum == 0) {
			return nd->sum;
		}
		int mid = nl + nr >> 1, sum = 0;
		if (l <= mid) {
			sum += query(nd->s[0], nl, mid, l, r);
		}
		if (r > mid) {
			sum += query(nd->s[1], mid + 1, nr, l, r);
		}
		return sum;
	}
}ctree;
struct _Main {
	lld ans[MXN];
	int str[MXN << 1];
	int bl[MXN << 1];
	int slen[MXN];
	int readstr(int* str) {
		int t;
		int idx = 0;
		while (!isalpha(t = getchar()));
		do {
			str[idx++] = t;
		} while ( isalpha(t = getchar()));
		return idx;
	}
	int lst[MXN];
	void prepro() {
		scanf("%d%d", &n, &need);
		if (need > n) return;
		for (int i = 1; i < n; i++) {
			ctree.root[i] = null;
		}
		for (int i = 1; i <= n; i++) {
			slen[i] = readstr(str + len);
			for (int j = len; j < len + slen[i]; j++) {
				bl[j] = i;
			}
			len += slen[i];
			str[len++] = -INF + n - i;//分隔符相同会WA掉 
		}
		if (need == 1) return;
		stree.build(str, len);
		getst();
		for (int i = n; i <= len - 1; i++) {
			int bl = this->bl[sa[i]];
			if (lst[bl]) {
				ctree.insert(i, i - 1, lst[bl], -1);
				ctree.insert(i, i, i, 1);
			} else {
				ctree.insert(i, i - 1, i, 1);
			}
			lst[bl] = i;
		}
	}
	int ask(int rk) { //need <= n && need > 1
		int l, r, mid;
		int ql, qr;
		l = 0; r = h[rk];
		if (rk + 1 < len) {
			r = max(r, h[rk + 1]);
		}
		while (l < r) {
			mid = (l + r >> 1) + 1;
			ql = qr = rk;
			for (int I = mxbit; I >= 0; I--) {
				if (ql - (1 << I) >= n) {
					if (st[ql][I] >= mid) {
						ql -= 1 << I;
					}
				}
			}
			for (int I = mxbit; I >= 0; I--) {
				if (qr + (1 << I) <= len - 1) {
					if (st[qr + (1 << I)][I] >= mid) {
						qr += 1 << I;
					}
				}
			}
			if (ctree.query(ctree.root[qr], n, len - 1, ql, qr) >= need) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}
	void solve() {
		if (need == 1) {
			for (int i = 1; i <= n; i++) {
				printf("%lld ", (lld)slen[i] * (slen[i] + 1) >> 1);
			}
			return;
		}
		if (need > n) {
			for (int i = 1; i <= n; i++) {
				printf("0 ");
			}
			return;
		}
		for (int i = n; i <= len - 1; i++) {
			ans[bl[sa[i]]] += ask(i);
		}
		for (int i = 1; i <= n; i++) {
			printf("%lld ", ans[i]);
		}
	}
	_Main() {
		prepro();
		solve();
	}
}T2;
}
