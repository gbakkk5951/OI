#include<cstdio>
typedef long long unsigned llu;
llu dp[22][2];
int main(){
    int n;
    int i;
    llu ans = 0;
    scanf("%d", &n);
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1] + dp[i-1][0];
    }
    ans = dp[n][1] + dp[n][0];
    printf("%llu", ans);
}
