using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>

namespace OI {
const int 
    MAXN = 20010;
struct Node {
    int val;
    Node *fa;
    int rand;
    double m[2], v;
    Node *son[2];
    inline void mark(double l = 0, double r = 1) {
        m[0] = l; m[1] = r;
        v = (l + r) / 2.0;
    }
}pool[MAXN];
int pidx;

int sa[MAXN], 
    rank[MAXN], 
    height[MAXN];


class SuffixTreap {
public:
double tot;
int len;
Node *root, *node[MAXN];
int *str;


int lrand() {
    return rand() << 15 | rand();
}

void remark(Node *nd, double l, double r) {
    if (nd == 0) {
        return;
    }
    nd->mark(l, r);
    remark(nd->son[0], nd->m[0], nd->v);
    remark(nd->son[1], nd->v, nd->m[1]);
}

void rotate(Node *nd) {
    Node *fa = nd->fa, *gfa = fa->fa, *s;
    int pos;
    nd->fa = gfa;
    if (gfa) {
        gfa->son[gfa->son[1] == fa] = nd;
    }
    pos = nd == fa->son[1];
    s = fa->son[pos] = nd->son[pos ^ 1];
    nd->son[pos ^ 1] = fa;
    fa->fa = nd;
    if (s) {
        s->fa = fa;
    }
}
int cmp(int idx, Node *nd) {
    if (str[idx] != str[nd->val]) {
        return str[idx] > str[nd->val];
    }
    return tot > node[nd->val + 1]->v;
}
void insert(int idx) {
    int pos;
    Node *nd = root;
    while (1) {
        pos = cmp(idx, nd);
        if (nd->son[pos]) {
            nd = nd->son[pos];
        } else {
            nd->son[pos] = new_node(idx, nd);  
            nd = nd->son[pos];
            break;
        }
    }
    while (nd->fa && nd->fa->rand < nd->rand) {
        rotate(nd);
    }
    new_mark(nd);
}
void new_mark(Node *nd) {
    double mark[2] = {0.0, 1.0};
    Node *fa = nd->fa;
    int pos;
    if (fa) {
        pos = fa->son[1] == nd;
        mark[pos] = fa->m[pos];
        mark[pos ^ 1] = fa->v;
    } else {
        root = nd;
    }
    remark(nd, mark[0], mark[1]);
    tot = nd->v;
}

Node *new_node(int val, Node *fa = 0) {
    Node *nd = &pool[pidx++];
    nd->val = val;
    nd->fa = fa;
    nd->rand = lrand();
    node[val] = nd;
    return nd;
}


void getsa(Node *nd, int &idx) {
    if (nd == 0) {
        return;
    }
    getsa(nd->son[0], idx);
    sa[idx++] = nd->val;
    getsa(nd->son[1], idx);
}
void getrank() {
    int i;
    for (i = 0; i < len; i++) {
        rank[sa[i]] = i;
    }
}

void getheight() {
    int i, j, k;
    for (i = 0, k = 0; i < len - 1; i++) {
        j = sa[rank[i] - 1];
        for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
        height[rank[i]] = k;
    }
}

void init(int *_str, int _len) {
    int i, j, k, idx = 0;
    str = _str;
    len = _len;
    root = new_node(len - 1);
    root->mark(0.0, 1.0);
    tot = root->v;
    for (i = len - 2; i >= 0; i--) {
        insert(i);
    }
    getsa(root, idx);
    getrank();
    getheight();
}
}tree;




struct _Main { 
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
int str[MAXN];

int exist(int goal) {
    int i, mx, mn, v = -2;
    for (i = 0; i < n; i++) {
        v = min(v, height[i]);
        if (v < goal) {
            mn = mx = sa[i];
            v = 0x3f3f3f3f;
        } else {
            mn = min(sa[i], mn);
            mx = max(sa[i], mx);
        }
        if (mx - mn > goal) {
            return 1;
        }
    }
    return 0;
}
int n;
_Main() {
    int i, j, k;
    read(n);
    for (i = 0; i < n; i++) {
        read(str[i]);
    } 
    for (i = n - 1; i > 0; i--) {
        str[i] -= str[i - 1];
    }
    str[n] = -0x3f3f3f3f - 1;
    tree.init(str + 1, n);

    int l = -1, r = n / 2, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (exist(mid + 1)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    printf("%d", l + 1);
}


}jsk;


}
