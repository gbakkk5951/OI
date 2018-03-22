#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N = 2e5 + 10;
 
typedef long long ll;
 
typedef pair<int, int> p;
 
// declare
int n, m;
 
// treap
int sz[N], ch[N][2], fix[N], rt[N];
 
int newnode() {
    static int tot = 0;
    ++ tot;
    sz[tot] = 1;
    fix[tot] = rand();
    return tot;
}
 
void update(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
 
int merge(int a, int b) {
    if(!a || !b) return a | b;
    if(fix[a] < fix[b]) {
        ch[a][1] = merge(ch[a][1], b);
        update(a);
        return a;
    } else {
        ch[b][0] = merge(a, ch[b][0]);
        update(b);
        return b;
    }
}
 
p split(int a, int k) {
    p ret(0, 0);
    if(!a) return ret;
    if(sz[ch[a][0]] >= k) {
        ret = split(ch[a][0], k);
        ch[a][0] = ret.second, ret.second = a;
    } else {
        ret = split(ch[a][1], k - sz[ch[a][0]] - 1);
        ch[a][1] = ret.first, ret.first = a;
    }
    update(a);
    return ret;
}
 
int rk(int a, int v) {
    if(!a) return 0;
    if(a > v) return rk(ch[a][0], v);
    else return sz[ch[a][0]] + 1 + rk(ch[a][1], v);
}
 
// dsu
 
int acc[N];
 
int getacc(int x) { return x == acc[x] ? x : acc[x] = getacc(acc[x]); }
 
// tree
 
vector<int> son[N];
 
int fa[N][25], deep[N];
 
// init
 
void dfs(int u) {
    if(!u) return;
    deep[u] = deep[fa[u][0]] + 1;
    for(int i = 0 ; i < son[u].size() ; ++ i) {
        int v = son[u][i];
        dfs(v);
    }
}
 
// modify
 
int id[N], cnt;
 
void print(int u) {
    if(u) print(ch[u][0]), printf("%d ", u), print(ch[u][1]);
}
 
void spread(int u) {
    if(!u) return;
    id[++ cnt] = getacc(u);
    for(int i = 0 ; i < son[u].size() ; ++ i) spread(son[u][i]);
}
 
void spread(int &host, int obj) {
    if(!obj) return;
    spread(host, ch[obj][0]), spread(host, ch[obj][1]);
    ch[obj][0] = ch[obj][1] = 0, sz[obj] = 1;
    acc[obj] = getacc(host);
    p tmp = split(host, rk(host, obj));
    host = merge(tmp.first, merge(obj, tmp.second));
}
 
inline void modify(int u) {
    if(u != getacc(u)) return;
    cnt = 0;
    for(int i = 0 ; i < son[u].size() ; ++ i) spread(son[u][i]);
    if(cnt <= 1) return;
    for(int i = 2, tar = 1 ; i <= cnt ; ++ i) {
        if(sz[rt[id[tar]]] < sz[rt[id[i]]]) swap(id[tar], id[i]);
        spread(rt[id[tar]], rt[id[i]]);
        if(i == cnt) {
            int v = id[tar];
            son[u].clear();
            son[v].clear();
            son[u].push_back(v);
            fa[v][0] = u;
            for(int j = 1 ; j <= 20 ; ++ j) fa[v][j] = fa[fa[v][j - 1]][j - 1];
            deep[v] = deep[u] + 1;
        }
    }
}
 
// query
 
inline int querylca(int u, int v) {
    int nu = getacc(u), nv = getacc(v);
    if(nu == nv) return min(u, v);
    if(deep[u = nu] < deep[v = nv]) swap(u, v);
    for(int i = 20 ; ~ i ; -- i) if(deep[fa[u][i]] >= deep[v]) u = fa[u][i];
    if(u == v) return u;
    for(int i = 20 ; ~ i ; -- i) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
 
inline int querydeep(int u) {
    int nu = getacc(u);
    return deep[nu] + rk(rt[nu], u) - 1;
}
 
// main
 
int main() {
    srand((unsigned long long) new char);
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v ; i < n ; ++ i) {
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        fa[v][0] = u;
    }
    for(int i = 1 ; i <= n ; ++ i) {
        acc[i] = rt[i] = newnode();
    }
    for(int j = 1 ; j <= 20 ; ++ j)
        for(int i = 1 ; i <= n ; ++ i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    dfs(1);
    for(int i = 1, op, u, v ; i <= m ; ++ i) {
        scanf("%d", &op);
        if(op == 1) {
            // modify u
            scanf("%d", &u);
            modify(u);
        } else if(op == 2) {
            // query lca(u, v)
            scanf("%d%d", &u, &v);
            printf("%d\n", querylca(u, v));
        } else if(op == 3) {
            // query deep(u)
            scanf("%d", &u);
            printf("%d\n", querydeep(u));
        }
    }
}
