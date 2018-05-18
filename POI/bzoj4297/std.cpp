#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 500010
#define LL long long
#define GET (ch>='0'&&ch<='9')
using namespace std;
int n,m,top,tp;
int c,head=1,tail;
LL ans,sum,tmp,now;
int val[MAXN],r[MAXN],del[MAXN],q[MAXN];
int sta[MAXN<<1],cnt;
int f[MAXN],d[MAXN];
inline int abs(int x)   {   return x<0?-x:x;    }
struct edge
{
    int to;
    edge *next;
}e[MAXN<<1],*prev[MAXN],E[MAXN],*Prev[MAXN];
inline void insert(int u,int v) {   d[u]++;e[++top].to=v;e[top].next=prev[u];prev[u]=&e[top];   }
inline void Insert(int u,int v) {   f[v]=u;E[++tp].to=v;E[tp].next=Prev[u];Prev[u]=&E[tp];  }
void in(int &x)
{
    char ch=getchar();x=0;
    while (!GET)    ch=getchar();
    while (GET) x=x*10+ch-'0',ch=getchar();
}
void dfs(int x)
{
    if (!Prev[x])   return;
    for (edge *i=Prev[x];i;i=i->next)   dfs(i->to);
    tmp=1ll<<62;sum=0;cnt=0;c=0;
    for (edge *i=Prev[x];i;i=i->next)   sta[++cnt]=val[i->to],sta[++cnt]=r[i->to],c--,sum+=val[i->to];
    sort(sta+1,sta+cnt+1);
    for (int i=1;i<=cnt;i++)
    {
        c++;sum-=sta[i];now=sum+1ll*sta[i]*c;
        if (now<tmp)    tmp=now,val[x]=sta[i];
        if (now==tmp)   r[x]=sta[i];
    }
    ans+=tmp;
}
int main()
{
    in(n);in(m);int u,v;
    for (int i=1;i<n;i++)   in(u),in(v),insert(u,v),insert(v,u);
    for (int i=1;i<=m;i++)  in(val[i]),r[i]=val[i];
    if (n==m)
    {
        for (int i=1;i<=n;i++)  for (edge *j=prev[i];j;j=j->next)   ans+=abs(r[i]-r[j->to]);
        return printf("%lld\n",ans>>1),0;
    }
    for (int i=1;i<=m;i++)  del[i]=1,q[++tail]=i;
    while (head<=tail)
    {
        int last=tail;
        for (int x=head;x<=tail;x++)    for (edge *i=prev[q[x]];i;i=i->next)    if (!del[i->to])    Insert(i->to,q[x]);
        for (;head<=last;head++)    for (edge *i=prev[q[head]];i;i=i->next)     if (!del[i->to]&&(--d[i->to])<=1)   del[i->to]=1,q[++tail]=i->to;
    }
    for (int i=1;i<=n;i++)  if (!f[i])  Insert(0,i);
    dfs(0);cout<<ans<<endl;
}
