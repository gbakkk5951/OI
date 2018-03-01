using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>
const int MAXE = 1e5;
const int MAXN = 330;
const int NXT = 2;
const int DST = 0;
const int FLOW = 1;
const int INF = 0x3f3f3f3f;
class Dinic {
private:    
    queue<int> q;
    int layer[MAXN];
    int head[MAXN];
    int now[MAXN];
    int edge[MAXE][3];
    int e_idx;
    int src, dst;
    int node_size;
    int tot_flow;
    char vis[MAXN];
private:
    void inline push(int nd, int nd_layer = 0) {
        q.push(nd);
        vis[nd] = 1;
        layer[nd] = nd_layer;
    }
    int getLayer() {
        memset(vis, 0, node_size * sizeof(char));
        push(src);
        int i, nd, t;
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !vis[t = edge[i][DST]]) {
                    push(t, layer[nd] + 1);   
                }
            }
        }
        return vis[dst];
    }
    int getFlow(int nd, int mx_flow = INF) {
        if (nd == dst) {
            tot_flow += mx_flow;
            return mx_flow;
        }
        int i, t, use = 0;
        for (; i = now[nd]; now[nd] = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t, min(mx_flow - use, edge[i][FLOW]));   
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
        return use;
    }
    
public:
    Dinic() {
        e_idx = 1;
    }
    void setSrc(int n) {
        src = n;
    }
    void setDst(int n) {
        dst = n;
    }
    void setMax(int n) {
        node_size = n + 1;
    }
    void add(int src, int dst, int flow) {
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
    
    int getMaxFlow() {
        return tot_flow;
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
    _Main() {
        int i, j, k;
        int a, b, c;
        int n, m;
        int dst, src;
        read(n); read(m);
        dinic.setSrc(src = 0);
        dinic.setDst(dst = n + 1);
        dinic.setMax(dst);
        for (i = 1; i <= n; i++) {
            read(a);
            if (a) {
                dinic.add(src, i, 1);
                dinic.add(i, src, 0);                
            } else {
                dinic.add(i, dst, 1);
                dinic.add(dst, i, 0);
            }
        }
        for (i = 1; i <= m; i++) {
            read(a); read(b);
            dinic.add(a, b, 1);
            dinic.add(b, a, 1);
        }
        dinic.run();
        printf("%d", dinic.getMaxFlow());
    }
    
    
    
    
    
}jsk;

