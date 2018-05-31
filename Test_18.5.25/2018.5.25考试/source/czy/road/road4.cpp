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

int n, m, vis[30];

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

int cnt_col[30]; // 每种颜色出现次数

int main() {

    freopen("road4.in", "r", stdin);
    freopen("road4.out", "w", stdout);

    /**
     * color: [1, 28]
    */

    scanf("%d%d", &n, &m);

    for(int i = 1 ; i <= m ; ++ i) {
        int u, v; ll w, c;
        scanf("%d%d%lld%lld", &u, &v, &w, &c);
        e.push_back((E) { u, v, i, w, c });
        sco += w;
        ++ cnt_col[c];
    }
    sco *= 20;

    sort(e.begin(), e.end());

    for(int s = 0 ; s < (1 << 28) ; ++ s) {

        if(s % 10000 == 0) cerr << (double) s / (1 << 28) * 100 << "%" << "\tcurrent: " << sco << endl;

        cnt = 0;
        for(int i = 1 ; i <= 28 ; ++ i) cnt += (vis[i] = (s >> (i - 1)) & 1);
        int tmp = 0;
        for(int i = 1 ; i <= 28 ; ++ i) if(vis[i]) tmp += cnt_col[i];
        if(tmp < n - 1) continue ;
        sol();

        if(s % 100000 == 0 && ans.size()) {
            FILE *f = fopen(("road4_" + to_string(s) + ".out").c_str(), "w");
            for(auto it: ans) {
                fprintf(f, "%d\n", it);
            }
            fclose(f);
            cerr << "output over, sum = " << sco << endl;
        }

    }

    for(auto it: ans) {
        printf("%d\n", it);
    }
    cerr << "final sum = " << sco << endl;
}