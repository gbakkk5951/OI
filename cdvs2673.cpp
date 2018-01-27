using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int 
    MAXN = 1000010;
int fa[MAXN];
int idx;
int mxlen;
int getfa(int nd) {
    return fa[nd] ? fa[nd] = getfa(fa[nd]) : nd;   
}
struct Block {
    int l, r;
}b[MAXN];
int belong[MAXN];
struct Element {
    int val, pos;
    bool operator < (const Element &b) const {
        return val < b.val;
    }
}sorted[MAXN];


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
    int getb(int nd) {
        return getfa(belong[nd]);
    }
    void insert(int nd) {
        int t;
        idx++;
        belong[nd] = idx;
        
        if (t = getb(nd - 1)) {
            b[idx].l = b[t].l;
            fa[t] = idx;
        } else {
            b[idx].l = nd;
        }
        if (t = getb(nd + 1) ) {
            b[idx].r = b[t].r;
            fa[t] = idx;            
        } else {
            b[idx].r = nd;
        }
        mxlen = max(mxlen, b[idx].r - b[idx].l + 1);
    }
    int n;
    _Main() {
        int i, j, k;
        int tmp;
        lld ans = 0;
        read(n);
        for (i = 1; i <= n; i++) {
            read(tmp);
            sorted[i].val = tmp;
            sorted[i].pos = i;
        }
        sort(sorted + 1, sorted + n + 1);
        for (i = n; i >= 1; i--) {
            insert(sorted[i].pos);
            ans = max(ans, (lld)sorted[i].val * mxlen);
        }
        printf("%lld", ans);
    }
    
    
    
}cdvs2673;

}
