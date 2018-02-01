using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int 
    INF = 0x3f3f3f3f
;
int lrand() {
    return rand() << 15 | rand();
}

double inline mid(double a, double b) {
    return (a + b) / 2.0;
}
struct Node {
    int val, rand;
    Node *son[2], *fa;
    double m[2], v;
    void mark(double l, double r) {
        m[0] = l; m[1] = r; v = mid(l, r);
    }
    void *operator new(size_t, int, Node*);
}pool[200010];
Node *node[200010];

int pidx;
void * Node::operator new(size_t, int val, Node *fa = 0) {
    Node *nd = &pool[pidx++];
    nd->fa = fa;
    nd->val = val;
    node[val] = nd;
    nd->rand = lrand();
    return nd;
}
int sa[200010], rank[200010], height[200010];

class SuffixHeap {
public:
    int *str, len;
    Node *root;
    double tot;
    int cmp(int idx, Node *nd) {
        if (str[idx] != str[nd->val]) {
            return str[idx] > str[nd->val];
        }
        return tot > node[nd->val + 1]->v;
    }
    void rotate(Node *nd) {
        Node *fa = nd->fa, *gfa = fa->fa, *s;
        nd->fa = gfa;
        if (gfa) {
            gfa->son[gfa->son[1] == fa] = nd;
        }
        int pos = nd == fa->son[1];
        s = fa->son[pos] = nd->son[pos ^ 1];
        if (s) {
            s->fa = fa;
        }
        nd->son[pos ^ 1] = fa;
        fa->fa = nd;
    }
    
    void insert(int idx) {
        Node *nd = root;
        while (1) {
            int pos = cmp(idx, nd);
            if (nd->son[pos]) {
                nd = nd->son[pos];
            } else {
                nd->son[pos] = new(idx, nd) Node;
                nd = nd->son[pos];
                return;
            }            
        }
        while (nd->fa && nd->fa->rand > nd->rand) {
            rotate(nd);
        }
        mark_new(nd);
    }
    
    void mark_new(Node *nd) {
        double m[2] = {0, 1};
        Node *fa = nd->fa;
        if (fa) {
            int pos = nd == fa->son[1];
            m[pos] = fa->m[pos];
            m[pos ^ 1] = fa->v;
        } else {
            root = nd;
        }
        remark(nd, m[0], m[1]);
        tot = nd->v;
    }
    
    void remark(Node *nd, double l, double r) {
        if (nd) {
            nd->mark(l, r);
            remark(nd->son[0], l, nd->v);
            remark(nd->son[1], nd->v, r);   
        }
    }
    
    void getSa(Node *nd, int &idx) {
        if (nd) {
            getSa(nd->son[0], idx);
            sa[idx++] = nd->val;   
            getSa(nd->son[1], idx);
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
        root = new(len - 1)Node;
        root->mark(0, 1);
        tot = root->v;
        int i, idx = 0;
        for (i = len - 2; i >= 0; i--) {
            insert(i);
        }
        getSa(root, idx);
        getRank();
        getHeight();
    }

}tree;



struct _Main {
    int arr[200010];
    int readStr(int *str) {
        int idx = 0, t;
        while (!isalpha(t = getchar()));
        do {
            str[idx++] = t;
        } while ( isalpha(t = getchar()));
        return idx;
    }
    int n;
    _Main() {
        int l1, l2;
        int i, j, k;
        l1 = readStr(arr);
        arr[l1] = - INF;
        l2 = readStr(arr + l1 + 1);
        arr[l1 + l2 + 1] = -INF - 1;
        n = l1 + l2 + 2;
        tree.build(arr, n);
        for (i = 0; i < n; i++) {
            for (j = sa[i]; j < n; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
        
    }
    
}jsk;

}
