using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>

namespace Protector {
const int MAXN = 520;
const int MAXE = 7500;
const int DST = 0;
const int FLOW = 2;
const int NXT = 1;

class Dinic {
private:
    queue<int> q;
    int head[MAXN];
    int now[MAXN];
    int layer[MAXN];
    int edge[MAXE][3];
    char vis[MAXN];
    int src, dst;
    int tot_flow;
    int size;
    int e_idx;
    
private:
     
    void inline push(int nd, int nd_layer = 0) {
        q.push(nd);
        vis[nd] = 1;
        layer[nd] = nd_layer;
    }
    
    int getLayer() {
        int i, nd, t;
        memset(vis, 0, size * sizeof(char));
        push(src);
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (edge[i][FLOW] && !vis[t = edge[i][DST]]) {
                    push(t);
                }
            }
        }
        return vis[t];
    }
    
    int getFlow(int nd, int mx_flow) {
        if (nd == dst) {
            tot_flow += mx_flow;
            return mx_flow;
        } 
        int i, t, use = 0;
        for (; i = now[nd]; now[nd] = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t, min(mx_flow - use, edge[i][FLOW]));
                if (t) {
                    edge[i][FLOW] -= t;
                    edge[i ^ 1][FLOW] += t;
                    use += t;
                    if (use == mx_flow) {
                        break;
                    }
                }
            }
        }
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
        size = n;
    }
    
    void clear() {
        memset(head, 0, size * sizeof(int));
        e_idx = 1;
        tot_flow = 0;
    }
    
    void add(int src, int dst, int flow) {
        e_idx++;
        edge[e_idx][DST] = dst;
        edge[e_dst][FLOW] = flow;
        edge[e_idx][NXT] = head[src];
        head[src] = e_idx;
    }
    
    void run() {
        while(getLayer()) {
            memcpy(now, head, size * sizeof(int));
            while (getFlow(src));
        }
    }
    
    int getMaxFlow() {
        return tot_flow; 
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
    
    typedef unsigned u;
    typedef long long lld;
    u and_sum;
    u or_sum;
    long long ans;
    char know[505];
    u num[505];
    int head[505];
    int edge[6055][2];
    int id[505];
    int org[505];
    int e_idx;
    int idx;
    void add(int a, int b) {
        e_idx++;
        edge[e_idx][DST] = b;
        edge[e_idx][NXT] = head[a];
        head[a] = e_idx;
    }
    
    _Main() {
        int i, j, k;
        int i;
        int n, m;
        int a, b;
        int t;
        int cst[2];
        u c;
        for (i = 1; i <= m; i++) {
            read(a); read(b);
            add(a, b); read(b, a);
        }
        read(t);
        for (i = 1; i <= t; i++) {
            read(a); read(c);
            know[a] = 1;
            num[a] = c;
        }
        ans_sum = (1 << 31) - 1 | 1 << 31;
        for (i = 1; i <= n; i++) {
            if (know[i]) {
                and_sum & = num[i];
                or_sum |= num[i];
                for (j = head[i]; j; j = edge[j][NXT]) {
                    if (know[t = edge[j][DST]] && t > i) {
                        ans += num[t] ^ num[i];
                    }
                }
            } else {
                id[i] = ++idx;
                org[idx] = i;
            }
        }
        
        for (I = 31; I >= 0; I--) {
            if ((and_sum >> I & 1) == (or_sum >> I & 1) {
                continue;
            }
            for (i = 1; i <= idx; i++) {
                cst[0] = cst[1] = 0;
                for (j = head[org[i]]; j; j =edge[j][NXT]) {
                    if (know[j]) {
                        cst[num[j] >> I & 1 ^ 1]++;
                    } else {
                        dinic.add(i, id[j], 1);
                        dinic.add(id[j], i, 1);
                    }
                }
                for (j = 0; j < 2; j++) {
                    if (cst[j]) {
                        dinic.add()
                        
                    }
                }
            }
            if (I) {
                dinic.clear();
            }
        }
    }
    
    
}jsk;


}
