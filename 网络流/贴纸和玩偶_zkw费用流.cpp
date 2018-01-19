using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
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
    
int src, dst, size;
int base;

class ZKWCostFlow {
public:
    char vis[MAXN];
    int edge[MAXE][4];
    int head[MAXN];
    int tot_flow, tot_cost;
    int eidx;
    
    ZKWCostFlow() {
        eidx = 1;
    }
    void dir_add(int src, int dst, int flow, int cost) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][COST] = cost;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
    
    void add(int src, int dst, int flow, int cost) {
        dir_add(src, dst, flow, cost);
        dir_add(dst, src, 0, -cost);
    }
    
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
//            tot_flow += mx_flow;
            tot_cost += mx_flow * base;
            return mx_flow;
        }
        int i, t, use = 0;
        vis[nd] = 1;
        for (i = head[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && !edge[i][COST] && !vis[t = edge[i][DST]]){
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
    
    char getLabel() {
        int delta = INF;
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
        if (delta == INF) {
            return 0;
        }
        for (i = 0; i <= size; i++) {
            if (vis[i]) {
                for (j = head[i]; j; j = edge[j][NXT]) {
                    edge[j][COST] -= delta;
                    edge[j ^ 1][COST] += delta;
                }
            }
        }
        base += delta;
        return 1;
    }
    
    void run() {
        do {
            do {
                memset(vis, 0, size * sizeof(char));
            }while (getFlow(src, INF));
        } while (getLabel());
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
