    #include<bits/stdc++.h>  
    using namespace std;  
    const int MAXP = 505;  
    const int INF = 1e9;  
    template <typename T> void read(T &x) {  
        int f = 1; x = 0;  
        char ch = getchar();  
        for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;  
        for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';  
        x *= f;  
    }  
    struct edge {int dest, flow; unsigned home; };  
    int T, C;  
    int n, m, s, t, tot, flow;  
    int goal[MAXP];  
    int dist[MAXP];  
    int ans[MAXP], bns[MAXP];  
    vector <edge> a[MAXP];  
    vector <int> b[MAXP][MAXP];  
    unsigned sz[MAXP], curr[MAXP];  
    int dinic(int pos, int limit) {  
        if (pos == t) return limit;  
        int used = 0, tmp;  
        for (unsigned &i = curr[pos]; i < a[pos].size(); i++)  
            if (a[pos][i].flow && dist[pos] + 1 == dist[a[pos][i].dest] && (tmp = dinic(a[pos][i].dest, min(limit - used, a[pos][i].flow)))) {  
                used += tmp;  
                a[pos][i].flow -= tmp;  
                a[a[pos][i].dest][a[pos][i].home].flow += tmp;  
                if (used == limit) return used;  
            }  
        return used;  
    }  
    bool bfs() {  
        static int q[MAXP], l = 0, r = -1;  
        for (int i = 0; i <= r; i++)  
            dist[q[i]] = 0;  
        q[l = r = 0] = s, dist[s] = 1;  
        while (l <= r) {  
            int tmp = q[l++];  
            for (unsigned i = 0; i < a[tmp].size(); i++)  
                if (a[tmp][i].flow && dist[a[tmp][i].dest] == 0) {  
                    q[++r] = a[tmp][i].dest;  
                    dist[a[tmp][i].dest] = dist[tmp] + 1;  
                }  
        }  
        return dist[t] != 0;  
    }  
    void packup() {  
        for (int i = 1; i <= tot; i++)  
            sz[i] = a[i].size();  
    }  
    void restore() {  
        for (int i = 1; i <= tot; i++)  
            a[i].resize(sz[i]);  
    }  
    void addedge(int s, int t, int flow) {  
        a[s].push_back((edge) {t, flow, a[t].size()});  
        a[t].push_back((edge) {s, 0, a[s].size() - 1});  
    }  
    int main() {  
        read(T), read(C);  
        while (T--) {  
            while (tot) {  
                a[tot].clear();  
                tot--;  
            }  
            s = ++tot;  
            read(n), read(m);  
            for (int i = 1; i <= n; i++)  
                addedge(s, ++tot, 1);  
            t = n + m + 2;  
            for (int i = 1; i <= m; i++) {  
                int x; read(x);  
                addedge(++tot, t, x);  
            }  
            ++tot;  
            for (int i = 1; i <= n; i++)  
            for (int j = 1; j <= m; j++) {  
                int x; read(x);  
                if (x != 0) b[i][x].push_back(j);  
            }  
            for (int i = 1; i <= n; i++)  
                read(goal[i]);  
            for (int i = 1; i <= n; i++)  
                ans[i] = m + 1;  
            memset(bns, -1, sizeof(bns));  
            packup();  
            for (int j = 1; j <= n; j++) {  
                if (bns[j] != -1) continue;  
                for (int val = 1; val <= goal[j]; val++)  
                for (unsigned k = 0; k < b[j][val].size(); k++)  
                    addedge(j + 1, n + 1 + b[j][val][k], 1);  
                if (!bfs()) bns[j] = j;  
                restore();  
            }  
            for (int i = 1; i <= n; i++) {  
                packup();  
                for (int j = 1; j <= m; j++) {  
                    for (unsigned k = 0; k < b[i][j].size(); k++)  
                        addedge(i + 1, n + 1 + b[i][j][k], 1);  
                    if (bfs()) {  
                        ans[i] = j;  
                        memset(curr, 0, sizeof(curr));  
                        flow += dinic(s, INF);  
                        break;  
                    } else restore();  
                }  
                if (bns[i] == -1) {  
                    if (ans[i] <= goal[i]) bns[i] = 0;  
                    else bns[i] = 1;  
                }  
                packup();  
                for (int j = i + 1; j <= n; j++) {  
                    if (bns[j] != -1) continue;  
                    for (int val = 1; val <= goal[j]; val++)  
                    for (unsigned k = 0; k < b[j][val].size(); k++)  
                        addedge(j + 1, n + 1 + b[j][val][k], 1);  
                    if (!bfs()) bns[j] = j - i;  
                    restore();  
                }  
            }  
            for (int i = 1; i <= n; i++)  
                printf("%d ", ans[i]);  
            printf("\n");  
            for (int i = 1; i <= n; i++)  
                printf("%d ", bns[i]);  
            printf("\n");  
            for (int i = 1; i <= n; i++)  
            for (int j = 1; j <= m; j++)  
                b[i][j].clear();  
        }  
        return 0;  
    }   
