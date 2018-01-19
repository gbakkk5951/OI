using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>

namespace Protector {
const int DST = 0;
const int NXT = 1;
const int FLOW = 2;
const int CST = 3;
const int INF = 0x3f3f3f3f;
const int MAXN = 160;
const int MAXE = 10500;
const long long LINF = (long long)INF << 32 | INF;
char less(int a, int b) {
    return a < b;
}
char greater(int a, int b) {
    return a > b;
}
class CostFlow{
private:
    char (*cmp)(int a, int b);
    long long ans;
    int head[MAXN];
    int edge[MAXE][4];
    int dis[MAXN];
    int src, dst, n;
    int from_node[MAXN], from_edge[MAXN];
    char in_q[MAXN];
    char init_dis;
    int eidx;
private:
    int SPFA() {
        int empty;
        int nd, i, t;
        queue<int>q;
        memset(dis, init_dis, n * sizeof(int));
        empty = dis[dst];
        dis[src] = 0;
        q.push(src);
        while(!q.empty()) {
            nd = q.front();
            in_q[nd] = 0;
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && cmp(dis[nd] + edge[i][CST], dis[t = edge[i][DST]]) ) {
                    dis[t] = dis[nd] + edge[i][CST];
                    from_node[t] = nd;
                    from_edge[t] = i;
                    if (!in_q[t]) {
                        in_q[t] = 1;
                        q.push(t);
                    }
                }
            }
        }
        return dis[dst] != empty;
    }
    
    void runFlow() {
        int nd = dst;
        int mn_flow = INF;
        int e;
        while (nd != src) {
            mn_flow = min(mn_flow, edge[from_edge[nd]][FLOW]);
            nd = from_node[nd];
        }
        nd = dst;
        while(nd != src) {
            e = from_edge[nd];
            edge[e][FLOW] -= mn_flow;
            edge[e ^ 1][FLOW] += mn_flow;
            ans += (long long) mn_flow * edge[e][CST];
            nd = from_node[nd];
        }
        
    }

public:
    CostFlow() {
        eidx = 1;
    }
    void setDst(int n) {
        dst = n;
    }
    void setSrc(int n) {
        src = n;
    }
    void setMax(int n) {
        this->n = n + 1;
    }
    void setMode(int mode) { // 1为最大费用 -1为最小费用 
        if (mode == 1) {
            cmp = greater;
            init_dis = 192;
        } else {
            cmp = less;
            init_dis = 63;
        }
    }
    
    void clear() {
        memset(head, 0, n * sizeof(int));
        ans = 0;
        eidx = 1;
    }
    void add(int src, int dst, int flow, int cst) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][CST] = cst;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }

    
    void run() {
        while(SPFA()) {
            runFlow();   
        }
    }
    long long getAns() {
        return ans;
    }
    
}solver;
int cnt1[105], cnt2[105];
int happy[102][52];
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
     
    int n, m;
    _Main() {
        int i, j;
        int src, dst;
        int Q;
        read(n); read(m);
        solver.setSrc(src = 0);
        solver.setDst(dst = n + m + 1);
        solver.setMax(dst);
        
        for (i = 1; i <= n; i++) {
            read(cnt1[i]);
        }
        for (i = 1; i <= m; i++) {
            read(cnt2[i]);
        }   
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                read(happy[i][j]);
            }
        }             
        for (Q = 1; Q <= 2; Q++) {
            if (Q == 1) {
                solver.setMode(-1);
            } else {
                solver.clear();
                solver.setMode(1);
            }
            for (i = 1; i <= n; i++) {
                solver.add(i, src, 0, 0);
                solver.add(src, i, cnt1[i], 0);
            }
            for (i = 1; i <= m; i++) {
                solver.add(i + n, dst, cnt2[i], 0);
                solver.add(dst, i + n, 0, 0);     
            }   
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= m; j++) {
                    solver.add(i, j + n, INF, happy[i][j]);
                    solver.add(j + n, i, 0, -happy[i][j]);
                }
            }
            solver.run();
            printf("%lld\n", solver.getAns());

            
        }
        
        
    }
    
    
    
}jsk;



}
