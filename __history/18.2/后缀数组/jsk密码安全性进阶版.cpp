using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace OI {
typedef long long lld;
const int INF = 0x3f3f3f3f;
int lrand() {
    return rand() << 15 | rand();
}
inline double mid(double l, double r) {
    return (l + r) / 2.0;
}

struct Node {
    int val, rand;
    double m[2], v;
    Node *fa,*son[2];
    void mark(double l, double r) {
        m[0] = l; m[1] = r; v = mid(l, r);
    }
    void * operator new (size_t, int, Node*);
    
}pool[1011];
Node *node[1011];
int pidx;

void * Node:: operator new(size_t, int val, Node* fa) {
    Node *nd = &pool[pidx++];
    nd->fa = fa;
    nd->rand = lrand();
    nd->val = val;
    node[val] = nd;
    return nd;
}


int sa[1010], rank[1010], height[1010];

class SuffixHeap {
public:
    int *str, len;
    Node *root;
    double tot;
    
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
    
    int cmp(int idx, Node *nd) {
        if (str[idx] != str[nd->val]) {
            return str[idx] > str[nd->val];
        }
        return tot > node[nd->val + 1]->v;
    }
    void insert(int idx) {
        Node *nd = root;
        while (1) {
            int pos = cmp(idx, nd);
            if (nd->son[pos]) {
                nd = nd->son[pos];
            } else {
                nd->son[pos] = new(idx, nd)Node;
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
        double m[2] = {0, 1};
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
        int i, j, k = 0;
        for (i = 0; i < len - 1; i++) {
            j = sa[rank[i] - 1];
            for (k ? k-- : 0; str[i + k] == str[j + k]; k++);
            height[rank[i]] = k;
        }
    }
    
    void build(int *_str, int _len) {
        str = _str; len = _len;
        int i, idx = 0;
        root = new(len - 1, 0)Node;
        root->mark(0, 1);
        tot = root->v;
        for (i = len - 2; i >= 0; i--) {
            insert(i);
        }     
        getSa(root, idx);
        getRank();
        getHeight();
    }
}tree;




struct _Main {
    
    int readStr(int *arr) {
        int idx = 0, t; 
        while (!isalpha(t = getchar()));
        do {
            arr[idx++] = t;
        } while (isalpha(t = getchar()));
        return idx;
    }
    
    
    int arr[1010];
    int n;
    lld ans;
    void getAns() {
        int i, j, k;
        
        for (i = 1; i <= n >> 1; i++) {
            int mx = -INF, mn = INF;
            for (j = 1; j < n; j++) {
                if (height[j] >= i) {
                    mx = max(mx, sa[j]);
                    mn = min(mn, sa[j]);
                } else {
                    if (mx - mn >= i) {
                        ans++;
                    }
                    mx = mn = sa[j];
                }
            }

            if (mx - mn >= i) {
                ans++;
            }   
        }
    }
    
    _Main() {
        int i, j, k;
        n = readStr(arr);
        arr[n++] = -INF;
        tree.build(arr, n);
        getAns();
        printf("%lld", ans);
    }
    
    
}jsk;




}


