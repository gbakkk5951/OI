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
const int mv3[5][8]={
    {0,4,1,5,2,6,3,7},
    {0,2,1,3,4,6,5,7},
    {0,2,1,3,4,6,5,7},
    {0,2,4,6,1,3,5,7},
    {0,1,2,3,4,5,6,7}
};
const int mv2[3][4]={
    {0,2,1,3},
    {0,2,1,3},
    {0,1,2,3}
};
int n,a[10010],k,ln,rw,tot,tmp[10010],tt[10];
bool mp[11][11];
int main()
{
    #ifndef LOCAL
        freopen("left.in","r",stdin);
        freopen("left.out","w",stdout);
    #endif
    while(scanf("%d",&n)&&n)
    {
        k=1<<n;
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        if(n==1)
        {
            if(a[0]!=0) puts("1");
            else puts("0");
        }
        rw=2*n-1,ln=1<<(n-1);
        tot=rw*ln;
        bool ok=0;
        for(int s=0;s<1<<tot;s++)
        {
            for(int i=0;i<k;i++) tmp[i]=i;
            for(int i=0;i<rw;i++)
                for(int j=0;j<ln;j++)
                    mp[rw-i][ln-j]=s>>(i*ln+j)&1;
            for(int i=1;i<=rw;i++)
            {
                for(int j=1;j<=ln;j++)
                    if(mp[i][j]) swap(tmp[(j-1)<<1],tmp[((j-1)<<1)+1]);
                if(n==2)
                {
                    for(int j=0;j<4;j++)
                        tt[mv2[i-1][j]]=tmp[j];
                    for(int j=0;j<4;j++) tmp[j]=tt[j];
                }
                else
                {
                    for(int j=0;j<8;j++)
                        tt[mv3[i-1][j]]=tmp[j];
                    for(int j=0;j<8;j++) tmp[j]=tt[j];
                }
            }
            bool flag=1;
            for(int i=0;i<k;i++) if(a[i]!=tmp[i]) flag=0;
            if(flag) {ok=1;break;}
        }
        if(!ok) puts("-1");
        else
        {
            for(int i=1;i<=rw;i++)
            {
                for(int j=1;j<=ln;j++) printf("%d",mp[i][j]);
                puts("");
            }
        }
        puts("");
    }
}
