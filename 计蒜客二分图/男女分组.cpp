using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
namespace Protector {
const int MAXN = 105;
const int DST = 0;
const int NXT = 1;
const char FAIL[] = "No Solution!";
class ErFenTu {
public:
    int cnt;
    int left_num;
    int tot_num;
    int match[MAXN];
    char vis[MAXN];
    char link[MAXN][MAXN];
    void add(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        link[a][b] = 1;
    }
    char dfs(int nd) {
        int i;
        for (i = left_num + 1; i <= tot_num; i++) {
            if (link[nd][i] && !vis[i]) {
                vis[i] = 1;
                if (match[i] == 0 || dfs(match[i])) {
                    match[i] = nd;  
                    match[nd] = i;
                    return 1;
                }
            }
        }
        return 0;
    }
    
    void augment() {
        int i;
        for (i = 1; i <= left_num; i++) {
            if (!match[i]) {
                memset(vis, 0, (tot_num + 1) * sizeof(char));
                if (dfs(i)) {
                    cnt++; 
                }
            }
        }
    }
    
}solver;


struct _Main {
    
    _Main () {
        int n, m;
        int a, b;
        int i, j;
        scanf("%d%d", &m, &n);
        solver.tot_num = n;
        solver.left_num = m;
        while (~scanf("%d%d", &a, &b)) {
            if (a == -1 && b == -1) break;
            solver.add(a, b);
        }
        solver.augment();
        if (solver.cnt == 0) {
            printf("%s", FAIL);
        } else {
            printf("%d\n", solver.cnt);
            for (i = 1; i <= m; i++) {
                if (solver.match[i]) {
                    printf("%d %d\n", i, solver.match[i]);
                }
            }
        }
    }
    
    
}jsk;




}
//ÉñTMÏÈ¶ÁMÔÙ¶ÁN 
