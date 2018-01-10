/* 
ID: CUGB-wwj 
PROG: 
LANG: C++ 
*/  
#include <iostream>  
#include <vector>  
#include <list>  
#include <map>  
#include <set>  
#include <deque>  
#include <queue>  
#include <stack>  
#include <bitset>  
#include <algorithm>  
#include <functional>  
#include <numeric>  
#include <utility>  
#include <sstream>  
#include <iomanip>  
#include <cstdio>  
#include <cmath>  
#include <cstdlib>  
#include <cctype>  
#include <string>  
#include <cstring>  
#include <cmath>  
#include <ctime>  
#define INF 2000000000  
#define MAXN 105  
#define MAXM 1005  
#define L(x) x<<1  
#define R(x) x<<1|1  
#define eps 1e-4  
using namespace std;  
typedef double type;  
struct Point  
{  
    double x, y;  
}p[MAXN];  
struct node  
{  
    int u, v;  
    type w;  
}edge[MAXN * MAXN];  
int pre[MAXN], id[MAXN], vis[MAXN], n, m;  
type in[MAXN];  
double dis(Point a, Point b)  
{  
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));  
}  
type Directed_MST(int root, int V, int E)  
{  
    type ret = 0;  
    while(true)  
    {  
        //1.����С���  
        for(int i = 0; i < V; i++) in[i] = INF;  
        for(int i = 0; i < E; i++)  
        {  
            int u = edge[i].u;  
            int v = edge[i].v;  
            if(edge[i].w < in[v] && u != v) {pre[v] = u; in[v] = edge[i].w;}  
        }  
        for(int i = 0; i < V; i++)  
        {  
            if(i == root) continue;  
            if(in[i] == INF) return -1;//���˸������е�û�����,����޷�������  
        }  
        //2.�һ�  
        int cnt = 0;  
        memset(id, -1, sizeof(id));  
        memset(vis, -1, sizeof(vis));  
        in[root] = 0;  
        for(int i = 0; i < V; i++) //���ÿ����  
        {  
            ret += in[i];  
            int v = i;  
            while(vis[v] != i && id[v] == -1 && v != root)  //ÿ����Ѱ����ǰ��㣬Ҫô����Ѱ����������Ҫô�ҵ�һ����  
            {  
                vis[v] = i;  
                v = pre[v];  
            }  
            if(v != root && id[v] == -1)//����  
            {  
                for(int u = pre[v]; u != v; u = pre[u]) id[u] = cnt;  
                id[v] = cnt++;  
            }  
        }  
        if(cnt == 0) break; //�޻�   ��break  
        for(int i = 0; i < V; i++)  
            if(id[i] == -1) id[i] = cnt++;  
              //3.������ͼ  
        for(int i = 0; i < E; i++)  
        {  
            int u = edge[i].u;  
            int v = edge[i].v;  
            edge[i].u = id[u];  
            edge[i].v = id[v];  
            if(id[u] != id[v]) edge[i].w -= in[v];  
        }  
        V = cnt;  
        root = id[root];  
    }  
    return ret;  
}  
int main()  
{  
    while(scanf("%d%d", &n, &m) != EOF)  
    {  
        for(int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);  
        for(int i = 0; i < m; i++)  
        {  
            scanf("%d%d", &edge[i].u, &edge[i].v);  
            edge[i].u--;  
            edge[i].v--;  
            if(edge[i].u != edge[i].v) edge[i].w = dis(p[edge[i].u], p[edge[i].v]);  
            else edge[i].w = INF; //ȥ���Ի�  
        }  
        type ans = Directed_MST(0, n, m);  
        if(ans == -1) printf("poor snoopy\n");  
        else printf("%.2f\n", ans);  
    }  
    return 0;  
}  
