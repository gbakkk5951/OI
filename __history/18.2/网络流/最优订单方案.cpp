using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

namespace Protector {
typedef long long lld;
    
const lld LINF = 0x3f3f3f3f3f3f3f3f;
const int NXT = 1;
const int FLOW = 2;
const int DST = 0;
const int MAXN = 220;
const int MAXE = 21000;
class Dinic {
private:
    queue<int> q;
    int layer[MAXN];
    int head[MAXN];
    int now[MAXN];
    lld edge[MAXE][3];
    int e_idx;
    lld tot_flow;
    int src, dst, size;
private:
    void inline push(int nd, int nd_layer) {
        q.push(nd);
        layer[nd] = nd_layer;
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
    
    lld getFlow(int nd, lld mx_flow = LINF) {
        if (nd == dst) {
            tot_flow += mx_flow;
            return mx_flow;
        }
        lld i;
        lld use = 0, t;
        for (i = now[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t, min(edge[i][FLOW], mx_flow - use));
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
        now[nd] = i;
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
        size = n + 1;
    }
    
    void inline add(int src, int dst, lld flow) {
        e_idx++;
        edge[e_idx][DST] = dst;
        edge[e_idx][FLOW] = flow;
        edge[e_idx][NXT] = head[src];
        head[src] = e_idx;
    }
    
    void run() {
        while (getLayer()) {
            memcpy(now, head, size * sizeof(int));
            while (getFlow(src));
        }
    }
    
    lld getMaxFlow() {
        return tot_flow;
    }
    
    int getVis(int nd) {
        return layer[nd];
    }
}dinic;



struct _Main {
    string buf;
    int idx;
    int len;
    void inline getLine() {
        idx = 0;
        getline(cin, buf);
        len = buf.length();
    }
    inline char nxtchar() {
        return idx < len ? buf[idx++] : -1;
    }
template <typename Type>
    int read(Type &a) {
        char t;
        while (!isdigit(t = nxtchar())) {
            if (t == -1) {
                return 0;
            }
        }
        a = t - '0';
        while ( isdigit(t = nxtchar())) {
            a *= 10;
            a += t - '0';
        }
        return 1;
    }   
    
    _Main() {
        int n, m;
        int i, j, k;
        int a, b, c;
        int src, dst;
        lld val, cst;
        lld sum = 0;
        ios::sync_with_stdio(false);
        cin.tie(0);
        getLine();
        read(n); read(m);
        dinic.setSrc(src = 0);
        dinic.setDst(dst = n + m + 1);
        dinic.setMax(dst);
        for (i = 1; i <= n; i++) {
            getLine();
            read(val);
            sum += val;
            dinic.add(src, i, val);
            dinic.add(i, src, 0);
            while (read(a)) {
                dinic.add(i, n + a, LINF);
                dinic.add(n + a, i, 0);
            }
        }
        getLine();
        for (i = 1; i <= m; i++) {
            read(cst);
            dinic.add(n + i, dst, cst);
            dinic.add(dst, n + i, 0);
        }
        dinic.run();
        for (i = 1; i <= n; i++) {
            if (dinic.getVis(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
        for (i = 1; i <= m; i++) {
            if (dinic.getVis(n + i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("%lld", sum - dinic.getMaxFlow());
    } 
    
    
}jsk;

}
