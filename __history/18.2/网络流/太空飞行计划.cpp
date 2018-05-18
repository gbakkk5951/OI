using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
namespace OI {
typedef long long lld;

const int 
    MAXN = 110,
    MAXE = 5300,
    INF = 0x3f3f3f3f
;
const lld 
    LINF = (lld) INF << 31 | INF;
int src, dst, size;
struct Edge {
    int src, dst, nxt;
    lld flow;
};
 
class ISAP{
public:
    Edge edge[MAXE];
    int now[MAXN],
        head[MAXN],
        dis[MAXN],
        pre[MAXN],
        cnt[MAXN],
        vis[MAXN],
        eidx
    ;
    lld tot_flow;
    queue<int> q;
    
    ISAP() {
        eidx = 1;
    }
    
    void inline push(int nd, int dis) {
        if (!this->dis[nd]) {
            this->dis[nd] = dis;
            q.push(nd);
        }
    }
    
    int getDis() {
        int i, nd;
        push(dst, 1);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i].nxt) {
                if (edge[i ^ 1].flow) {
                    push(edge[i ^ 1].src, dis[nd] + 1);
                }
            }
        }       
        return dis[src];
    }
    lld augment() {
        lld mn_flow = LINF;
        int i;
        for (i = pre[dst]; i; i = pre[edge[i].src]) {
            mn_flow = min(mn_flow, edge[i].flow);
        }
        for (i = pre[dst]; i; i = pre[edge[i].src]) {
            edge[i].flow -= mn_flow;
            edge[i ^ 1].flow += mn_flow;
        }
        return mn_flow;
    }
    
    void run() {
        int nd, t, i, mn_dis;
        getDis();
        memcpy(now, head, size * sizeof(int));
        while (dis[src] <= size) {
            if (nd == dst) {
                tot_flow += augment();
                nd = src;
            }
            for (i = now[nd]; i; i = edge[i].nxt) {
                if (edge[i].flow && dis[t = edge[i].dst] < dis[nd]) {
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
                if (--cnt[dis[nd]] == 0) {
                    break;
                }
                cnt[dis[nd] = mn_dis + 1]--;
                now[nd] = head[nd];
                nd = edge[pre[nd]].src;
            } else {
                nd = t;
            }
        }
    }
    void dir_add(int src, int dst, lld flow) {
        eidx++;
        edge[eidx].dst = dst;
        edge[eidx].flow = flow;
        edge[eidx].src = src;
        edge[eidx].nxt = head[src];
        head[src] = eidx;
    }
    void add(int src, int dst, lld flow) {
        dir_add(src, dst, flow);
        dir_add(dst, src, 0);
    }
    void dfs(int nd) {
        vis[nd] = 1;
        int i, t;
        for (i = head[nd]; i; i = edge[i].nxt) {
            if (edge[i ^ 1].flow && !vis[t = edge[i ^ 1].src]) {
                dfs(t);
            }
        }
        
    }
    
    void dfs() {
        dfs(dst);
    }
}netFlow;










struct _Main {
    string buf;
    int len, buf_idx;
    void getLine() {
        buf_idx = 0;
        getline(cin, buf);
        len = buf.length();
    }

template <typename Type>
    int readArr(Type a[]) {
        int cnt = 0;
        while (read(a[cnt])) {
            cnt++;
        }
        return cnt;
    }
    char nxtchar() {
        if (buf_idx < len) {
            return buf[buf_idx++];
        }
        return -1;
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
    int node_idx;
    int node() {
        return node_idx++;
    }
    int needs[55], need[55][55];
    int id[2][55];
    int vis[2][55];
    int num[2];
    _Main() {
        int i, j;
        int n, m;
        lld a, sum;
        src = node(); dst = node();
        getLine();
        read(n); read(m);
        num[0] = n; num[1] = m;
        for (i = 0; i <= 1; i++) {
            for (j = 1; j <= num[i]; j++) {
                id[i][j] = node();
            }
        }
        for (i = 1, sum = 0; i <= n; i++) {
            getLine();
            read(a);
            sum += a;
            netFlow.add(src, id[0][i], a);
            needs[i] = readArr(need[i] + 1);
            for (j = 1; j <= needs[i]; j++) {
                netFlow.add(id[0][i], id[1][need[i][j]], LINF);
            }
        }
        getLine();
        for (i = 1; i <= m; i++) {
            read(a);
            netFlow.add(id[1][i], dst, a);
        }
        size = node_idx;
        netFlow.run();
        netFlow.dfs();
        for (i = 1; i <= n; i++) {
            if (!netFlow.vis[id[0][i]]) {
                vis[0][i] = 1; 
                for (j = 1; j <= needs[i]; j++) {
                    vis[1][need[i][j]] = 1;
                }
            }
        }
        for (i = 0; i <= 1; i++) {
            for (j = 1; j <= num[i]; j++) {
                if (vis[i][j]) {
                    printf("%d ",j);
                }
            }
            printf("\n");    
        }
        printf("%lld", sum - netFlow.tot_flow);
    }
    
    
}LOJ6001;





}

