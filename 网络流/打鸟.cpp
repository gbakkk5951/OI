using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>

namespace Protector {

const int MAXE = 85000;
const int DST = 0;
const int FLOW = 1;
const int NXT = 2;
const int MAXN = 20050;
class Dinic {
private:
    char vis[MAXN];
    int head[MAXN];
    int edge[MAXE][3];
    int layer[MAXN];
    int now[MAXN];
    int cnt;
    int e_idx;
    int src, dst;
    int max_idx;
    queue<int> q;

private:
    int getLayer() {
        memset(vis, 0, (max_idx + 1) * sizeof(char));
        q.push(src);
        vis[src] = 1;
        int nd;
        int i;
        int t;
        while (!q.empty()) {
            nd = q.front();
            q.pop();
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
    
    int getFlow(int nd) {
        if (nd == dst) {
            cnt++;
            return 1;
        }
        int i;
        int t;
        for ( ; i = now[nd]; now[nd] = edge[i][NXT]) {
            if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
                t = getFlow(t);
                if (t) {
                    edge[i][FLOW] = 0;
                    edge[i ^ 1][FLOW] = 1;
                    return 1;
                }
            }
        }
        return 0;
    }
    
public:
    

    
Dinic() {
    e_idx = 1; 
    max_idx = 0;
}    
void setMax(int new_max) {
    max_idx = new_max;
}
void add(int src, int dst, int flow) {
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
void run() {
    /*
    if (max_idx == 0 || src == dst) {
        printf("He init");
    }
    */
    while (getLayer()) {
        memcpy(now, head, (max_idx * 1) * sizeof(int));
        while (getFlow(src));
    }
}

int getMaxFlow() {
    return cnt;
}

    
}dinic;



struct _Main {

    
template<typename Type>
    void read(Type & a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        
    }

char vis[20010];
_Main() {
    int map_size, birds;
    int i;
    int a, b;
    int src, dst;
    read(map_size); read(birds);
    dinic.setSrc(src = 0); 
    dinic.setDst(dst = map_size * 2 + 1);
    dinic.setMax(dst);
    
    for (i = 1; i <= birds; i++) {
        read(a); read(b);
        b += map_size;
        if (!vis[a]) {
            vis[a] = 1;
            dinic.add(src, a, 1);
            dinic.add(a, src, 0);
        }
        if (!vis[b]) {
            vis[b] = 1;
            dinic.add(b, dst, 1);
            dinic.add(dst, b, 0);
        }
        dinic.add(a, b, 1);
        dinic.add(b, a, 0);
    }
    dinic.run();
    printf("%d", dinic.getMaxFlow());
    
}




}jsk;


}
// geyLayer
// memset(vis, 0, (max_idx + 1) * sizeof(char)); 
// char Ð´³É int 

