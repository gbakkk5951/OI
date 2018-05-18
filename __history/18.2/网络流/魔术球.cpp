using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
namespace OI {
const int 
    MAXN = 60050,
    MAXE = 4000000,
    INF = 0x3f3f3f3f,
    ans[] = {0, 1, 3, 7, 11, 17, 23, 31, 39, 49, 59, 71, 83, 97, 111, 127, 143,
             161, 179, 199, 219, 241, 263, 287, 311, 337, 363, 391, 419, 449, 479, 
             511, 543, 577, 611, 647, 683, 721, 759, 799, 839, 881, 923, 967, 1011, 
             1057, 1103, 1151, 1199, 1249, 1299,1351, 1403, 1457, 1511, 1567
             };

;
struct Edge {
    int dst, flow, nxt;
};

int src, dst, size;

class Dinic {
public:
    Edge edge[MAXE];
    int head[MAXN],
        now[MAXN],
        layer[MAXN],
        left[MAXN],
        match[MAXN]
    ;
    int eidx;
    int tot_flow;
    queue<int> q;
    Dinic() {
        eidx = 1;
    }
    void push(int nd, int layer) {
        if (!this->layer[nd]) {
            q.push(nd);
            this->layer[nd] = layer;
        }
    }
    int getLayer() {
        int i, nd, t;
        memset(layer, 0, size * sizeof(int));
        push(src, 1);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i].nxt) {
                if (edge[i].flow) {
                    push(edge[i].dst, layer[nd] + 1);
                }
            }
        }
        return layer[dst];
    }
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            return 1;
        }
        int i, t, use = 0;
        for (i = now[nd]; i; i = edge[i].nxt) {
            if (edge[i].flow && layer[t = edge[i].dst] > layer[nd]) {
                t = getFlow(t, min(edge[i].flow, mx_flow - use));  
                if (t) {
                    if (left[nd]) {
                        match[nd] = edge[i].dst;
                        match[edge[i].dst] = nd;
                    }
                    edge[i].flow -= t;
                    edge[i ^ 1].flow += t;
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
    void inline dir_add(int src, int dst, int flow) {
        eidx++;
        edge[eidx].dst = dst;
        edge[eidx].flow = flow;
        edge[eidx].nxt = head[src];
        head[src] = eidx;
    }
    void inline add(int src, int dst, int flow) {
        dir_add(src, dst, flow);
        dir_add(dst, src, 0);
    }
    void clear() {
        memset(left, 0, size * sizeof(int));
        memset(head, 0, size * sizeof(int));
        tot_flow = 0;
        eidx = 1;
    }
    void run() {
        while (getLayer()) {
            memcpy(now, head, size * sizeof(int));
            tot_flow += getFlow(src, INF);
        }
    }
}netflow;

    



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
    
    int inline pf(int a) {
        return a * a;
    }
    int sqrt(int nd) {
        int l = 1, r = nd;
        int mid;
        while (l < r) {
            mid = l + r >> 1;
            if (pf(mid + 1) <= nd) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    char is_sq[20005];
    int in[10005], out[10005];
    int org[21000];
    int nxt[10005], ind[10005];
    int node_idx;
    
    int node() {
        return node_idx++;
    }
    
    _Main() {
        int i, j, k;
        int n, l, r, mid, t, nd;
        for (i = 1; i * i <= 20000; i++) {
            is_sq[i * i] = 1;
        }
        read(n);
        mid = ans[n];
        netflow.clear();
        node_idx = 0;
        src = node();
        dst = node();
        for (i = 1; i <= mid; i++) {
            in[i] = node();
            out[i] = node();
            org[in[i]] = org[out[i]] = i;
            netflow.left[out[i]] = 1;
            netflow.add(src, out[i], 1);
            netflow.add(in[i], dst, 1);
            for (j = 1; j < i; j++) {
                if (is_sq[i + j]) {
                    netflow.add(out[i], in[j], 1);
                }
            }
        }
        size = node_idx;
        netflow.run();
        
        printf("%d\n", mid);
        for (i = 1; i <= mid; i++) {
            if (t = netflow.match[out[i]]) {
                nxt[i] = org[t];
                ind[org[t]]++;
            }
        }
        
        for (i = 1; i <= mid; i++) {
            if (ind[i] == 0) {
                nd = i;
                while (nd) {
                    printf("%d ", nd);
                    ind[nd] = -1;
                    nd = nxt[nd];
                }
                printf("\n");
            }
        }
        
    }
}LOJ6003;

}

