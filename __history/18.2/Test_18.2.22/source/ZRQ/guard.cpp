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
struct link{
    int fr,to,fb,tb;
    link(){}
    link(int x,int y,int xx,int yy):fr(x),to(y),fb(xx),tb(yy){}
};
vector<link> lnk;
int n,a,b,c,tot;
int C[51],id[51][101];
int match[101],inp[101];
int mp[101][101],ban[101];
int dfs(int x)
{
    for(int i=1;i<=tot;i++)
        if(mp[x][i]&&!ban[i]&&!inp[i])
        {
            inp[i]=1;
            if(!match[i]||dfs(match[i]))
            {
                match[i]=x;
                return 1;
            }
        }
    return 0;
}
int solve()
{
    for(int i=0;i<(signed)lnk.size();i++)
        mp[id[lnk[i].fb][lnk[i].fr]][id[lnk[i].tb][lnk[i].to]]=1,
        mp[id[lnk[i].tb][lnk[i].to]][id[lnk[i].fb][lnk[i].fr]]=1;
    int ret=0;
    if(!(n&1))
    {
        ret=tot;
        for(int i=1;i<=n;i++)   if(i&1)
                for(int j=1;j<=C[i];j++)
                {
                    memset(inp,0,sizeof inp);
                    if(dfs(id[i][j])) ret--;
                }
    }
    else
    {
        int ct=0,cnt;
        for(int i=1;i<=n;i++)
            if(C[i]<=10) {ct=i;break;}
        for(int s=0;s<(1<<C[ct]);s++)
        {
            cnt=0;
            memset(ban,0,sizeof ban);
            memset(match,0,sizeof match);
            for(int i=1;i<=C[ct];i++)
            {
                ban[id[ct][i]]=1;
                if((s>>(i-1))&1)
                {
                	++cnt;
                    for(int k=1;k<=tot;k++)
                        if(mp[id[ct][i]][k]) ban[k]=1;
                }
            }
            int ans1=0,ans2=0;
            for(int i=1;i<=tot;i++)
                if(!ban[i]) ++ans1;
            for(int i=1;i<=tot;i++)
                if(!ban[i])
                {
                    memset(inp,0,sizeof inp);
                    if(dfs(i)) ans2++;
                }
            ret=max(ret,cnt+ans1-ans2/2);
        }
    }
    return ret;
}
int main()
{
	freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    scanf("%d",&n);
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        int to=c==n?1:c+1;
        lnk.push_back(link(a,b,c,to));
        C[to]=max(C[to],b);
        C[c]=max(C[c],a);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=C[i];j++)
            id[i][j]=++tot;
    printf("%d\n",solve());
}
