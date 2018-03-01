using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <algorithm>
#include <cstring>
namespace Protector {
typedef long long lld;
const int 
    DST = 0,
    NXT = 1,
    FLOW = 2,
    MAXE = 90000,
    MAXN = 420,
    INF = 0x3f3f3f3f
;
int 
    src,
    dst,
    size
;

class Dinic {
public:
    int 
        head[MAXN],
        now[MAXN],
        edge[MAXE][3],
        layer[MAXN],
        tot_flow,
        eidx
    ;
    queue<int> q;
    Dinic() {
        eidx = 1;
    }
    
    void push(int nd, int layer) {
        this->layer[nd] = layer;
        q.push(nd);
    }
    
    int getLayer() {
        int i, nd, t;
        memset(layer, 0, size * sizeof(int));
        push(src, 1);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !layer[t = edge[i][DST]]) {
                    push(t, layer[nd] + 1);
                }
            }
        }
        return layer[dst];
    }
    
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            tot_flow += mx_flow;
            return mx_flow;
        }
        int t, i, use = 0;
        for (i = now[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t, min(edge[i][FLOW], mx_flow - use));
                if (t) {
                    use += t;
                    edge[i][FLOW] -= t;
                    edge[i ^ 1][FLOW] += t;
                    if (use == mx_flow) {
                        break;
                    }
                }
            }
        }
        now[nd] = i;
        return use;
    }
    
    void inline add(int src, int dst, int flow) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
    
    void run() {
        while (getLayer()) {
            memcpy(now, head, size * sizeof(int));
            while (getFlow(src, INF));
        }
    }
    void clear() {
        memset(head, 0, size * sizeof(head));
        eidx = 1;
        tot_flow = 0;
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
int node_idx;
long long dis[210][210];
int hold[210], now[210];
int hold_id[210], now_id[210];
int soldier_sum;
_Main() {
    int n, m;
    int i, j, k;
    int a, b, c;
    long long dis_sum = 0;
    long long l, r, mid;
    memset(dis, 63, sizeof(dis));
    read(n); read(m);
    src = node_idx++;
    dst = node_idx++;
    for (i = 1; i <= n; i++) {
        read(now[i]); read(hold[i]);
        soldier_sum += now[i];
        hold_id[i] = node_idx++;
        now_id[i] = node_idx++;
        dis[i][i] = 0;
    }
    size = node_idx;
    for (i = 1; i <= m; i++) {
        read(a); read(b); read(c);
        dis_sum += c;
        dis[a][b] = dis[b][a] = min(dis[a][b], (lld)c);
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    
    
    l = 0, r = dis_sum + 1;
    while (l < r) {
        mid = l + r >> 1;
        if (l != 0 || r != dis_sum + 1) {
            dinic.clear();
        }
        for (i = 1; i <= n; i++) {
            dinic.add(src, now_id[i], now[i]);
            dinic.add(now_id[i], src, 0);
            dinic.add(hold_id[i], dst, hold[i]);
            dinic.add(dst, hold_id[i], 0);
            for (j = 1; j <= n; j++) {
                if (dis[i][j] <= mid) {
                    dinic.add(now_id[i], hold_id[j], INF);
                    dinic.add(hold_id[j], now_id[i], 0);
                }
            }
        }
        dinic.run();
        if (dinic.tot_flow == soldier_sum) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == dis_sum + 1) {
        printf("-1");
    } else{
        printf("%lld", l);
    }
}
    
    
}jsk;


}
