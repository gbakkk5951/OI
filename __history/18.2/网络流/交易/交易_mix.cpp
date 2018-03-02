using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>

namespace OI {
const int 
    MAXN = 150,
    MAXE = 20010,
    DST = 0,
    FLOW = 2,
    NXT = 1,
    INF = 0x3f3f3f3f
    ;
    


int src, dst, size;



  
struct Edge {  
    int from, to, cap, flow;  
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}  
};  
  
struct EdmondsKarp {  
    int n, m;  
    vector < Edge > edges;  
    vector < int > G[MAXN];  
    int a[MAXN];  
    int p[MAXN];  
  
    void add(int from, int to, int cap) {  
        edges.push_back(Edge(from, to, cap, 0));  
        edges.push_back(Edge(to, from, 0, 0));  
        m = edges.size();  
        G[from].push_back(m - 2);  
        G[to].push_back(m - 1);  
    }  
  
    int Maxflow(int s, int t) {  
        int flow = 0;  
  
        for(;;) {  
            memset(a, 0, sizeof a);  
            queue < int > Q;  
            Q.push(s);  
            a[s] = INF;  
  
            while(!Q.empty()) {  
                int x = Q.front();  
                Q.pop();  
  
                for(int i = 0; i < G[x].size(); ++i) {  
                    Edge& e = edges[G[x][i]];  
  
                    if(!a[e.to] && e.cap > e.flow) {  
                        p[e.to] = G[x][i];  
                        a[e.to] = min(a[x], e.cap - e.flow);  
                        Q.push(e.to);  
                    }  
                }  
  
                if(a[t]) {  
                    break;  
                }  
            }  
  
            if(!a[t]) {  
                break;  
            }  
  
            for(int u = t; u != s; u = edges[p[u]].from) {  
                edges[p[u]].flow += a[t];  
                edges[p[u] ^ 1].flow -= a[t];  
            }  
  
            flow += a[t];  
        }  
  
        return flow;  
    }  
} ek;  


struct _Main{
   
    char vis[MAXN];
    
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
    int node_idx;
    int node() {
        return node_idx++;
    }
    int pigs[1005];
    int fa[1005];
    _Main() {
        freopen("data0.in", "r", stdin);
        int i, j, k;
        int n, m;
        int buys;
        int buy_id;
        int a, b, c;
        int fa;
        src = node();
        dst = node();
        read(n); read(m);
        for (i = 1; i <= n; i++) {
            read(pigs[i]);
        }
        for (i = 1; i <= m; i++) {
            buy_id = node();
            read(a);
            for (j = 1; j <= a; j++) {
                read(b);
                if (!vis[fa = this->fa[b]]) {
                    if (fa == 0) {
                        fa = src;
                        c = pigs[b];
                    } else {
                        vis[fa] = 1;
                        c = INF;
                    }
                    ek.add(fa, buy_id, c);
                }
                this->fa[b] = buy_id;
            }
            memset(vis, 0, node_idx * sizeof(char));
            read(buys);
            ek.add(buy_id, dst, buys);
        }
//        cerr<<dinic.eidx<<endl;
        size = node_idx;
        printf("%d", ek.Maxflow(src, dst));
    }
    
}jsk;



}
