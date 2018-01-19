using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>

namespace OI {
const int 
    MAXN = 150,
    MAXE = 20010,
    DST = 0,
    FLOW = 2,
    NXT = 1,
    INF = 0x3f3f3f3f
    ;
    


int src, dst, size;

class Dinic{
public:
    int edge[MAXE][3];
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    int tot_flow;
    int eidx;
    queue<int> q;
    Dinic() {
        eidx = 1;
    }
           
    void inline push(int nd, int lay) {
        q.push(nd);
        layer[nd] = lay;
    }
    
    int getLayer() {
        int nd, i, t;
        memset(layer, 0, size * sizeof (int));
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
    int run() {
        while (getLayer()){
            memcpy(now, head, size * sizeof(int));
            tot_flow += getFlow(src, INF);
        }
        return tot_flow; 
    }
    void add(int src, int dst, int flow) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
}dinic;



struct _Main{
   
    char vis[MAXN];
    
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
    int node() {
        return node_idx++;
    }
    int pigs[1005];
    int fa[1005];
    _Main() {
        int i, j;
        int n, m;
        int buys;
        int buy_id;
        int a, b, c;
        int fa;
        src = node();
        dst = node();
        read(n); read(m);
        for (i = 1; i <= n; i++) {
            read(pigs[i]);
        }
        for (i = 1; i <= m; i++) {
            buy_id = node();
            read(a);
            for (j = 1; j <= a; j++) {
                read(b);
                if (!vis[fa = this->fa[b]]) {
                    if (fa == 0) {
                        fa = src;
                        c = pigs[b];
                    } else {
                        vis[fa] = 1;
                        c = INF;
                    }
                    dinic.add(fa, buy_id, c);
                    dinic.add(buy_id, fa, 0);
                }
                this->fa[b] = buy_id;
            }
            memset(vis, 0, node_idx * sizeof(char));
            read(buys);
            dinic.add(buy_id, dst, buys);
            dinic.add(dst, buy_id, 0);
        }
        size = node_idx;
        dinic.run();
        printf("%d", dinic.tot_flow);
    }
    
}jsk;



}
