using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <queue>
const int 
    MAXN = 110,
    MAXE = 5500,
    INF = 0x3f3f3f3f
;
namespace Protector {
struct Edge {
    int dst, 
        flow,
        nxt
    ;
} ;
int src, dst, size;
class Dinic {
public:
    Edge edge[MAXE];
    int head[MAXN],
        now[MAXN],
        layer[MAXN],
        eidx,
        tot_flow
    ;
    queue<int> q;
    Dinic() {
        eidx = 1;
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
    void inline push(int nd, int layer) {
        if (!this->layer[nd]) {
            q.push(nd);
            this->layer[nd] = layer;
        }
    }
    int getLayer() {
        int i, t, nd;
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
        int i, t, use = 0;
        for (i = now[nd]; i; i = edge[i].nxt) {
            if (edge[i].flow && layer[t = edge[i].dst] == layer[nd] + 1) {
                t = getFlow(t, min(mx_flow - use, edge[i].flow));
                if (t) {
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
    
}dinic;

struct _Main {

int n, m;
int id[105];
int node_idx;
char link[105][105];
int EOF_TAG;
int node() {
    return node_idx++;
}
template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar())) {
            if (t == EOF) {
                EOF_TAG = 1;
                return;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }        
    }
_Main() {
    int i, j, k;
    int a, b, c;
    read(n); read(m);
    src = node(); dst = node();
    for (i = 1; i <= n; i++) {
        id[i] = node();
        if (i <= m) {
            dinic.add(src, id[i], 1);
        } else {
            dinic.add(id[i], dst, 1);
        }
    }
    while (1) {
        read(a); read(b);
        if (EOF_TAG) {
            break;
        }
        if(a > b){
            swap(a, b);
        }
        if (b <= m) {
            continue;
        }
        if (!link[a][b]) {
            dinic.add(id[a], id[b], 1);
            link[a][b] = 1;
        }
    }
    size = node_idx;
    dinic.run();
    printf("%d", dinic.tot_flow);
}


}LOJ6000;

}
