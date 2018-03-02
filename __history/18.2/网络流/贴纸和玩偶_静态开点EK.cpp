using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

namespace Protector {
const int 
    DST = 0,
    NXT = 1,
    FLOW = 2,
    COST = 3,
    MAXN = 700,
    INF = 0x3f3f3f3f,
    MAXE = 75000
;
typedef long long lld;
const lld LINF = 0x3f3f3f3f3f3f3f3f;    
int src, dst, size;

class CostFlow {

public:
int eidx;
lld tot_cost;
lld tot_flow;
int head[MAXN];
lld edge[MAXE][4];
queue<int> q;
int in_q[MAXN];
int from_edge[MAXN], from_node[MAXN];
lld dis[MAXN];


CostFlow() {
    eidx = 1;
}

void inline push(int nd) {
    if (!in_q[nd]) {
        q.push(nd);
        in_q[nd] = 1;
    }
}
int inline pop() {
    int nd = q.front();
    q.pop();
    in_q[nd] = 0;
    return nd;
}
long long SPFA() {
    memset(dis, 63, size * sizeof(lld));
    dis[src] = 0;
    push(src);
    int nd, i, t;
    while (!q.empty()) {
        nd = pop();
        for (i = head[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && dis[t = edge[i][DST]] > dis[nd] + edge[i][COST]) {
                dis[t] = dis[nd] + edge[i][COST];
                from_edge[t] = i;
                from_node[t] = nd;
                push(t);
            }
        }
    }
    return dis[dst];
}

void getFlow() {
    lld mn_flow = LINF;
    int nd, e;
    for (nd = dst; nd != src; nd = from_node[nd]) {
        mn_flow = min(mn_flow, edge[from_edge[nd]][FLOW]);
    }
    tot_flow += mn_flow;
    for (nd = dst; nd != src; nd = from_node[nd]) {
        e = from_edge[nd];
        tot_cost += mn_flow * edge[e][COST];
        edge[e][FLOW] -= mn_flow;
        edge[e ^ 1][FLOW] += mn_flow;
    }
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
    while (SPFA() < LINF) {
        getFlow();
    }
}


}cost_flow;


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
    int customer_id[61];
    int time[61][11];
    int inline node() {
        return node_idx++;
    }
    _Main() {
        int m, n;
        int i, j, k;
        int nd;
        read(m); read(n);
        
        src = node();
        dst = node();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                read(time[i][j]);
            }
        }
        for (i = 1; i <= n; i++) {
            customer_id[i] = node();
            cost_flow.add(customer_id[i], dst, 1, 0);
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                nd = node();
                cost_flow.add(src, nd, 1, 0);
                for (k = 1; k <= n; k++) {
                    cost_flow.add(nd, customer_id[k], 1, time[k][i] * j);
                }
            }
        }
        size = node_idx;
        cost_flow.run();
        printf("%.2f", round(cost_flow.tot_cost * 100.0 / n) / 100.0);
    }
    
    
}jsk;

}
