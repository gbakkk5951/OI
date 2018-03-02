using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>

namespace OI {
const int 
    MAXN = 410,
    MAXE = 13000,
    INF = 0x3f3f3f3f
;
struct Edge {
    int dst, flow, nxt;
};

int src, dst, size;
class Dinic {
public:
    Edge edge[MAXE];
    int head[MAXN],
        now[MAXN],
        layer[MAXN],
        match[MAXN],
        left[MAXN],
        eidx,
        tot_flow
    ;
    queue<int> q;
    Dinic() {
        eidx = 1;
    }    
    void inline push(int nd, int layer) {
        if (!this->layer[nd]) {
            q.push(nd);
            this->layer[nd] = layer;         
        }
    }
    int getLayer() {
        int nd, i;
        memset(layer, 0, size * sizeof(int));
        push(src, 1);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i].nxt) {
                if (edge[i].flow) {
                    push(edge[i].dst, layer[nd] + 1);
                }   
            }
        }
        return layer[dst];
    }
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            return mx_flow;
        }
        int i, t, t2, use = 0;
        for (i = now[nd]; i; i = edge[i].nxt) {
            if (edge[i].flow && layer[t2 = edge[i].dst] > layer[nd]) {
                t = getFlow(t2, min(mx_flow - use, edge[i].flow));
                if (t) {
                    if (left[nd]) {
                        match[nd] = t2;
                        match[t2] = nd;                        
                    }
                    edge[i].flow -= t;
                    edge[i ^ 1].flow += t;
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
    
    
    void inline dir_add(int src, int dst, int flow) {
        eidx++;
        edge[eidx].dst = dst;
        edge[eidx].flow = flow;
        edge[eidx].nxt = head[src];
        head[src] = eidx;
    }
    void inline add(int src, int dst, int flow) {
        dir_add(src, dst, flow);
        dir_add(dst, src, 0);
    }
    
    
}netflow;

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
int in[205], out[205];
int org[415];
int node_idx;
int head[205];
int eidx;
int ind[205];
int nxt[205];




int node() {
    return node_idx++;
}

_Main() {
    int n, m;
    int i, j, k;
    int a, b;
    int nd, t;
    src = node(); dst = node();
    read(n); read(m);
    for (i = 1; i <= n; i++) {
        in[i] = node();
        out[i] = node();
        org[in[i]] = org[out[i]] = i;
        netflow.add(src, out[i], 1);
        netflow.add(in[i], dst, 1);
        netflow.left[out[i]] = 1;
    }    
    for (i = 1; i <= m; i++) {
        read(a); read(b);
        netflow.add(out[a], in[b], 1);
    }
    size = node_idx;
    netflow.run();
    for (i = 1; i <= n; i++) {
        if (t = netflow.match[out[i]]) {
            nxt[i] = org[t];
            ind[org[t]]++;
        }
    }
    for (i = 1; i <= n; i++) {
        nd = i;
        if(ind[nd] == 0) {
            while (nd) {
                ind[nd] = -1;
                printf("%d ", nd);
                nd = nxt[nd];
            }
            printf("\n");
        }
    }
    printf("%d", n - netflow.tot_flow);
}    
    
    
}LOJ6002;




}

//对于多倍点的建图，向前映射的数组要开大 
//下标映射一定要映射到相同的下标集合再进行建边、拓扑等操作 
