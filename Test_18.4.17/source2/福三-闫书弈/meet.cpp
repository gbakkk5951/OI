#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,a[100010],b[200010],c[200010],d[200010],f[100010][25],h[100010][25],w[100010],x[200010][25],y[200010];
int u[200010],p;
long long g[100010][25],v[100010];
inline void dfs(int i)
{
    int j;
    x[++p][0]=i;
    y[i]=p;
    for(j=1;j<=20;j++)
      {
       f[i][j]=f[f[i][j-1]][j-1];
       g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
       h[i][j]=max(h[i][j-1],h[f[i][j-1]][j-1]);
      }
    for(j=a[i];j>0;j=d[j])
      if(b[j]!=f[i][0])
        {
         w[b[j]]=w[i]+1;
         v[b[j]]=v[i]+c[j];
         f[b[j]][0]=i;
         g[b[j]][0]=h[b[j]][0]=c[j];
         dfs(b[j]);
         x[++p][0]=i;
        }
}
inline int minn(int i,int j)
{
    return w[i]<w[j]?i:j;
}
inline int lca(int i,int j)
{
    i=y[i];
    j=y[j];
    if(i>j)
      swap(i,j);
    int k=u[j-i];
    return minn(x[i][k],x[j-(1<<k)+1][k]);
}
inline bool check(int u,int v,long long t)
{
    int k;
    for(k=20;k>=0;k--)
      if(w[u]-(1<<k)>=w[v])
        {
         if(h[u][k]>t)
           return 1;
         u=f[u][k];
        }
    return 0;
}
inline bool uu(int u1,int v1,long long t1,int u2,int v2,long long t2)
{
    int k;
    k=lca(u1,u2);
    if(w[k]<=w[v1] || w[k]<=w[v2])
      return 0;
    t1+=v[u1]-v[k];
    t2+=v[u2]-v[k];
    return check(k,v1+v2-minn(v1,v2),abs(t1-t2));
}
inline bool dd(int u1,int v1,long long t1,int u2,int v2,long long t2)
{
    t1+=v[u1]-v[v1];
    t2+=v[u2]-v[v2];
    return uu(u1,v1,t2,u2,v2,t1);
}
inline bool check2(int u,int v1,int v2,long long t1,long long t2)
{
    long long t=(v[u]-v[v2]-(t1-t2));
    if(t<0)
      while(1);
    int x=0;
    if(t&1)
      x=1;
    int k;
    t=(t>>1);
    for(k=20;k>=0;k--)
      if(g[u][k]<=t)
        {
         t-=g[u][k];
         u=f[u][k];
        }
    if((t || x) && w[u]>w[v1] && w[u]>w[v2])
      return 1;
    else
      return 0;
}
inline bool ud(int u1,int v1,long long t1,int u2,int v2,long long t2)
{
    int k;
    k=lca(u1,u2);
    if(w[k]<=w[v1] || w[k]<=w[v2])
      return 0;
    t1+=v[u1]-v[k];
    t2+=v[k]-v[v2];
    if(t2<=t1)
      return 0;
    t2-=v[k]-v[v2];
    if(t1+v[k]-v[v2]<=t2)
      return 0;
    return check2(k,v1,v2,t1,t2);
}
int main()
{
	freopen("meet.in","r",stdin);
	freopen("meet.out","w",stdout);
	int i,j,k,l,u1,v1,t1,u2,v2,t2;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	  {
       scanf("%d%d%d",&j,&k,&l);
       b[2*i-1]=k;
       c[2*i-1]=l;
       d[2*i-1]=a[j];
       a[j]=2*i-1;
       b[2*i]=j;
       c[2*i]=l;
       d[2*i]=a[k];
       a[k]=2*i;
      }
    w[1]=1;
    dfs(1);
    for(i=p;i>0;i--)
      for(j=1;j<=20;j++)
        x[i][j]=minn(x[i][j-1],x[min(i+(1<<j-1),p)][j-1]);
    for(i=2;i<=p;i++)
      u[i]=u[i>>1]+1;
    while(m--)
      {
       scanf("%d%d%d%d%d%d",&u1,&v1,&t1,&u2,&v2,&t2);
       i=lca(u1,v1);
       j=lca(u2,v2);
       if(uu(u1,i,t1,u2,j,t2) || dd(v1,i,t1+v[u1]-v[i],v2,j,t2+v[u2]-v[j]) || ud(u1,i,t1,v2,j,t2+v[u2]-v[j])
       || ud(u2,j,t2,v1,i,t1+v[u1]-v[i]))
         printf("YES\n");
       else
         printf("NO\n");
      }
	return 0;
}

