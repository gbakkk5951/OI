#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define cl(x) memset(x,0,sizeof(x))
using namespace std;

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
inline void read(int &x){
    char c=nc(),b=1;
    for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
    for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

const int N=105;
const int M=100005;

#define V G[p].v
struct edge{    
    int u,v,f,w;    
    int next;    
}G[M];    
int head[N],inum=1;    

inline void add(int u,int v,int w,int f,int p){    
    G[p].u=u; G[p].v=v; G[p].w=w; G[p].f=f; G[p].next=head[u]; head[u]=p;    
}    
inline void link(int u,int v,int w,int f){    
    add(u,v,w,f,++inum); add(v,u,-w,0,++inum);    
}
inline void clear(){
    cl(head); inum=1;
}

int S,T;    
int pre[N],dis[N],ins[N];    
int Q[1000005],l,r;    

#define V G[p].v    
int Mincost;    
inline bool SPFA(){    
    for (int i=1;i<=T;i++) dis[i]=1<<30,pre[i]=0,ins[i]=0;    
    l=r=-1; dis[S]=0; Q[++r]=S; ins[S]=1;    
    while (l!=r){    
        int u=Q[++l]; ins[u]=0;    
        for (int p=head[u];p;p=G[p].next)    
            if (G[p].f && dis[V]>dis[u]+G[p].w){    
      			dis[V]=dis[u]+G[p].w; pre[V]=p;    
       			if (!ins[V]) Q[++r]=V,ins[V]=1;    
            }    
    }    
    if (dis[T]==(1<<30)) return 0;    
    int minv=1<<30;    
    for (int p=pre[T];p;p=pre[G[p].u])    
        minv=min(minv,G[p].f);    
    Mincost+=minv*dis[T];    
    for (int p=pre[T];p;p=pre[G[p].u])    
        G[p].f-=minv,G[p^1].f+=minv;    
    return 1;    
}    


int n,m,K;
int us[N*N],vs[N*N],ds[N];
int s,t;

inline bool check(int v){
    clear();
    s=n+1; t=n+2; S=n+3; T=n+4;
    link(t,s,0,1<<30);
    for (int i=1;i<=m;i++) link(us[i],vs[i],1,1);
    for (int i=1;i<=n;i++)
        if (ds[i]>=v){
            link(s,i,0,2*v);
            link(S,i,0,ds[i]-v); link(s,T,0,ds[i]-v);
        }else if (ds[i]<=-v){
            link(i,t,0,2*v);
            link(S,t,0,-ds[i]-v); link(i,T,0,-ds[i]-v);
        }else{
            link(s,i,0,ds[i]+v); link(i,t,0,v-ds[i]);
        }
    Mincost=0; while (SPFA());
    return Mincost<=K;
}

int main(){
    int Q,Case=0;
    freopen("t.in","r",stdin);
//    freopen("t.out","w",stdout);
    read(Q);
    while (Q--){
        read(n); read(m); read(K); K=m-K; cl(ds);
        for (int i=1;i<=m;i++) read(us[i]),read(vs[i]),ds[vs[i]]--,ds[us[i]]++;
        int L=-1,R=n,MID;
        while (L+1<R)
            if (check(MID=(L+R)>>1))
        R=MID;
            else
        L=MID;
        printf("Case %d: %d\n",++Case,R);
    }
    return 0;
}
