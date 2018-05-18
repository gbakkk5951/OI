#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 1005
#define ll long long
#define M 2000006
using namespace std;
int n,k,ms,me;
int head[N],ver[M],nxt[M],tot,f[M];
ll quan[M];
void add(int a,int b,int c,ll d)
{
//  cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;f[tot]=c;quan[tot]=d;
    tot++;nxt[tot]=head[b];head[b]=tot;ver[tot]=a;f[tot]=0;quan[tot]=-d;
    return ;
}
queue<int>q;
int minn[N],in[N],with[N],v[N];
ll dis[N];int S,T;
bool tell()
{
    memset(minn,0x3f,sizeof(minn));
    for(int i=1;i<=T+1;i++)dis[i]=-12312123123123123LL;
    dis[S]=0;q.push(S);
    int cnt=0;
    while(!q.empty())
    {
        int tmp=q.front();q.pop();in[tmp]=0;
        for(int i=head[tmp];i;i=nxt[i])
        {
            if(f[i]&&dis[ver[i]]<dis[tmp]+quan[i])
            {
                dis[ver[i]]=dis[tmp]+quan[i];
                with[ver[i]]=i;minn[ver[i]]=min(minn[tmp],f[i]);
                if(!in[ver[i]])
                {
                    in[ver[i]]=1;q.push(ver[i]);
                }
            }
        }
    }
    while(!q.empty())q.pop();
    return dis[T]!=dis[T+1];
}
ll zeng()
{
    for(int i=T;i!=S;i=ver[with[i]^1])
    {
        f[with[i]]-=minn[T];f[with[i]^1]+=minn[T];
    }
    return dis[T]*minn[T];
}
ll dinic()
{
    ll r=0;
    while(tell())r+=zeng();
    return r;
}
ll s[N],e[N];
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
    tot=1;
    scanf("%d%d%d%d",&n,&k,&ms,&me);
    S=0;T=n+1;
    ll ans=0;int tmp=k-ms-me;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
        ans+=s[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&e[i]);
        e[i]=e[i]-s[i];
    }
     
    for(int i=1;i<=min(k,n-k);i++)add(n-k+1,i,1,e[i]);
     
    for(int i=n-k+1;i<=k;i++)add(n-k+1,n-k+2,1,e[i]);
     
    add(n-k+1,1,tmp,0);add(S,n-k+1,k-ms,0);
     
    add(n-k+2,T,k-ms,0);add(n-k,n-k+2,tmp,0);
     
    for(int i=max(k+1,n-k+1);i<=n;i++)add(i-k,n-k+2,1,e[i]);
     
     
    for(int i=k+1;i<=n-k;i++)add(i-k,i,1,e[i]);
     
    for(int i=2;i<=n-k;i++)add(i-1,i,tmp,0);
     
    printf("%lld\n",ans+dinic());
     
    return 0;
     
}
