 #include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010
#define M 8000010
int w[N],a[N],b[N],c[N],san[N],A[N],B[N],C[N],vis[N],lca[N],lft[N],rht[N],first[N],fa[N],f[N],root[N];
int sum[M],ls[M],rs[M];
int n,m,tot,cnt,ne,TOT,tim,numa,numb;
vector<pair<int,int> > ask[N];
struct edge{int y,next;}e[N << 1];
void addedge(int x,int y){
   e[++ cnt].next = first[x];e[cnt].y = y;first[x] = cnt;
   e[++ cnt].next = first[y];e[cnt].y = x;first[y] = cnt;
}
char ch;
void read(int &x){
   while (ch = getchar(),ch < '0' || ch > '9');
   x = ch - '0';
   while (ch = getchar(),ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
void update(int lson,int rson,int x,int k){
   sum[++ TOT] = sum[x] + k;ls[TOT] = lson;rs[TOT] = rson;
}
int change(int x,int l,int r,int y,int k){
   if (l == r) {update(0,0,x,k);return TOT;}
   int m = l + r >> 1;
   if (y <= m) ne = change(ls[x],l,m,y,k),update(ne,rs[x],x,k);
   else ne = change(rs[x],m + 1,r,y,k),update(ls[x],ne,x,k);
   return TOT;
}
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void dfs(int x){
   root[x] = change(root[f[x]],1,tot,w[x],1);
   lft[x] = ++ tim;fa[x] = x;
   for(int i = first[x];i;i = e[i].next) if(e[i].y != f[x]){
       f[e[i].y] = x;dfs(e[i].y);fa[e[i].y] = x;
   }
   rht[x] = tim;
   vis[x] = 1;
   int t = ask[x].size();
   for (int i = 0;i < t;i ++) if (vis[ask[x][i].first]){
       lca[ask[x][i].second] = find(ask[x][i].first);
   }
}
void get(int x,int p){
   if(p){
       a[numa ++] = root[x];
       x = lft[x];
       while (x) a[numa ++] = c[x],x -= x & (-x);
   }else{
       b[numb ++] = root[x];
       x = lft[x];
       while (x) b[numb ++] = c[x],x -= x & (-x);
   }
}
void bitup(int x,int pos,int k){
   while (x <= n){
       c[x] = change(c[x],1,tot,pos,k);
       x += x & (-x);
   }
}
int query(int *a,int numa,int *b,int numb,int k){
   int t,tt,l = 1,r = tot;
   while (l < r){
       t = 0,tt = 0;
       for (int i = 0;i < numa;i ++) t += sum[rs[a[i]]],tt += sum[a[i]];
       for (int i = 0;i < numb;i ++) t -= sum[rs[b[i]]],tt -= sum[b[i]];
       if (tt < k) return -1;
       if (k <= t){
           for (int i = 0;i < numa;i ++) a[i] = rs[a[i]];
           for (int i = 0;i < numb;i ++) b[i] = rs[b[i]];
           l = (l + r >> 1) + 1;
       }else{
           for (int i = 0;i < numa;i ++) a[i] = ls[a[i]];
           for (int i = 0;i < numb;i ++) b[i] = ls[b[i]];
           r = l + r >> 1;
           k -= t;
       }
   }
   return l;
}
int main(){
   read(n);read(m);
   int x,y,mid;
   for (int i = 1;i <= n;i ++) read(w[i]),san[++ tot] = w[i];
   for (int i = 1;i < n;i ++) read(x),read(y),addedge(x,y);
   for (int i = 1;i <= m;i ++){
       read(A[i]);read(B[i]);read(C[i]);
       if (!A[i])san[++ tot] = C[i];
       else ask[B[i]].push_back(make_pair(C[i],i)),ask[C[i]].push_back(make_pair(B[i],i));
   }
   sort(san + 1,san + 1 + tot);
   tot = unique(san + 1,san + 1 + tot) - san - 1;
   for (int i = 1;i <= n;i ++) w[i] = lower_bound(san + 1,san + tot + 1,w[i]) - san;
   dfs((n + 1) / 2);
   for (int i = 1;i <= n;i ++) c[i] = root[0];
   for (int i = 1;i <= m;i ++){
       if (A[i]){
           x = B[i],y = C[i],mid = lca[i];
           numa = numb = 0;
           get(x,1),get(y,1);
           get(mid,0),get(f[mid],0);
           x = query(a,numa,b,numb,A[i]);
           if(x < 0) puts("invalid request!");
           else printf("%d\n",san[x]);
       }else{
           x = B[i],y = C[i];
           y = lower_bound(san + 1,san + tot + 1,y) - san;
           bitup(lft[x],w[x],-1);
           bitup(rht[x] + 1,w[x],1);
           bitup(lft[x],y,1);
           bitup(rht[x] + 1,y,-1);
           w[x] = y;
       }
   }
   return 0;
}


