#include <queue>  
#include <vector>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
  
using namespace std;  
  
const int MAXN = 1000 + 10,  
           INF = 0x3f3f3f3f,  
             s = 0,  
             t = 101;  
  
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
  
    void AddEdge(int from, int to, int cap) {  
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
  
int main(void) {  
    int m, n;  
    cin >> m >> n;  
    int N_pig[MAXN];  
    int last_cus[MAXN];  
    memset(last_cus, 0, sizeof last_cus);  
    for(int i = 1; i <= m; ++i) {  
        cin >> N_pig[i];  
    }  
      
    for(int i = 1; i <= n; ++i) {  
        int N;  
        cin >> N;  
        for(int j = 0; j < N; ++j) {  
            int can_visiting;  
            cin >> can_visiting;  
            if(last_cus[can_visiting] == 0) {  
                ek.AddEdge(s, i, N_pig[can_visiting]);  
            } else {  
                ek.AddEdge(last_cus[can_visiting], i, INF);  
            }  
            last_cus[can_visiting] = i;  
        }  
          
        int wanted;  
        cin >> wanted;  
        ek.AddEdge(i, t, wanted);  
    }  
      
    cout << ek.Maxflow(s, t);  
    return 0;  
}  
