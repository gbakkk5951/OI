using namespace std;
int main() {}

#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace OI {
typedef double lf;
const int 
	MAXN = 100010,
	INF = 0x3f3f3f3f
;
int lrand() {
	return rand() << 15 | rand();
}
struct Node {
	Node *s[2], *f;
	lf m[2], v;
	int rand, val;
	void mark(lf l, lf r) {
		m[0] = l; m[1] = r; v = (l + r) / 2.0;
	}
};

int sa[MAXN], rank[MAXN], h[MAXN];

class SuffixTreap {
public:
	Node pool[MAXN];
	Node *node[MAXN];
	Node *root;
	int pidx;
	Node * new_node(int val, Node *f = 0) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		nd->val = val;
		nd->rand = lrand();
		node[val] = nd;
		return nd;
	}
	lf tot;
	int *str, len;
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
 			sa[idx++] = nd->val;
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
 	void build(int *_str, int _len) {
 		str = _str, len = _len;
 		int i, idx = 0;
 		root = new_node(len - 1);
 		root->mark(0, 1);
 		for (i = len - 2;i >= 0; i--) {
 			insert(i);
 		}
 		getSa(root, idx);
 		getRank();
 		getH();
 	}
}tree;

struct _Main {
	char buf[MAXN];
	int str[MAXN];
	void to_int(char *src, int *dst, int len) {
		for (int i = 0; i < len; i++) {
			dst[i] = src[i];
		}
	}
	_Main() {
		int i, j, len;
		scanf("%s", buf);
		len = strlen(buf);
		to_int(buf, str, len);
		str[len++] = -INF;
		tree.build(str, len);
		for (i = 1; i < len; i++) {
			printf("%d ", sa[i] + 1);
		}
		printf("\n");
		for (i = 2; i < len; i++) {
			printf("%d ", h[i]);
		}
	}
	
}uoj35;






}

