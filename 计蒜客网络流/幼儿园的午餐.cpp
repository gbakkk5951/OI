using namespace std;
int main() {}

#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>

namespace OI {
const int 
    PERSON_IN = 0,
    PERSON_OUT = 1,
    FOOD = 2,
    DRINK = 3,
    MAXN = 420,
    MAXE = 42000,
    DST = 0,
    NXT = 1,
    FLOW = 2,
    INF = 0x3f3f3f3f
;
    
int dst, src, size;

class Dinic {
public:
    int eidx, tot_flow;
    int edge[MAXE][3];
    int layer[MAXN], now[MAXN], head[MAXN];
    queue<int> q;
    Dinic() {
        eidx = 1;
    }
    void add(int src, int dst, int flow) {
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

    void inline push(int nd, int layer) {
        q.push(nd);
        this->layer[nd] = layer;
    }
    
    int getLayer() {
        int nd, t, i;
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
    int node_idx;
    int inline node() {
        return node_idx++;
    }
    
    int n[4];
    int id[4][105];
    int like[4];
    _Main() {
        int i, j;
        int a, b, c;
        src = node(); dst = node();
        for (i = 0; i < 4; i++) {
            if (i == 1) {
                n[PERSON_OUT] = n[PERSON_IN];
            } else {
                read(n[i]);
            }
            for (j = 1; j <= n[i]; j++) {
                id[i][j] = node();
            }
        }
        
        for (i = 1; i <= n[PERSON_IN]; i++) {
            dinic.add(id[PERSON_IN][i], id[PERSON_OUT][i], 1);
            dinic.add(id[PERSON_OUT][i], id[PERSON_IN][i], 0);
        }
        for (i = 1; i <= n[FOOD]; i++) {
            dinic.add(src, id[FOOD][i], 1);
            dinic.add(id[FOOD][i], src, 0);
        }
        for (i = 1; i <= n[DRINK]; i++) {
            dinic.add(id[DRINK][i], dst, 1);
            dinic.add(dst, id[DRINK][i], 0);
        }
        for (i = 1; i <= n[PERSON_IN]; i++) {
            read(like[FOOD]);
            read(like[DRINK]);
            for (j = 1; j <= like[FOOD]; j++) {
                read(a);
                dinic.add(id[FOOD][a], id[PERSON_IN][i], 1);
                dinic.add(id[PERSON_IN][i], id[FOOD][a], 0);
            }
            for (j = 1; j <= like[DRINK]; j++) {
                read(a);
                dinic.add(id[PERSON_OUT][i], id[DRINK][a], 1);
                dinic.add(id[DRINK][a], id[PERSON_OUT][i], 0);
            }
        }
        size = node_idx;
        dinic.run();
        printf("%d", dinic.tot_flow);
    }
    
    
    
    
}jsk;


}
 
