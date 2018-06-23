#include <stdio.h>
#include <string.h>
#include <queue>
#define M 100010
#define N 1005
const int inf = 0x3f3f3f3f;
using namespace std;
struct E         //邻接表建边，to是下个结点，w 是权值 nxt 是下条边的位置
{
    int to,w,nxt;
}edge[2*M];

struct data    //g 表示起点到当前点的距离，h表终点到当前点的距离
{
    int g,h;
    int to;
    bool operator < (data a) const   //优先队列的排序（其实也不能这么讲） 使g+h小的在队首
    {
        return a.h + a.g < h + g;
    }
};
int e,n,src,des,head[N],tail[N],dis[N];//head 是正向边，tail是逆向边 dis是des（终点）到各点的距离
void addedge (int cu,int cv,int cw)
{
    edge[e].to = cv;
    edge[e].w = cw;
    edge[e].nxt = head[cu];
    head[cu] = e ++;
    edge[e].to = cu;
    edge[e].w = cw;
    edge[e].nxt = tail[cv];
    tail[cv] = e ++;
}

void dij ()          //dijstra算法求des到各点的距离 用于估价函数h
{
    int i,j,k;
    int vis[N];
    memset (vis,0,sizeof(vis));
    memset (dis,0x3f,sizeof(dis));
    dis[des] = 0;
    for (i = 1;i <= n;i ++)
    {
        k = -1;
        int min = inf;
        for (j = 1;j <= n;j ++)
            if (!vis[j]&&min > dis[j])
            {
                k = j;
                min = dis[j];
            }
       // if (k == -1)      //因为这里图肯定是连通的 可加可不加
       //     break;
        vis[k] = 1;
        for (int u = tail[k];u != -1;u = edge[u].nxt)
        {
            int v;
            v = edge[u].to;
            if (!vis[v]&&dis[v] > dis[k] + edge[u].w)
                dis[v] = dis[k] + edge[u].w;
        }
    }
}

int Astar (int k)    //A*算法求第k短路
{
    int cnt[N];
    data cur,nxt;     //当前结点 下个结点
    priority_queue <data> node;
    memset (cnt,0,sizeof(cnt));
    cur.to = src;             //当前结点初始化 这就不用多说了
    cur.g = 0;
    cur.h = dis[src];
    node.push (cur);
    while (!node.empty())
    {
        cur = node.top ();
        node.pop();
        cnt[cur.to] ++;
        if (cnt[cur.to] > k)//如果当前想拓展的点cnt>k就没必要拓展了
            continue;        //因为这个点已经是求到k+1短路了 从这个点继续往下搜肯定得到的是大于等于k+1短路的路径
        if (cnt[des] == k)  //找到第K短路 返回
            return cur.g;
        for (int u = head[cur.to];u != -1;u = edge[u].nxt)  //相连的点入队列
        {
            int v = edge[u].to;
            nxt.to = v;
            nxt.g = cur.g + edge[u].w;
            nxt.h = dis[v];
            node.push (nxt);
        }
    }
    return -1;
}
int main ()
{
    int m,u,v,w,k;
    while (~scanf ("%d%d",&n,&m))
    {
        e = 0;
        memset (head,-1,sizeof (head));
        memset (tail,-1,sizeof (tail));
        while (m --)
        {
            scanf ("%d%d%d",&u,&v,&w);
            addedge (u,v,w);
        }
        scanf ("%d%d%d",&src,&des,&k);
        if (src == des)     //起点和终点相同时，k要++
            k ++;
        dij ();
        int ans = Astar (k);
        printf ("%d",ans);
    }
    return 0;
}

