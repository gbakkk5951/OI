using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>

namespace Protector {
const int MAXE = 1000000;
const int MAXN = 40020;
const int DST = 0;
const int FLOW = 1;
const int NXT = 2;
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
class Dinic {
private:
    queue<int> q;
    
    int edge[MAXE][3];
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    char vis[MAXN];
    int e_idx;
    int src, dst;
    int node_size;
    int cnt ;
    
private:
    
    void inline push(int nd, int nd_layer = 0) {
        q.push(nd);
        vis[nd] = 1;
        layer[nd] = nd_layer;        
    }
    
    int getLayer() {
        memset(vis, 0, node_size * sizeof(char));
        push(src);
        int nd, i, t;
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !vis[t = edge[i][DST]]) {
                    push(t, layer[nd] + 1);
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
    
    void setSrc(int new_src) {
        src = new_src;
    }
    
    void setDst(int new_dst) {
        dst = new_dst;
    }
    
    void setMax(int max_idx) {
        node_size = max_idx + 1;
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
            memcpy(now, head, node_size * sizeof(int));
            while (getFlow(src));
        }
    }
    
    int getMaxFlow() {
        return cnt;
    }
}dinic;

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
    
    char vis[205][205];
    int id[205][205];
    int idx;
    int n;
    int is_legal(int x, int y) {
        return x > 0 && y > 0 && x <= n && y <= n;
    }
    
    _Main() {

        
        int i, j, k;
        int m;
        int x, y;
        int xi, yi;
        int src, dst;
        read(n); read(m);
        for (i = 1; i <= m; i++) {
            read(x); read(y);
            vis[x][y] = 1;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (!vis[i][j]) {
                    id[i][j] = ++idx;
                }
            }
        }
        dinic.setSrc(src = 0);
        dinic.setDst(dst = idx + 1);
        dinic.setMax(dst);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (id[i][j]) {
                    if (i + j & 1) {
                        dinic.add(src, id[i][j], 1);
                        dinic.add(id[i][j], src, 0);
                        for (k = 0; k < 8; k++) {
                            if (is_legal(x = i + dx[k], y = j + dy[k]) && id[x][y]) {
                                dinic.add(id[i][j], id[x][y], 1);
                                dinic.add(id[x][y], id[i][j], 0);
                            }
                        }
                    } else {
                        dinic.add(id[i][j], dst, 1);
                        dinic.add(dst, id[i][j], 0);
                    }
                }
            }
        }
        dinic.run();
        printf("%d", idx - dinic.getMaxFlow());
    }
    
    
    
}horse;









}
