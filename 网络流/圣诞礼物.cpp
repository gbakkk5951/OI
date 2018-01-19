using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>

namespace OI {
const int
    MAXN = 2100,
    MAXE = 2010000,
    NXT = 1,
    DST = 0,
    FLOW = 2,
    INF = 0x3f3f3f3f
;
    
int src, dst, size;
class Dinic {
public:
    int head[MAXN], now[MAXN], layer[MAXN];
    int edge[MAXE][3];
    int eidx;
    int tot_flow;
    queue<int> q;
    Dinic() {
        eidx = 1;    
    }
    void inline push(int nd, int layer) {
        q.push(nd);
        this->layer[nd] = layer;
    }
    int getLayer() {
        int i, nd, t;
        memset(layer, 0, size * sizeof(int));
        push(src, 1);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            int cnt = 0;
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !layer[t = edge[i][DST]]) {
                    push(t, layer[nd] + 1);
                }
            }
        }
        return layer[dst];
    }
    void inline add(int src, int dst, int flow) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            return mx_flow;
        }
        int i, t, use = 0;
        for (i = now[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t, min(mx_flow - use, edge[i][FLOW]));
                if (t) {
                    edge[i][FLOW] -= t;
                    edge[i ^ 1][FLOW] += t;
                    use += t;
                    if (use == mx_flow) {
                        break;
                    }
                }
            }
        }
        now[nd] = i;
        return use;
    }
    void run() {
        while (getLayer()) {
            memcpy(now, head, size * sizeof(int));
            tot_flow += getFlow(src, INF);
        }
    }
    
}dinic;


struct _Main {
template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }   
    }
    int dis[105][105];
    int fa[1005];
    int city[1005], time[1005], out[1005], in[1005];
    int node_idx;
    int node() {
        return node_idx++;
    }
    _Main() { 
        int i, j, k;
        int n, m, q;
        int a, b, c;
        int real_q;
        read(n); read(m); read(q);
        memset(dis, 63, sizeof(dis));
        src = node();
        dst = node();
        for (i = 1; i <= q; i++) {
            fa[i] = i; 
        }
        
        for (i = 1; i <= m; i++) {
            read(a); read(b); read(c);
            dis[a][b] = dis[b][a] = min(dis[a][b], c);
        }
        
        for (k = 0; k < n; k++) {
            dis[k][k] = 0;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        
        for (i = 1; i <= q; i++) {
            read(city[i]); read(time[i]);
        }
        for (i = 1; i <= q; i++) {
            if (fa[i] != i) {
                continue;
            }
            for (j = i + 1; j <= q; j++) {
                if (dis[city[i]][city[j]] == 0 && time[i] == time[j]) {
                    fa[j] = i;
                }
            }
        }
        real_q = 0;
        for (i = 1; i <= q; i++) {
            if (fa[i] == i) {
                real_q++;
                in[i] = node();
                out[i] = node();
                dinic.add(src, out[i], 1);
                dinic.add(out[i], src, 0);
                dinic.add(in[i], dst, 1);
                dinic.add(dst, in[i], 0);
            }
        }
        for (i = 1; i <= q; i++) {
            if (fa[i] != i) {
                continue;
            }
            for (j = i + 1; j <= q; j++) {
                if (fa[j] != j) {
                    continue;
                }
                if (time[i] + dis[city[i]][city[j]] <= time[j]) {
                    dinic.add(out[i], in[j], 1);
                    dinic.add(in[j], out[i], 0);
                }
                if (time[j] + dis[city[i]][city[j]] <= time[i]) {
                    dinic.add(out[j], in[i], 1);
                    dinic.add(in[i], out[j], 0);
                }                
            }
        }
        size = node_idx;
        dinic.run();
        printf("%d\n", real_q - dinic.tot_flow - 1);
    }
        
    
}jsk;



}


