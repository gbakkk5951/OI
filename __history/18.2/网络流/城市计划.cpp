using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>
namespace Protector {
const int MAXE = 65000;
const int MAXN = 10050;
const int DST = 0;
const int FLOW = 1;
const int NXT = 2;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
class Dinic {
private:
    queue<int> q;
    
    int head[MAXN];
    int now[MAXN];
    int edge[MAXE][3];
    int layer[MAXN];
    char vis[MAXN];
    int src, dst;
    int max_idx;
    int e_idx;
    int cnt;
    
    int getLayer() {
        memset(vis, 0, max_idx * sizeof(char));
        vis[src] = 1;
        q.push(src);
        int nd, i, t;
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !vis[t = edge[i][DST]]) {
                    vis[t] = 1;
                    layer[t] = layer[nd] + 1;
                    q.push(t);  
                }
            }
        }
        return vis[dst];
    }
    
    int getFlow(int nd) {
        if (nd == dst) {
            cnt++;
            return 1;
        }
        int i, t;
        for (; i = now[nd]; now[nd] = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t);
                if (t) {
                    edge[i][FLOW] = 0;
                    edge[i ^ 1][FLOW] = 1;
                    return 1;
                }   
            }
        }
        return 0;
    }
    
    
public:
    Dinic() {
        e_idx = 1;
    }
    void setMax(int new_max_idx) {
        max_idx = new_max_idx + 1;
    }
    void setSrc(int new_src) {
        src = new_src;    
    }    
    void setDst(int new_dst) {
        dst = new_dst;
    }
    void add(int src, int dst, int flow) {
        e_idx++;
        edge[e_idx][DST] = dst;
        edge[e_idx][FLOW] = flow; 
        edge[e_idx][NXT] = head[src];
        head[src] = e_idx;
    }
    
    void run() {
        while (getLayer()) {
            memcpy(now, head, max_idx * sizeof(int));
            while (getFlow(src));
        }
    }
    int getMaxFlow() {
        return cnt;
    }
}dinic;


struct _Main {
template<typename Type>
    void getSymbol(Type &a) {
        while (isspace(a = getchar()));
    }
    int num[105][105];
    char vis[105][105];
    int house_idx;
    
    _Main() {
        int n, m;
        int i, j, k;
        int a, b, c;
        int x, y;
        int src, dst;
        char t;
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                getSymbol(t);
                if (t == '*') {
                    num[i][j] = ++house_idx;
                }
            }
        }
        dinic.setSrc(src = 0);
        dinic.setDst(dst = house_idx + 1);
        dinic.setMax(dst);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if ((i + j & 1) && num[i][j]) {
                    for (k = 0; k < 4; k++) {
                        if (num[x = i + dx[k]][y = j + dy[k]]) {
                            dinic.add(num[i][j], num[x][y], 1);
                            dinic.add(num[x][y], num[i][j], 0);
                            vis[i][j] = 1;
                            vis[x][y] = 1;
                        }    
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (vis[i][j]) {
                    if (i + j & 1) {
                        dinic.add(src, num[i][j], 1);   
                        dinic.add(num[i][j], src, 0);
                    } else {
                        dinic.add(num[i][j], dst, 1);                                      
                        dinic.add(dst, num[i][j], 0);             
                    }
                }
            }
        }
        dinic.run();
        printf("%d", house_idx - dinic.getMaxFlow());
    }
    
    
}jsk;


}
//e_idx一定要赋为1 
