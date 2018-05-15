#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;const int N=15*1e4+10;typedef long long ll;
int v[2*N];int x[2*N];int ct;int al[N];int val[2*N];bool book[N];bool cut[N];
int siz[N];int w[N];ll dep[N];int tot;int nrt;int miv;ll res;int n;int m;ll A;
struct data//存储节点信息的vector
{
    int val;ll ss;ll sv;
    friend bool operator <(data a,data b){return a.val<b.val;}
};vector <data> ans[N][3];
struct ed{int f;ll dis;int tp;};vector <ed> fa[N];//存储到祖先距离的vector
inline void add(int u,int V,int va){v[++ct]=V;x[ct]=al[u];al[u]=ct;val[ct]=va;}
void dfs1(int u)//寻找siz
{
    book[u]=true;siz[u]=1;
    for(int i=al[u];i;i=x[i]){if(!book[v[i]]&&!cut[v[i]]){dfs1(v[i]);siz[u]+=siz[v[i]];}}
    book[u]=false;
}
void dfs2(int u)//寻找中心
{
    book[u]=true;int mav=tot-siz[u];
    for(int i=al[u];i;i=x[i]){if(!book[v[i]]&&!cut[v[i]]){dfs2(v[i]);mav=max(mav,siz[v[i]]);}}
    book[u]=false;if(miv>mav){miv=mav;nrt=u;}
}
void dfs3(int u,const int& g,const int& t)//处理深度
{
    book[u]=true;fa[u].push_back((ed){g,dep[u],t});
    ans[g][t].push_back((data){w[u],1,dep[u]});
    for(int i=al[u];i;i=x[i]){if(!book[v[i]]&&!cut[v[i]]){dep[v[i]]=dep[u]+val[i];dfs3(v[i],g,t);}}
    book[u]=false;
}
void solve(int u)//点分治构建点分树
{
    dfs1(u);if(siz[u]==1){cut[u]=true;fa[u].push_back((ed){u,0,-1});return;}//边界条件
    tot=siz[u];miv=0x3f3f3f3f;dfs2(u);cut[nrt]=true;fa[nrt].push_back((ed){nrt,0,-1});
    for(int i=al[nrt],t=0;i;i=x[i])
    {
        if(cut[v[i]]){continue;}
        dep[v[i]]=val[i];dfs3(v[i],nrt,t);//预处理vector
        ans[nrt][t].push_back((data){0x3f3f3f3f,0,0});
        sort(ans[nrt][t].begin(),ans[nrt][t].end());//按点权sort
        for(int j=ans[nrt][t].size()-2;j>=0;j--)
        {
            ans[nrt][t][j].ss+=ans[nrt][t][j+1].ss;//处理后缀和
            ans[nrt][t][j].sv+=ans[nrt][t][j+1].sv;
        }t++;
    }for(int i=al[nrt];i;i=x[i]){if(!cut[v[i]]){solve(v[i]);}}//递归点分治
}
inline void query(int l,int r,int u)//暴力跳链，二分出答案
{
    res=0;vector <data>:: iterator L;vector <data>:: iterator R;
    for(int i=fa[u].size()-1;i>=0;i--)
    {
        int f=fa[u][i].f;
        for(int tp=0;tp<=2;tp++)
        {
            if(tp==fa[u][i].tp||ans[f][tp].empty()){continue;}
            L=lower_bound(ans[f][tp].begin(),ans[f][tp].end(),(data){l,0,0});//使用upper和lower_bound可以轻易的二分出一个左闭右开的边界
            R=upper_bound(ans[f][tp].begin(),ans[f][tp].end(),(data){r,0,0});
            res+=fa[u][i].dis*(L->ss-R->ss)+L->sv-R->sv;//处理这个重心的贡献
        }if(l<=w[f]&&w[f]<=r){res+=fa[u][i].dis;}//特判一下这个点到中心的距离
    }
}
int main()
{
    scanf("%d%d%lld",&n,&m,&A);
    for(int i=1;i<=n;i++){scanf("%d",&w[i]);}
    for(int i=1,u,v,c;i<n;i++){scanf("%d%d%d",&u,&v,&c);add(u,v,c);add(v,u,c);}
    solve(1);//点分治
    for(int i=1;i<=m;i++)
    {
        int u;ll l;ll r;scanf("%d%lld%lld",&u,&l,&r);
        /*(l+=res)%=A;(r+=res)%=A;*/if(l>r)swap(l,r);
        query(l,r,u);printf("%lld\n",res);//处理答案
    }return 0;//拜拜程序~
}
