using namespace std;
int main () {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>

namespace Protector {
const int CNT = 0;
const int MAXN = 10010;
const char FAIL[] = "No Answer";

class ErFenTu {
private:
    int vis[MAXN << 1];
    int link[MAXN][5];
    int match[MAXN << 1];
    char is_static[MAXN << 1];
    int n;
    int cnt;
private:
    void setStatic(int nd, char val = 1) {
        is_static[nd] = val;
    }
    
    char dfs(int nd) {
        int i, t;
        for (i = 1; i <= link[nd][CNT]; i++) {
            t = link[nd][i];
            if (vis[t] != vis_idx && !is_static[t]) {
                vis[t] = vis_idx;
                if (match[t] == -1 || dfs(match[t])) {
                    match[t] = nd;
                    match[nd] = t;
                    return 1;
                }
            }
        }
        return 0;
    }   
     
public:
    int vis_idx;

    void setSize(int new_size) {
        n = new_size;
    }
    
    int getCnt() {
        return cnt;
    }
    
    int getMatch(int nd) {
        return match[nd];
    }
    

    void add(int left, int right) {
        link[left][++link[left][CNT]] = right;
    }
    void init() {
        int i;
        memset(match, 255, (n + 1) * 2 * sizeof(int));
        for (i = 0; i < n; i++) {
            sort(&link[i][0] + 1, &link[i][0] + link[i][CNT] + 1);
            link[i][CNT] = unique(&link[i][0] + 1, &link[i][0] + link[i][0] + 1) - &link[i][0] - 1;
        }
    }
    
    void augment() {
        int i;
        cnt = 0;
        for (i = 0; i < n; i++) {
            ++vis_idx;
            if (match[i] != -1 || dfs(i)) {
                cnt++;
            }
        }
    }
    void getMinDictOrder() {
        int i, j, t;
        for (i = 0; i < n; i++) {
            match[match[i]] = -1;
            for (j = 1; j <= link[i][CNT]; j++) {
                t = link[i][j];
                if (match[i] > t && !is_static[t]) {
                    vis[t] = ++vis_idx;
                    if (dfs(match[t])) {
                        match[i] = t;
                        break;
                    }
                } else {
                    break;
                }
            }
            match[match[i]] = i;
            setStatic(match[i]);
        }        
        
    }

    
}er_fen_tu;

class Solver {
private:    
    int n;
    int dis[MAXN];
private:
    char legal(int pos, int y) {
        if (y >= 0 && y < n && min(abs(y - pos), n - abs(y - pos)) == dis[pos]) {
            return 1;
        }
        return 0;
    }
public:
    inline void setDis(int pos, int val) {
        dis[pos - 1] = val;
    }    
    inline void setSize(int new_size) {
        n = new_size;
    }
    void init() {
        int i, y, j, k;
        int D;
        er_fen_tu.setSize(n);
        for (i = 0; i < n; i++) {
            D = dis[i];
            for (j = 1; j <= 2; j++) {
                y = i + D;
                if (legal(i, y)) {
                    er_fen_tu.add(i, n + y);
                }
                y = i - D;
                if (legal(i, y)) {
                    er_fen_tu.add(i, n + y);
                }
                D = -D + n;
            }
        }
        er_fen_tu.init();
    }
    void getAns() {
        int i;
        er_fen_tu.augment();
        if (er_fen_tu.getCnt() != n) {
            printf("%s", FAIL);
            return;
        }
        er_fen_tu.getMinDictOrder();
        for (i = 0; i < n; i++) {
            printf("%d", er_fen_tu.getMatch(i) - n);
            if (i != n - 1) {
                putchar(' ');
            } 
        }
        
    }
    
    
}solver;




struct _Main {
template<typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }

_Main() {
    int n, i;
    int a;
    scanf("%d", &n);
    solver.setSize(n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);
        solver.setDis(i, a);
    }
    solver.init();
    solver.getAns();
}

}jsk;






}

//更改阈值之后要检查全部代码， 如0变 -1； 
//读题，最后一个数之后没有空格 
