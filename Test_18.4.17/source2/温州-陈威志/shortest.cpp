#include<cstdio>
#define MAXN 1000000001
#define N 100001
using namespace std;
int n,m,K,tail,head;
int roadto[N],road[N],roadw[N],roadnum[N],cantdel[N],bedel[N],roadfrom[N],h[N],b[N],sameroad[N],ans[N],dist[N],from[N],wz[N],u[N],v[N],w[N];
int T[N],Tfrom[N];

void spfa()
{
  for(int i=1;i<=n;i++) dist[i]=MAXN,roadfrom[i]=from[i]=0;
  dist[1]=0,h[tail=head=1]=1,b[1]=1;
  while(tail<=head)
    {
      int t=roadto[h[tail]];
      while(t)
        {
		  if(dist[h[tail]]+roadw[t]<dist[road[t]] && !bedel[t])
		    {
			  dist[road[t]]=dist[h[tail]]+roadw[t],from[road[t]]=h[tail],roadfrom[road[t]]=t;
			  if(!b[road[t]]) b[road[t]]=1,h[++head]=road[t];
			}
		  t=roadto[t];
		}
	  b[h[tail++]]=0;
	}
}

int main()
{
  int i,t,pd,tt,tfrom,p=0;
  freopen("shortest.in","r",stdin);
  freopen("shortest.out","w",stdout);
  scanf("%d%d%d",&n,&m,&K);
  for(i=1;i<=n;i++) wz[i]=i;
  for(i=1;i<=m;i++) 
    {
	 scanf("%d%d%d",&u[i],&v[i],&w[i]);
	 roadto[wz[u[i]]]=n+i*2-1,wz[u[i]]=n+i*2-1,road[wz[u[i]]]=v[i],roadw[wz[u[i]]]=w[i],roadnum[wz[u[i]]]=i;
	 roadto[wz[v[i]]]=n+i*2,wz[v[i]]=n+i*2,road[wz[v[i]]]=u[i],roadw[wz[v[i]]]=w[i],roadnum[wz[v[i]]]=i;
	 sameroad[wz[v[i]]]=wz[u[i]],sameroad[wz[u[i]]]=wz[v[i]];
	}
  spfa();
  while(K--)
    {
	  t=n,pd=0,T[0]=0,p=1;
	  while(t>1) T[++T[0]]=t,Tfrom[T[0]]=roadfrom[t],t=from[t];
	  while(p<=T[0])
	    {
	      t=T[p],tfrom=Tfrom[p];
		  if(!cantdel[tfrom])
		  { 
		   bedel[tfrom]=bedel[sameroad[tfrom]]=1,tt=tfrom;
		   spfa();
		   if(dist[n]==MAXN) bedel[tt]=bedel[sameroad[tt]]=0,cantdel[tt]=cantdel[sameroad[tt]]=1;
		   else
		     {
			   pd=1,ans[++ans[0]]=roadnum[tt];
			   break;
			 }
		  }
		  p++;
		}
	  if(!pd) break;
	}
  for(i=0;i<=ans[0];i++) printf("%d\n",ans[i]);
}
