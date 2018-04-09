#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 101000
#define INF 1e13
#define eps 1e-4
#define V e[i].v
using namespace std;
struct Eli
{
    int v,len,next;
}e[N<<1];
int head[N],cnt;
inline void add(int u,int v,int len)
{
    e[++cnt].v=v;
    e[cnt].len=len;
    e[cnt].next=head[u];
    head[u]=cnt;
}

int can[N],size[N],deep[N],q[N];
int L,R,tl,tr;
int n,length,dep;
int root,DEP;
double a[N],b[N],sum[N];
double ans,mid;
inline void getroot(int x,int p)
{
    int d=0;
    size[x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(can[V]&&V!=p)
        {
            getroot(V,x);
            size[x]+=size[V];
            d=max(d,size[V]);
        }
    d=max(n-size[x],d);
    if(d<length)length=d,root=x;
}
inline void dfs(int x,int p)
{
    size[x]=1;
    deep[x]=deep[p]+1;
    for(int i=head[x];i;i=e[i].next){
        if(can[V]&&V!=p){
            dfs(V,x);
            size[x]+=size[V];
        }
    }
    if(deep[x]>DEP)DEP=deep[x];
}
inline void dfs1(int x,int p)
{
    if(deep[x]>R)return; // ����Ȳ��ܾ�������
    a[deep[x]]=max(a[deep[x]],sum[x]);
    for(int i=head[x];i;i=e[i].next)
    {
        if(can[V]&&V!=p)
        {
            sum[V]=sum[x]+e[i].len-mid;
            dfs1(V,x);
        }
    }
    if(deep[x]>dep)dep=deep[x];
}
bool check()
{
    double mx,tmp,maxx;
    int pos,i,j;

    b[0]=0;
    for(i=1;i<=DEP;i++)b[i]=-INF;
    tmp=-INF;maxx=-INF;
    int maxp=0;
    for(i=head[root];i;i=e[i].next)if(can[V])
    {
        tl=tr=0;
        a[0]=0;
        for(j=1;j<=DEP;j++)a[j]=-INF;
        // ö����� a[i]��¼���������Ϊi�����Ȩ
        dep=0;
        sum[V]=e[i].len-mid;
        // ĿǰֻҪ��������iʱ���������mid����*·������
        dfs1(V,root);
        // ����a���飬ͬʱ��¼��ǰ������������ȡ�
        if(maxp)q[++tr]=maxp;
        for(j=1;j<=dep;j++)
        {
            if(j>R)break;
            if(tl<tr&&q[tl+1]>R-j)tl++;
            if(L>=j&&L-j<=DEP)
            {
                while(tl<tr&&b[q[tr]]<b[L-j])tr--;
                q[++tr]=L-j;
                tmp=max(tmp,b[q[tl+1]]+a[j]);
            }
            else if(j>L)tmp=max(tmp,b[q[tl+1]]+a[j]);
        }
        for(j=1;j<=dep;j++) // b_i�ǵ�ǰ�����������i���Ȩ
        {
            b[j]=max(b[j],a[j]);
            if(j>=L&&j<=R&&maxx<b[j])
                maxx=b[j],maxp=j;
        }
    }
    return tmp>0;
}
void work(int x)
{
    length=n,getroot(x,0); // ����������
    if(n<=L)return;
    DEP=0;
    dfs(root,0); // ����ÿ����������Ϊ����deep����ȣ�ͬʱ��¼������
    double l=ans,r=1e10;
    while(l<r-eps) // �����滮
    {
        mid=(l+r)/2;
        if(check())l=mid;
        else r=mid;
    }
    ans=l;
    can[root]=0; // �ݹ����
    for(int i=head[root];i;i=e[i].next)
        if(can[V])n=size[V],work(V);
}
int main()
{
    scanf("%d%d%d",&n,&L,&R);
    int x,y,z;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    memset(can,-1,sizeof can);
    deep[0]=-1;
    work(1);
    printf("%.3lf\n",ans);
    return 0;
}
