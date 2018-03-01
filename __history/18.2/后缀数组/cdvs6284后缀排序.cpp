using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cstring>

namespace OI {
typedef long long lld;
typedef double lf;
struct Node;
typedef Node* ptr;
const int 
	MAXN = 105,
	INF = 0x3f3f3f3f
;
int lrand() {
	return rand() << 15 | rand();
}
struct Node {
	ptr s[2], f;
	lf m[2], v;
	int rand, val;
	void mark(lf l, lf r) {
		m[0] = l, m[1] = r, v = (l + r) / 2.0;
	}
};

int sa[MAXN];

class SuffixTreap {
public:
	Node pool[MAXN];
	int pidx;
	ptr node[MAXN];
	int *str, len;
	lf tot;
	ptr root;
	ptr new_node(int val, ptr f = 0) {
		ptr nd = &pool[pidx++];
		nd->f = f;
		nd->val = val;
		node[val] = nd;
		nd->rand = lrand();
		return nd;
	}
	
	int cmp(int idx, ptr nd) {
		if (str[idx] != str[nd->val]) {
			return str[idx] > str[nd->val];
		}
		return tot > node[nd->val + 1]->v;
	}
	void rotate(ptr nd) {
		ptr f = nd->f, gf = f->f, s;
		nd-> f = gf;
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
		ptr nd = root;
		while (1) {
			int pos = cmp(idx, nd);
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = new_node(idx, nd);
				break;
			}
		}
		while(nd->f && nd->rand > nd->f->rand) {
			rotate(nd);
		}
		mark_new(nd);
	}
	void mark_new(ptr nd) {
		lf m[2] = {0, 1};
		if (ptr f = nd->f) {
			int pos = nd == f->s[1];
			m[pos] = f->m[pos];
			m[pos ^ 1] = f->v;
		} else {
			root = nd;
		}
		remark(nd, m[0], m[1]);
		tot = nd->v;
	}
	void remark(ptr nd, lf l, lf r) {
		if (nd) {
			nd->mark(l, r);
			remark(nd->s[0], l, nd->v);
			remark(nd->s[1], nd->v, r);
		}
	}
	void getSa(ptr nd, int &idx) {
		if (nd) {
			getSa(nd->s[0], idx);
			sa[idx++] = nd->val;
			getSa(nd->s[1], idx);
		}
	}
	void build(int *_str, int _len) {
		str = _str, len = _len;
		int i, idx = 0;
		root = new_node(len - 1);
		root->mark(0, 1);
		for (i = len - 2; i >= 0; i--) {
			insert(i);
		}
		getSa(root, idx);
	}

}tree;

struct _Main {

int str[MAXN];
int readStr(int *str) {
	int idx = 0, t;
	while (!isalpha(t = getchar()));
	do {
		str[idx++] = t; 
	} while (isalpha(t = getchar()));
	return idx;
}

_Main() {
	int n = readStr(str);
	str[n] = -INF;
	tree.build(str, n + 1);
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d ", sa[i] + 1);
	}		
}

}cdvs6284;

}


