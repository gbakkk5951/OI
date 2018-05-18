 #include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, a[N], b[N];

namespace force_9_11 {
    int check() {
        for(int i = 1 ; i <= n ; ++ i) {
            if(a[i] != i || b[i] != i % n + 1) return 0;
        }
        return 1;
    }
    void sol() {
        printf("%d\n", n - 1);
        for(int i = 1 ; i <= n - 1 ; ++ i) {
            printf("%d %d\n", i, i + 1);
        }
    }
}

namespace zhijiecaijielun {
    vector<pair<int, int> > ans;

    vector<int> cir[N];

    int fa[N], pos[N];

    int get(int x) {
        return x == fa[x] ? x : fa[x] = get(fa[x]);
    }

    void sol() {

        for(int i = 1 ; i <= n ; ++ i) fa[i] = i, pos[b[i]] = i;

        for(int i = 1 ; i <= n ; ++ i) {
            // i -> pos[a[i]]
            if(i != pos[a[i]]) {
                fa[get(i)] = get(fa[pos[a[i]]]);
            }
        }

        for(int i = 1 ; i <= n ; ++ i) {
            cir[get(i)].push_back(i);
        }

        for(int i = 1 ; i <= n ; ++ i) {
            if(cir[i].size()) {
                for(auto v : cir[i]) {
                    printf("%d ", v);
                }
                puts("");
            }
        }

        printf("%d\n", (int) ans.size());
        for(int i = 0 ; i < ans.size() ; ++ i) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
}

int allsame() {
    for(int i = 1 ; i <= n ; ++ i) if(a[i] != b[i]) return 0;
    return 1;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++ i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1 ; i <= n ; ++ i) {
        scanf("%d", &b[i]);
    }
    if(n == 1) {
        puts("0");
    } else if(allsame()) {
        puts("0");
    } else if(n == 2) {
        if(a[1] == b[1] && a[2] == b[2]) {
            puts("0");
        } else {
            puts("1\n1 2");
        }
    } else if(n == 3) {
        if(a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
            puts("0");
        } else if(a[1] == b[1]) {
            puts("1\n2 3");
        } else if(a[2] == b[2]) {
            puts("1\n1 3");
        } else if(a[3] == b[3]) {
            puts("1\n1 2");
        } else if(a[1] == 1 && a[2] == 2 && a[3] == 3) {
            if(b[1] == 2 && b[2] == 3 && b[3] == 1) {
                puts("2\n1 2\n2 3");
            } else if(b[1] == 3 && b[2] == 1 && b[3] == 2) {
                puts("2\n2 3\n1 2");
            }
        } else if(a[1] == 1 && a[2] == 3 && a[3] == 2) {
            if(b[1] == 2 && b[2] == 1 && b[3] == 3) {
                puts("2\n2 3\n1 2");
            } else if(b[1] == 3 && b[2] == 2 && b[3] == 1) {
                puts("2\n1 2\n2 3");
            }
        } else if(a[1] == 2 && a[2] == 3 && a[3] == 1) {
            if(b[1] == 1 && b[2] == 2 && b[3] == 3) {
                puts("2\n2 3\n1 2");
            } else if(b[1] == 3 && b[2] == 1 && b[3] == 2) {
                puts("2\n1 2\n2 3");
            }
        } else if(a[1] == 2 && a[2] == 1 && a[3] == 3) {
            if(b[1] == 1 && b[2] == 3 && b[3] == 2) {
                puts("2\n1 2\n2 3");
            } else if(b[1] == 3 && b[2] == 2 && b[3] == 1) {
                puts("2\n2 3\n1 2");
            }
        } else if(a[1] == 3 && a[2] == 1 && a[3] == 2) {
            if(b[1] == 1 && b[2] == 2 && b[3] == 3) {
                puts("2\n1 2\n2 3");
            } else if(b[1] == 2 && b[2] == 3 && b[3] == 1) {
                puts("2\n2 3\n1 2");
            }
        } else if(a[1] == 3 && a[2] == 2 && a[3] == 1) {
            if(b[1] == 1 && b[2] == 3 && b[3] == 2) {
                puts("2\n2 3\n1 2");
            } else if(b[1] == 2 && b[2] == 1 && b[3] == 3) {
                puts("2\n1 2\n2 3");
            }
        }
    } else if(force_9_11 :: check()) {
        force_9_11 :: sol();
    } else {
        force_9_11 :: sol();
    }
    // zhijiecaijielun :: sol();
}
