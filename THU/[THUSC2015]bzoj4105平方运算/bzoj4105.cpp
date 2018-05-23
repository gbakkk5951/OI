using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e4 + 10;
const int DST = 0, NXT = 1;
int lcm = 1;
int head[MXN], edge[MXN << 1][2];
int eidx;
int dfn[MXN], low[MXN], dfnidx;
int stk[MXN], top;
int /*nxt[MXN],*/ pre[MXN];
int instk[MXN];
int lpid[MXN];
int lpidx;
int vis[MXN];
int arr[100010];
struct LS {
    int inline operator [] (const int &a) {
        return a << 1;
    }
}ls;
struct RS {
    int inline operator [] (const int &a) {
        return a << 1 | 1;
    }
}rs;
 
struct Node {
    int arr[60], py, tag, oth;
};
 
int p;
         
struct Tree {
    Node node[270000];
    void inline mov(const int &nd, const int &py) {
        node[nd].py += py;
        node[nd].tag += py;
    }
    void inline push(const int &nd) {
        if (node[nd].tag) {
            mov(ls[nd], node[nd].tag);
            mov(rs[nd], node[nd].tag);
            node[nd].tag = 0;
        }
    }
    void update(int nd) {
        int t1, t2;
        node[nd].oth = node[ls[nd]].oth + node[rs[nd]].oth;
        t1 = (node[ls[nd]].py - node[nd].py) % lcm;
        t2 = (node[rs[nd]].py - node[nd].py) % lcm;
        for (int i = 0; i < lcm; i++, t1++, t2++) {
            t1 -= (t1 == lcm) * t1;
            t2 -= (t2 == lcm) * t2;
            node[nd].arr[i] = node[ls[nd]].arr[t1] + node[rs[nd]].arr[t2];
        }
    }
    void change(int nd, int nl, int nr, int l, int r) {
        if (l <= nl && nr <= r && node[nd].oth == 0) {
            mov(nd, 1);
            return;
        } 
        if (nl == nr) {
            node[nd].oth = node[nd].oth * node[nd].oth % p;
            if (lpid[node[nd].oth]) {
                int now = (node[nd].py + 1) % lcm, lst;
                lst = node[nd].arr[node[nd].py % lcm] = node[nd].oth;
                for (int i = 1; i < lcm; i++, now++) {
                    now -= (now == lcm) * lcm;
                    lst = node[nd].arr[now] = lst * lst % p;
                }
                node[nd].oth = 0;
            }
            return;
        }
        push(nd);
        int mid = nl + nr >> 1;
        if (l <= mid) change(ls[nd], nl, mid, l, r);
        if (r > mid) change(rs[nd], mid + 1, nr, l, r);
        update(nd);
    }
    int query(int nd, int nl, int nr, int l, int r) {
        if (l <= nl && nr <= r) {
            return node[nd].arr[node[nd].py % lcm] + node[nd].oth;
        }
        push(nd);
        int ret = 0, mid = nl + nr >> 1;
        if (l <= mid) ret += query(ls[nd], nl, mid, l, r);
        if (r > mid) ret += query(rs[nd], mid + 1, nr, l, r);
        return ret;
    }
    void init(int nd, int nl, int nr) {
        if (nl == nr) {
            Node *a = &node[nd];
            if (lpid[arr[nl]]) {
                int lst = a->arr[0] = arr[nl];
                for (int i = 1; i < lcm; i++) {
                    lst = a->arr[i] = lst * lst % p;
                }
            } else {
                a->oth = arr[nl];
            }
            return;
        }
        int mid = nl + nr >> 1;
        init(ls[nd], nl, mid);
        init(rs[nd], mid + 1, nr);
        update(nd);
    }
}tree;
 
struct _Main {
    inline void add(int a, int b) {
        eidx++;
        edge[eidx][DST] = b;
        edge[eidx][NXT] = head[a];
        head[a] = eidx;
    }
    void dfs(int nd, int fe) {
        dfn[nd] = low[nd] = ++dfnidx;
        stk[++top] = nd;
        instk[nd] = 1;
        int t;
        for (int e = head[nd]; e; e = edge[e][NXT]) {
            if (e == (fe ^ 1)) continue;
            t = edge[e][DST];
            //if (t == fa) continue; //双元环会挂掉
            if (!dfn[t]) {
                dfs(t, e);
                low[nd] = min(low[nd], low[t]);
            } else if (instk[t]) {
                low[nd] = min(low[nd], dfn[t]);
            }
        }
        int lst = nd, id, tp;
        id = (low[stk[top]] >= dfn[nd] && (stk[top] != nd || nd * nd % p == nd)) ? ++lpidx : 0;//自环
        while (top && low[stk[top]] >= dfn[nd]) {
            tp = stk[top];
//          nxt[tp] = lst;
            pre[lst] = tp;
            lst = tp;
            lpid[tp] = id;
            instk[tp] = 0;
             
            --top;
        }
    }
    int getlen(int nd) {
        int ret = 0;
        for (; !vis[nd]; nd = pre[nd]) {
            ret += vis[nd] = 1;
        }
        return ret;
    }
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
     
    _Main() {
        int t; 
        int n, Qn;
        int op, l, r;
        eidx = 1;
        read(n); read(Qn); read(p);
        for (int i = 0; i <= p - 1; i++) {
            t = i * i % p;
            add(i, t); add(t, i);
        }
        for (int i = 0; i <= p - 1; i++) {
            if (!dfn[i]) dfs(i, 0);
        }
        for (int i = 0; i <= p - 1; i++) {
            if (lpid[i]) {
                if (!vis[i]) {
                    t = getlen(i);
                    lcm = lcm / gcd(lcm, t) * t;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            read(arr[i]);
        }
        tree.init(1, 1, n);
        for (int i = 1; i <= Qn; i++) {
            read(op); read(l); read(r);
            if (op == 0) {
                tree.change(1, 1, n, l, r);
            } else {
                printf("%d\n", tree.query(1, 1, n, l, r));
            }
        }
         
    }
template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10; a += t - '0';
        }
    }
}bzoj4105;
}

