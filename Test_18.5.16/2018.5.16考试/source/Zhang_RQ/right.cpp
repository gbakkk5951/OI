#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cassert>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN=1E5+10;
int n,q,p,opt,l,r,x;
int a[MAXN];
namespace brute_force{
    const int MAXNN=1010;
    int sg(int x)
    {
        if(p&1) return x&1;
        if(x%(p+1)==p) return 2;
        else return (x%(p+1))&1;
    }
    void solve()
    {
        while(q--)
        {
            scanf("%d%d%d",&opt,&l,&r);
            if(opt==0)
            {
                scanf("%d",&x);
                for(int i=l;i<=r;i++) a[i]+=x;
            }
            else
            {
                ll ans=0;
                for(int i=l;i<=r;i++) ans^=sg(a[i]);
                puts(ans?"1":"0");
            }
        }
    }
}
namespace part1{
    struct node{
        bool cnt0,cnt1,tag;
    }t[MAXN<<3];
    inline void pushup(const int &x){t[x].cnt0=t[x<<1].cnt0^t[x<<1|1].cnt0;t[x].cnt1=t[x<<1].cnt1^t[x<<1|1].cnt1;}
    inline void pushdown(const int &x)
    {
        if(t[x].tag)
        {
            swap(t[x<<1].cnt0,t[x<<1].cnt1);swap(t[x<<1|1].cnt0,t[x<<1|1].cnt1);
            t[x<<1].tag^=1;t[x<<1|1].tag^=1;
            t[x].tag=0;
        }
    }
    void build(int x,int l,int r)
    {
        if(l==r) {t[x].cnt1=a[l]&1;t[x].cnt0=t[x].cnt1^1;return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid);build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void change(int x,int l,int r,int cl,int cr)
    {
        if(cl<=l&&r<=cr) {swap(t[x].cnt0,t[x].cnt1);t[x].tag^=1;return;}
        int mid=(l+r)>>1;pushdown(x);
        if(cl<=mid) change(x<<1,l,mid,cl,cr);
        if(cr>mid)  change(x<<1|1,mid+1,r,cl,cr);
        pushup(x);
    }
    bool query(int x,int l,int r,int ql,int qr)
    {
        if(ql<=l&&r<=qr) return t[x].cnt1;
        int mid=(l+r)>>1,ret=0;pushdown(x);
        if(ql<=mid) ret^=query(x<<1,l,mid,ql,qr);
        if(qr>mid)  ret^=query(x<<1|1,mid+1,r,ql,qr);
        return ret;
    }
    void solve()
    {
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d%d",&opt,&l,&r);
            if(opt==0)
            {
                scanf("%d",&x);
                if(x&1) change(1,1,n,l,r);
            }
            else printf("%d\n",query(1,1,n,l,r));
        }
    }
}
namespace part2{
    struct node{
        bool val[105];
        int tag;
    }t[MAXN<<3];
    int tmp[2][105];
    inline void pushup(const int &x)  {for(int i=0;i<=p;i++) t[x].val[i]=t[x<<1].val[i]^t[x<<1|1].val[i];}
    inline void pushdown(const int &x)
    {
        if(t[x].tag)
        {
            for(int i=0;i<=p;i++)
                tmp[0][i]=t[x<<1].val[i],tmp[1][i]=t[x<<1|1].val[i];
            for(int i=0;i<=p;i++)
                t[x<<1].val[(i+t[x].tag)%(p+1)]=tmp[0][i],
                t[x<<1|1].val[(i+t[x].tag)%(p+1)]=tmp[1][i];
            (t[x<<1].tag+=t[x].tag)%=(p+1);(t[x<<1|1].tag+=t[x].tag)%=(p+1);
            t[x].tag=0;
        }
    }
    void build(int x,int l,int r)
    {
        if(l==r) {t[x].val[a[l]%(p+1)]=1;return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid);build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void change(int x,int l,int r,int cl,int cr,int val)
    {
        if(cl<=l&&r<=cr)
        {
            (t[x].tag+=val)%=(p+1);
            for(int i=0;i<=p;i++) tmp[0][i]=t[x].val[i];
            for(int i=0;i<=p;i++)
                t[x].val[(i+val)%(p+1)]=tmp[0][i];
            return;
        }
        int mid=(l+r)>>1;pushdown(x);
        if(cl<=mid) change(x<<1,l,mid,cl,cr,val);
        if(cr>mid)  change(x<<1|1,mid+1,r,cl,cr,val);
        pushup(x);
    }
    int query(int x,int l,int r,int ql,int qr)
    {
        if(ql<=l&&r<=qr)
        {
            int ret=0;
            for(int i=1;i<=p;i+=2) ret^=t[x].val[i];
            ret^=t[x].val[p]*2;
            return ret;
        }
        int mid=(l+r)>>1,ret=0;pushdown(x);
        if(ql<=mid) ret^=query(x<<1,l,mid,ql,qr);
        if(qr>mid)  ret^=query(x<<1|1,mid+1,r,ql,qr);
        return ret;
    }
    void solve()
    {
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d%d",&opt,&l,&r);
            if(opt==0)
            {
                scanf("%d",&x);x%=(p+1);
                change(1,1,n,l,r,x);
            }
            else puts(query(1,1,n,l,r)?"1":"0");
        }
    }
}
int main()
{
    #ifndef LOCAL
        freopen("right.in","r",stdin);
        freopen("right.out","w",stdout);
    #endif
    scanf("%d%d%d",&n,&q,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n<=5000) brute_force::solve();
    else if(p&1) part1::solve();
    else if(p<=100) part2::solve();
}
