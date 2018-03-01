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
const lld LINF = 0x3f3f3f3f3f3f3f3fLL;
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
