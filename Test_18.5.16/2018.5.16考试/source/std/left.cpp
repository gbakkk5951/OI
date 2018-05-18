#include<cstdio>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
#define rm(x1,x2) (x1>>x2)
const int maxn=20000;
const int maxk=20;

int fa[maxn],di[maxn];

int K,n,cando;
int seq[maxn],rseq[maxn],ms[maxn],rp[maxn];
int f[maxk][maxn],sf[maxk][maxn];
int c[maxk][maxn],sc[maxk][maxn];
int pos[maxn],vis[maxn];

void init()
{
  int i;
  n=1<<K;
  for(i=0;i<n;i++)
    scanf("%d",seq+i);
  for(i=0;i<n;i++)
    f[0][seq[i]]=rseq[seq[i]]=i;
  memset(c,0,sizeof(c));
  cando=1;
}

int getfather(int x)
{
  if(fa[x]==-1)return x;
  int rt=getfather(fa[x]);
  di[x]^=di[fa[x]];
  fa[x]=rt;
  return rt;
}

void merge(int i,int j,int p)
{
  int fi=getfather(i);
  int fj=getfather(j);
  if(fi==fj)
  {
    if((di[i]^di[j]^p)!=0)cando=0;
    return;
  }
  fa[fi]=fj;
  di[fi]=(di[i]^di[j]^p);
}

void getlevel(int l,int x)
{
  int r=l+rm(n,x);
  memset(fa,-1,sizeof(fa));
  memset(di,0,sizeof(di));
  for(int i=l;i<r;i++)
    pos[f[x][i]>>x]=i;
  int i,p1,p2;
  for(i=l;i<r;i+=2)
  {
    p1=pos[rm(f[x][i],x)^1];
    p2=pos[rm(f[x][i+1],x)^1];
    if(((p1^i)&1)==0)merge(((p1|1)^1),i,1);
    else merge(((p1|1)^1),i,0);
    if(((p2^(i+1))&1)==0)merge(((p2|1)^1),i,1);
    else merge(((p2|1)^1),i,0);
  }
}

void work(int x,int l)
{
  int r=l+rm(n,x);
  if(l+1>=r||cando==0)return;
  getlevel(l,x);
  int i,ff;
  for(i=l;i<r;i+=2)
  {
    ff=getfather(i);
    if(ff!=n+1)
    {
      c[x][i]=0;
      merge(i,n+1,0);
    }
    else
    {
      c[x][i]=di[i];
      if(c[x][i])swap(f[x][i],f[x][i+1]);
    }
  }
  int mid=rm(r-l,1);
  for(int i=0;i<mid;i++)
    f[x+1][l+i]=f[x][l+i*2];
  for(int i=0;i<mid;i++)
    f[x+1][l+mid+i]=f[x][l+i*2+1];
  work(x+1,l);
  work(x+1,rm(l+r,1));
}

void swork(int x,int l)
{
  int r=l+rm(n,x);
  if(l+1>=r)return;
  int mid=rm(l+r,1);
  for(int i=l;i<r;i+=2)
  {
    if(rp[sf[x][i]]>=mid)
    {
      swap(sf[x][i],sf[x][i+1]);
      sc[x][i]=1;
    }
    else sc[x][i]=0;
  }
  mid=rm(r-l,1);
  for(int i=0;i<mid;i++)
    sf[x+1][l+i]=sf[x][l+i*2];
  for(int i=0;i<mid;i++)
    sf[x+1][l+mid+i]=sf[x][l+i*2+1];
  swork(x+1,l);
  swork(x+1,rm(l+r,1));
}

void solve()
{
  int dep=0;
  for(int i=n;i>2;(i>>=1),dep++);
  for(int i=0;i<n;i++)
  {
    ms[i]=f[dep][i];
    rp[ms[i]]=i;
  }
  for(int i=0;i<n;i++)
    sf[0][i]=i;
  swork(0,0);
  if(!cando){printf("impossible\n\n");return;}
  for(int x=0;x<dep;x++)
  {
    for(int i=0;i<n;i+=2)
      printf("%1d",c[x][i]);
    puts("");
  }
  for(int x=dep;x>=0;x--)
  {
    for(int i=0;i<n;i+=2)
      printf("%1d",sc[x][i]);
    puts("");
  }
  puts("");
}
int main()
{
  freopen("left.in","r",stdin);
  freopen("left.out","w",stdout);
  while(1)
  {
    scanf("%d",&K);
    if(K==0)return 0;
    init();
    work(0,0);
    solve();
  }
  return 0;
}
