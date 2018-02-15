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
	BEG = 1,
	END = 2,
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

int ans[MAXN][3];
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
	int lst;
	int now_len;
	int cnt;
	int mx_len;
	int vis[MAXN];
	int q[MAXN][2];
	int qhead, qtail;
	void mov_ahead() {
		int f = OI::f[sa[lst]];
		if (f) {
			vis[f]--;
			if (vis[f] == 0) {
				cnt--;
			}
			if (qhead < qtail && lst == q[qhead][POS]) {
				qhead++;
				if (qhead < qtail) {
					now_len = q[qhead][VAL];
				}
			}
		} 
		lst++;
	}
	void add(int idx) {
		int f = OI::f[sa[idx]];
		if (f) {
			vis[f]++;
			//printf("vis[%d] = %d\n", f, vis[f]);
			if (vis[f] == 1) {
				cnt++;
			}
			int val = max(now_len, height[idx]);
			while (qhead < qtail && val < q[qtail - 1][VAL]) {
				qtail--;
			}
			q[qtail][VAL] = val;
			q[qtail][POS] = idx;
			qtail++;
		}
	}
	void add_ans(int src, int beg, int end) {
		ans[ansidx][SRC] = src;
		ans[ansidx][BEG] = beg;
		ans[ansidx][END] = end;
		//printf("add(%d, %d, %d)\n", src, beg, end);
		ansidx++;
	}
	void getAns() {
		int i;
		int mx_len = 0;
		this->mx_len = 7;
		for (i = 0; i < tot_len; i++) {
			if (height[i] < this->mx_len) {
				mx_len = 0;
				while (lst < i) {
					mov_ahead();
				}
			}
			
			//printf("from %d to %d\n", lst, i);
			//printf("now_len = %d\n", now_len);
			/*while (lst < i && cnt >= (n + 1) / 2) {
				mov_ahead();
			}
			*/
            
			while (lst < i && cnt - (vis[f[sa[lst]]] == 1 && f[sa[lst]] != f[sa[i]]) + (vis[f[sa[i]]] == 0) >= (n + 1) / 2) {
				mov_ahead();
			}
			now_len = min(now_len, height[i]);
			if (lst == i) {
				now_len = len[f[sa[i]]] - (sa[i] - beg[f[sa[i]]]);
			}            
            add(i);
			//printf("cnt = %d\n", cnt);

//			printf("qhead = %d, qtail = %d\n", qhead, qtail);
			if (i == 165) {
			    for (int j = qhead; j < qtail; j++) {
			        printf("[%d]%d ", q[j][POS], q[j][VAL]);
			    }
                printf("\ncnt = %d, vis = %d, len = %d, lst = %d, mx l = %d, g = %d\n", cnt, vis[f[sa[lst]]], now_len, lst, mx_len, this->mx_len);
			}
            
            
            if (cnt >= (n + 1) / 2) {
                if (this->mx_len <= now_len && mx_len < now_len) {
					
                    this->mx_len = now_len;
                    add_ans(sa[i], sa[i] + mx_len , sa[i] + now_len - 1);
					mx_len = now_len;
				}
			}
		}
	}
	void printAns() {
		int i, j, k;
		for (i = 0, j = 0; i < ansidx; i++) {
			if (ans[i][END] - ans[i][SRC] + 1 == mx_len){
                printf("%d ", ans[i][SRC]);
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
		/*for (i = 0; i < tot_len; i++) {
			for (j = sa[i]; j < tot_len; j++) {
				printf("%d ", str[j]);
			}
			printf("\n%d\n", height[i]);
		}*/
		
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
