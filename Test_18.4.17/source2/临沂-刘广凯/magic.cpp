#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstring>

void exgcd(int a, int b, int &x, int &y){
    if(b == 0) x = 1, y = 0; else exgcd(b, a % b, y, x), y -= x * (a / b);
}

inline int inv(int t, int m){
    int x, y;
    exgcd(t, m, x, y);
    int i = (x % m + m) % m;

    assert(i * t % m == 1);

    return i;
}

inline int fastPowMod(int x, int k, int m){
    int ans = 1;
    for(; k; k >>= 1, x = x * x % m) if(k & 1) ans = ans * x % m;
    return ans;
}

inline int crt(int n, const int r[], const int m[]){
    int M = 1;
    for(int i = 0; i < n; i++) M *= m[i];

    int x = 0;
    for(int i = 0; i < n; i++){
        int t = M / m[i];
        int a = (t % M) * (inv(t, m[i]) % M) % M;
        (x += a * (r[i] % M) % M) %= M;
    }

    return x;
}

const int MAX_N = 400000;

int n, k;
int a[MAX_N + 1];

int cnt[MAX_N + 1], fact[MAX_N + 1], factInv[MAX_N + 1];

inline int c(int n, int k, int p){
    int x = cnt[n] - cnt[n - k] - cnt[k];
    if(x >= 1) return 0;
    return (long long)fact[n] * factInv[n - k] * factInv[k] % p;
}

inline int calc(int p){
    memset(fact, 0, sizeof fact);
    memset(cnt, 0, sizeof cnt);
    memset(factInv, 0, sizeof factInv);

    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        if(i % p != 0){
            fact[i] = fact[i - 1] * i % p;
            cnt[i] = cnt[i - 1];
        } else{
            cnt[i] = cnt[i - 1];

            int x = i;
            while(x % p == 0) x /= p, cnt[i]++;

            fact[i] = fact[i - 1] * x % p;
        }
    }

    factInv[n] = inv(fact[n], p);
    for(int i = n; i >= 1; i--){
        if(i % p != 0){
            factInv[i - 1] = factInv[i] * i % p;
        } else{
            int x = i;
            while(x % p == 0) x /= p;

            factInv[i - 1] = factInv[i] * x;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        (ans += c(n - 1, i - 1, p) * a[i] % p) %= p;
    }
    return ans;
}

inline int solve10(){
    int r2 = calc(2);
    int r5 = calc(5);

    return (5 * r2 + 6 * r5) % 10;
}

inline int solveForce(){
    for(int m = n; m > 1; m--){
        for(int i = 1; i <= m - 1; i++){
            (a[i] += a[i + 1]) %= k;
        }
    }

    return a[1] % k;
}

int main(){
    // freopen("mogic.in", "r", stdin), freopen("mogic.out", "w", stdout);
    freopen("magic.in", "r", stdin), freopen("magic.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int ans = 0;

    if(n <= 1000) ans = solveForce();
    else if(k == 10) ans = solve10();
    else ans = calc(k);

    printf("%d\n", ans);

    fclose(stdin), fclose(stdout);
    return 0;
}

