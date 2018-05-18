#include<cstdio>
#include<algorithm>
using namespace std;const int N=1e5+10;
int n;int m;int dfn[N];int nfd[N];int siz[N];int df;int f[N][22];
int v[2*N];int x[2*N];int al[N];int ct;int dep[N];int h[N];
struct splaytree
{
    int s[N][2];int fa[N];
    inline int gc(int x){return s[fa[x]][1] == x;}
    inline void rt(int x)
    {
        int d=fa[x];int t=gc(x);
        s[d][t]=s[x][t^1];fa[s[x][t^1]]=d;
        s[fa[d]][gc(d)]=x;fa[x]=fa[d];
        s[x][t^1]=d;fa[d]=x;
    }
    inline void rtup(int x){rt((gc(x)^gc(fa[x]))?x:fa[x]);rt(x);}
    inline void splay(int x){for(;fa[fa[x]]&&fa[x];rtup(x));if(fa[x])rt(x);}
    inline int mi(int x){for(;s[x][0];x=s[x][0]);return x;}
    inline int getmi(int x){splay(x);return mi(x);}
    inline void split(int x){splay(x);fa[s[x][1]]=0;s[x][1]=0;}
    inline void merge(int x, int y){splay(y);s[x][0]=y;fa[y]=x;}
}spt;
struct linetree
{
    int add[4*N];int ma[4*N];
    inline void pushdown(int p)
    {
        add[p<<1]+=add[p];add[p<<1|1]+=add[p];
        ma[p<<1]+=add[p];ma[p<<1|1]+=add[p];add[p]=0;
    }
    inline void setadd(int p, int l, int r, int dl, int dr, int plus)
    {
        if(dl == l&&dr == r){add[p]+=plus;ma[p]+=plus;return;}
        int mid=(l+r)/2;pushdown(p);
        if(dl<mid){setadd(p<<1, l, mid, dl, min(dr, mid), plus);}
        if(mid<dr){setadd(p<<1|1, mid, r, max(dl, mid), dr, plus);}
        ma[p]=max(ma[p<<1], ma[p<<1|1]);
    }
    inline int gmax(int p, int l, int r, int dl, int dr)
    {
        if(dl == l&&dr == r){return ma[p];}
        int mid=(l+r)/2;pushdown(p);int res=-0x3f3f3f3f;
        if(dl<mid){res=max(res, gmax(p<<1, l, mid, dl, min(dr, mid)));}
        if(mid<dr){res=max(res, gmax(p<<1|1, mid, r, max(dl, mid), dr));}
        return res;
    }
    inline void build(int p, int l, int r)
    {
        if(r-l == 1){ma[p]=dep[dfn[r]];return;}int mid=(l+r)/2;
        build(p<<1, l, mid);build(p<<1|1, mid, r);ma[p]=max(ma[p<<1], ma[p<<1|1]);
    }
}lt;
inline void add(int u, int V){v[++ct]=V;x[ct]=al[u];al[u]=ct;}
inline void dfs(int u)
{
    siz[u]=1;dfn[++df]=u;nfd[u]=df;
    for(int i=0;f[u][i];i++){f[u][i+1]=f[f[u][i]][i];}
    for(int i=al[u];i;i=x[i])
    {   
        if(siz[v[i]]){continue;}
        f[v[i]][0]=u;dep[v[i]]=dep[u]+1;dfs(v[i]);siz[u]+=siz[v[i]];
    }   
}
inline int lca(int u, int v)
{
    if(dep[u]<dep[v]){swap(u, v);}int d=dep[u]-dep[v];
    for(int i=0;d;d>>=1, i++){if(d&1){u=f[u][i];}if(u == v){return v;}}
    for(int i=20;i>=0;i--){if(f[u][i]!=f[v][i]){u=f[u][i];v=f[v][i];}}
    return f[u][0];
}
inline void modify(int u)
{
    if(h[u]){lt.setadd(1, 0, n, nfd[h[u]]-1, nfd[h[u]]+siz[h[u]]-1, 1);spt.split(u);h[u]=0;}
    for(u=spt.getmi(u);u!=1;u=spt.mi(f[u][0]))
    {
        int& d=f[u][0];
        if(h[d]){lt.setadd(1, 0, n, nfd[h[d]]-1, nfd[h[d]]+siz[h[d]]-1, 1);spt.split(d);}
        lt.setadd(1, 0, n, nfd[u]-1, nfd[u]+siz[u]-1, -1);spt.merge(u, d);h[d]=u;
    }
}
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("run.out", "w", stdout);
    scanf("%d%d", &n, &m);int tp;int u;int v;
    for(int i=1;i<n;i++){scanf("%d%d", &u, &v);add(u, v);add(v, u);}
    dfs(1);lt.build(1, 0, n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d", &tp, &u);
        if(tp == 1){modify(u);}
        else if(tp == 2)
        {
            scanf("%d", &v);int l=lca(u, v);
            int du=lt.gmax(1, 0, n, nfd[u]-1, nfd[u]);
            int dv=lt.gmax(1, 0, n, nfd[v]-1, nfd[v]);
            int dl=lt.gmax(1, 0, n, nfd[l]-1, nfd[l]);
            printf("%d\n", du+dv-2*dl+1);
        }else {printf("%d\n", lt.gmax(1, 0, n, nfd[u]-1, nfd[u]+siz[u]-1)+1);}
    }/*fclose(stdin);fclose(stdout);*/return 0;
}
