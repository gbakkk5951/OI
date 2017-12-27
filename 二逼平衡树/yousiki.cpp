#include <cstdio>
 
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
 
template <class T>
inline T getmin(const T &a, const T &b) {
    return min(a, b);
}
 
template <class T>
inline T getmax(const T &a, const T &b) {
    return max(a, b);
}
 
const int mxn = 100005;
const int mxm = 3000005;
const int inf = 100000008;
 
namespace splay {
    int tot;
    int siz[mxm];
    int num[mxm];
    int fat[mxm];
    int son[mxm][2];
     
    int insert(int &t, int f, int v) {
        if (!t) {
            t = ++tot;
            fat[t] = f;
            num[t] = v;
            siz[t] = 1;
            son[t][0] = 0;
            son[t][1] = 0;
             
            return t;
        }
         
        ++siz[t];
         
        if (v <= num[t])
            return insert(son[t][0], t, v);
        else
            return insert(son[t][1], t, v);
    }
     
    #define update(t) (siz[t] = siz[son[t][0]] + siz[son[t][1]] + 1)
     
    inline void rotate(int t) {
        int f = fat[t];
        int g = fat[f];
        int a = son[f][1] == t;
        int b = !a, s = son[t][b];
         
        fat[t] = g;
        fat[f] = t;
         
        son[t][b] = f;
        son[f][a] = s;
         
        if (s)
            fat[s] = f;
        if (g) {
            if (son[g][0] == f)
                son[g][0] = t;
            else
                son[g][1] = t;
        }
         
        update(f);
        update(t);
    }
     
    inline void splay(int t, int p = 0) {
        while (fat[t] != p) {
            int f = fat[t];
            int g = fat[f];
             
            if (g == p)
                rotate(t);
            else {
                int a = son[f][1] == t;
                int b = son[g][1] == f;
                 
                if (a == b)
                    rotate(f), rotate(t);
                else
                    rotate(t), rotate(t);
            }
        }
    }
     
    inline int rnk(int t, int v) {
        int k = 0;
         
        while (t) {
            if (v <= num[t]) 
                t = son[t][0];
            else {
                k += siz[t];
                 
                t = son[t][1];
                 
                k -= siz[t];
            }
        }
         
        return k;
    }
     
    inline int kth(int t, int k) {
        while (t) {
            int s = siz[son[t][0]];
             
            if (k <= s)
                t = son[t][0];
            else if (k == ++s)
                return t;
            else
                t = son[t][1], k -= s;
        }
         
        return 0;
    }
     
    inline int fnd(int t, int v) {
        while (t) {
            if (num[t] == v)
                return t;
             
            if (v < num[t])
                t = son[t][0];
            else
                t = son[t][1];
        }
         
        return 0;
    }
     
    inline int pre(int t, int v) {
        int r = -inf;
         
        while (t) {
            if (v <= num[t])
                t = son[t][0];
            else {
                r = max(r, num[t]);
                t = son[t][1];
            }
        }
         
        return r;
    }
     
    inline int nxt(int t, int v) {
        int r = +inf;
         
        while (t) {
            if (v >= num[t])
                t = son[t][1];
            else {
                r = min(r, num[t]);
                t = son[t][0];
            }
        }
         
        return r;
    }
     
    inline void ins(int &t, int v) {
        int p = insert(t, 0, v);
        splay(p, 0);
        t = p;
    }
     
    inline void rmv(int &t, int v) {
        int p = fnd(t, v);
         
        if (p) {
            splay(p, 0);
             
            if (!son[p][0])
                t = son[p][1], fat[t] = 0;
            else if (!son[p][1])
                t = son[p][0], fat[t] = 0;
            else {
                t = son[p][0];
                 
                while (son[t][1])
                    t = son[t][1];
                 
                splay(t, p);
                 
                son[t][1] = son[p][1];
                 
                fat[son[p][1]] = t;
                 
                fat[t] = 0;
                 
                update(t);
            }
        }
    }
     
    void print(int t) {
        if (!t)return;
         
        print(son[t][0]);
         
        printf("%d: [%d] (%d) (%d %d) {%d}\n", 
            t, num[t], fat[t], son[t][0], son[t][1], siz[t]);
         
        print(son[t][1]);
    }
     
    #undef update
}
 
namespace stree {
    int tot;
    int rot[mxm];
    int lsn[mxm];
    int rsn[mxm];
     
    int build(int l, int r, int *s) {
        int t = ++tot;
         
        for (int i = l; i <= r; ++i)
            splay::ins(rot[t], s[i]);
         
        if (l != r) {
            int m = (l + r) >> 1;
             
            lsn[t] = build(l, m, s);
            rsn[t] = build(m + 1, r, s);
        }
         
        return t;
    }
     
    void update(int t, int l, int r, int p, int a, int b) {
        splay::rmv(rot[t], a);
        splay::ins(rot[t], b);
         
        if (l != r) {
            int m = (l + r) >> 1;
             
            if (p <= m)
                update(lsn[t], l, m, p, a, b);
            else
                update(rsn[t], m + 1, r, p, a, b);
        }
    }
     
    int queryRnk(int t, int l, int r, int x, int y, int v) {
        if (l == x && y == r)
            return splay::rnk(rot[t], v);
         
        int m = (l + r) >> 1;
         
        if (y <= m)
            return queryRnk(lsn[t], l, m, x, y, v);
        else if (x > m)
            return queryRnk(rsn[t], m + 1, r, x, y, v);
         
        return
            queryRnk(lsn[t], l, m, x, m, v)
        +   queryRnk(rsn[t], m + 1, r, m + 1, y, v);
    }
     
    int queryPre(int t, int l, int r, int x, int y, int v) {
        if (l == x && y == r)
            return splay::pre(rot[t], v);
         
        int m = (l + r) >> 1;
         
        if (y <= m)
            return queryPre(lsn[t], l, m, x, y, v);
        else if (x > m)
            return queryPre(rsn[t], m + 1, r, x, y, v);
         
        return getmax(
            queryPre(lsn[t], l, m, x, m, v),
            queryPre(rsn[t], m + 1, r, m + 1, y, v));
    }
     
    int queryNxt(int t, int l, int r, int x, int y, int v) {
        if (l == x && y == r)
            return splay::nxt(rot[t], v);
         
        int m = (l + r) >> 1;
         
        if (y <= m)
            return queryNxt(lsn[t], l, m, x, y, v);
        else if (x > m)
            return queryNxt(rsn[t], m + 1, r, x, y, v);
         
        return getmin(
            queryNxt(lsn[t], l, m, x, m, v),
            queryNxt(rsn[t], m + 1, r, m + 1, y, v));
    }
}
 
int n, m, s[mxn];
 
signed main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
     
    scanf("%d%d", &n, &m);
     
    for (int i = 1; i <= n; ++i)
        scanf("%d", s + i);
     
    stree::build(1, n, s);
     
    for (int i = 1, k, x, y, z; i <= m; ++i) {
        scanf("%d%d%d", &k, &x, &y);
         
        if (k == 3)
            stree::update(1, 1, n, x, s[x], y), s[x] = y;
        else {
            scanf("%d", &z);
             
            if (k == 1)
                printf("%d\n", stree::queryRnk(1, 1, n, x, y, z) + 1);
            else if (k == 4)
                printf("%d\n", stree::queryPre(1, 1, n, x, y, z));
            else if (k == 5)
                printf("%d\n", stree::queryNxt(1, 1, n, x, y, z));
            else {
                int lt = 0, rt = +inf, mid, ans;
                 
                while (lt <= rt) {
                    mid = (lt + rt) >> 1;
                     
                    if (stree::queryRnk(1, 1, n, x, y, mid) < z)
                        lt = mid + 1, ans = mid;
                    else
                        rt = mid - 1;
                }
                 
                printf("%d\n", ans);
            }
        }
    }
}
