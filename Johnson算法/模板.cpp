using namespace std;
int main() {}

#include <queue> 
#include <cstdio>
#include <cctype>
#include <ctime>
#include <functional>
#include <vector>
#include <cstring>
#include <iostream>

const int 
    MAXN = 1005,
    MAXE = 5005,
    DST = 0,
    NXT = 1,
    DIS = 2,
    MAXDIS = 1000050
;
int got_negative;

int head[MAXN];
int edge[MAXE][3];
struct Edge{
    int dst, val;
    bool operator > (const Edge &b) const {
        return val > b.val;
    }
};

class Heap {
private:
    Edge node[MAXE];
    int n;
private:
    void swim(int nd) {
        while (nd >> 1 && node[nd >> 1] > node[nd]) {
            swap(node[nd], node[nd >> 1]);
            nd >>= 1;
        }
    }
    void sink(int nd) {
        int chose;
        while (1) {
            chose = 0;
            if (nd << 1 <= n) {
                chose = nd << 1;
                if ( (nd << 1 | 1) <= n && node[chose] > node[nd << 1 | 1] ) {
                    chose |= 1;
                }
            }
            if (chose && node[nd] > node[chose]) {
                swap(node[nd], node[chose]);
                nd = chose;
            } else {
                return;
            }
        }
         
    }
public:    
    int empty() {
        return n == 0;
    }
    void push(const Edge &a) {
        node[++n] = a;
        swim(n);
    }
    const Edge & top() {
        return node[1];
    }
    void pop() {
        swap(node[1], node[n]);
        n--;
        sink(1);
    }
    
}heap;

int eidx;
struct _Main {

template<typename Type>
    void read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '-') {
                f = -1;
                got_negative = 1;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        a *= f;
    }   
    char in_q[MAXN];
    int cnt[MAXN];
    int label[1005];
    int dis[1005][1005];
    int n, size, m;
    int getLabel() {
        
        int i, j;
        int *dis = label;
        queue<int> q;
        for (i = 1; i <= n; i++) {
            dis[i] = 0;
            q.push(i);
            in_q[i] = 1;
            cnt[i] = 1;
        }
        int nd, t;
        while (!q.empty()) {
            nd = q.front();
            in_q[nd] = 0;
            q.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (dis[t = edge[i][DST]] > dis[nd] + edge[i][DIS]) {
                    dis[t] = dis[nd] + edge[i][DIS];
                    cnt[t]++;
                    if (cnt[t] > n + 1) {
                        return 0;
                    }
                    if (!in_q[t]) {
                        in_q[t] = 1;
                        q.push(t);
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = head[i]; j; j = edge[j][NXT]) {
                edge[j][DIS] += label[i] - label[edge[j][DST]];
            }
        }
        return 1;
    }
    
    void dijkstra(int src) {
        memset(dis[src], 63, size * sizeof(int));
        dis[src][src] = 0;
        int i, t, v, nd;
        heap.push((Edge){src, 0});
        while (!heap.empty()) {
            if (heap.top().val > dis[src][nd = heap.top().dst]) {
                heap.pop();
                continue;
            }
            heap.pop();
            for (i = head[nd]; i; i = edge[i][NXT]) {
                if (dis[src][t = edge[i][DST]] > (v = dis[src][nd] + edge[i][DIS])) {
                    dis[src][t] = v;
                    heap.push((Edge){t, v});
                }
            }
        }
        for (i = 1; i <= n; i++) {
            dis[src][i] += label[i] - label[src];
        }
    }
    
    void add(int src, int dst, int dis) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][DIS] = dis;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }
    _Main() {
        freopen("Êý¾Ý0.in", "r", stdin);
        float t_r1, t_r2;
        float t_a, t_b, t_c, t_d;
        int i, j, k;
        int a, b, c;
        t_r1 = clock();
        read(n); read(m);
        size = n + 1;
        for (i = 1; i <= m; i++) {
            read(a); read(b); read(c);
            add(a, b, c);
        }
        t_r2 = clock();
        cerr << "read uses "<<t_r2 - t_r1 <<" ms"<<endl;
        t_a = clock();
        if (!got_negative || getLabel()) {
            t_b = clock();
            for (i = 1; i <= n; i++) {
                dijkstra(i);
            }
            t_c = clock();
            cerr << "label uses "<< t_b - t_a << " ms" <<endl;
            cerr << "dijkstra uses "<< t_c - t_b << " ms" <<endl;
            /*for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    printf("%d ", min(dis[i][j], MAXDIS));
                }
                printf("\n");
            }*/
            t_d = clock();
            cerr << "output uses "<< t_d - t_c<<" ms"<<endl;
        } else {
            printf("-1");
        }
    }
    
}A;

