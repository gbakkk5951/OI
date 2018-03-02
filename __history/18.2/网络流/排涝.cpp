using namespace std;
int main() {}
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cstring>

namespace Protector {
const int DST = 0;
const int FLOW = 1;
const int NXT = 2;
const int MAXN = 205;
const int MAXE = 420;
const int INF = 0x3f3f3f3f;
typedef int lld;

    
class Dinic {
private:
    class Queue {
    private:
        int q[MAXN];
        int qhead, qtail;
    public:
        void push(int val) {
            q[qtail++] = val;
        }
        int top() {
            return q[qhead];
        }
        int front() {
            return q[qhead];
        }
        int pop() {
            return q[qhead++];
        }
        char isEmpty() {
            return qhead == qtail;
        }
        void clear() {
            qhead = qtail = 0;
        }
    }q;
    
    int head[MAXN];
    int now[MAXN];
    int edge[MAXE][3];
    int layer[MAXN];
    char vis[MAXN];
    int n;
    int src, dst;
    int e_idx;
    lld tot_flow;

    char getLayer() {
        int i, j;
        int nd;
        int t;
        memset(vis, 0, (n + 1) * sizeof(char));
        q.clear();
        
        vis[src] = 1;
        layer[src] = 0;
        q.push(src);
        while (!q.isEmpty()) {
            nd = q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !vis[t = edge[i][DST]]) {
                    vis[t] = 1;
                    layer[t] = layer[nd] + 1;
                    q.push(t);
                }
            }
        }
        return vis[dst];
    }
    
    int getFlow(int nd, int max_flow) {
        if (nd == dst) {
            tot_flow += max_flow;
            return max_flow;
        }
        int i;
        lld tot = 0;
        lld t;
        for (i = now[nd]; i; i = now[nd] = edge[i][NXT]) {
            if (layer[edge[i][DST]] > layer[nd] && edge[i][FLOW]) {
                t = getFlow(edge[i][DST], min(edge[i][FLOW], max_flow - tot));
                edge[i][FLOW] -= t;
                edge[i ^ 1][FLOW] += t;
                tot += t;
                if (tot == max_flow) {
                    break;
                }
            }
        }
        return tot;
    }
    
public:  
    Dinic () {
        e_idx = 1;
    }
    void setSize(int new_size) {
        n = new_size;
    }
    int addEdge(int src, int dst, int flow) {
        e_idx++;
        edge[e_idx][DST] = dst;
        edge[e_idx][FLOW] = flow;
        edge[e_idx][NXT] = head[src];
        head[src] = e_idx;    
    }
    
    void setSrc(int new_src) {
        src = new_src;
    }
    
    void setDst(int new_dst) {
        dst = new_dst;
    }
    
    lld getMaxFlow() {
        while (getLayer()) {
            memcpy(now, head, (n + 1) * sizeof(int));
            while (getFlow(1, INF));
        }
        return tot_flow;
    }    
    
    
    
}dinic;    
    
    
    
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
    
    _Main() {
        int n, m;  
        int i, j;
        int a, b, c;
        long long ans;
        read(m); read(n);
        dinic.setSrc(1);
        dinic.setDst(n);
        dinic.setSize(n);
        for (i = 1; i <= m; i++) {
            read(a); read(b); read(c);
            dinic.addEdge(a, b, c);
            dinic.addEdge(b, a, 0);
        }
        ans = dinic.getMaxFlow();
        printf("%lld", ans);
    }    
    
    
}jsk;



}

