using namespace std;
int main () {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace OI {
typedef long long lld;
typedef double lf;
struct Node;
typedef Node* ptr;

const int 
    MAXN = 100050,
    INF = 0x3f3f3f3f,
    ZHENG = 0,
    REV = 1
;



int lrand() {
    return rand() << 15 | rand();
}
struct Node {
    Node *f, *s[2];
    lf m[2], v;
    int rand, val;    
    void mark(lf l, lf r) {
        m[0] = l, m[1] = r, v = (l + r) / 2.0;
    }
    void * operator new (size_t, int, Node*);
};
int log[MAXN];

class RMQ {
public:
    int bit;
    int mn[18][MAXN];
    void init(int *arr, int len) {
        int i, j;
        for (bit = 1; 1 << bit < len; bit++);
        for (i = 0; i < len; i++) {
        	mn[0][i] = arr[i];
        }
        for (i = 1; i < bit; i++) {
        	for (j = 0; j < len; j++) {
        		mn[i][j] = mn[i - 1][j];
        		if (j + (1 << i - 1) < len) {
        			mn[i][j] = min(mn[i][j], mn[i - 1][j + (1 << i - 1)]);
        		} 
        	}
        }
    }
    int query(int l, int r) {
    	int lg = log[r - l + 1];
    	return min(mn[lg][l], mn[lg][r - (1 << lg) + 1]);	
    }
}h[2], rank;

class SuffixTreap {
public:
    Node pool[MAXN];
    Node *node[MAXN]; 
    int pidx;
    Node * new_node (int val, Node* f = 0) {
        Node *nd = &pool[pidx++];
        nd->s[0] = nd->s[1] = 0;
        nd->f = f;
        nd->val = val;
        node[val] = nd;
        nd->rand = lrand();
        return nd;
    }
    int sa[MAXN], h[MAXN], rank[MAXN];
    int *str, len;
    lf tot;
    Node *root;
    int cmp(int idx, Node *nd) {
        if (str[idx] != str[nd->val]) {
            return str[idx] > str[nd->val];
        }
        return tot > node[nd->val + 1]->v;
    }
    void rotate(Node *nd) {
        ptr f = nd->f, gf = f->f, s; 
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
        nd->s[pos ^ 1] =f;
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
        while (nd->f && nd->rand > nd->f->rand) {
            rotate(nd);
        }
        mark_new(nd);
    }
    void mark_new(ptr nd) {
        lf m[2] = {0, 1};
        ptr f = nd->f;
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
    void getRank() {
    	for (int i = 0; i < len; i++) {
    		rank[sa[i]] = i;
    	}
    }
    void getHeight() {
    	int i, j, k;
    	for (i = 0, k = 0; i < len - 1; i++) {
    		j = sa[rank[i] - 1];
    		for (k ? k-- : 0; str[j + k] == str[i + k]; k++);
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
    	getHeight();
    }
    void clear() {
    	memset(this, 0, sizeof(SuffixTreap));
   		pidx = 0;
    }
}tree[2];



struct _Main {
	int tot_len;
	int ans_l, ans_r, ans_rank, ans_cnt;
	int readStr(int *str) {
		int idx = 0, t;
		while (!isalpha(t = getchar()) && t != '#');
		do {
			str[idx++] = t;
		} while (isalpha(t = getchar()));
		return idx;
	}
	int str[2][MAXN];
	int lcp(int idx, int a, int b) {
		a = tree[idx].rank[a];
		b = tree[idx].rank[b];
		if (a > b) {
			swap(a, b);
		}
		return h[idx].query(a + 1, b);
	}
	int n;
	void getAns(int len) {
		int i, j, k, l = 0, r, step, rank;
		for (i = 0; i + len < n; i += len) {
			r = lcp(ZHENG, i, i + len);
			if (i) {
				l = lcp(REV, (n - 1) - (i - 1), (n - 1) - (i - 1 + len));
			}
			step = (l + r) / len + 1;
			if (step > ans_cnt) {
				ans_cnt = step;
				ans_rank = INF;
			}
			if (step == ans_cnt && (rank = OI::rank.query(i - l, i - l + (l + r) % len)) < ans_rank) {
				ans_rank = rank;
				ans_l = tree[ZHENG].sa[ans_rank];
				ans_r = ans_l + step * len - 1;
			}
		}
	}
	_Main() {
		int T, i, j, k;
		for (i = 1, j = 0; i <= 100005; i++) {
			if (1 << j + 1 == i) {
				j++;
			}
			log[i] = j;
		}
		for (T = 1; 1; T++) {
			n = tot_len = readStr(str[ZHENG]);
			if (str[ZHENG][0] == '#') {
				break;
			}
			printf("Case %d: ", T);
			for (i = n - 1; i >= 0; i--) {
				str[REV][i] = str[ZHENG][n - i - 1];
			}
			for (i = 0; i < 2; i++) {
				str[i][tot_len] = -INF;
			}
			tot_len++;
			for (i = 0; i < 2; i++) {
				tree[i].clear();
				tree[i].build(str[i], tot_len);
				h[i].init(tree[i].h, tot_len);
			}
			rank.init(tree[0].rank, tot_len);
			for (i = 0, ans_rank = INF, ans_cnt = 1; i < n; i++) {
				if (tree[ZHENG].rank[i] < ans_rank) {
					ans_rank = tree[ZHENG].rank[i];
					ans_l = ans_r = i;
				}
			}
			
			for (i = 1; i <= n >> 1; i++) {
				getAns(i);
			} 
			for (i = ans_l; i<= ans_r; i++) {
				putchar(str[ZHENG][i]);
			}
			putchar('\n');
		}
		
	}
	
}poj3693;


}

//RMQ 写WA了， getAns里求l，r以及求rank的参数写WA了，  
