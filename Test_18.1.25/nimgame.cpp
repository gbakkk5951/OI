using namespace std;
int main() {}
#include <cstdio>
#include <cstring>

namespace OI {
typedef long long lld;
const lld 
    MOD = 2013265921,
    PHI = MOD - 1
;
struct _Main {
    lld win, rate;
    lld fastpower(lld base, lld pow) {
        lld ret = 1;
        pow = (pow % PHI + PHI) % PHI;
        while (pow) {
            if (pow & 1) {
                ret = ret * base % MOD;
            }
            pow >>= 1;
            base = base * base % MOD;
        }
        return ret;
    }
    int now[25];
    lld rev[25];
    int n; 
    void dfs(int times = 0, lld rate = 1) {
        int i, cnt = 0, j, k;
        for (i = 1; i <= n; i++) {
            cnt += now[i];
        }
        for (i = 1; i <= n; i++) {
            if (now[i] !=0) {
                for (j = 1; j <= now[i]; j++) {
                    now[i] -= j;
                    dfs(times ^ 1, (rate * rev[cnt]) % MOD);
                    now[i] += j;
                }
            }
        }
        if (cnt == 0) {
            
            if (times) {
                win++;
                this->rate = (this->rate + rate) % MOD;; 
            }
        }
    }
    void read(int &a) {
        scanf("%d", &a);
    }
    _Main() {
        int T, Tn, i;
        for (i = 1; i <= 20; i++) {
            rev[i] = fastpower(i, -1);
        }
        read(Tn);
        for (T = 1; T <= Tn; T++) {
            rate = win = 0;
            memset(now, 0, sizeof(now));
            read(n);
            for (i = 1; i <= n; i++) {
                read(now[i]);
            }
            dfs();
            printf("%lld %lld\n", rate, win);
        }
    }
    
}T2;


}

