using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>
#include <cmath>

namespace Protector {
const int NXT = 1;
const int DST = 0;
const int FLOW = 2;
const int CST = 3;
const int INF = 0x3f3f3f3f;
const int MAXN = 150;
const int MAXE = 10010;
struct _Main {
int src, dst;
int size;
int head[MAXN];
int edge[MAXE][4];
int belong[MAXN];
int node_idx;
int cnt[15];
int use[15]; 
int dis[MAXN];
int from_node[MAXN];
int from_edge[MAXN];
long long ans;
int barbers, customers;
int eidx;
char in_q[MAXN];

int SPFA() {
    queue<int> q;
    int i;
    int nd, t;
    memset(dis, 63, size * sizeof(int));
    dis[src] = 0;
    q.push(src);
    while (!q.empty()) {
        nd = q.front();
        q.pop();
        in_q[nd] = 0;
        for (i = head[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && dis[nd] + edge[i][CST] < dis[t = edge[i][DST]]) {
                dis[t] = dis[nd] + edge[i][CST];
                from_edge[t] = i;
                from_node[t] = nd;
                if (!in_q[t]) {
                    in_q[t] = 1;
                    q.push(t);
                }
            }
        }
    }
    return dis[dst] < INF;
}
void getFlow() {
    int mn_flow = INF;
    int nd = dst, t;
    int sum = 0;
    while (nd != src) {
        mn_flow = min(mn_flow, edge[from_edge[nd]][FLOW]);
        t = belong[nd];
        if (t && from_node[nd] == src) {
//            use[t]++;
//            if (use[t] == cnt[t]) {
                build_node(t);
//            }             
        }

        nd = from_node[nd];
    }
    nd = dst;
    while (nd != src) {
        t = from_edge[nd];
        edge[t][FLOW] -= mn_flow;
        edge[t ^ 1][FLOW] += mn_flow;
        sum += edge[t][CST];
        nd = from_node[nd];
    }
    ans += sum * mn_flow;
}

void build_node(int src) {
    int i;
    node_idx++;
    cnt[src]++;
    belong[node_idx] = src;
    size = node_idx + 1;
    add(this->src, node_idx, 1, 0);
    add(node_idx, this->src, 0, 0);
    for (i = 1; i <= customers; i++) {
        add(node_idx, i, 1, cnt[src] * time[src][i]);
        add(i, node_idx, 0, -cnt[src] * time[src][i]);
    }
}

void add(int src, int dst, int flow, int cst) {
    eidx++;
    edge[eidx][DST] = dst;
    edge[eidx][FLOW] = flow;
    edge[eidx][CST] = cst;
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
    int time[11][65];
    _Main() {
        eidx = 1;
        int i, j;
        read(barbers); read(customers);
        for (i = 1; i <= customers; i++) {
            for (j = 1; j <= barbers; j++) {
                read(time[j][i]);
            }
        }
        src = 0;
        dst = customers + 1;
        node_idx = dst;
        size = dst + 1;
        for (i = 1; i <= customers; i++) {
            add(i, dst, 1, 0);
            add(dst, i, 0, 0);
        }
        for (i = 1; i <= barbers; i++) {
            build_node(i);
        }
        while(SPFA()) {
            getFlow(); 
        } 
        printf("%.2f", round((double)ans / customers * 100.0) / 100.0);
    }
    
}jsk;











}
//读入格式错误 
//增广的时候不要开点。 
