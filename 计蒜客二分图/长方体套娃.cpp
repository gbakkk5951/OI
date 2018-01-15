using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>

namespace Protecotr {
const int MAXN = 1020;
const int MAXE = 270000;
const int DST = 0;
const int FLOW = 1;
const int NXT = 2;

class Dinic {
private:
    queue<int> q;
    int edge[MAXE][3];
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    char vis[MAXN];
    int cnt;
    int node_size;
    int e_idx;
    int src, dst;
    
    void inline push(int nd, int nd_layer = 0) {
        q.push(nd);
        vis[nd] = 1;
        layer[nd] = nd_layer;
    }
    
    int getLayer() {
        memset(vis, 0, node_size * sizeof(char));
        push(src);
        int i, nd, t;
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
    
    void setMax(int max_idx) {
        node_size = max_idx + 1;
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
            memcpy(now, head, node_size * sizeof (int));
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
    
    int cmp(int a[3], int b[3]) {//1大，0其他，-1小 
        int i;
        for (i = 0; i < 3 && a[i] > b[i]; i++);
        if (i == 3) {
            return 1;
        }
        if (i == 0) {
            for (i = 0; i < 3 && a[i] < b[i]; i++);
        }
        return i == 3 ? -1 : 0;
    }
    
    int x[505][3];
    _Main() {
        int n;
        int i, j, k;
        int src, dst;
        int t;
        read(n);
        for (i = 1; i <= n; i++) {
            for (j = 0; j < 3; j++) {
                read(x[i][j]);
            }
        }
        dinic.setSrc(src = 0);
        dinic.setDst(dst = (n << 1) + 1);
        dinic.setMax(dst);
        for (i = 1; i <= n; i++) {
            dinic.add(src, i, 1);
            dinic.add(i, src, 0);
            dinic.add(n + i, dst, 1);
            dinic.add(dst, n + i, 0);
            for (j = i + 1; j <= n; j++) {
                t = cmp(x[i], x[j]);  
                if (t == 1) {
                    dinic.add(j, i + n, 1);
                    dinic.add(i + n, j, 0);     
                } else if (t == -1) {
                    dinic.add(i, j + n, 1);
                    dinic.add(j + n, i, 0);                      
                }
            }
        }
        dinic.run();
        printf("%d", n - dinic.getMaxFlow());
    }
    
    
}CubeRussian;


}
//e_idx = 1;
//node_size = max_idx + 1;
