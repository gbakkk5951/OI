#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;
const int maxn=1050;
struct node
{
    int arr,st,ed;//到达车站的时间,起点，终点。
}id[maxn*10];
int t[maxn];//最晚时间
int ti[maxn];//到达时间
int sum[maxn];//effect
int dis[maxn];//
int g[maxn];
int n,m,k;
void init ()
{
    memset(t,0,sizeof(t));
    memset(sum,0,sizeof(sum));
}
int main()
{
    ~scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i=1;i<n;i++)
        scanf("%d",&dis[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&id[i].arr,&id[i].st,&id[i].ed);
        t[id[i].st]=max(t[id[i].st],id[i].arr);//到大某点的最晚时间
        sum[id[i].ed]++;//到达某点的人数
    }
    for(int i=2;i<=n;i++)
        sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++)
        ti[i]=max(ti[i-1],t[i-1])+dis[i-1];
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=ti[id[i].ed]-id[i].arr;
    while(k)
    {
        g[n-1]=n;
        for(int i=n-2;i>0;i--)
        {
            if(ti[i+1]>t[i+1])
                g[i]=g[i+1];
            else
                g[i]=i+1;
        }
        int pos=0,ma=0;
        for(int i=1;i<n;i++)
        {
            if(dis[i]&&(sum[g[i]]-sum[i])>ma)
            {
                ma=sum[g[i]]-sum[i];
                pos=i;
            }
        }
        if(!ma)
            break;
        k--;
        dis[pos]--;
        ans-=ma;
        for(int i=1;i<=n;i++)
            ti[i]=max(ti[i-1],t[i-1])+dis[i-1];
    }
//    for(int i=1;i<n;i++)
//    {
//    	printf("%d ",dis[i]);
//	}
//	printf("\n");
    printf("%d\n",ans);
    return 0;
}
