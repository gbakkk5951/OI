using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>
namespace Protector {
    
const char SUCCESS[] = "^_^";
const char FAIL[] = "T_T";
const int DST = 0;
const int FLOW = 1;
const int NXT = 2;

queue<int> q;

class Dinic {
private:
    
    int edge[2100000][3];
    int head[2020];
    int now[2020];
    int layer[2020];
    
    char vis[2020];
    int e_idx;
    int cnt;
    int src, dst;
    char getFlow(int nd) {
        if (nd == dst) {
            cnt++;
            return 1;
        }
        int i;
        int t = 0;
        for ( ; i = now[nd]; now[nd] = edge[i][NXT]) {
            if (layer[t = edge[i][DST]] > layer[nd] && edge[i][FLOW]) {
                t = getFlow(t);
                if (t) {
                    edge[i][FLOW] ^= t;
                    edge[i ^ 1][FLOW] ^= t;                    
                    return 1;
                }
            }
        }
        return 0;
        
    }
    char getLayer() {
        memset(vis, 0, sizeof(vis));
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
public:
    Dinic() {
        e_idx = 1;
    }
    void clear() {
        memset(this, 0, sizeof(Dinic));
        e_idx = 1;
    }   
    void run() {
        while (getLayer()) {
            memcpy(now, head, sizeof(head));
            while (getFlow(src));
        }
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
    int getAns() {
        return cnt;
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
    char in_com[1010];
    char is_com[1010];
    char know;
    int new_id[1010];
    int chair;
    int new_n;
    _Main() {
        int T;
        int n;
        int i, j, k;
        int a, b, c;
        int src, dst;
        read(T);
        
        while (T--) {
            memset(this, 0, sizeof(_Main));
            dinic.clear();
            read(n);
            for (i = 1; i <= n; i++) {
                read(is_com[i]);
                if (is_com[i]) {
                    chair++;
                }
            }
            for (i = 1; i <= n; i++) {
                read(in_com[i]);
                if (is_com[i]) {
                    in_com[i] ^= 1;
                } else{
                    in_com[i] = 1;
                }
                if (in_com[i]) {
                    new_id[i] = ++new_n;
                }
            }
            
            
            dinic.setSrc(src = 0);
            dinic.setDst(dst = n + new_n + 1);
            
            for (i = 1; i <= n; i++) {
                if (in_com[i]) {
                    dinic.add(0, new_id[i], 1);
                    dinic.add(new_id[i], 0, 0);
                }
                for (j = 1; j <= n; j++) {
                    read(know);
                    if ((know || i == j) && in_com[i] && is_com[j]) {
                        dinic.add(new_id[i], new_n + j, 1);
                        dinic.add(new_n + j, new_id[i], 0);
                    }
                }
                if (is_com[i]) {
                    dinic.add(new_n + i, dst, 1);
                    dinic.add(dst, new_n + i, 0);
                }
            }
            if (new_n > chair) {
                printf("%s\n", FAIL);
                continue;
            }
            dinic.run();
            if (dinic.getAns() < new_n) {
                printf("%s\n", FAIL);
            } else {
                printf("%s\n", SUCCESS);
            }
            
        }
    }
    
}jsk;

}
//神TM 0表示在， 1表示不在 
