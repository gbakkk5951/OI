using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
namespace OI{
const char 
FAIL[] = "impossible",
SUCCESS[] = "possible";
    
const int 
NXT = 1,
DST = 0,
FLOW = 2,
MAXN = 220,
MAXE = 2500,
INF = 0x3f3f3f3f;
;

int src, dst, size;


class Dinic {
public:
    int edge[MAXE][3];
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    int cnt;
    int eidx;
    queue<int> q;
    Dinic() {
        eidx = 1;
    }
    
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
                if (edge[i][FLOW] && ! layer[t = edge[i][DST]]) {
                    push(t, layer[nd] + 1);
                }
            }
        }
        return layer[dst];
    }
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            cnt += mx_flow;
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
    void add(int src, int dst, int flow) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
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
int visable[MAXE];
int id[MAXN];
int node_idx;
int in[MAXN], out[MAXN];
int head[MAXN];
int edge[MAXE][2];
int eidx;
void add(int src, int dst, int visable){
    eidx++;
    edge[eidx][DST] = dst;
    edge[eidx][NXT] = head[src];
    head[src] = eidx;    
    this->visable[eidx] = visable; 
    if (visable) {
        in[dst]++;
        out[src]++;
    }
}
int node() {
    return node_idx++;
}
int crossings, streets;
_Main() {
    int i, j, k, t;
    int a, b, d;
    int tot_need = 0;
    src = node();
    dst = node();
    read(crossings); read(streets);
    for (i = 1; i <= crossings; i++) {
        id[i] = node();
    }
    size = node_idx;
    for (i = 1; i <= streets; i++) {
        read(a); read(b); read(d);
        add(a, b, 1);
        if (d == 0) {
            add(b, a, 0);      
        }
    }
    for (i = 1; i <= crossings; i++) {
        if (in[i] > out[i]) {
            dinic.add(src, id[i], in[i] - out[i] >> 1);
            dinic.add(id[i], src, 0);
            tot_need += in[i] - out[i] >> 1;
        } else if (in[i] < out[i]){
            dinic.add(id[i], dst, out[i] - in[i] >> 1);
            dinic.add(dst, id[i], 0);
        }
        if (in[i] - out[i] & 1) {
            goto FailTag;
        }
    }
    for (i = 1; i <= crossings; i++) {
        for (j = head[i]; j; j = edge[j][NXT]) {
            if (!visable[j]) {
                t = edge[j][DST];
                dinic.add(id[i], id[t], 1);
                dinic.add(id[t], id[i], 0);
            }
        }
    }
    dinic.run();
    if (dinic.cnt < tot_need) {
        goto FailTag;
    }
    printf("%s", SUCCESS);
    return;
    FailTag:
    printf("%s", FAIL);
}

}jsk;


}
