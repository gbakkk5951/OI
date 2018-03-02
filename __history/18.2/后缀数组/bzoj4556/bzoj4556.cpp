using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <ctime>
namespace OI {
typedef double lf;
const int 
	C_MAXN = 2400000,
	S_MAXN = 100020,
	INF = 0x3f3f3f3f,
	ZHENG = 0,
	REV = 1
;

int lrand() {
	return rand() << 15 | rand();
}
struct S_Node {
	S_Node *s[2], *f;
	lf m[2], v;
	int rand, idx;
	void mark(lf a, lf b) {
		m[0] = a; m[1] = b; v = (a + b) / 2.0;
	}
};

int h[S_MAXN], sa[S_MAXN], rank[S_MAXN];
class SuffixTreap {
typedef S_Node Node;
private:
	Node *root;
	Node *node[S_MAXN];
	Node pool[S_MAXN];
	int pidx;
	lf tot;
	int *str, len;
	Node *new_node(int idx, Node *f = 0) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		node[idx] = nd;
		nd->idx = idx;
		nd->rand = lrand();
		return nd;
	}
	int cmp(int idx, Node *nd) {
		if (str[idx] != str[nd->idx]) {
			return str[idx] > str[nd->idx];
		}
		return tot > node[nd->idx + 1]->v;
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
	
	void insert(int idx) {
		Node *nd = root;
		while (1) {
			int pos = cmp(idx, nd);
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = new_node(idx, nd);
				break;
			}
		}
		while (nd->f && nd->f->rand > nd->rand) {
			rotate(nd);
		}
		mark_new(nd);
	}
	void mark_new(Node *nd) {
		lf m[2] = {0, 1};
		if (Node *f = nd->f) {
			int pos = nd == f->s[1];
			m[pos] = f->m[pos];
			m[pos ^ 1] = f->v;
		} else {
			root = nd;
		}
		remark(nd, m[0], m[1]);
		tot = nd->v;
	}
	void remark(Node *nd, lf l, lf r) {
		if (nd) {
			nd->mark(l, r);
			remark(nd->s[0], l, nd->v);
			remark(nd->s[1], nd->v, r);
		}
	}
	void getSa(Node *nd, int &idx) {
		if (nd) {
			getSa(nd->s[0], idx);
			sa[idx++] = nd->idx;
			getSa(nd->s[1], idx);
		}
	}
	void getRank() {
		for (int i = 0; i < len; i++) {
			rank[sa[i]] = i;
		}
	}
	void getH() {
		int i, j, k;
		for (i = 0, k = 0; i < len - 1; i++) {
			j = sa[rank[i] - 1];
			for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
			h[rank[i]] = k;
		}
	}
public:
	void build(int *_str, int _len) {
		len = _len; str = _str;
		int i, idx = 0;
		root = new_node(len - 1);
		root->mark(0, 1);
		for (i = len - 2; i >= 0; i--) {
			insert(i);
		}
		getSa(root, idx);
		getRank();
		getH();
	}
}suffix_tree;

namespace rmq{
	int bit;
	int mn[2][18][S_MAXN];
	void init(int *src, int len) {
		for (bit = 1; 1 << bit < len + 1; bit++);
		bit--;
		int I, i, j, f, g;

		for (I = 0; I < 2; I++){
			for (i = 0; i < len; i++) {
				mn[I][0][i] = src[i];
			}
			f = I ? -1 : 1;
			for (i = 1; i <= bit; i++) {
				for (j = 0; j < len; j++) {
					mn[I][i][j] = mn[I][i - 1][j];
					g = j + f * (1 << i - 1);
					if (g < len && g >= 0) {
						mn[I][i][j] = min(mn[I][i][j], mn[I][i - 1][g]);
					}
				}
			}
		}
	}
}

struct C_Node {
	C_Node *s[2];
	int l, r, sum, mid;
};

class ChairTree {
public:
	typedef C_Node Node;
	int mx;
	Node pool[C_MAXN];
	Node *root[S_MAXN];
	int pidx;
	int ridx;
	Node* build(int l, int r) {
		Node *nd = new_node(l, r);
		if (l < r) {
			nd->s[0] = build(l, nd->mid);
			nd->s[1] = build(nd->mid + 1, r);
		}
		return nd;
	}
	
	Node* new_node(int l, int r) {
		Node *nd = &pool[pidx++];
		nd->l = l; nd->r = r; nd->mid = (l + r) >> 1;
		return nd;
	}
	
	void init(int, int _mx) {
		mx = _mx;
		root[ridx++] = build(0, _mx);
	}
	Node *insert(int val, Node* pre) {
		Node* nd = new_node(pre->l, pre->r);
		
		if (nd->l == nd->r) {
			nd->sum = 1;
			return nd;
		}
		int pos = val > nd->mid;
		nd->s[pos] = insert(val, pre->s[pos]);
		nd->s[pos ^ 1] = pre->s[pos ^ 1];
		nd->sum = nd->s[0]->sum + nd->s[1]->sum;
		return nd;
	}
	int query(Node *lnd, Node* rnd, int l, int r) {
		if (l <= lnd->l && lnd->r <= r) {
			return rnd->sum - lnd->sum;
		}
		int ret = 0;
		if (l <= lnd->mid) {
			ret += query(lnd->s[0], rnd->s[0], l, r);
		}
		if (r > lnd->mid) {
			ret += query(lnd->s[1], rnd->s[1], l, r);
		}
		return ret;
	}
	int query(int lidx, int ridx, int l, int r) {
		return query(root[lidx], root[ridx], l, r);
	}
	void insert(int pos) {
		root[ridx++] = insert(pos, root[ridx - 1]);
	}
	
}chair_tree;



struct _Main {
	int str[S_MAXN];
	char buf[S_MAXN];
	
	void to_int(char *buf, int *str, int len) {
		for (int i = 0; i < len; i++) {
			str[i] = buf[i];
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
	int confirm(int a, int b, int c, int d, int len) {
		using namespace rmq;
		int l, r;
		int i, g;
		
		l = r = rank[c];
		for (i = bit; i >= 0; i--) {
			if (l - (1 << i) >= 0 && mn[REV][i][l] >= len) {
				l -= 1 << i;
			}
		}
		for (i = bit; i >= 0; i--) {
			if (r + (1 << i) < tot_len && mn[ZHENG][i][r + 1] >= len) {
				r += 1 << i;
			}
		}
		//assert l > 0;
		return chair_tree.query(l - 1, r, a, b - len + 1);
	}
	int getAns(int a, int b, int c, int d) {
		int l = 0, r = min(d - c + 1, b - a + 1), mid;
		while (l < r) {
			mid = (l + r >> 1) + 1;
			if (confirm(a, b, c, d, mid)) {
				l = mid;	
			} else {
				r = mid - 1;
			}
		}
		return l;		
	}
	int tot_len;
	_Main() {
		freopen("data0.in", "r", stdin);
		int n, Qn, Q;
		int i, j, k;
		scanf("%d%d", &n, &Qn);
		scanf("%s", buf);
		to_int(buf, str, n);
		tot_len = n;
		str[tot_len++] = -INF;
		suffix_tree.build(str, tot_len);
		chair_tree.init(0, n - 1);
		for (i = 1; i < tot_len; i++) { //assert 第0名无用 
			chair_tree.insert(sa[i]);
		}
		rmq::init(h, tot_len);
		
		int a, b, c, d;
		int ans = 0;
		for (Q = 1; Q <= Qn; Q++) {
			read(a); read(b); read(c); read(d);
			a--; b--; c--; d--;
			ans = getAns(a, b, c, d);
//			printf("%d\n", ans);
		}
		
		
	}	
	
}bzoj4556;



}
