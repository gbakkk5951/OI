#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dfn[220],low[220],belong[220],first[220],st[220],rd[220];
int line[220],num[220],dat[220][220];
int s[40400],e[40400],nxt[40400];
int n,t,ans,cnt,top,l,r,group;
bool inst[220],boo[220],workout;

void tarjan(int k)
{
     dfn[k]=++cnt;
     low[k]=cnt;
     st[++top]=k;inst[k]=true;
     int tt=top;
     for (int p=first[k];p;p=nxt[p])
         if (!dfn[e[p]])
         {
            tarjan(e[p]);
            low[k]=min(low[k],low[e[p]]);
         }
         else if (inst[e[p]]) low[k]=min(low[k],low[e[p]]);
     if (dfn[k]==low[k])
     {
        num[st[tt]]=top-tt+1;
        while (top>=tt)
        {
            belong[st[top]]=st[tt];
            inst[st[top--]]=false;
        }
     }
}

void tuopu()
{
     for (int i=1;i<=t;++i)
         if (belong[s[i]]!=belong[e[i]])
            ++rd[belong[e[i]]];
     for (int i=1;i<=n;++i)
         if ((belong[i]==i)&&(!rd[i]))
            line[++r]=i;
     for (l=1;l<=r;++l)
         for (int i=1;i<=n;++i)
             if (i==belong[line[l]])
                for (int p=first[i];p;p=nxt[p])
                    if (belong[e[p]]!=belong[line[l]])
                    {
                       --rd[belong[e[p]]];
                       if (!rd[belong[e[p]]])
                          line[++r]=e[p];
                    }
}

void work(int now,int head,int num)
{
     st[++top]=now;
     boo[now]=true;
     --num;
     if (!num)
        if ((now==head)||(dat[now][head]))
        {
           workout=true;
           return;
        }
     for (int p=first[now];p;p=nxt[p])
         if ((!boo[e[p]])&&(group==belong[e[p]]))
         {
            work(e[p],head,num);
            if (workout) return;
         }
     --top;
     boo[now]=false;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            scanf("%d",&dat[i][j]);
            if (dat[i][j])
            {
               s[++t]=i;e[t]=j;
               nxt[t]=first[i];
               first[i]=t;
            }
        }
    for (int i=1;i<=n;++i)
        if (!belong[i]) tarjan(i);
    ans=0;
    for (int i=1;i<=n;++i)
        if (belong[i]!=belong[1]) ans=1;
    printf("%d\n",ans);
    tuopu();
    for (l=1;l<=r;++l)
    {
        group=line[l];
        workout=false;
        work(line[l],line[l],num[line[l]]);
    }
    for (int i=1;i<=n-1;++i) printf("%d ",st[i]);
    printf("%d\n",st[n]);
    return 0;
}
