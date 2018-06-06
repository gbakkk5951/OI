#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000010;
const int inf=0x3f3f3f3f;
struct node
{
    int d[2],mx[2],mn[2],l,r;
    int& operator [](int x){return d[x];}
    node(int x=0,int y=0) 
    {
        d[0]=x;d[1]=y;l=0;r=0;
    }
};
node p[maxn];
int n,m,D,root;
bool operator < (node a,node b)
{
    return a[D]<b[D];
}
int dis(node a,node b)
{
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}
struct kdtree
{
    int ans;
    node T[maxn],t;
    void update(int x)
    {
        node l=T[T[x].l],r=T[T[x].r];
        for(int i=0;i<2;i++)
        {
            if(T[x].l) T[x].mn[i]=min(T[x].mn[i],l.mn[i]),T[x].mx[i]=max(T[x].mx[i],l.mx[i]);
            if(T[x].r) T[x].mn[i]=min(T[x].mn[i],r.mn[i]),T[x].mx[i]=max(T[x].mx[i],r.mx[i]);
        }
    }
    int build(int l,int r,int now)  {
        D=now;
        int mid=(l+r)>>1;
        nth_element(p+l,p+mid,p+r+1);
        T[mid]=p[mid];
        for(int i=0;i<2;i++)
            T[mid].mn[i]=T[mid].mx[i]=T[mid][i];
        if(l<mid) T[mid].l=build(l,mid-1,now^1);
        if(r>mid) T[mid].r=build(mid+1,r,now^1);
        update(mid);
        return mid;
    }
    int getdist(int x,node p){
        int res=0;
        for(int i=0;i<2;i++)
            res+=max(0,T[x].mn[i]-p[i]);
        for(int i=0;i<2;i++)
            res+=max(0,p[i]-T[x].mx[i]);
        return res;
    }
    void insert(int k,int now, int dep = 0){
        if(T[k][now]<=t[now])
        {
            if(T[k].r) insert(T[k].r,now^1, dep + 1);
            else
            {
			//	cerr << "dep = " << dep << endl;
				
                n++;T[k].r=n;T[n]=t;
                for(int i=0;i<2;i++)
                    T[n].mn[i]=T[n].mx[i]=T[n][i];
            }
        }
        else
        {
            if(T[k].l) insert(T[k].l,now^1, dep + 1);
            else
            {
			//	cerr << "dep = " << dep << endl;
                n++;T[k].l=n;T[n]=t;
                for(int i=0;i<2;i++)
                    T[n].mn[i]=T[n].mx[i]=T[n][i];
            }
        }
        update(k);
    }
    void query(int x,int now){
        int d,dl=inf,dr=inf;
        d=dis(T[x],t);
        ans=min(ans,d);
        if(T[x].l) dl=getdist(T[x].l,t);
        if(T[x].r) dr=getdist(T[x].r,t);
        if(dl<dr)
        {
            if(dl<ans) query(T[x].l,now^1);
            if(dr<ans) query(T[x].r,now^1);
        }
        else
        {
            if(dr<ans) query(T[x].r,now^1);
            if(dl<ans) query(T[x].l,now^1);  
        }
    }
    int query(node p)
    {
        ans=inf;
        t=p;query(root,0);
        return ans;
    }
    void insert(node p)
    {
        t=p;insert(root,0);
    }
}kd;
int k,op,x,y;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i][0],&p[i][1]);
    root=kd.build(1,n,0);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op==1) kd.insert(node(x,y));
        else printf("%d\n",kd.query(node(x,y)));
    }
    return 0;
}
