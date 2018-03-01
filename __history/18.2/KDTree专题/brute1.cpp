using namespace std;
int main() {}
#include<cstdio>
#include<algorithm>
namespace Protector {
int x[100010][2];
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
long long inline pf(long long a) {
    return a * a;
}
struct _Main{

_Main() { 
    int i, j, k;
    int Q, Qn;
    int a, b, c;
    int n;
    long long now_ans;
    scanf("%d%d", &n, &Qn);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &x[i][0], &x[i][1]);
    }
    for (Q = 1; Q <= Qn; Q++) {
        scanf("%d%d", &a, &b);
        now_ans = INF;
        for (i = 1; i <= n; i++) {
            now_ans = min(now_ans, pf(x[i][0] - a) + pf(x[i][1] - b));
        }
        printf("%lld\n",now_ans);
    }
}

}brute1;

}

