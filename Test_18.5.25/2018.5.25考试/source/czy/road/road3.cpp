#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

struct E {
    int u, v, id;
    ll w, c;
    bool operator < (E t) {
        return w < t.w;
    }
};

vector<E> e;

int n, m, vis[21];

vector<int> ans, tmp;

ll sco;

int fa[N], cnt;

int get(int x) {
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

void sol() {
    ll sum = 0;
    tmp.clear();
    for(int i = 1 ; i <= n ; ++ i) fa[i] = i;
    for(auto e: :: e) {
        int u = e.u, v = e.v, id = e.id; ll w = e.w, c = e.c;
        if(vis[c]) {
            if(get(u) != get(v)) {
                fa[get(u)] = get(v);
                sum += w;
                if(sum * cnt >= sco) {
                    return ;
                }
                tmp.push_back(id);
            }
        }
    }
    if(tmp.size() != n - 1) return ;
    sco = sum * cnt;
    ans = tmp;
}

int main() {

    freopen("road3.in", "r", stdin);
    freopen("road3.out", "w", stdout);

    scanf("%d%d", &n, &m);
    
    for(int i = 1 ; i <= m ; ++ i) {
        int u, v; ll w, c;
        scanf("%d%d%lld%lld", &u, &v, &w, &c);
        e.push_back((E) { u, v, i, w, c });
        sco += w;
    }
    sco *= 20;

    sort(e.begin(), e.end());

    for(int s = 0 ; s < (1 << 20) ; ++ s) {

        cerr << (double) s / (1 << 20) * 100 << "%" << "\tcurrent: " << sco << endl;

        cnt = 0;
        for(int i = 1 ; i <= 20 ; ++ i) cnt += (vis[i] = (s >> (i - 1)) & 1);
        sol();
    }

    for(auto it: ans) {
        printf("%d\n", it);
    }
    cerr << "sco = " << sco << endl;
}