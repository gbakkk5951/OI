#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 10;
 
int n, m;
 
ll a[N], f[N][20], k, p, ans, tag;
 
ll pw(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
 
int main() {
    scanf("%d%d%lld%lld", &n, &m, &k, &p);
    for(int i = 1 ; i <= n ; ++ i) scanf("%lld", &a[i]);
    for(int i = 1 ; i <= n ; ++ i) f[i][0] = a[i] % p;
    for(int j = 1 ; j <= 20 ; ++ j) {
        for(int i = 1 ; i <= n ; ++ i) {
            if(i + (1 << j) - 1 > n) break;
            f[i][j] = (f[i][j - 1] + f[i + (1 << (j - 1))][j - 1] * pw(k, 1 << (j - 1)) % p) % p;
        }
    }
    for(int i = 1, l, r ; i <= m ; ++ i) {
        scanf("%d%d", &l, &r);
        ans = 0, tag = 0;
        for(int j = 20 ; ~j ; -- j) {
            if(l + (1 << j) - 1 > r) continue;
            ans += f[l][j] * pw(k, tag) % p;
            ans %= p;
            l += 1 << j;
            tag += 1 << j;
        }
        printf("%lld\n", ans);
    }
}
