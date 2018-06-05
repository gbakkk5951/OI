#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int f = 1, x = 0, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) f = (ch == '-') ? -1 : 1;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return f * x;
}

const int N = 5000 + 5, LOG = 15;
const int M = 10000 + 5;
const int V = 40000 + 5;

int n, q;

int w[N], val[N];
int qV[N], T, head[N], nxt[N], qid[N];

struct Graph {
    int m, head[N], nxt[M], to[M];
    void add(int a, int b) {
        ++m, to[m] = b; nxt[m] = head[a]; head[a] = m, swap(a, b), ++m, to[m] = b; nxt[m] = head[a]; head[a] = m;
        return ;
    }
} ori, dac;


void push(int u, int id) { qid[++T] = id; nxt[T] = head[u]; head[u] = T; }

int root, size, f[N], siz[N];
bool vis[N];

void findrt(int u, int fa) {
    siz[u] = 1; f[u] = 0;
    for(int o = ori.head[u]; o; o = ori.nxt[o]) if(ori.to[o] != fa && !vis[ori.to[o]]) {
        findrt(ori.to[o], u);
        f[u] = max(f[u], siz[ori.to[o]]);
        siz[u] += siz[ori.to[o]];
    }
    f[u] = max(f[u], size - siz[u]);
    if(f[root] > f[u]) root = u;
    return ;
}
void build(int u) {
    vis[u] = 1;
    for(int o = ori.head[u]; o; o = ori.nxt[o]) if(!vis[ori.to[o]]) {
        f[root = 0] = size = siz[ori.to[o]]; 
        findrt(ori.to[o], u);
        dac.add(u, root);
        build(root);
    }
    return ;
}

int dep[N], MN[N];
void getdep(int u, int fa) {
    MN[u] = n + 1;
    for(int o = dac.head[u]; o; o = dac.nxt[o]) if(dac.to[o] != fa) {
        dep[dac.to[o]] = dep[u] + 1;
        getdep(dac.to[o], u);
        MN[u] = min(MN[u], min(MN[dac.to[o]], dac.to[o]));
    }
    return ;
}
int F[LOG][V], ans[N];
bool ok[N];
void ckmax(int& a, int b) {
    if(a < b) a = b;
    return ;
}


void solve(int u, int fa) {
    if(u == 1) {
        for (int i = 0; i <= V - 1 - w[i]; ++i) ckmax(F[dep[u]][i+w[u]], F[dep[u]][i] + val[u]), ckmax(F[dep[u]][i+1], F[dep[u]][i]);
        for(int o = head[u]; o; o = nxt[o]) ans[qid[o]] = F[dep[u]][qV[qid[o]]];
        ok[u] = 1;
    }
    for(int o = ori.head[u]; o; o = ori.nxt[o]) if (ok[ori.to[o]]) {
        memcpy(F[dep[u]], F[dep[ori.to[o]]], sizeof(F[dep[u]]));
        for (int i = 0; i <= V - 1 - w[i]; ++i) ckmax(F[dep[u]][i+w[u]], F[dep[u]][i] + val[u]), ckmax(F[dep[u]][i+1], F[dep[u]][i]);
        for(int o = head[u]; o; o = nxt[o]) ans[qid[o]] = F[dep[u]][qV[qid[o]]];
        ok[u] = 1;
        break;
    }
    for(int o = dac.head[u]; o; o = dac.nxt[o]) if (dac.to[o] != fa && min(MN[dac.to[o]], dac.to[o]) == MN[u]) {
        solve(dac.to[o], u);
    }
    for(int o = dac.head[u]; o; o = dac.nxt[o]) if (dac.to[o] != fa && min(MN[dac.to[o]], dac.to[o]) != MN[u]) {
        solve(dac.to[o], u);
    }
    if(ok[u]) {
        for(int o = ori.head[u]; o; o = ori.nxt[o]) if(!ok[ori.to[o]] && dep[ori.to[o]] < dep[u]) {
            int v = ori.to[o];
            memcpy(F[dep[v]], F[dep[u]], sizeof(F[dep[u]]));
            for (int i = 0; i <= V - 1 - w[ori.to[o]]; ++i) {
                ckmax(F[dep[v]][i+w[v]], F[dep[v]][i] + val[v]), ckmax(F[dep[v]][i + 1], F[dep[v]][i]);
            }
            for(int E = head[v]; E; E = nxt[E]) ans[qid[E]] = F[dep[ori.to[o]]][qV[qid[E]]];
            ok[v] = 1;
        }
    }
    return ;
}

int main() {
    freopen("ggg.in", "r", stdin);
    freopen("ggg.out", "w", stdout);
    n = read(); q = read();
    for (int i = 1; i <= n; ++i) w[i] = read(), val[i] = read();
    for (int i = 2; i <= n; ++i) {
        int u = read();
        ori.add(u, i);
    }
    root = 0;
    f[root] = size = n; 
    findrt(1, 0); 
    build(root);
    for (int i = 1; i <= q; ++i) qV[i] = read();
    for (int i = 1; i <= q; ++i) push(read(), i);

    memset(vis, 0, sizeof(vis));
    
    root = 0;
    f[0] = size = n; 
    findrt(1, 0);
    
    getdep(root, 0);
    solve(root, 0);
    
    for (int i = 1; i <= q; ++i)  printf("%d\n", ans[i]);
    
    return 0;
}