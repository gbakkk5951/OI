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
//����һ�¸�����ĺ��壺
///vis�����ô���spfa��ķ��ʱ�ǣ�����ʱ��ķ��ʱ�ǣ�
//dis��ÿ����ľ�����
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
//����SPFA����ά�������ŵ�ʱ��Ҫ�����ܣ�
//��������ά�������յ�����·��
    queue<int>q;
    q.push_back(dst);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int k = head[now]; k > -1; k = next[k]) {
            if (flow[k ^ 1] && dis[obj[k]] > dis[now] - cost[k]) {
                //����flow[k^1]��Ϊʲô�أ�
                //��Ϊ����Ҫ��֤����������SPFA�ǵ����ܵģ�
                //����˵����Ҫ��flow[k]�Ķ�Ӧ����������ģ�
                //������֤�ߵķ�������ȷ��
                dis[obj[k]] = dis[now] - cost[k];
                //��Ϊ�Ѿ��ǵ��ŵ��ˣ�
                ///����Ҳ���Ժ�������׵�֪�����ߵ�ʱ����ߵı�Ȩ�Ǹ��ģ�
                //���Լ�һ�¾Ͷ��ˣ�����������
                if(!vis[obj[k]]) {
                    vis[obj[k]] = 1;
                    q.push_back(obj[k]);
                }
            }
        }
    }
    return dis[src] < 1e9;
//�ж�����յ��Ƿ���ͨ
}
inline int dfs(int nd, int mx_flow) {
//������ǽ��Љ�����
    if(nd == dst) {
        vis[dst] = 1;
        return mx_flow;
    }
    int used = 0, a;
    vis[nd] = 1;
//����ǲ��Ǻ�dinic����
    int k;
    for (k = head[nd]; k > -1; k = next[k]) {
        if(!vis[obj[k]] && flow[k] && dis[nd] - cost[k] == dis[obj[k]]) {
            //��������ͱ�ʾ�����߿��Խ��Љ���
            a = dfs(obj[k], min(flow[k], mx_flow-used));
            if(a) {
                tot_cost += a*cost[k];
                flow[k] -= a;
                flow[k ^ 1] += a;
                used += a;
            }
            //�ۼӴ𰸣������Ȳ�����������
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
