using namespace std;
int main() {}

#include <queue> 
#include <cstdio>
#include <cctype>
#include <ctime>
#include <functional>
#include <vector>
#include <cstring>
const int 
    MAXN = 1005,
    MAXE = 5005,
    DST = 0,
    NXT = 1,
    DIS = 2
;
int head[MAXN];
int edge[MAXE][3];
struct Edge{
    int dst, val;
    bool operator > (const Edge &b) const {
        return val > b.val;
    }
};

struct _Main {
template<typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }
template<typename Type>
    void signed_read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '-') {
                f = -1;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        a *= f;
    }   
    char in_q[MAXN];
    int cnt[MAXN];
    int label[1005];
    int dis[1005][1005];
    int n, size;
    int getLabel() {
        int i;
        int *dis = label;
        queue<int> q;
        for (i = 1; i <= n; i++) {
            dis[i] = 0;
            q.push(i);
            in_q[i] = 1;
            cnt[i] = 1;
        }
        int nd, t;
        while (!q.empty()) {
            nd = q.front();
            in_q[nd] = 0;
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (dis[t = edge[i][DST]] > dis[nd] + edge[i][DIS]) {
                    dis[t] = dis[nd] + edge[i][DIS];
                    cnt[t]++;
                    if (cnt[t] > n + 1) {
                        return 0;
                    }
                    if (!in_q[t]) {
                        in_q[t] = 1;
                        q.push(t);
                    }
                }
            }
        }
        return 1;
    }
    
    void dijkstra(int src) {
        memset(dis[src], 63, size * sizeof(int));
        dis[src][src] = 0;
        int i, t, v, nd;
        priority_queue <Edge, vector <Edge>, greater <Edge> > heap;
        heap.push(Edge{src});
        while (!heap.empty()) {
            if (heap.top().val > dis[src][nd = heap.top().dst]) {
                heap.pop();
                continue;
            }
            heap.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (dis[src][t = edge[i][DST]] > (v = dis[src][nd] + label[nd] - label[t] + edge[i][DIS])) {
                    dis[src][t] = v;
                    heap.push(Edge{t, v});
                }
            }
        }
        for (i = 1; i <= n; i++) {
            dis[src][i] += label[i] - label[src];
        }
    }
    

    _Main() {
        int n, m;
        int i, j, k;
        read(n); read(m);
        size = n + 1;
        if (getLabel()) {
            for (i = 1; i <= n; i++) {
                dijkstra(i);
            }
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    printf("%d ", dis[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("-1");
        }
    }
    
};

