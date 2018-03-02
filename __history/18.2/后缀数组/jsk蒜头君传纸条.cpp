using namespace std;
int main() {}

#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>

namespace OI {

int lrand() {
    return rand() << 15 | rand(); 
}

struct Node {
    int val, rand;
    double m[2], v;
    Node *fa, *son[2];
    void mark(double l, double r) {
        m[0] = l; m[1] = r; v = (l + r) / 2.0;
    }
    
}pool[20010];
int pidx;
Node *node[20010];
Node * new_node(int val, Node *fa = 0) {
    Node *nd = &pool[pidx++];
    nd->val = val;
    nd->fa = fa;
    nd->rand = lrand();
    node[val] = nd;
    return nd;
} 
int sa[20010], rank[20010], height[20010];
class SuffixHeap{
public:
    double tot;
    int *str, len;
    Node *root;

void rotate(Node *nd) {
    Node *fa = nd->fa, *gfa = fa->fa, *s;
    int pos;
    nd->fa = gfa;
    if (gfa) {
        gfa->son[gfa->son[1] == fa] = nd;
    }
    pos = nd == fa->son[1];
    s = fa->son[pos] = nd->son[pos ^ 1];
    if (s) {
        s->fa = fa;
    }
    nd->son[pos ^ 1] = fa;
    fa->fa = nd;
}

int cmp(int idx, Node *nd) {
    if (str[idx] != str[nd->val]) {
        return str[idx] > str[nd->val];
    }
    return tot > node[nd->val + 1]->v;
}


void insert(int idx) {
    Node *nd = root;
    int pos;
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
    while (nd->fa && nd->rand < nd->fa->rand) {
        rotate(nd);
    }
    mark_new(nd);
}

void mark_new(Node *nd) {
    double m[2] = {0.0, 1.0};
    if (nd->fa) {
        int pos = nd == nd->fa->son[1];
        m[pos] = nd->fa->m[pos];
        m[pos ^ 1] = nd->fa->v;
    } else {
        root = nd;
    }
    remark(nd, m[0], m[1]);
    tot = nd->v;
}

void remark(Node *nd, double l, double r) {
    if (nd == 0) {
        return;
    }
    nd->mark(l, r);
    remark(nd->son[0], l, nd->v);
    remark(nd->son[1], nd->v, r);
}
void getSa(Node *nd, int &idx) {
    if (nd == 0) {
        return;
    }
    getSa(nd->son[0], idx);
    sa[idx++] = nd->val;
    getSa(nd->son[1], idx);
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
    root = new_node(len - 1);
    root->mark(0.0, 1.0);
    tot = 0.5;
    for (i = len - 2; i >= 0; i--) {
        insert(i);
    }
    getSa(root, idx);
    getRank();
    getHeight();
}
    
}tree;




struct _Main {
template <typename Type>
    void read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '-') {
                f = -1;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        a *= f;
    }
int n, need;
int exist(int val) {
    int i;
    int cnt = 0, v = -0x3f3f3f3f - 1;
    
    for (i = 0; i <= n; i++) {
        v = min(v, height[i]);
        cnt++;
        if (v < val) {
            cnt = 1;
            v = 0x3f3f3f3f;
        }
        if (cnt >= need) {
            return 1;   
        }
    }
    return 0;
}
int getLen() {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (exist(mid + 1)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int arr[20010];
_Main() {
    int i, j;
    read(n); read(need);
    for (i = 1; i <= n; i++) {
        read(arr[i]);
    }
    arr[n + 1] = -0x3f3f3f3f - 1;
    tree.build(arr + 1, n + 1);
    /*for (i = 0; i <= n; i++) {
        for (j = sa[i] + 1; j <= n + 1; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n%d\n", height[i]);
    }*/
    
    printf("%d", getLen());
}
    
    
}jsk;



}
