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
    MAXN = 100010,
    INF = 0x3f3f3f3f
;
const lld 
    LINF = (lld)INF << 31 | INF
;

struct Node {
    int val, rand;
    double m[2], v;
    Node *son[2], *fa;
    void mark(double l, double r) {
        m[0] = l; m[1] = r;
        v = (l + r) / 2.0;
    }
    void* operator new(size_t, int val, Node *fa);
    void* operator new(size_t, int val, Node *fa, double l, double r);
}pool[MAXN];
int pidx;
Node *node[MAXN];

int lrand() {
    return rand() << 15 | rand();
}
void* Node::operator new(size_t, int val, Node *fa, double l, double r) {
    Node *nd = &pool[pidx++];
    nd->val = val;
    nd->fa = fa;
    nd->rand = lrand();
    node[val] = nd;
    nd->mark(l, r);
    return nd;
}
void* Node::operator new(size_t, int val, Node *fa) {
    Node *nd = &pool[pidx++];
    nd->val = val;
    nd->fa = fa;
    nd->rand = lrand();
    node[val] = nd;
    return nd;
}
int sa[MAXN], rank[MAXN], height[MAXN];

class SuffixHeap {
public:
    Node *root;
    int *str, len;
    double tot;
    
    int cmp(int idx, Node *nd) {
        if (str[idx] != str[nd->val]) {
            return str[idx] > str[nd->val];
        }
        return tot > node[nd->val + 1]-> v;
    }
    
    void rotate(Node *nd) {
        Node *fa = nd->fa, *gfa = fa->fa, *s;
        int pos;
        nd->fa = gfa;
        if (gfa) {
            gfa->son[fa == gfa->son[1]] = nd;
        }
        pos = fa->son[1] == nd;
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
                break;
            }
        }
        while (nd->fa && nd->rand < nd->fa->rand) {
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
            remark(nd->son[0], nd->m[0], nd->v);
            remark(nd->son[1], nd->v, nd->m[1]);
        }
    }
    
    void getRank() {
        int i;
        for (i = 0; i < len; i++) {
            rank[sa[i]] = i;
        }
    }
    
    void getSa(Node *nd, int &idx) {
        if (nd) {
            getSa(nd->son[0], idx);
            sa[idx++] = nd->val;
            getSa(nd->son[1], idx);
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
        root = new(len - 1, 0, 0, 1)Node;
        for (i = len - 2; i >= 0; i--) {
            insert(i);
        }
        getSa(root, idx);
        getRank();
        getHeight();
    }
}suffix_heap;


struct ST{
lld h[MAXN][18];
lld l[MAXN][18];
int n;
int mx_bit;
void build(int _n) {
    n = _n;
    int i, j, k, I, J;
    lld (*arr)[18];
    for (i = 0; i < n; i++) {
        h[i][0] = height[i];
    }
    for (i = 0; i < n; i++) {
        l[i][0] = sa[i];
    }
    arr = h;
    for (mx_bit = 1; 1 << mx_bit < n; mx_bit++);
    for (I = 0, arr = h; I < 2; I++) {
        for (J = 1; J <= mx_bit; J++) {
            for (i = 0; i < n; i++) {
                arr[i][J] = min(arr[i][J - 1], (i + (1 << J - 1)) < n ?
                                arr[i + (1 << J - 1)][J - 1] : LINF);
            }   
        }
        arr = l;
    }
}
int getPos(int beg, int len) {
    int I, pos = rank[beg] + 1;
    lld ret = beg;
    for(I = mx_bit; I >= 0; I--) {
        if (pos + (1 << I) < n + 1 && h[pos][I] >= len) {
            ret = min(ret, l[pos][I]);
            pos += 1 << I;
        }
    }
    return ret;
}
    
    
}st;


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
    int getStr(int *a) {
        int idx = 0;
        char t;
        while (!isalpha(t = getchar()));
        a[idx++] = t;
        while ( isalpha(t = getchar())) {
            a[idx++] = t;
        } 
        return idx;
    }
    lld sum[MAXN];
    void getSum() {
        int i;
        sum[0] = 0;
        for(i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + n - sa[i] - 1 - height[i]; //-1 是为了去删掉-INF 
        }
        sum[n] = LINF;
    }
    
    void query(lld val, lld &l_, lld &r_) {
        int l, r, mid;
        l = 0; r = n;
        while (l < r) {
            mid = l + r >> 1;
            if (sum[mid] < val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l == n) {
            l_ = 0; r_ = 0;
            return;
        }
        val -= sum[l - 1];
        int len = height[l] + val;
        l_ = st.getPos(sa[l], len) + 1;
        r_ = l_ + len - 1;
    }
    int arr[MAXN];
    int n;
    _Main() {
        lld l = 0, r = 0;
        lld v;
        int Q, Qn;
        n = getStr(arr);
        read(Qn);
        arr[n++] = -INF - 1;
        suffix_heap.build(arr, n);
        getSum();
        st.build(n);
        for (Q = 1; Q <= Qn; Q++) {
            read(v);
            query((v ^ l ^ r) + 1, l, r);
            printf("%lld %lld\n", l, r);
        }
    }
    
    
    
}jsk;


}

