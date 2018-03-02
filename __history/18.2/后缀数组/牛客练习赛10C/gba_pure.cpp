using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>

namespace OI  {
typedef long long lld;
typedef double lf;
const int 
	MAXN = 200100,
	INF = 0x3f3f3f3f
;
int lrand() {
	return rand() << 15 | rand();
}
struct Node {
	lf m[2], v;
	Node *f, *s[2];
	int val, rand;
	void mark(lf l, lf r) {
		m[0] = l, m[1] = r, v = (l + r) / 2.0;
	}
};

int h[MAXN], sa[MAXN], rank[MAXN];
class SuffixTreap {
public:
	int *str, len;
	lf tot;
	Node *root;
	int pidx;
	Node pool[MAXN];
	Node *node[MAXN];
	Node *new_node(int val, Node* f = 0) {
		Node *nd = &pool[pidx++];
		nd->f = f;
		nd->val = val;
		node[val] = nd;
		nd->rand = lrand();
//		nd->s[0] = nd->s[1] = 0;
		return nd;
	}
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
		for (i = len - 2; i >= 0; i--) {
			insert(i);
		}
		getSa(root, idx);
		getRank();
		getH();
	}
	void clear() {
		pidx = 0;
	}
}tree;

int log[MAXN];

class RMQ {
public:
	int bit;
	int mn[18][MAXN];
	void init(int *arr, int len) {
		for (bit = 1; 1 << bit < len + 1; bit++);
		int I, i;
		for (i = 0; i < len; i++) {
			mn[0][i] = arr[i];
		}
		for (I = 1; I < bit; I++) {
			for (int j = 0; j < len; j++) {
				mn[I][j] = mn[I - 1][j];
				if (j + (1 << I - 1) < len) {
					mn[I][j] = min(mn[I][j], mn[I - 1][j + (1 << I - 1)]);
				}
			}
		}
	}
	int query(int l, int r) {
		int lg = log[r - l + 1];
		return min(mn[lg][l], mn[lg][r - (1 << lg) + 1]);
	}
}rmq;


struct _Main {

	char buf[2][MAXN >> 1];
	char new_buf[MAXN];
	int str[MAXN];

	int match[MAXN];
	int lcp(int a, int b) {
		a = rank[a]; b = rank[b];
		if (a > b) {
			swap(a, b);
		}
		return rmq.query(a + 1, b);
	}	
	int getAns(int a, int mid, int n) {
		int ret = match[mid];
		int l, r;
		int i = mid >> 1;
		int m = ret >> 1;
		
		/*if (mid & 1) {
			if (a == 0) {
				l = i - m - 1; r = i + m;	
			} else {
				l = i - m; r = i + m + 1;
			}
		} else {
			if (a == 0) {
				l = i - 1 - m; r = i - 1 + m;
			} else {
				l = i - m; r = i + m;
			}
		}*/
		l = i - m - 1 + a;
		r = i - (a ^ 1) + (mid & 1) + m;
		if (l >= 0 && r >= 0) {
			ret += (lcp(r, n + 1 + (n - l - 1)) << 1);
		} 
		return ret;
	}
	void to_int(char *src, int *dst, int len) {
		int i;
		for (i = 0; i < len; i++) {
			dst[i] = src[i];
		}
	}
	void rev_int(char *src, int *dst, int len) {
		for (int i = 0; i < len; i++) {
			dst[len - i - 1] = src[i];
		}
	}
	void manacher(char *str, int len) {
		int n = 0; int i, j, k;
		int l, r;
		new_buf[n++] = '#';
		for (i = 0; i < len; i++) {
			new_buf[n++] = str[i];
			new_buf[n++] = '#';
		}
		int mid = 0; k = 0;
		for (i = 1; i < n; i++) {
			
			r = i;
			if (k > i) {
				r += match[mid - (i - mid)];
			} 
			if (r >= k) {
				r = max(k, i);
				l = i - (r - i);
				while (r < n && l - 1 >= 0 && new_buf[r + 1] == new_buf[l - 1]) {
					r++; l--;
				}
			}
			match[i] = r - i;
			if (r > k) {
				mid = i; k = r;
			}
		}
		
		
		
	}
	
	_Main() {
		int n, ans;
		int a = 1;
		int i, j, k, I;
		ans = 1;
		scanf("%d%s%s", &n, buf[0], buf[1]);
		for (i = 1, j = 0; i <= n << 1; i++) {
			if (i == 1 << j + 1) {
				j++;
			}
			log[i] = j;
		}
		to_int(buf[1], str, n);
		str[n] = -INF + 1;
		rev_int(buf[0], str + n + 1, n);
		str[n + 1 + n] = -INF;
		tree.build(str, (n + 1) << 1);		
		for (I = 0; I < 2; I++) {
			// a包含对称中心， 
			manacher(buf[a], n);
			rmq.init(h, (n + 1) << 1);
			for (i = 0; i <= n * 2; i++) {
				ans = max(ans, getAns(a, i, n));
			}
			a ^= 1;
		}
		printf("%d", ans);
	}



}nowcoder;


}

//ST又双叒叕写WA了， 这次是运算符优先级， 
//对称中心的定义还是要小心 
//分类讨论的时候一定要耐心，不要瞎调，合并的时候一定要一项一项地来， 
