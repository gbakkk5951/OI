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
const int forbid[7]={233,2333,23333,233333,2333333,23333333,233333333};
bool j_forbid(int val){for(int i=0;i<6;i++){if(forbid[i]==val) return 1;}return 0;}
int n,q;
namespace solve1{
    const int MAXN=4010;
    int a[MAXN],opt,pos,l,r,x;
    void solve()
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&opt);
            if(opt==1)
                scanf("%d",&pos),printf("%d\n",a[pos]);
            if(opt==2)
            {
                scanf("%d%d%d",&l,&r,&x);
                if(j_forbid(x)) ++x;
                for(int j=l;j<=r;j++) a[j]=x;
            }
            if(opt==3)
            {
                scanf("%d%d%d",&l,&r,&x);
                for(int j=l;j<=r;j++)
                    a[j]+=x;
                while(1)
                {
                    int flg=1;
                    for(int j=l;j<=r;j++) if(j_forbid(a[j])) {flg=0;break;}
                    if(flg) break;
                    for(int j=l;j<=r;j++) ++a[j];
                }
            }
            if(opt==4)
            {
                scanf("%d%d",&l,&r);
                int mn=2E9;
                for(int j=l;j<=r;j++) mn=min(mn,a[j]);
                for(int j=l;j<=r;j++) a[j]=mn;
            }
            if(opt==5)
            {
                scanf("%d%d",&l,&r);                
                int mx=0;
                for(int j=l;j<=r;j++) mx=max(mx,a[j]);
                for(int j=l;j<=r;j++) a[j]=mx;
            }
            if(opt==6)
            {
                scanf("%d%d",&l,&r);                
                ll sum=0;
                for(int j=l;j<=r;j++) sum+=a[j];
                sum/=(r-l+1);
                if(j_forbid(sum)) ++sum;
                for(int j=l;j<=r;j++) a[j]=sum;
            }
        }
    }
}
namespace solve2{
    const int MAXN=100010;
    struct node{
        int tag_p,tag,mn,mx;
        ll sum;
        node(){tag=-1;}
    }t[MAXN<<3];
    int a[MAXN];
    inline void pushup(int x)
    {
        t[x].sum=t[x<<1].sum+t[x<<1|1].sum;
        t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx);
        t[x].mn=min(t[x<<1].mn,t[x<<1|1].mn);
    } 
    inline void pushdown(int x,int l,int r)
    {
        if(t[x].tag!=-1)
        {
            int mid=(l+r)>>1;
            t[x<<1].sum=1ll*t[x].tag*(mid-l+1);
            t[x<<1|1].sum=1ll*t[x].tag*(r-mid);
            t[x<<1].mn=t[x<<1].mx=t[x<<1|1].mn=t[x<<1|1].mx=t[x].tag;
            t[x<<1].tag=t[x].tag;t[x<<1|1].tag=t[x].tag;
            t[x].tag=-1;t[x<<1].tag_p=t[x<<1|1].tag_p=0;
        }
        if(t[x].tag_p)
        {
            int mid=(l+r)>>1;
            t[x<<1].sum+=1ll*t[x].tag_p*(mid-l+1);
            t[x<<1|1].sum+=1ll*t[x].tag_p*(r-mid);
            t[x<<1].mn+=t[x].tag_p;t[x<<1].mx+=t[x].tag_p;
            t[x<<1|1].mn+=t[x].tag_p;t[x<<1|1].mx+=t[x].tag_p;
            if(t[x<<1].tag!=-1) t[x<<1].tag+=t[x].tag_p;
            else t[x<<1].tag_p+=t[x].tag_p;
            if(t[x<<1|1].tag!=-1) t[x<<1|1].tag+=t[x].tag_p;
            else t[x<<1|1].tag_p+=t[x].tag_p;
            t[x].tag_p=0;
        }
    }
    void build(int x,int l,int r)
    {
        if(l==r)
        {
            t[x].sum=t[x].mn=t[x].mx=a[l];t[x].tag=-1;
            return;
        }
        int mid=(l+r)>>1;
        t[x].tag=-1;
        build(x<<1,l,mid);build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void change(int x,int l,int r,int cl,int cr,int val)
    {
        if(cl<=l&&r<=cr)
        {
            t[x].sum=1ll*val*(r-l+1);
            t[x].mn=t[x].mx=val;
            t[x].tag=val;t[x].tag_p=0;
            return;
        }
        int mid=(l+r)>>1;pushdown(x,l,r);
        if(cl<=mid) change(x<<1,l,mid,cl,cr,val);
        if(cr>mid)  change(x<<1|1,mid+1,r,cl,cr,val);
        pushup(x);
    }
    void plus(int x,int l,int r,int cl,int cr,int val)
    {
        if(cl<=l&&r<=cr)
        {
            t[x].sum+=1ll*val*(r-l+1);
            t[x].mn+=val;t[x].mx+=val;
            t[x].tag_p+=val;
            return;
        }
        int mid=(l+r)>>1;pushdown(x,l,r);
        if(cl<=mid) plus(x<<1,l,mid,cl,cr,val);
        if(cr>mid)  plus(x<<1|1,mid+1,r,cl,cr,val);
        pushup(x);
    }
    ll ask_sum(int x,int l,int r,int ql,int qr)
    {
        if(ql<=l&&r<=qr) return t[x].sum;
        int mid=(l+r)>>1;pushdown(x,l,r);
        ll ret=0;
        if(ql<=mid) ret+=ask_sum(x<<1,l,mid,ql,qr);
        if(qr>mid)  ret+=ask_sum(x<<1|1,mid+1,r,ql,qr);
        return ret;
    }
    int ask_val(int x,int l,int r,int pos)
    {
        if(l==r) return t[x].sum;
        int mid=(l+r)>>1;pushdown(x,l,r);
        if(pos<=mid) return ask_val(x<<1,l,mid,pos);
        else return ask_val(x<<1|1,mid+1,r,pos);
    }
    int ask_max(int x,int l,int r,int ql,int qr)
    {
        if(ql<=l&&r<=qr) return t[x].mx;
        int mid=(l+r)>>1,ret=0;pushdown(x,l,r);
        if(ql<=mid) ret=max(ret,ask_max(x<<1,l,mid,ql,qr));
        if(qr>mid)  ret=max(ret,ask_max(x<<1|1,mid+1,r,ql,qr));
        return ret;
    }
    int ask_min(int x,int l,int r,int ql,int qr)
    {
        if(ql<=l&&r<=qr) return t[x].mn;
        int mid=(l+r)>>1,ret=1E9;pushdown(x,l,r);
        if(ql<=mid) ret=min(ret,ask_min(x<<1,l,mid,ql,qr));
        if(qr>mid)  ret=min(ret,ask_min(x<<1|1,mid+1,r,ql,qr));
        return ret;
    }
    void solve()
    {
        int opt,l,r,x;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&opt);
            if(opt==1) scanf("%d",&x),printf("%d\n",ask_val(1,1,n,x));
            if(opt==2)
            {
                scanf("%d%d%d",&l,&r,&x);
                if(j_forbid(x)) ++x;
                change(1,1,n,l,r,x);
            }
            if(opt==3)
            {
                scanf("%d%d%d",&l,&r,&x);
                plus(1,1,n,l,r,x);
            }
            if(opt==4)
            {
                scanf("%d%d",&l,&r);
                int mx=ask_max(1,1,n,l,r);
                change(1,1,n,l,r,mx);
            }
            if(opt==5)
            {
                scanf("%d%d",&l,&r);
                int mn=ask_min(1,1,n,l,r);
                change(1,1,n,l,r,mn);
            }
            if(opt==6)
            {
                scanf("%d%d",&l,&r);
                ll sum=ask_sum(1,1,n,l,r)/(r-l+1);
                change(1,1,n,l,r,sum);
            }
        }
    }
}
int main()
{
    #ifndef LOCAL
        freopen("eee.in","r",stdin);
        freopen("eee.out","w",stdout);
    #endif
    scanf("%d%d",&n,&q);
    if(n<=4500) solve1::solve();
    else solve2::solve();
    #ifdef LOCAL
        system("pause");
    #endif
}