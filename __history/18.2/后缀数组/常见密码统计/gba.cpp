using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdlib>

namespace OI {
typedef long long lld;
typedef double lf;
const int 
	MAXN = 100200,
	INF = 0x3f3f3f3f,
	SRC = 0,
	END = 1,
	POS = 0,
	VAL = 1
;

int lrand() {
	return rand() << 15 | rand();
}
struct Node {
	Node *f, *s[2];
	double m[2], v;
	int val, rand;
	void mark(lf a, lf b) {
		m[0] = a; m[1] = b; v = (a + b) / 2.0;
	}
	void *operator new(size_t, int, Node*);
}pool[MAXN];
int pidx;
Node *node[MAXN];
void *Node::operator new(size_t, int val, Node* f = 0) {
	Node *nd = &pool[pidx++];
	nd->f = f;
	nd->val = val;
	node[val] = nd;
	nd->rand = lrand();
	return nd;
}
int sa[MAXN], rank[MAXN], height[MAXN];
class SuffixTreap {
public:
	int *str, len;
	double tot;
	Node *root;
	int cmp(int idx, Node *nd) {
		if (str[idx] != str[nd->val]) {
			return str[idx] > str[nd->val];
		}
		return tot > node[nd->val + 1]->v;
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		int pos;
		nd->f = gf;
		if (gf) {
			gf->s[f == gf->s[1]] = nd;
		}
		pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s) {
			s->f = f;
		}
		f->f = nd;
		nd->s[pos ^ 1] = f;
	}
	void insert(int idx) {
		Node *nd = root;
		int pos;
		while (1) {
			pos = cmp(idx, nd);
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = new(idx, nd)Node;
				break;
			}
		}
		while (nd->f && nd->f->rand > nd->rand) {
			rotate(nd);
		}
		mark_new(nd);
	}	
	void mark_new(Node *nd) {
		double m[2] = {0, 1};
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
			height[rank[i]] = k;
		}
	}
	void build(int *_str, int _len) {
		str = _str; len = _len;
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

int ans[MAXN][2];
int ansidx;
int f[MAXN];
struct _Main {

	int str[MAXN];
	int readStr(int* str) {
		int idx = 0, t;
		while (!isalpha(t = getchar()));
		do {
			str[idx++] = t;
		} while (isalpha(t = getchar()));
		return idx;
	}
	int now_len;
	int cnt;
	int lst;
	int mx_len;
	int now_mx;
	int vis[MAXN];
	int q[MAXN][2];
	int qhead, qtail;
	void add_ans(int src, int end) {
		ans[ansidx][SRC] = src;
		ans[ansidx][END] = end;
		//printf("add(%d, %d, %d)\n", src, beg, end);
		ansidx++;
	}
	void push(int pos, int val) {
		while (qhead < qtail && q[qtail - 1][VAL] > val) {
			qtail--;
		}
		q[qtail][VAL] = val;
		q[qtail][POS] = pos;
		qtail++;
		now_len = q[qhead][VAL];
		if (now_len < now_mx) {
			now_mx = 0;
		}
	}
	char greater() {
		int t = f[sa[lst]];
		return cnt - (vis[t] == 1) >= (n >> 1) + 1;
	}
	void pop() {
		qhead++;
		now_len = q[qhead][VAL];
		if (now_len < now_mx) {
			now_mx = 0;
		}
	}
	void getAns() {
		mx_len = 1;
		int i;
		lst = n;
		for (i = n; i < tot_len; i++) {
			push(i - 1, height[i]);
			push(i, getLen(sa[i]));
				
			
			if (++vis[f[sa[i]]] == 1) {
				cnt++;
				
//				printf("vis[%d] = %d\n", f[sa[i]], vis[f[sa[i]]]);
			}
//			printf("bef\n");
//			for (int j = qhead; j < qtail; j++) {
//				printf("q %d val = %d\n", q[j][POS], q[j][VAL]);
//			} 	
			while (1) {
				while(qhead < qtail && q[qhead][POS] < lst) {
					pop();
				}
				if (lst < i && greater()) {
					if (--vis[f[sa[lst]]] == 0) {
						cnt--;
					}
//					printf("vis[%d] = %d\n", f[sa[lst]], vis[f[sa[lst]]]);
					lst++;
				} else {
					break;
				}
			}
//			printf("af\n");
//			for (int j = qhead; j < qtail; j++) {
//				printf("q %d val = %d\n", q[j][POS], q[j][VAL]);
//			} 	
//			printf("now_len = %d, mx_len = %d, now_mx = %d, cnt = %d, lst = %d\n",
//					 now_len, mx_len, now_mx, cnt, lst);
			if (now_len >= mx_len && now_len > now_mx && cnt >= (n >> 1) + 1) {
				now_mx = now_len;
				mx_len = now_len;
				add_ans(sa[i], sa[i] + mx_len - 1);
			}			
		}
//		for (int j = qhead; j < qtail; j++) {
//			printf("q %d val = %d\n", q[j][POS], q[j][VAL]);
//		} 		
	}
	int getLen(int src) {
		return len[f[src]] - (src - beg[f[src]]);
	}
	void printAns() {
		int i, j, k;
		for (i = 0, j = 0; i < ansidx; i++) {
			if (ans[i][END] - ans[i][SRC] + 1 == mx_len){
//                printf("%d ", ans[i][SRC]);
                for (k = ans[i][SRC]; k <= ans[i][END]; k++) {
					putchar((char)str[k]);
				}
				j++;
				putchar('\n');
			}
		}
		if (j == 0) {
			putchar('?');
		}
	}
	int beg[MAXN];
	int len[MAXN];
	int n;
	int tot_len;
	_Main() {
		int i, j, k;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			beg[i] = tot_len;
			len[i] = readStr(str + tot_len);
			tot_len += len[i];
			for (j = beg[i]; j < tot_len; j++) {
				f[j] = i;
			}
			str[tot_len++] = -INF + (i != n);
		}
		tree.build(str, tot_len);
		getAns();
		printAns();		
	}



}jsk;




}
/*
3
cdefghi
efghijk
abcdefg
*/
