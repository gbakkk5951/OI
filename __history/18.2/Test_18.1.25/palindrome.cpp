using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
namespace OI {
typedef long long lld;
const lld MOD = 2013265921;
struct _Main {

char org[105];
char now[105];
int cmp(int l1, int r1, int l2, int r2) {
    if (org[l1] == org[r2]) {
        int s1, s2, s, i;
        s1 = r1 - l1 + 1; s2 = r2 - l2 + 1;
        s = s1 + s2;
        memcpy(now + 1, org + l1, s1 * sizeof(char));
        memcpy(now + s1 + 1, org + l2, s2 * sizeof(char));
        for (i = 1; i <= s >> 1; i++) {
            if (now[i] != now[s - i + 1]) {

                return 0;
            }
        }
        now[s + 1] = '\0';
        return s;
    }        
    return 0;
}
char buf[500010];
_Main() {
    int i, j, k, l;
    int n;lld ans = 0;
    char t;
    scanf("%s", buf + 1);
    n = strlen(buf + 1);
    if (n > 100) {
        return;
    } else {
        memcpy(org, buf, (n + 2) * sizeof(char));
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n; j++) {
                for (k = 1; k <= n; k++) {
                    for (l = k; l <= n; l++) {
                        ans += cmp(i, j, k, l);
                    }
                }
            }
        }
        printf("%lld", ans % MOD);
    }
    
}




}T3;

}
