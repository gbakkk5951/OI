#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
using namespace std;
bool vis[200001];
int dis[200001];
//解释一下各数组的含义：
///vis两个用处：spfa里的访问标记，増广时候的访问标记，
//dis是每个点的距离标号
int n, m, src, dst, tot_cost = 0;
int tot_flow;
int eidx = -1, obj[200001], flow[200001], cost[200001], next[200001], head[200001];

inline void addedge(int x, int y, int z, int zz) {
    obj[++eidx] = y;
    flow[eidx] = z;
    cost[eidx] = zz;
    next[eidx] = head[x];
    head[x] = eidx;
}

inline bool spfa(int src, int dst) {
    memset(vis, 0, sizeof vis);
    memset(dis, 63, (n + 1) * sizeof(int));
    dis[dst] = 0;
    vis[dst] = 1;
//首先SPFA我们维护距离标号的时候要倒着跑，
//这样可以维护出到终点的最短路径
    queue<int>q;
    q.push_back(dst);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int k = head[now]; k > -1; k = next[k]) {
            if (flow[k ^ 1] && dis[obj[k]] > dis[now] - cost[k]) {
                //首先flow[k^1]是为什么呢，
                //因为我们要保证正流，但是SPFA是倒着跑的，
                //所以说我们要求flow[k]的对应反向边是正的，
                //这样保证走的方向是正确的
                dis[obj[k]] = dis[now] - cost[k];
                //因为已经是倒着的了，
                ///我们也可以很清楚明白地知道建边的时候反向边的边权是负的，
                //所以减一下就对了（负负得正）
                if(!vis[obj[k]]) {
                    vis[obj[k]] = 1;
                    q.push_back(obj[k]);
                }
            }
        }
    }
    return dis[src] < 1e9;
//判断起点终点是否连通
}
inline int dfs(int nd, int mx_flow) {
//这里就是进行増广了
    if(nd == dst) {
        vis[dst] = 1;
        return mx_flow;
    }
    int used = 0, a;
    vis[nd] = 1;
//这边是不是和dinic很像啊
    int k;
    for (k = head[nd]; k > -1; k = next[k]) {
        if(!vis[obj[k]] && flow[k] && dis[nd] - cost[k] == dis[obj[k]]) {
            //这个条件就表示这条边可以进行増广
            a = dfs(obj[k], min(flow[k], mx_flow-used));
            if(a) {
                tot_cost += a*cost[k];
                flow[k] -= a;
                flow[k ^ 1] += a;
                used += a;
            }
            //累加答案，加流等操作都在这了
            if (use == mx_flow) {
                break;
            }
        }
    }
    return use;
}
inline int costflow() {
    while(spfa(src, dst)) {
        vis[dst] = 1;
        while(vis[dst]) {
            memset(vis, 0, sizeof vis);
            tot_flow += dfs(src, 1e9);
        }
    }
    return tot_flow;
}
int main()
 {
    memset(next, -1, sizeof next);
    memset(head, -1, sizeof head);
    scanf("%d%d%d%d", &n, &m, &src, &dst);
    for(int i = 1; i <= m; i++) {
        int src, dst, flow, cost;
        scanf("%d%d%d%d", &src, &dst, &flow, &cost);
        addedge(src, dst, flow, cost);
        addedge(dst, src, 0, -cost);
    }
    costflow();
    return 0;
}
