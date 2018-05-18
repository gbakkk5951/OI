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
int n,a[2010];
int tmp[2010],top,ans;
int gcd(int a,int b)
{
    if(!a||!b) return a|b;
    return a<b?gcd(b%a,a):gcd(a%b,b);
}
int main()
{
    #ifndef LOCAL
        freopen("math.in","r",stdin);
        freopen("math.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int s=1;s<(1<<n);s++)
    {
        top=0;
        for(int i=0;i<n;i++) if((s>>i)&1) tmp[++top]=a[i+1];
        bool ok=1;
        for(int i=1;i<top;i++)
            for(int j=i+1;j<=top;j++)
                if(gcd(tmp[i],tmp[j])!=1) ok=0;
        ans+=ok;
    }
    printf("%d\n",ans);
}
