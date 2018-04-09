    #include<cmath>  
    #include<ctime>  
    #include<cstdio>  
    #include<cstring>  
    #include<cstdlib>  
    #include<complex>  
    #include<iostream>  
    #include<algorithm>  
    #include<iomanip>  
    #include<vector>  
    #include<string>  
    #include<bitset>  
    #include<queue>  
    #include<set>  
    #include<map>  
    using namespace std;  
      
    inline int read()  
    {  
        int x=0,f=1;char ch=getchar();  
        while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  
        while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}  
        return x*f;  
    }  
    void print(int x)  
    {if(x<0)putchar('-'),x=-x;if(x>=10)print(x/10);putchar('0'+x%10);}  
      
    const int N=80100;  
      
    int a[N],h[N<<1],n,Q,m;  
      
    int ecnt,last[N];  
    struct EDGE{int to,nt;}e[N<<1];  
    inline void add(int u,int v)  
    {e[++ecnt]=(EDGE){v,last[u]};last[u]=ecnt;}  
      
    struct question{int k,u,v;}q[N];  
      
    int fa[N][18],size[N],d[N],dfn[N],pos[N],dfncnt;  
      
    void dfs(int u)  
    {  
        size[u]=1;dfn[u]=++dfncnt;pos[dfn[u]]=u;  
        register int i;  
        for(i=last[u];i;i=e[i].nt)  
        {  
            if(e[i].to==fa[u][0])continue;  
            d[e[i].to]=d[u]+1;fa[e[i].to][0]=u;dfs(e[i].to);size[u]+=size[e[i].to];  
        }  
    }  
      
    inline int hsh(int x)  
    {  
        register int l=1,r=m,mid;  
        while(l<=r)  
        {  
            mid=(l+r)>>1;  
            if(h[mid]==x)return mid;  
            h[mid]>x?r=mid-1:l=mid+1;  
        }  
        return 0;  
    }  
      
      
    struct president_tree{int w,ls,rs;}tr[N<<7];  
      
    int root[N],bit[N],cnt;  
    void insert(int &k,int x,int l,int r,int aim,int val)  
    {  
        k=++cnt;tr[k].w=tr[x].w+val;  
        if(l==r)return ;int mid=(l+r)>>1;  
        tr[k].ls=tr[x].ls;tr[k].rs=tr[x].rs;  
        aim>mid?insert(tr[k].rs,tr[x].rs,mid+1,r,aim,val):insert(tr[k].ls,tr[x].ls,l,mid,aim,val);  
    }  
      
    void build(int u)  
    {  
        insert(root[u],root[fa[u][0]],1,m,a[u],1);  
        for(int i=last[u];i;i=e[i].nt)  
        {  
            if(e[i].to==fa[u][0])continue;  
            build(e[i].to);  
        }  
    }  
      
    void init()  
    {  
        dfs(1);  
        register int i,j,tmp=0;  
        for(j=1;j<=17;++j)for(i=1;i<=n;++i)fa[i][j]=fa[fa[i][j-1]][j-1];  
        sort(h+1,h+1+m);h[++tmp]=h[1];  
        for(i=2;i<=m;++i)if(h[i]!=h[tmp])h[++tmp]=h[i];  
        m=tmp;  
        for(i=1;i<=n;++i)a[i]=hsh(a[i]);  
        build(1);  
    }  
      
    inline int getlca(int u,int v)  
    {  
        register int i,len;  
        if(d[u]<d[v])swap(u,v);  
        len=d[u]-d[v];  
        for(i=0;(1<<i)<=len;++i)if(len&(1<<i))u=fa[u][i];  
        if(u==v)return u;  
        for(i=17;i>=0;i--)if(fa[u][i]^fa[v][i])u=fa[u][i],v=fa[v][i];  
        return fa[u][0];  
    }  
      
    inline void modify(int x,int aim,int val)  
    {for(;x<=n;x+=(x&-x))insert(bit[x],bit[x],1,m,aim,val);}  
      
    int L[N],R[N],lf,rf;  
      
    inline int check()  
    {  
        register int i,sum=0;  
        for(i=1;i<=lf;++i)sum-=tr[L[i]].w;  
        for(i=1;i<=rf;++i)sum+=tr[R[i]].w;  
        return sum;  
    }  
      
    inline void query(int u,int v,int rk)  
    {  
        register int i,lca,l=1,r=m,mid,sum;lf=0,rf=0;  
        lca=getlca(u,v);  
        L[++lf]=root[lca];L[++lf]=root[fa[lca][0]];  
        R[++rf]=root[u];R[++rf]=root[v];  
        for(i=dfn[u];i;i-=(i&-i))R[++rf]=bit[i];  
        for(i=dfn[v];i;i-=(i&-i))R[++rf]=bit[i];  
        for(i=dfn[lca];i;i-=(i&-i))L[++lf]=bit[i];  
        for(i=dfn[fa[lca][0]];i;i-=(i&-i))L[++lf]=bit[i];  
        if(check()<rk){puts("invalid request!");return ;}  
        while(l<r)  
        {  
            mid=(l+r)>>1;sum=0;  
            for(i=1;i<=lf;++i)sum-=tr[tr[L[i]].rs].w;  
            for(i=1;i<=rf;++i)sum+=tr[tr[R[i]].rs].w;  
            if(sum>=rk)  
            {  
                for(i=1;i<=lf;++i)L[i]=tr[L[i]].rs;  
                for(i=1;i<=rf;++i)R[i]=tr[R[i]].rs;  
                l=mid+1;  
            }  
            else   
            {  
                for(i=1;i<=lf;++i)L[i]=tr[L[i]].ls;  
                for(i=1;i<=rf;++i)R[i]=tr[R[i]].ls;  
                rk-=sum;r=mid;  
            }  
        }  
        print(h[l]);puts("");  
    }  
      
    void solve()  
    {  
        register int i,u,val;  
        for(i=1;i<=Q;++i)  
        {  
            if(q[i].k)query(q[i].u,q[i].v,q[i].k);  
            else  
            {  
                u=q[i].u;val=q[i].v;  
                modify(dfn[u],a[u],-1);modify(dfn[u]+size[u],a[u],1);  
                a[u]=hsh(val);  
                modify(dfn[u],a[u],1);modify(dfn[u]+size[u],a[u],-1);  
            }     
        }  
    }  
      
    int main()  
    {  
        n=read();Q=read();  
        register int i,  
        u,v;  
        for(i=1;i<=n;++i)a[i]=read(),h[++m]=a[i];  
        for(i=1;i<n;++i){u=read();v=read();add(u,v);add(v,u);}  
        for(i=1;i<=Q;++i){q[i].k=read();q[i].u=read();q[i].v=read();if(!q[i].k)h[++m]=q[i].v;}  
        init();solve();  
        return 0;  
    }  
