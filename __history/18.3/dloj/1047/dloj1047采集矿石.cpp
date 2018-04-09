using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace OI {
typedef double lf;
typedef long long lld;
const int MXN = 100010;
const int INF = 0x3f3f3f3f;
struct Node {
	Node *s[2], *f, *nxt;
	int rand, pos;
	lf m[2], v;
	void mark(lf l, lf r) {
		m[0] = l; m[1] = r; v = (l + r) / 2.0;
	}
};
int sa[MXN], rk[MXN], h[MXN];
struct SuffixTreap {
	Node pool[MXN];
	int pidx;
	SuffixTreap() {
		srand(2354961 ^ (unsigned long long)new char);
	}
	Node *lst;
	Node *new_(int pos, Node *f) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		nd->pos = pos;
		nd->rand = rand();
		nd->nxt = lst;
		lst = nd;
		return nd;
	}
	Node *root;
	int *str, len;
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf) {
			gf->s[f == gf->s[1]] = nd;
		}
		int spo = nd == f->s[1];
		s = f->s[spo] = nd->s[spo ^ 1];
		if (s) {
			s->f = f;
		}
		f->f = nd;
		nd->s[spo ^ 1] = f;
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
		Node *f = nd->f;
		if (f) {
			int spo = nd == f->s[1];
			m[spo] = f->m[spo];//f写成nd 
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
			for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
			h[rk[i]] = k;
		}
	}
	void build(int *_str, int _len) {
		str = _str; len = _len;
		root = new_(len - 1, 0);
		root->mark(0, 1);
		for (int i = len - 2; i >= 0; i--) {
			insert(i);
		}
		int idx;
		getsa(root, idx = 0);
		getrk();
		geth();
	}
}tree;

struct _Main {
	int str[MXN];
	int len;
	int readstr(int str[]) {
		int idx = 0, t;
		while (!isalpha(t = getchar()));
		do {
			str[idx++] = t;
		} while ( isalpha(t = getchar()));
		return idx;
	}
	int vsum[MXN];
	lld nsum[MXN];
	int mn[MXN];
	void calcsum() {
		for (int i = len - 1; i >= 0; i--) {
			nsum[i] += nsum[i + 1] + len - (sa[i] + h[i]) - 1;
		}
		for (int i = 1; i < len - 1; i++) {
			vsum[i] += vsum[i - 1];
		}
	}
	int ans[MXN];
	int getsum(int l, int r) {
		return vsum[r] - (l ? vsum[l - 1] : 0);
	}
	lld getrk(int l, int r) { //返回值不是lld 
		int nd = rk[l];
		for (int I = mxbit; I >= 0; I--) {
			if (nd >= 1 << I && st[nd][I] >= r - l + 1) {
				nd -= 1 << I;
			}
		}
		r = sa[nd] + r - l;
		return nsum[nd + 1] + len - 2 - r + 1;
	}
	void calcans() {
		int l, r, mid, v;
		lld rk;
		memset(ans, -1, len * sizeof(int));
		for (int i = 0; i < len; i++) {
			if (sa[i] < len - 1) {
				l = sa[i], r = len - 2;
				while (l < r) {
					mid = l + r >> 1;
					v = getsum(sa[i], mid);
					rk = getrk(sa[i], mid);
					if (v > rk) {
						r = mid - 1;
					} else if (v == rk) {
						l = r = mid;
					} else {
						l = mid + 1;
					}
				}
				if (l == r && getsum(sa[i], l) == getrk(sa[i], l)) {
					ans[sa[i]] = l;
				}
			}
		}
	}
	int st[MXN][17];
	int mxbit;
	void getst() {
		for (mxbit = 0; 1 << mxbit + 1 <= len; mxbit++);
		for (int i = 0; i < len; i++) {
			st[i][0] = h[i];
		}
		for (int I = 1; I <= mxbit; I++) {
			for (int i = (1 << I); i < len; i++) {
				st[i][I] = min(st[i][I - 1], st[i - (1 << I - 1)][I - 1]);
			}
		}
	}
	void prepro() {
		len = readstr(str);
		for (int i = 0; i < len; i++) {
			read(vsum[i]);
		}
		str[len++] = -INF;
		tree.build(str, len);
		calcsum();
		getst();
	}
	void solve() {
		calcans();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (ans[i] >= i) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < len; i++) {
			if (ans[i] >= i) {
				printf("%d %d\n", i + 1, ans[i] + 1);
			}
		}
	}
	
	_Main() {
		prepro();
		solve();
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
}dloj1047;
}

