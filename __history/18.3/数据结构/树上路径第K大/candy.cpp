#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lc(x) t[x].l
#define rc(x) t[x].r
typedef long long ll;
const int N=8e4+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int n,Q,w[N],u,v,k;
int mp[N<<1],m;
struct ques{
    int k,a,b;
}q[N];
void getMP(){
    sort(mp+1,mp+1+m);
    int p=0;mp[++p]=mp[1];
    for(int i=2;i<=m;i++) if(mp[i]!=mp[i-1]) mp[++p]=mp[i];
    m=p;
}
int Bin(int v){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(mp[mid]==v) return mid;
        else if(v<mp[mid]) r=mid-1;
        else l=mid+1;
    }
    return 0;
}

struct edge{
    int v,ne;
}e[N<<1];
int h[N],cnt;
inline void ins(int u,int v){
    cnt++;
    e[cnt].v=v;e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].ne=h[v];h[v]=cnt;
}
int deep[N],fa[N],mx[N],size[N],top[N],tid[N],tot;
int L[N],R[N];
void dfs(int u){
    size[u]=1;
    for(int i=h[u];i;i=e[i].ne){
        int v=e[i].v;
        if(v==fa[u]) continue;
        fa[v]=u;deep[v]=deep[u]+1;
        dfs(v);
        size[u]+=size[v];
        if(size[v]>size[mx[u]]) mx[u]=v;
    }
}
void dfs(int u,int anc){
    if(!u) return;
    tid[u]=L[u]=++tot;
    top[u]=anc;
    dfs(mx[u],anc);
    for(int i=h[u];i;i=e[i].ne)
        if(e[i].v!=fa[u]&&e[i].v!=mx[u]) dfs(e[i].v,e[i].v);
    R[u]=tot;
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    if(tid[x]>tid[y]) swap(x,y);
    return x;
}

struct node{
    int l,r,w;
}t[N*128];
int crt[N],rt[N],sz;
void ins(int &x,int l,int r,int p,int d){//printf("ins %d %d %d %d %d\n",x,l,r,p,d);
	t[++sz]=t[x];x=sz;
    t[x].w+=d;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p<=mid) ins(lc(x),l,mid,p,d);
    else ins(rc(x),mid+1,r,p,d);
}
void build(int u){//printf("build %d\n",u);
    if(!u) return;
    rt[u]=rt[fa[u]];
    ins(rt[u],1,m,w[u],1);
    build(mx[u]);
    for(int i=h[u];i;i=e[i].ne)
        if(e[i].v!=fa[u]&&e[i].v!=mx[u]) build(e[i].v);
}


inline int lowbit(int x){return x&-x;}
void add(int x,int v,int d){
    for(int i=x;i<=tot;i+=lowbit(i)) ins(crt[i],1,m,v,d);
}
int A[N<<1],B[N<<1],a,b;
bool check(int k){
    int suml=0,sumr=0;
    for(int i=1;i<=a;i++) suml+=t[A[i]].w;
    for(int i=1;i<=b;i++) sumr+=t[B[i]].w;
    //printf("check %d %d\n",sumr,suml);
    return sumr-suml>=k;
}
int cal(){
    int suml=0,sumr=0;
    for(int i=1;i<=a;i++) suml+=t[rc(A[i])].w;
    for(int i=1;i<=b;i++) sumr+=t[rc(B[i])].w;
    //printf("cal %d %d\n",sumr,suml);
    return sumr-suml;
}
void query(int ql,int qr,int k){
    a=b=0;int p=lca(ql,qr);//printf("que %d %d %d  %d %d\n",ql,qr,k,p,fa[p]);
    B[++b]=rt[ql];B[++b]=rt[qr];
    A[++a]=rt[p];A[++a]=rt[fa[p]];
    for(int i=L[ql];i;i-=lowbit(i)) B[++b]=crt[i];
    for(int i=L[qr];i;i-=lowbit(i)) B[++b]=crt[i];
    for(int i=L[p];i;i-=lowbit(i)) A[++a]=crt[i];
    for(int i=L[fa[p]];i;i-=lowbit(i)) A[++a]=crt[i];
    if(!check(k)){puts("invalid request!");return;}
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1,rsize=cal();//printf("erfen %d %d %d %d\n",l,r,mid,rsize);
        if(rsize>=k){
            l=mid+1;
            for(int i=1;i<=a;i++) A[i]=rc(A[i]);
            for(int i=1;i<=b;i++) B[i]=rc(B[i]);
        }else{
            r=mid;
            k-=rsize;
            for(int i=1;i<=a;i++) A[i]=lc(A[i]);
            for(int i=1;i<=b;i++) B[i]=lc(B[i]);
        }
    }
    printf("%d\n",mp[l]);
}
void solve(){
    build(1);
    for(int i=1;i<=Q;i++){
        int k=q[i].k,a=q[i].a,b=q[i].b;
        if(k==0){
            add(L[a],w[a],-1);add(R[a]+1,w[a],1);
            w[a]=Bin(b);
            add(L[a],w[a],1);add(R[a]+1,w[a],-1);
        }else{
            query(a,b,k);
        }
    }
}
void tet(){
    for(int i=1;i<=n;i++)
        printf("dfs %d %d\n",L[i],R[i]);
}
int main(int argc, const char * argv[]) {
    n=read();Q=read();
    for(int i=1;i<=n;i++) mp[++m]=w[i]=read();
    for(int i=1;i<=n-1;i++) u=read(),v=read(),ins(u,v);
    dfs(1);dfs(1,1);//tet();
    for(int i=1;i<=Q;i++){
        q[i].k=read(),q[i].a=read(),q[i].b=read();
        if(q[i].k==0) mp[++m]=q[i].b;
    }
    getMP();
    for(int i=1;i<=n;i++) w[i]=Bin(w[i]);
    solve();
    return 0;
}
