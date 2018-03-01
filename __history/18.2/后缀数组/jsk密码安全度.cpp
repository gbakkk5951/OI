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
    double l, r;
    Node *son[2], *fa;
    int val, rand;
}pool[MAXN];
int pidx;

int sa[MAXN], 
    rank[MAXN], 
    height[MAXN];


class SuffixTreap {
public:
double tot;
Node *root, *node[MAXN];
int *str;
int lrand() {
    return rand() << 15 | rand();
}

void remark(Node *nd, double l, double r) {
    nd->l = l;
    nd->r = r;
    if (nd->son[0]) {
        remark(nd->son[0], nd->l, (nd->r + nd->l) / 2.0);
    }
    if (nd->son[1]) {
        remark(nd->son[1], (nd->r + nd->l) / 2.0, nd->r);
    }    
}

void rotate(Node *nd) {
    Node *fa, *s;
    int pos;
    fa = nd->fa;
    nd->fa = fa->fa;
    if (fa->fa) {
        fa->fa->son[fa == fa->fa->son[1]] = nd;
    }
    pos = nd == fa->son[1];
    fa->son[pos] = s = nd->son[pos ^ 1];
    nd->son[pos ^ 1] = fa;
    fa->fa = nd;
    if (s) {
        s->fa = fa;
    }
}

void insert(int idx) {
    Node *nd = root;
    int pos;
    while (1) {
        if (str[idx] != str[nd->val]) {
            pos = str[idx] > str[nd->val];
        } else {
            pos = tot > (node[nd->val + 1]->r + node[nd->val + 1]->l) / 2.0;
        }
        if (nd->son[pos]) {
            nd = nd->son[pos];
        } else {
            nd->son[pos] = &pool[pidx++];  
            nd->son[pos]->fa = nd;
            nd = nd->son[pos];
            nd->val = idx;
            nd->rand = lrand();
            break;
        }
    }
    while (nd->fa && nd->fa->rand < nd->rand) {
        rotate(nd);
    }
    double l = 0, r = 1;
    if (nd->fa) {
        l = nd->fa->l; r = nd->fa->r;
        if (nd->fa->son[0] == nd) {
            r = (l + r) / 2.0;
        } else {
            l = (l + r) / 2.0;
        }
    } else {
        root = nd;
    }
    tot = (l + r) / 2.0;
    remark(nd, l, r);
    node[idx] = nd;
}
int getsa(Node *nd = (Node *)0, int idx = 0) {
    int i;
    if (nd->son[0]) {
        idx = getsa(nd->son[0], idx);
    }
    sa[idx++] = nd->val;
    if (nd->son[1]) {
        idx = getsa(nd->son[1], idx);
    }    
    return idx;
}

void init(int *_str, int len) {
    int i, j, k;
    str = _str;
    
    root = &pool[pidx++];
    root->val = len - 1;
    root->l = 0.0;
    tot = 0.5;
    root->r = 1.0;
    root->rand = lrand();
    node[len - 1] = root;
    for (i = len - 2; i >= 0; i--) {
        insert(i);
    }
    getsa(root);
    for (i = 0; i < len; i++) {
        rank[sa[i]] = i;
    }
    for (i = 0, k = 0; i < len; i++) {
        if (rank[i]) {
            j = sa[rank[i] - 1];
            for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
        } else {
            k = 0;
        }
        height[rank[i]] = k;
    }
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
    int i, mx, mn, v;
    mx = mn = sa[0];
    v = 0x3f3f3f3f;
    for (i = 1; i < n; i++) {
        v = min(v, height[i]);
        mn = min(sa[i], mn);
        mx = max(sa[i], mx);
        if (v < goal) {
            mn = mx = sa[i];
            v = 0x3f3f3f3f;
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
