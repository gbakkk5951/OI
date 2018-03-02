using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <queue>
const int 
    MAXN = 110,
    MAXE = 5500,
    INF = 0x3f3f3f3f
;
namespace Protector {
struct Edge {
    int src, 
        dst, 
        flow,
        nxt
    ;
} ;
int src, dst, size;
class ISAP {
public:
    Edge edge[MAXE];
    int head[MAXN],
        now[MAXN],
        dis[MAXN],
        vis[MAXN],
        num[MAXN],
        pre[MAXN],
        eidx,
        tot_flow
    ;
    queue<int> q;
    ISAP() {
        eidx = 1;
    }
    void inline dir_add(int src, int dst, int flow) {
        eidx++;
        edge[eidx].nxt = head[src];
        head[src] = eidx;
        edge[eidx].src = src;
        edge[eidx].dst = dst;
        edge[eidx].flow = flow;
    }
    void inline add(int src, int dst, int flow) {
        dir_add(src, dst, flow);
        dir_add(dst, src, 0);
    }
    void inline push(int nd, int dis) {
        if (!vis[nd]) {
            q.push(nd);
            vis[nd] = 1;
            this->dis[nd] = dis;
        }
    }
    int bfs() {
        int i, t, nd;
        memset(vis, 0, sizeof(vis));
        push(dst, 0);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i].nxt) {
                if (edge[i ^ 1].flow) {
                    push(edge[i ^ 1].src, dis[nd] + 1);
                }
            }
        }
        return vis[src];
    }
    int augment() {
        int e, mn_flow = INF;
        for (e = pre[dst]; e; e = pre[edge[e].src]) {
            mn_flow = min(mn_flow, edge[e].flow);
        }
        for (e = pre[dst]; e; e = pre[edge[e].src]) {
            edge[e].flow -= mn_flow;
            edge[e ^ 1].flow += mn_flow;
        }        
        return mn_flow;
    }
    int run() {
        int i, nd, t, mn_dis;
        bfs();
        for (i = 0; i < size; i++) {
            num[dis[i]]++;
        }
        memcpy(now, head, size * sizeof(int));
        nd = src;
        while (dis[src] < size) {
            if (nd == dst) {
                tot_flow += augment();
                nd = src;
            }
            for (i = now[nd]; i; i = edge[i].nxt) {
                if (edge[i].flow && dis[nd] == dis[t = edge[i].dst] + 1) {
                    pre[t] = i;
                    break;
                }
            }
            now[nd] = i;
            if (now[nd] == 0) {
                mn_dis = size;
                for (i = head[nd]; i; i = edge[i].nxt) {
                    if (edge[i].flow) {
                        mn_dis = min(mn_dis, dis[edge[i].dst]);
                    }
                }
                
                if (--num[dis[nd]] == 0) {
                    break;
                }
                num[dis[nd] = mn_dis + 1]++;
                now[nd] = head[nd];
                nd = edge[pre[nd]].src;
            } else {
                nd = t;
            }
        }
    }
    
}isap;

struct _Main {

int n, m;
int id[105];
int node_idx;
char link[105][105];
int EOF_TAG;
int node() {
    return node_idx++;
}
template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar())) {
            if (t == EOF) {
                EOF_TAG = 1;
                return;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }        
    }
_Main() {
    int i, j, k;
    int a, b, c;
    read(n); read(m);
    src = node(); dst = node();
    for (i = 1; i <= n; i++) {
        id[i] = node();
        if (i <= m) {
            isap.add(src, id[i], 1);
        } else {
            isap.add(id[i], dst, 1);
        }
    }
    while (1) {
        read(a); read(b);
        if (EOF_TAG) {
            break;
        }
        if(a > b){
            swap(a, b);
        }
        if (b <= m) {
            continue;
        }
        if (!link[a][b]) {
            isap.add(id[a], id[b], 1);
            link[a][b] = 1;
        }
    }
    size = node_idx;
    isap.run();
    printf("%d", isap.tot_flow);
}


}LOJ6000;

}
