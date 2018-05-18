#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXINT = ~0U >> 1;

int n, m, base, tot_cost = 0;
bool vis[550];
struct Edge
{
    int dst, cost, flow;
    Edge *next, *pair;
    
    Edge() {
    
    }
    
    Edge(int t_, int c_, int u_, Edge* next_) {
        dst = t_;
        cost = c_;
        flow = u_;
        next = next_;
    }
    
    void* operator new(size_t, void* p) {
        return p;
    }
} *edge[550];

int augment(int nd, int mx_flow)
{
    if(nd == n) {
        tot_cost += base * mx_flow;
        return mx_flow;
    }
    vis[nd] = true;
    int rem = mx_flow, t;
    for(Edge *i = edge[nd]; i; i = i->next) {
        if(i->flow && !i->cost && !vis[i->dst])
        {
            t = augment(i->dst, min(i->flow, rem));
            if (t) {
                i->flow -= t;
                i->pair->flow += t;
                rem -= t;
                if(!rem) {
                    return mx_flow;
                }
            }
        }
    }
    return mx_flow - rem;
}

bool getLabel()
{
    int delta = MAXINT;
    for(int i = 1; i <= n; ++i) {
        if (vis[i]) {
            for (Edge *j = edge[i]; j; j = j->next) {
                if (j->flow && !vis[j->dst]) {
                    delta = min(j->cost, delta);            
                }
            }
        }
    }
    if(delta == MAXINT) {
        return false;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            for(Edge *j = edge[i]; j; j = j->next) {
                j->cost -= delta;
                j->pair->cost += delta;      
            }
        }
    }
    base += delta;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    Edge *pool = new Edge[m + m];
    while (m--) {
        int src, dst, cost, flow;
        scanf("%d%d%d%d", &src, &dst, &flow, &cost);
        edge[src] = new(pool++)Edge(dst,  cost, flow, edge[src]);
        edge[dst] = new(pool++)Edge(src, -cost, 0, edge[dst]);
        edge[src]->pair = edge[dst];
        edge[dst]->pair = edge[src];
    }
    do {
        do {
            memset(vis, 0, sizeof(vis));
        } while (augment(1, MAXINT));
    } while (getLabel());
    printf("%d\n", tot_cost);
    return 0;
}
