#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

typedef long long ll;

const ll mod = 1e9 + 7;

int n, a[N], d[N][N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

ll ans;

namespace force_1_3 {

    int sta[N], p;

    void dfs(int i) {
        if(i == n + 1) {
            if(!p) return ;
            for(int j = 1 ; j <= p ; ++ j) {
                for(int k = j + 1 ; k <= p ; ++ k) {
                    if(d[sta[j]][sta[k]] != 1) {
                        return ;
                    }
                }
            }
            ++ ans;
        } else {

            dfs(i + 1);

            sta[++ p] = a[i];
            dfs(i + 1);
            -- p;
        }
    }

    void sol() {
        dfs(1);
    }

}

int main() {
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    for(int i = 1 ; i <= 2000 ; ++ i) {
        for(int j = i ; j <= 2000 ; ++ j) {
            d[i][j] = d[j][i] = gcd(i, j);
        }
    }
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++ i) scanf("%d", &a[i]);

    if(n <= 20) {
        force_1_3 :: sol();
    }

    printf("%lld\n", ans);
}
