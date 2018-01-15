using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>

namespace Protector {
typedef long long lld;

const int MAXN = 1010;
const int MAXE = 200010;
const int NXT = 2;
const int DST = 0;
const int FLOW = 1;
const int INF = 0x3f3f3f3f;
const lld LINF = 0x3f3f3f3f3f3f3f3f;

class Dinic {
private:
    queue<int> q;
    int now[MAXN];
    int head[MAXN];
    lld edge[MAXE][3];
    int layer[MAXN];
    lld tot_flow;
    int src, dst;
    int node_size;
    int e_idx;
    char vis[MAXN];
private:
    void inline push(int nd, int nd_layer = 0) {
        q.push(nd);
        vis[nd] = 1;
        layer[nd] = nd_layer;
    }
    lld getFlow(int nd, lld mx_flow = LINF) {
         if (nd == dst) {
             tot_flow += mx_flow;
             return mx_flow;
         }
         lld use = 0, i, t;
         for (; i = now[nd]; now[nd] = edge[i][NXT]) {
             if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                 t = getFlow(t, min(edge[i][FLOW], mx_flow - use));
                 if (t) {
//                     printf("from %d to %d\n", nd, edge[i][DST]);
                     use += t;
                     edge[i][FLOW] -= t;
                     edge[i ^ 1][FLOW] += t;
                     if (use == mx_flow) {
                         break;
                     }
                 }   
             }
         }
         return use;
    }
    int getLayer() {
        int i, nd, t;
        memset(vis, 0, node_size * sizeof(char));
        push(src);
        while(!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i =edge[i][NXT]) {
                if (edge[i][FLOW] && !vis[t = edge[i][DST]]) {
                    push(t, layer[nd] + 1);
                }
            }
        }
        return vis[dst];
    }
public:
    Dinic() {
        e_idx = 1;
    }
    
    void setMax (int max_idx) {
        node_size = max_idx + 1;
    }
    void setSrc(int new_src) {
        src = new_src;
    }
    void setDst(int new_dst) {
        dst = new_dst;
    }
    void add(int src, int dst, lld flow) {
        e_idx++;
        edge[e_idx][DST] = dst;
        edge[e_idx][FLOW] = flow;
        edge[e_idx][NXT] = head[src];
        head[src] = e_idx;
    }
    void run() {
        while (getLayer()) {
            memcpy(now, head, node_size * sizeof(int));
            while (getFlow(src));
        }
    }
    lld getMaxFlow() {
        return tot_flow;
    }
}dinic;


struct _Main {
template <typename Type>
    void read (Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }    
    }
    _Main () {
        int n, m;
        lld u, v, w, d;
        int i, j, k;
        int src, dst;
        read(n); read(m);
        dinic.setDst(dst = n - 1);
        dinic.setSrc(src = 0);
        dinic.setMax(dst);
        for (i = 1; i <= m; i++) {
            read(u); read(v); read(w); read(d);
            dinic.add(u, v, w * (m + 1) + 1);
            dinic.add(v, u, (w * (m + 1) + 1) * d);
        }
        dinic.run();
        printf("%lld", dinic.getMaxFlow() % (m + 1));
    }
    
}jsk;


}

// *d 要在最外面乘 
