#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct _Main {
    
    double ans;
    double x[105][2];
    double pf(double a) {
        return a * a;
    } 
    double getDis(int a, int b) {
        return sqrt(pf(x[a][0] - x[b][0]) + pf(x[a][1] - x[b][1]));
    }
    double dis[105];
    char vis[105];
    _Main() {
        int n, m;
        while (~scanf("%d%d", &n, &m)) {
            ans = 0;
            int i, j;
            int a, b;
            int chose;
            for (i = 1; i <= n; i++) {
                vis[i] = 0;
                scanf("%lf%lf", &x[i][0], &x[i][1]);
            }
            for (i = 1; i <= m; i++) {
                scanf("%d%d", &a, &b);
            }
            for (i = 2; i <= n; i++) {
                dis[i] = 1e100;
            }
            for (i = 1; i <= n; i++) {
                chose = -1;
                for (j = 1; j <= n; j++) {
                    if (!vis[j] && (chose == -1 || dis[chose] > dis[j])) {
                        chose = j;
                    }
                }
                ans += dis[chose];
                vis[chose] = 1;
                for (j = 1; j <= n; j++) {
                    if (!vis[j]) {
                        dis[j] = min(dis[j], getDis(chose, j));
                    }
                }
                
            }
            printf("%.2lf\n", ans);   
        }

    }
    
    
    
    
    
}brute;
int main () {}

