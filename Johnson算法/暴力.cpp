using namespace std;
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>

const int 
    MAXN = 1005,
    MAXE = 5005,
    DST = 0,
    NXT = 1,
    DIS = 2,
    MAXDIS = 1000050
;
int head[MAXN];
int edge[MAXE][3];
int label[1005];
int n, m;
char in_q[MAXN];
int cnt[MAXN];
int getLabel() {
        int i;
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
        return 1;
    }

int dis[1005][1005];
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
template<typename Type>
    void signed_read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '-') {
                f = -1;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        a *= f;
    }   
    
    int ok() {
        int i;
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
        return 1;
    }    
    int eidx;
    void add(int src, int dst, int dis) {
        eidx++;
        edge[eidx][DST] = dst;
        edge[eidx][DIS] = dis;
        edge[eidx][NXT] = head[src];
        head[src] = eidx;
    }    
int main() {
    
    int i, j, k;
    int a, b, c;
    memset(dis, 63, sizeof(dis));
    read(n); read(m);
    for (i = 1; i <= m; i++) {
        read(a); read(b); signed_read(c);
        dis[a][b] = min(dis[a][b], c);
        add(a, b, c);
    }
    if (!ok()) {
        printf("-1");
        return 0;
    }
    for (i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (k = 1; k <= n; k++) {
        for (j = 1; j <= n; j++) {
            for (i = 1; i <= n; i++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", min(dis[i][j], MAXDIS));
        }
        printf("\n");
    }
}
