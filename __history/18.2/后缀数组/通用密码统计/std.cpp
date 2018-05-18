using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>

namespace OI {
typedef long long lld;
typedef double lf;
const int
	INF = 0x3f3f3f3f,
	MAXN = 400400,
	POS = 0,
	VAL = 1
;
int lrand() {
	return rand() << 15 | rand();
}
struct Node {
	Node *s[2], *f;
	lf m[2], v;
	int val, rand;
	void mark(lf a, lf b) {
		m[0] = a; m[1] = b; v = (a + b) / 2.0;
	}
	void* operator new (size_t, int, Node *);
}pool[MAXN];
Node *node[MAXN];
int pidx;
void* Node:: operator new (size_t, int val, Node *f = 0) {
	Node *nd = &pool[pidx++];
	nd->f = f;
	nd->val = val;
	nd->rand = lrand();
	node[val] = nd;
	return nd;
}

int sa[MAXN], rank[MAXN], h[MAXN];

class SuffixTreap {
public:
	int *str, len;
	Node *root;
	lf tot;
	int cmp(int idx, Node *nd) {
		if (str[idx] != str[nd->val]) {
			return str[idx] > str[nd->val];
		}
		return tot > node[nd->val + 1]->v;
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf) {
			gf->s[gf->s[1] == f] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s) {
			s->f = f;
		}
		nd->s[pos ^ 1] = f;
		f->f = nd;
	}
	void insert(int idx) {
		Node *nd = root;
		while (1) {
			int pos = cmp(idx, nd);
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = new(idx, nd)Node;
				break;
			}
		}
		while (nd->f && nd->rand > nd->f->rand) {
			rotate(nd);
		}
		mark_new(nd);
	}
	void mark_new(Node *nd) {
		lf m[2] = {0, 1};
		Node *f = nd->f;
		if (f) {
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
			sa[idx++] = nd->val;
			getSa(nd->s[1], idx);
		}
	}
	void getRank() {
		int i;
		for (i = 0; i < len; i++) {
			rank[sa[i]] = i;
		}
	}
	void getHeight() {
		int i, j, k;
		for (i = 0, k = 0; i < len - 1; i++) {
			j = sa[rank[i] - 1];
			for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
			h[rank[i]] = k;
		}
	}
	
	void build(int *_str, int _len) {
		str = _str, len = _len;
		int i, idx = 0;
		root = new (len - 1) Node;
		root->mark(0, 1);
		for (i = len - 2; i >= 0; i--) {
			insert(i);
		}
		getSa(root, idx);
		getRank();
		getHeight();
	}

	
}tree;



struct _Main {
int ans;


int n;
int str[MAXN];
int tot_len;
int beg[210];
int f[MAXN];
int bl[MAXN];
int end[210];
int readStr(int *str) {
	int idx = 0, t;
	while (!isalpha(t = getchar()));
	do {
		str[idx++] = t;
	} while (isalpha(t = getchar()));
	return idx;
}

int getRev(int *str, int idx) {
	int i;
	int ret = 0;
	for (i = end[idx]; i >= beg[idx]; i--) {
		str[ret++] = this->str[i];
	}
	return ret;
}

_Main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= 2 * n; i++) {
		beg[i] = tot_len;
		if (i <= n) {
			tot_len += readStr(str + tot_len);
		} else {
			tot_len += getRev(str + tot_len, i - n);
		}
		end[i] = tot_len - 1;
		k = (i - 1) % n + 1;
		for (j = beg[i]; j <= end[i]; j++) {
			f[j] = i;
			bl[j] = k;
		}
		str[tot_len++] = -INF + (i != 2 * n);
	}
	tree.build(str, tot_len);
	/*
	for (i = 0; i < tot_len; i++) {
		printf("[%d] ", i);
		for (j = sa[i]; j < tot_len; j++) {
			printf("%d ", str[j]);
		}
		printf("\n%d\n", h[i]);
	}
	*/
	getAns();
	printf("%d", ans);
}

int cnt;
int vis[115];
int now_len;
int lst;
int qhead, qtail;
int q[MAXN][2];
int getLen(int pos) {
	return end[f[pos]] - pos + 1;
}
void pop() {
	qhead++;
	if (qhead < qtail) {
		now_len = q[qhead][VAL];
	} else {
		now_len = 0;
	}
}
void push(int pos, int val) {
	while (qhead < qtail && val <= q[qtail - 1][VAL]) {
		qtail--;
	}
	q[qtail][VAL] = val;
	q[qtail][POS] = pos;
	if (qhead == qtail) {
		now_len = val;
	}
	qtail++;
}

int greater() {
	return cnt - (vis[bl[sa[lst]]] == 1) == n;
}
void getAns() {
	int i, j, k;	
	lst = 2 * n;
	for (i = 2 * n; i < tot_len; i++) {
		push(i - 1, h[i]);
		push(i, getLen(sa[i]));
		/*
        for (j = sa[i]; j < tot_len; j++) {
			printf("%d ", str[j]);
		}
		
		printf("\nbef\n");

		for (j = qhead; j < qtail; j++) {
			printf("[%d] %d ; ", q[qhead][POS], q[qhead][VAL]);
		}
		printf("\n");
		*/
		if (++vis[bl[sa[i]]] == 1) {
			cnt++;
		}
		while (1) {
			while (qhead < qtail && q[qhead][POS] < lst) {
				pop();
			}
			if (lst <= i && (now_len <= ans || greater() )) {
				if (--vis[bl[sa[lst]]] == 0) {
					cnt--;
				}
				lst++;
			} else {
				break;
			}
		}
		/*
		printf("af\n");
		for (j = qhead; j < qtail; j++) {
			printf("[%d] %d ; ", q[qhead][POS], q[qhead][VAL]);
		}
		printf("\n");
		*/
		if (cnt == n) {
			ans = max(ans, now_len);
		}
	}
}


}jsk;


}


