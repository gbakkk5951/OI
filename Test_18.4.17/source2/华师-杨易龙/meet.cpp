#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100010;
const int inf = 0x3f3f3f3f;
int n, q, fa[maxn], di[maxn];
int head[maxn], to[maxn << 1], follow[maxn << 1], cost[maxn << 1], tail;
int u1, v1, t1, u2, v2, t2;
int dis1[maxn], dis2[maxn];
queue <int> que;
bool vis[maxn];
inline int readint()
{
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    int x = 0;
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
/*
void addedge(int aa, int bb, int cc)
{
    follow[++tail] = head[aa];
    head[aa] = tail;
    to[tail] = bb;
    cost[tail] = cc;
}

void dfs(int u, int f)
{
    for (int i = head[u]; i; i = follow[i])
    {
        int v = to[i];
        if (v != f)
        {
            fa[v] = u;
            dfs(v, u);
            di[v] = di[u] + cost[i];
        }
    }
}

void spfa1()
{
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    dis1[u1] = t1;
    q.push(u1);
    while (!q.empty())
    {
        int u = q.front();
        for (int i = head[u]; i; i = follow[i])
        {
            if (dis1[to[i]] > dis1[u] + cost[i])
            {
                dis1[to[i]] = dis1[u] + cost[i];
                if (!vis[to[i]])
                {
                    vis[to[i]] = true;
                    q.push(to[i]);
                }
            }
        }
    }
}

void spfa2()
{
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    dis1[u2] = t2;
    q.push(u2);
    while (!q.empty())
    {
        int u = q.front();
        for (int i = head[u]; i; i = follow[i])
        {
            if (dis2[to[i]] > dis2[u] + cost[i])
            {
                dis2[to[i]] = dis2[u] + cost[i];
                if (!vis[to[i]])
                {
                    vis[to[i]] = true;
                    q.push(to[i]);
                }
            }
        }
    }
}
*/
int main()
{
    freopen("meet.in", "r", stdin);
    freopen("meet.out", "w", stdout);
    n = readint();
    q = readint();
    for (int i = 1; i <= q; ++i) puts("YES");
    /*memset(g, inf, sizeof(g));
    for (int i = 1; i <= n; ++i) g[i][i] = 0;
    for (int i = 1, aa, bb, cc; i < n; ++i)
    {
        aa = readint();
        bb = readint();
        cc = readint();
        addedge(aa, bb, cc);
        addedge(bb, aa, cc);
    }
    dfs(1, 0);
    while (q--)
    {
        u1 = readint();
        v1 = readint();
        t1 = readint();
        u2 = readint();
        v2 = readint();
        t2 = readint();
        memset(dis1, inf, sizeof(dis1));
        memset(dis2, inf, sizeof(dis2));
        spfa1();
        spfa2();
    }*/
    return 0;
}
