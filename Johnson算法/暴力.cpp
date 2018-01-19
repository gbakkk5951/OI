#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
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
int main() {
    int n, m;
    int i, j, k;
    int a, b, c;
    memset(dis, 63, sizeof(dis));
    read(n); read(m);
    for (i = 1; i <= m; i++) {
        read(a); read(b); signed_read(c);
        dis[a][b] = min(dis[a][b], c);
    }
    for (k = 1; k <= n; k++) {
        for (j = 1; j <= n; j++) {
            for (i = 1; i <= n; i++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
}
