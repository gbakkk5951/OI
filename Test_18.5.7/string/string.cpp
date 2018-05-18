using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
namespace OI {
typedef long double lf;
const int MXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int ORG = 0, REV = 1; 

struct Node {
	Node *s[2], *f, *nxt;
	lf m[2], v;
	int rand, val, pos;
	inline void mark(lf l, lf r) {
		m[0] = l; m[1] = r; v = (l + r) / 2.0;
	}
};
const int seed = 1656457;
struct SuffixTreap {
	Node pool[MXN], *null;
	int pidx;
	int len, *s, *sa, *rk, *h;
	Node *lst, *root;
	inline Node* new_(int val, int pos, Node *f) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		nd->val = val;
		nd->pos = pos;
		nd->rand = rand();
		//nd->rand = pidx % 17;
		nd->nxt = lst;
		lst = nd;
		nd->s[0] = nd->s[1] = null;
		return nd;
	}
	
	SuffixTreap() {
		null = new_(-INF, -1, 0);
		null->rand = -INF; //小根堆
		lst = null;
	}
	
	inline void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f;
		nd->f = gf;
		gf->s[f == gf->s[1]] = nd;
		int spo = nd == f->s[1];
		(f->s[spo] = nd->s[spo ^ 1])->f = f;
		nd->s[spo ^ 1] = f;
		f->f = nd;
	}
	
	void insert(int val, int pos) {
		Node *nd = root;
		int spo;
		while (1) {
			if (val != nd->val) {
				spo = val > nd->val;
			} else {
				spo = lst->v > nd->nxt->v;
			}
			if (nd->s[spo] != null) {
				nd = nd->s[spo];
			} else {
				nd = nd->s[spo] = new_(val, pos, nd);
				break;
			}
		}
		while (nd->f->rand > nd->rand) {
			rotate(nd);
		}
		lf m[2] = {0, 1};
		Node *f = nd->f;
		if (f != null) {
			spo = nd == f->s[1];
			m[spo] = f->m[spo];
			m[spo ^ 1] = f->v;
		} else {
			root = nd;
		}
		remark(nd, m[0], m[1]);
	}
	void remark(Node *nd, lf l, lf r) {
		if (nd != null) {
			nd->mark(l, r);
			remark(nd->s[0], l, nd->v);
			remark(nd->s[1], nd->v, r);
		}
	}
	void getsa(Node *nd, int &idx) {
		if (nd != null) {
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
		for (int i = 0, j, k = 0; i < len; i++) {
			if (rk[i] > 0) {
				j = sa[rk[i] - 1];
				for (k ? k-- : 0; s[j + k] == s[i + k]; ++k); //len与[0, len - 1]不同
				h[rk[i]] = k;
			}
		}
	}
	void build(int _len, int *_s, int *_sa, int *_rk, int *_h) {
		len = _len; s = _s; sa = _sa; rk = _rk; h = _h;
		root = new_(s[len - 1], len - 1, null);
		root->mark(0, 1);
		for (int i = len - 2; i >= 0; i--) {
			insert(s[i], i);
		}
		int idx = 0;
		getsa(root, idx);
		getrk();
		geth();
	}
}tree[2];

struct _Main {
	int mxp;
	int s[2][MXN], sa[2][MXN], rk[2][MXN], h[2][MXN];
	int st[2][MXN][20];
	int log[MXN];
	void getst(int len, int st[][20], int arr[]) {
		for (int i = 0; i < len; i++) {
			st[i][0] = arr[i];
		}
		for (int I = 1; I <= mxp; I++) {
			for (int i = 0; i + (1 << I) - 1 < len; i++) {
				st[i][I] = min(st[i][I - 1], st[i + (1 << I - 1)][I - 1]);
			}
		}
	}
	inline int getmn(int st[][20], int l, int r) {
		int lg = log[r - l + 1];
		return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
	}
	
	int calc(int sublen, int i) {
		int n, a, b;
		a = rk[ORG][i];
		b = rk[ORG][i + sublen];
		n = getmn(st[ORG], min(a, b) + 1, max(a, b));
		
		if (n >= sublen) {
			return 1;
		}
		if (i > 0) {
			a = rk[REV][len - (i + sublen - 1) - 1];
			b = rk[REV][len - (i - 1) - 1];
			n += getmn(st[REV], min(a, b) + 1, max(a, b));
			if (n >= sublen) {
				int cnt = 0;
				for (int a = i + sublen - 1, b = i - 1; b >= 0; a--, b--) {
					if (s[ORG][a] != s[ORG][b]) break;
					++cnt;
				}
				if (cnt != getmn(st[REV], min(a, b) + 1, max(a, b))) {
					printf("cnt = %d\nst = %d\n", cnt, getmn(st[REV], min(a, b) + 1, max(a, b)));
				}
				int cnt2 = 0;
				for (int a = i, b = i + sublen; b < len; a++, b++) {
					if (s[ORG][a] != s[ORG][b]) break;
					++cnt2;
				}
				if (cnt + cnt2 != n) {
					printf("cnt2 = %d, n = %d\n", cnt, n);
				}
				printf("i = %d, sublen = %d\n", i, sublen);
			}
		}
		return n >= sublen;
	}
	int len;
	_Main() {
		//freopen("string.in", "r", stdin);
		//freopen("string.out", "w", stdout);
		//srand(165713246843554LLU ^ (unsigned long long)new char);
		int ans = 0;
		int t;
		/*len = 1000000;
		srand(seed);
		for (int i = 0; i < len; i++) {
			s[ORG][i] = rand() % 2 + 'a';
		}*/
		
		while (!isalpha(t = getchar()));
		do {
			s[ORG][len++] = t;
		} while (isalpha(t = getchar()));
		
		memmove(s[REV], s[ORG], len * sizeof(int));
		for (int i = 0; i < len >> 1; i++) {
			swap(s[REV][i], s[REV][len - i - 1]);
		}
		for (int i = 1; i <= len; i++) {
			log[i] = log[i - 1] + (i == 1 << log[i - 1] + 1);
		}
		mxp = log[len];
		//printf("mxp = %d\n", mxp);
		for (int I = 0; I < 2; I++) {
			tree[I].build(len, s[I], sa[I], rk[I], h[I]);
			/*
			printf("[%d]\n", I);
			for (int i = 0; i < len; i++) {
				printf("%d ", s[I][i]);
			}
			printf("\n");
			for (int i = 0; i < len; i++) {
				for (int j = sa[I][i]; j < len; j++) {
					printf("%d ", s[I][j]);
				}
				printf("\n%d\n", h[I][i]);
			}
			printf("\n");
			*/
			getst(len, st[I], h[I]);
		}
		//printf("here\n");
		//return;
		for (int I = len >> 1; I >= 1; I--) {
			for (int j = 0; j < len; j += I) {
				if (calc(I, j)) {
					ans = I << 1;
					break;
				}
			}
			if (ans) break;
		}
		printf("%d", ans);
		//fclose(stdout);
	}
}string;
}
