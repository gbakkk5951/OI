#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 10010
#define inf 0x7fffffff
using namespace std;
struct node
{
    int next,to,s;
};
node Edge[N*20];
const int m=5000;
const int T=10000;
int n,ans,s,tot=1;
int head[N];
int h[N],que[N];
bool used[N];
int to[N];

void add(int x,int y,int z)
{
    Edge[++tot].next=head[x];
    Edge[tot].to=y;
    Edge[tot].s=z;
    head[x]=tot;
}

void ins(int x,int y)
{
    add(x,y,1),add(y,x,0);
}

bool bfs()
{
    queue<int>Q;
    memset(h,-1,sizeof(h));
    h[0]=0;
    Q.push(0);
    while(!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        for(int i=head[now];i;i=Edge[i].next)
        {
            if(h[Edge[i].to]==-1&&Edge[i].s)
            {
                h[Edge[i].to]=h[now]+1;
                Q.push(Edge[i].to);
            }
        }
    }
    if(h[T]==-1)return false;
    return true;
}

int dfs(int u,int f)
{
    if(u==T)return f;
    int used=0;
    for(int i=head[u];i;i=Edge[i].next)
    {
        if(!Edge[i].s||h[Edge[i].to]!=h[u]+1)continue;
        int w=f-used;
        w=dfs(Edge[i].to,min(w,Edge[i].s));
        Edge[i].s-=w;
        Edge[i^1].s+=w;
        used+=w;
        if(used==f)return f;
    }
    if(!used)h[u]=-1;
    return used;
}

void dinic()
{
    while(bfs())
        ans-=dfs(0,inf);
}

void getans()
{
    for(int i=1;i<s;i++)
    {
        for(int j=head[i];j;j=Edge[j].next)
        {
            if(Edge[j].s)continue;
            to[i]=Edge[j].to-m;
            break;
        }
    }
    for(int i=1;i<s;i++)
    {
        if(used[i])continue;
        int t=i;
        while(t!=-m)
        {
            printf("%d ",t);
            used[t]=true;
            t=to[t];
        }
        puts("");
    }
}

int main()
{
    cin>>n;
    for(;;)
    {
        ans++,s++;
        for(int i=1;i<s;i++)
            if(sqrt(i+s)==(int)sqrt(i+s))
                ins(i,s+m);
        ins(0,s),ins(s+m,T);
        dinic();
        if(ans>n)break;
    }
    printf("%d\n",s-1);
    getans();
    return 0;
}
