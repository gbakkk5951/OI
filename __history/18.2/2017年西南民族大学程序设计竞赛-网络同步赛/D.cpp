using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
int preSum[10010];
typedef long long lld;
struct _Main {
    
    _Main() {
        int n, m;
        lld ans = 0;
        int i, j, k;
        int a, b;
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &preSum[i]);
            preSum[i] += preSum[i-1];
        }
        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            ans += max(0, preSum[b] - preSum[a - 1]);
        }
        printf("%lld", ans);
    }
    
    
}D;

//没看样例输入导致理解错题意 
//不同变量的范围要分别估计 preSum不爆int 不代表 Ans 不爆int 
