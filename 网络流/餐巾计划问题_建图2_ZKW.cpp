using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>
namespace OI {
typedef long long lld;
const int 
    BUY = 0, 
    FAST = 1,
    SLOW = 2,
    DST = 0,
    NXT = 1,
    FLOW = 2,
    COST = 3,
    MAXN = 2010,
    MAXE = 13000,
    MIN_COST = -2e7,
    INF = 0x3f3f3f3f,
    USE = 0,
    STORGE = 1 
;
const lld LINF = (lld)INF << 31 | INF;
int src, dst, size;

class CostFlow {
public:
int eidx;
lld tot_cost;
lld tot_flow;
int head[MAXN];
char vis[MAXN];
lld edge[MAXE][4];
lld dis[MAXN];
lld base;


CostFlow() {
    eidx = 1;
}

int getLabel() {
    lld delta = LINF;
    int i, j;
    for (i = 0; i < size; i++) {
        if (vis[i]) { 
            for (j = head[i]; j; j = edge[j][NXT]) {
                if (edge[j][FLOW] && !vis[edge[j][DST]]) {
                    delta = min(delta, edge[j][COST]);
                }
            }
        }
    }
    if (delta == LINF) {
        return 0;
    }
    base += delta;
    for (i = 0; i < size; i++) {
        if (vis[i]) {
            for (j = head[i]; j; j = edge[j][NXT]) {
                edge[j][COST] -= delta;
                edge[j ^ 1][COST] += delta;
            }
        }
    }
    return 1;
}

lld getFlow(int nd, lld mx_flow) {
    if (nd == dst) {
        tot_cost += mx_flow * base;
        return mx_flow;
    }
    int i;
    lld t;
    lld use = 0;
    vis[nd] = 1;
    for (i = head[nd]; i; i = edge[i][NXT]) {
        if (edge[i][FLOW] && !edge[i][COST] && !vis[t = edge[i][DST]]) {
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
    return use;
}


void inline dir_add(lld src, lld dst, lld flow, lld cost) {
    eidx++;
    edge[eidx][DST] = dst;
    edge[eidx][FLOW] = flow;
    edge[eidx][COST] = cost;
    edge[eidx][NXT] = head[src];
    head[src] = eidx;
}
void inline add(lld src, lld dst, lld flow, lld cost) {
    dir_add(src, dst, flow, cost);
    dir_add(dst, src, 0, -cost);
}


void run() {
    lld t;
    do {
        do {
            memset(vis, 0, size * sizeof(char));
            t = getFlow(src, INF);  
            tot_flow += t;
        } while (t);
    } while (getLabel());
}


}cost_flow;


struct _Main{
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
    int cost[3];
    int time[3];
    int id[1005][2];
    int node_idx;
    int inline node() {
        return node_idx++;
    }
    _Main() {
        int i, j, k;
        int n;
        int need;
        read(n);
        read(cost[BUY]);
        for (i = FAST; i <= SLOW; i++) {
            read(time[i]);   
            read(cost[i]);
        }
        src = node();
        dst = node();
        
        for (i = 1; i <= n; i++) {
            for (j = 0; j < 2; j++) {
                id[i][j] = node();
            }
        }
        
        for (i = 1; i <= n; i++) {
            read(need);
            cost_flow.add(src, id[i][USE], LINF, cost[BUY]);
            cost_flow.add(id[i][USE], dst, need, 0);
            cost_flow.add(src, id[i][STORGE], need, 0);
            if (i + 1 <= n) {
                cost_flow.add(id[i][USE], id[i + 1][USE], LINF, 0);
            }
            for (j = FAST; j <= SLOW; j++) {
                if (i + time[j] <= n) {
                    cost_flow.add(id[i][STORGE], id[i + time[j]][USE], LINF, cost[j]);
                }
            }
        }
        size = node_idx;
        cost_flow.run();
        printf("%lld", cost_flow.tot_cost);
    }
    
    
    
}problem;



}
