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
#include<cassert>
#include<ctime>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN=1E5+5;
const int MAXM=2E5+5;
struct __edge{
    int nxt,v,w;
}Edge[MAXM];
int head[MAXN],cnt_e,n,u,v,w,du[MAXN],k;
inline void add(int u,int v,int w)
{
    Edge[++cnt_e].v=v;
    Edge[cnt_e].nxt=head[u];
    Edge[cnt_e].w=w;
    head[u]=cnt_e;
}
namespace solve1{
    ll f[MAXN],g[MAXN],ans=-10000000;
    multiset<ll> s[MAXN],q[MAXN];
    inline void insert(int x,ll val)
    {
        if(q[x].size()==3&&val<*q[x].begin()) return;
        q[x].insert(val);
        if(q[x].size()>3) q[x].erase(q[x].begin());
    }
    inline ll get(int x)
    {
        if(q[x].size()<3) return -1;
        ll ret=0;
        for(multiset<ll>::iterator it=q[x].begin();it!=q[x].end();++it)
            ret+=*it;
        return ret;
    }
    void dfs1(int x,int fa)
    {
        q[x].insert(0);
        for(int i=head[x];i;i=Edge[i].nxt)
        {
            int v=Edge[i].v;
            if(v==fa) continue;
            dfs1(v,x);
            insert(x,f[v]+Edge[i].w);
        }
        f[x]=*q[x].rbegin();
    }
    void dfs2(int x,int fa,ll tv,int fav)
    {
        ll tmp=0;
        g[x]=tv+fav;
        s[x].insert(0);
        for(int i=head[x];i;i=Edge[i].nxt)
            if(Edge[i].v!=fa)
                s[x].insert(f[Edge[i].v]+Edge[i].w);
        insert(x,g[x]);
        for(int i=head[x];i;i=Edge[i].nxt)
        {
            int v=Edge[i].v;
            if(v==fa) continue;
            int __ts=s[x].size();
            s[x].erase(s[x].find(f[v]+Edge[i].w));
            if(s[x].size()>0) tmp=*s[x].rbegin();
            else tmp=0;
            dfs2(v,x,max(tv+fav,tmp),Edge[i].w);
            s[x].insert(f[v]+Edge[i].w);
            assert(__ts==s[x].size());
        }
    }
    void solve()
    {
        dfs1(1,0);
        dfs2(1,0,0,-100000);
        for(int i=1;i<=n;i++) if(du[i]>=2) ans=max(ans,get(i));
        printf("%lld",ans*2);
    }
}
namespace solve2{
    ll f[MAXN],g[MAXN],ans;
    void dfs(int x,int fa)
    {
        f[x]=g[x]=0;
        for(int i=head[x];i;i=Edge[i].nxt)
        {
            int v=Edge[i].v;
            if(v==fa) continue;
            dfs(v,x);
            if(f[v]+Edge[i].w>f[x]) g[x]=f[x],f[x]=f[v]+Edge[i].w;
            else g[x]=max(g[x],f[v]+Edge[i].w);
        }
        ans=max(ans,f[x]+g[x]);
    }
    void solve()
    {
        dfs(1,0);
        printf("%lld",ans);
    }
}
int main()
{
    scanf("%*d%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
        du[u]++;du[v]++;
    }
    if(k==2) solve2::solve();
    else solve1::solve();
    #ifdef LOCAL
        system("pause");
    #endif
}

