using namespace std;
int main (){}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace protector{
const long long mod = 1e9 + 7;    
struct _Main {

    template <typename Type>
        void read(Type &a) {
            char t;
            while (!isdigit(t = getchar()));
            a = t - '0';
            while ( isdigit(t = getchar())) {
                a *= 10;
                a += t - '0';
            }
        }
    long long inline getRev(long long a) {
        return fastpower(a, mod - 2);
    }
    long long fastpower(long long base, long long pow) {
        long long ret = 1;
        while (pow) {
            if (pow & 1) {
                (ret *= base) %= mod;
            }
            pow >>= 1;
            (base *= base) %= mod;
        }
        return ret;
    }
    int n, m; 
    long long fact[2000100];
    int sum[1000100];
    int belong[1000100];
    int sum_cnt[1000100];
    int limit_num[25];
    int limit_val[25];
    int limit[25];
    int limit_cnt;
    
    int dfs_sum[10];
    int dfs_cnt[10];
    void dfs(int pos, long long &ans) {
        if (pos == n + 1) {
            ans++;
            return;
        }
        if( dfs_cnt[belong[pos]] == sum_cnt[belong[pos]] - 1) {
            if (sum[belong[pos]] - dfs_sum[belong[pos]] > limit[pos]) {
                return;
            } else {
                dfs(pos + 1, ans);
            }
        } else {
            int i;
            dfs_cnt[belong[pos]]++;
            for (i = 0 ; i + dfs_sum[belong[pos]] <= sum[belong[pos]] && i <= limit[pos]; i++) {
                dfs_sum[belong[pos]] += i;
                dfs(pos + 1, ans);
                dfs_sum[belong[pos]] -= i;
            }
            dfs_cnt[belong[pos]]--;
        }
    }
    
    _Main() {
        int i, j, k;
        int a, b, c;
        int maxfact = 10;
        read(n); read(m);
        for (i = 1; i <= m; i++) {
            read(sum_cnt[i]);
            for (j = 1; j <= sum_cnt[i]; j++) {
                read(a);
                belong[a] = i;
            }
            read(sum[i]);
            maxfact = max(maxfact, sum[i] + sum_cnt[i] - 1);
        }
        fact[0] = 1;
        for (i = 1; i <= maxfact; i++) {
            fact[i] = i * fact[i-1] % mod;
        }
        read(limit_cnt);
        for (i = 1; i <= limit_cnt; i++) {
            read(limit_num[i]); read(limit_val[i]);
            if (limit_val[i] >= sum[belong[limit_num[i]]]) {
                limit_cnt--;
                i--;
            }
        }
        long long ans = 1;
        if (limit_cnt == 0) {
            for (i = 1; i <= m; i++) {
                (ans *= fact[sum_cnt[i] + sum[i] - 1] * getRev(fact[sum[i]] * fact[sum_cnt[i] - 1] % mod) % mod) %=mod;
            }
        } else {
            for (i = 1; i <= n; i++) {
                limit[i] = 1e9 + 7;
            }
            for (i = 1; i <= limit_cnt; i++) {
                limit[limit_num[i]] = limit_val[i];
            }
            ans = 0;
            dfs(1, ans);
        }
        printf("%lld", (ans % mod + mod) % mod);
    }
    
    
}T3;

}

//¼õ1¼õ´íÎ»ÖÃÁË 
