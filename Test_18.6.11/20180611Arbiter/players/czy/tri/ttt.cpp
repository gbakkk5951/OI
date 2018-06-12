#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1010;

int n, m;

ll ans;

ll d(ll a, ll b) { return b ? d(b, a % b) : a; }

ll c(ll x) { return x * (x - 1) * (x - 2) / 6; }

ll nm[N][N], ij[N][N], m_[N][N], n_[N][N];

int main() {
    freopen("tri.in", "r", stdin);
    for(int i = 1 ; i < N ; ++ i) {
        for(int j = 1 ; j < N ; ++ j) {
            ll num = d(i, j) - 1;
            nm[i][j] = nm[i - 1][j] + nm[i][j - 1] - nm[i - 1][j - 1];
            ij[i][j] = ij[i - 1][j] + ij[i][j - 1] - ij[i - 1][j - 1];
            m_[i][j] = m_[i - 1][j] + m_[i][j - 1] - m_[i - 1][j - 1];
            n_[i][j] = n_[i - 1][j] + n_[i][j - 1] - n_[i - 1][j - 1];
            if(num >= 1) {
                nm[i][j] += -2 * num;
                ij[i][j] += -2 * num * i * j;
                m_[i][j] += 2 * num * i;
                n_[i][j] += 2 * num * j;
            }
        }
    }

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        ++ n, ++ m;
        ans = (c((ll)n * m) - (ll)n * c(m) - (ll)m * c(n));
        ans += n * m * nm[n][m];
        ans += ij[n][m];
        ans += m * m_[n][m];
        ans += n * n_[n][m];
        printf("%lld\n", ans);
    }
}
