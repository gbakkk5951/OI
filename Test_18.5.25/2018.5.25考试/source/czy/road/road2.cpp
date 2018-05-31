#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef long long ll;

int n, m;

struct E {
    int u, v, id; ll w;
    bool operator < (E t) {
        return w < t.w;
    }
};

vector<E> edge;

vector<int> ans;

int fa[N];

int get(int x) {
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main() {
    /*
        颜色都相同，那么就是最小生成树了
    */
    freopen("road2.in", "r", stdin);
    freopen("road2.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1 ; i <= n ; ++ i) fa[i] = i;
    for(int i = 1 ; i <= m ; ++ i) {
        int u, v; ll w, c;
        scanf("%d%d%lld%lld", &u, &v, &w, &c);
        edge.push_back((E) { u, v, i, w } );
        assert(c == 1);
    }
    ll sum = 0;
    sort(edge.begin(), edge.end());
    for(auto it: edge) {
        int u = it.u, v = it.v, id = it.id; ll w = it.w;
        if(get(u) != get(v)) {
            fa[get(u)] = get(v);
            ans.push_back(id);
            sum += w;
        }
    }
    for(auto it: ans){
        printf("%d\n", it);
    }
    cerr << "sum = " << sum << endl;
}