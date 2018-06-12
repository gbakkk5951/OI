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
int a[MAXN],n,k;
multiset<int> s;
void solve()
{
    s.clear();ll ans=0;
    multiset<int>::iterator it1,it2;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n-k+1;i++)
    {
        s.clear();
        int min_gap=1<<30;
        for(int j=i;j<=n;j++)
        {
            it1=it2=s.insert(a[j]);
            if(it1!=s.begin()) --it1,min_gap=min(min_gap,a[j]-*it1);
            if(it2!=s.end())
            {
                ++it2;
                if(it2!=s.end()) min_gap=min(min_gap,*it2-a[j]);
            }
            if(j-i+1>=k&&min_gap!=1<<30)
                ans=max(ans,1ll*(j-i)*min_gap);
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    #ifndef LOCAL
        freopen("gap.in","r",stdin);
        freopen("gap.out","w",stdout);
    #endif
    int T;
    for(scanf("%d",&T);T--;solve());
    #ifdef LOCAL
        system("pause");
    #endif
}