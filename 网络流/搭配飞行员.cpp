using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>

namespace Protector {
const int 
    DST = 0,
    NXT = 1,
    FLOW = 2,
    MAXN = 110,
    MAXE = 500
;
int src, dst, size;

class Dinic {
public:
    int now[MAXN],
        head[MAXN],
        edge[MAXN][3],
        layer[MAXN],
        eidx,
        tot_flow
    ;
    Dinic() {
        eidx = 1;
    }
    void add(int src, int dst, int flow) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][FLOW] = flow;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
    
    
}dinic;



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
    
    
}

