using namespace std;
int main() {}

#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
namespace Protector {

const int MAXN = 56000;
const int MAXE = 320000;
const int NXT = 1;
const int DST = 0;
const int FLOW = 2;
const int INF = 0x3f3f3f3f;
class Dinic {
private:    

    queue<int> q;
    int edge[MAXE][3];
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    int dst, src, size;
    int tot_flow;
    int e_idx;
private:
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            tot_flow += mx_flow;
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
    void inline push(int a, int b) {
        q.push(a);
        layer[a] = b;
    }
    int getLayer() {
        memset(layer, 0, size * sizeof(int));
        push(src, 1);
        int nd, i, t;
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
    
public:
    Dinic() {
        e_idx = 1;
    }
    void setMax(int n) {
        size = n + 1;
    }
    void setSrc(int n) {
        src = n;
    }
    void setDst(int n) {
        dst = n;
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
            memcpy(now, head, size * sizeof(int));
            while (getFlow(src, INF));
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
    
    _Main () {
        int i, j;
        int cst, val;
        int sum = 0;
        int n, m;
        int src, dst;
        int need[2];
        
        read(n); read(m);
        dinic.setSrc(src = 0);
        dinic.setDst(dst = n + m + 1);
        dinic.setMax(dst);
        for (i = 1; i <= n; i++) {
            read(cst);
            dinic.add(i, dst, cst);
            dinic.add(dst, i, 0);
        }
        for (i = 1; i <= m; i++) {
            for (j = 0; j < 2; j++) {
                read(need[j]);
            }
            read(val);
            sum += val;
            dinic.add(src, n + i, val);
            dinic.add(n + i, src, 0);
            for (j = 0; j < 2; j++) {
                dinic.add(n + i, need[j], INF);
                dinic.add(need[j], n + i, 0);
            }
        }
        dinic.run();
        printf("%d", sum - dinic.getMaxFlow());
    }
    
}jsk;

}

// 15.5 * 2 = 21 数据范围估算一定要用计算器，算多遍 
