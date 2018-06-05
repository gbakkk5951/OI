#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

struct E {
    int u, v, id;
    ll w, c;
    bool operator < (E t) {
        return w < t.w;
    }
};

vector<E> e;

int n, m, vis[30];

vector<int> ans, tmp;

ll sco;

int fa[N], cnt;

int get(int x) {
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

void sol() {
    tmp.clear();
    for(int i = 1 ; i <= n ; ++ i) fa[i] = i;
    for(auto e: :: e) {
        int u = e.u, v = e.v, id = e.id; ll w = e.w, c = e.c;
        if(get(u) != get(v)) {
            fa[get(u)] = get(v);
            tmp.push_back(id);
        }
    }
    ans = tmp;
}

int main() {

    freopen("road6.in", "r", stdin);
    freopen("road6.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i = 1 ; i <= m ; ++ i) {
        int u, v; ll w, c;
        scanf("%d%d%lld%lld", &u, &v, &w, &c);
        e.push_back((E) { u, v, i, w, c });
    }
    sort(e.begin(), e.end());

    sol();
    
    for(auto it: ans) {
        printf("%d\n", it);
    }
}