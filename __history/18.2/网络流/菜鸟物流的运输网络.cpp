using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>

namespace Protector {
const int IN = 1;
const int OUT = 2;
const int FLOW = 2;
const int DST = 1;
const int NXT = 0;
const int MAXN = 210;
const int MAXE = 22000;
const int T = 1;
const int S = 0;
const int INF = 0x3f3f3f3f;
struct _Main{
    int src, dst;
    queue<int>q;
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    int edge[MAXE][3];
    int id[MAXN];
    int type[MAXN];
    int size;
    int node_idx;
    int eidx;
    int tot_flow;
    void inline push(int nd, int layer) {
        q.push(nd);
        this->layer[nd] = layer;
    }
    int getLayer() {
        memset(layer, 0, size * sizeof(int));
        push(src, 1);
        int i, nd, t;
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
            tot_flow += mx_flow;
            return mx_flow;
        }
        int i, t, use = 0;
        for (i = head[nd]; i; i = edge[i][NXT]) {
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
        now[nd] = i;
        return use;
    }
    
    
    void run() {
        while (getLayer()) {
            memcpy(now, head, size * sizeof(int));
            while (getFlow(src, INF));
        }
    }
    
    void clear() {
        node_idx = 0;
        memset(head, 0, size * sizeof(int));
        memset(id, 0, size * sizeof(int));
        memset(type, 0, size * sizeof(int));
        eidx = 1;
    }
    int getAns(int ans[], int nd) {
        int idx = 0;
        int i, t;
        ans[++idx] = id[nd];
        nd = out[id[nd]];
        while (1) {
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] == 0) {
                    if ((t = edge[i][DST]) == dst) {
                        return idx;
                    }
                    if (type[t] == IN && id[t] != id[nd]) {
                        nd = t;
                        ans[++idx] = id[nd];  
                        nd = out[id[nd]];
                        
                        break;
                    }
                }
            }
        }
    }
    void add(int src, int dst, int flow) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
    
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
    int in[MAXN], out[MAXN];
    int ans[2][MAXN];
    int len[2];
    _Main() {
        int TestCases;
        int n, m;
        int a, b;
        int i, j;
        read(TestCases);
        int duan[2], mid;
        while(TestCases--) {
            eidx = 1;
            read(n); read(m);
            read(duan[S]); read(duan[T]); read(mid);
            src = node_idx++;
            dst = node_idx++;
            for (i = 1; i <= n; i++) {
                if (i == mid) {
                    continue;
                }
                id[in[i] = node_idx++] = i;
                type[in[i]] = IN;
                id[out[i] = node_idx++] = i;
                type[out[i]] = OUT;
                add(in[i], out[i], 1);
                add(out[i], in[i], 0);
            }
            size = node_idx;
            add(src, in[duan[S]], 1);
            add(in[duan[S]], src, 0);
            add(src, in[duan[T]], 1);
            add(in[duan[T]], src, 0);
            for (i = 1; i <= m; i++) {
                read(a); read(b);
                if (a == mid) {
                    swap(a, b);
                }
                if (b == mid) {
                    add(out[a], dst, 1);
                    add(dst, out[a], 0);
                } else{
                    for (j = 1; j <= 2; j++) {
                        add(out[a], in[b], 1);
                        add(in[b], out[a], 0);                      
                        swap(a, b);  
                    }
                }
            }
            run();
            if (duan[S] != mid)len[S] = getAns(ans[S], in[duan[S]]);
            if (duan[T] != mid)len[T] = getAns(ans[T], in[duan[T]]);
            for (i = 1; i <= len[S]; i++) {
                printf("%d ", ans[S][i]);   
            }
            printf("%d", mid);
            for (i = len[T]; i >= 1; i--) {
                printf(" %d", ans[T][i]);   
            }
            if (TestCases) {
                printf("\n");
                clear();
            }
        }
    }
    
    
}jsk;


}
//边数一定要以建图为准， ((n * (n - 1)) / 2 * 2 + n + eps) * 2
//由于拆点， 每条原图边其实被拆成两对边。 
