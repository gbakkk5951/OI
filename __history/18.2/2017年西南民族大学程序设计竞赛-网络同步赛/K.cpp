using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>

struct _Main {
    
    
    int cha_fen[5010];
    _Main() {
        int n, m;
        int a, b;
        int i, j, k;
        int ans = 0;
        int mx = 0;
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &a, &b);
            mx = max(mx, b);
            cha_fen[a]++;
            cha_fen[b + 1]--;
        }
        for (i = 1; i <= mx; i++) {
            cha_fen[i] += cha_fen[i - 1];
            ans = max(ans, (cha_fen[i] + m - 1) / m);
        }
        printf("%d", ans);
    }
    
    
    
}K;

