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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,ms,me,k;
int vs[20],ve[20],ans=0;;
int main()
{
    freopen("entertainment.in","r",stdin);
    freopen("entertainment.out","w",stdout);
    scanf("%d%d%d%d",&n,&k,&ms,&me);
    for(int i=1;i<=n;i++)
        scanf("%d",&vs[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&ve[i]);
    for(int s=0;s<(1<<n);s++)
    {
        int cnts=0,cnte=0,flag=0;
        int tans=0;
        for(int i=1;i<=n-k+1;i++)
        {
            cnte=cnts=flag=0;
            for(int j=0;j<=k-1;j++)
                cnts+=(s>>(i+j-1))&1,
                cnte+=((s>>(i+j-1))&1)^1;
            if(cnts<ms||cnte<me){flag=1;break;}
        }
        if(flag) continue;
        for(int i=1;i<=n;i++)
            tans+=vs[i]*((s>>(i-1))&1)+ve[i]*(((s>>(i-1))&1)^1);
        ans=max(ans,tans);
    }
    printf("%d\n",ans);
}
