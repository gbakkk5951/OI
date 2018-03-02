#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN=210;
const int MAXM=1E5+5;
int out[MAXN];
struct Graph{
    struct node{
        int nxt,v;
    }Edge[MAXM];
    int head[MAXN],cnt_e;
    inline void add(int u,int v,bool flag)
    {
        Edge[++cnt_e].v=v;
        Edge[cnt_e].nxt=head[u];
        head[u]=cnt_e;
        if(flag)  ++out[u];
    }
}G,Gr;
int n,tmp;
int len[MAXN],vis[MAXN];
int stk[MAXN],top;
int solve()
{
    int cnt=0;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!out[i]) ++cnt,len[i]=1,q.push(i);
    if(cnt==0) return 0;
    if(cnt==1)
    {
        while(q.size())
        {
            int x=q.front();
            q.pop();
            for(int i=Gr.head[x];i;i=Gr.Edge[i].nxt)
            {
                int v=Gr.Edge[i].v;
                if(!(--out[v])) q.push(v);
                len[v]=max(len[v],len[x]+1);
            }
        }
        int now=-1;
        for(int i=1;i<=n;i++) if(len[i]==n) {now=i;break;}
        if(now!=-1)
        {
            puts("1");
            while(now)
            {
                int tnow=now;
                printf("%d ",now);
                for(int i=G.head[now];i;i=G.Edge[i].nxt)
                {
                    int v=G.Edge[i].v;
                    if(len[v]==len[now]-1) {now=v;break;}
                }
                if(tnow==now) break;
            }
            puts("");
            return 1;
        }
        else return -1;
    }
    return -1;
}
void dfs(int x)
{
    vis[x]=1;
    stk[++top]=x;
    for(int i=G.head[x];i;i=G.Edge[i].nxt)
    {
        int v=G.Edge[i].v;
        if(!vis[v]) dfs(v);
        if(vis[v]&&top==n) {return;}
    }
    --top;
    vis[x]=0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&tmp);
            if(tmp) G.add(i,j,1),Gr.add(j,i,0);
        }
    int t=solve();
    if(t==-1) {puts("-1");return 0;}
    if(t==1) return 0;
    if(t==0)
    {
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            top=0;
            dfs(i);
            if(top==n)
            {
                puts("0");
                for(int j=1;j<=top;j++)
                    printf("%d ",stk[j]);
                puts("");
                return 0;
            }
        }
        puts("-1");
    }
}
