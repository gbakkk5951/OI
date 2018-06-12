#include <cstdio>
using namespace std;
typedef long long ll;
const int p = 1e9 + 7;

int n, m;

ll ans;

ll d(ll a, ll b) { return b ? d(b, a % b) : a; }

ll c(ll x) { return x * (x - 1) * (x - 2) / 6; }

int main() {
    freopen("tri.in", "r", stdin);
    // freopen("tri.out", "w", stdout);
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        ++ n, ++ m;
        ans = (c((ll)n * m) - (ll)n * c(m) - (ll)m * c(n)) % p;
        for(int i = 1 ; i < n ; ++ i) {
            for(int j = 1 ; j < m ; ++ j) {
                ll num = d(i, j) - 1;
                if(num >= 1) ans = (ans - num * (n - i) * (m - j) * 2) % p;
            }
        }
        printf("%lld\n", (ans % p + p) % p);
    }
}