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
    set<int> col;
    tmp.clear();
    for(int i = 1 ; i <= n ; ++ i) fa[i] = i;
    for(auto e: :: e) {
        int u = e.u, v = e.v, id = e.id; ll w = e.w, c = e.c;
        if(get(u) != get(v)) {
            fa[get(u)] = get(v);
            sum += w;
            col.insert(c);
            if(sum * col.size() >= sco) {
                return ;
            }
            tmp.push_back(id);
        }
    }
    if(tmp.size() != n - 1) return ;
    sco = sum * col.size();
    ans = tmp;
}

#define CASE "7"

int main() {

    srand((unsigned long long) new char);

    freopen("road" CASE ".in", "r", stdin);
    freopen("road" CASE ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i = 1 ; i <= m ; ++ i) {
        int u, v; ll w, c;
        scanf("%d%d%lld%lld", &u, &v, &w, &c);
        e.push_back((E) { u, v, i, w, c });
    }

    sco = 0x7fffffffffffffffll;

    sort(e.begin(), e.end());
    sol();

    for(int s = 0 ; s < (1 << 28) ; ++ s) {

        if(s % 10000 == 0) cerr << "solving: road " CASE << ",  " << (double) s / (1 << 28) * 100 << "%" << "\tcurrent: " << sco << endl;

        random_shuffle(e.begin(), e.end());

        sol();

        if(s % 1000000 == 0 && ans.size()) {
            FILE *f = fopen(("road" CASE "_" + to_string(s) + ".out").c_str(), "w");
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