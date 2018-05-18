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
int n,a[200010],b[200010];
int t[15],term,beg;
map<int,pair<int,int> > mp,to;
map<int,bool> ins;
map<int,int> tos;
int zip()
{
    int ret=0,base=1;
    for(int i=1;i<=n;i++,base*=10) ret+=t[i]*base;
    return ret;
}
void unzip(int s)
{
    for(int i=1;i<=n;i++) t[i]=s%10,s/=10;
}
pair<int,int> dfs(int s,int lsts)
{
    if(mp.count(s)) return mp[s];
    ins[s]=1;
    pair<int,int> ret=make_pair(23333333,23333333);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            unzip(s);
            swap(t[i],t[j]);
            int ns=zip();
            if(ins[ns]) continue;
            pair<int,int> np=dfs(ns,s);
            np.first+=j-i,np.second+=1;
            if(np.first<ret.first||(np.first==ret.first&&np.second<ret.second))
                ret=np,tos[s]=ns,to[s]=make_pair(i,j);
        }
    ins[s]=0;
    return mp[s]=ret;
}
void print()
{
    int S=beg;
    while(S!=term)
    {
        printf("%d %d\n",to[S].first,to[S].second);
        S=tos[S];
    }
}
int main()
{
    #ifndef LOCAL
        freopen("swap.in","r",stdin);
        freopen("swap.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    if(n==1) puts("0");
    else if(n==2)
    {
        if(a[1]==b[1]) puts("0");
        else puts("1\n1 2");
    }
    bool ok=1;
    for(int i=1;i<=n;i++) if(a[i]!=i) ok=0;
    for(int i=1;i<=n;i++) if(b[i]!=i%n+1) ok=0;
    if(ok)
    {
        printf("%d\n",n-1);
        for(int i=1;i<n;i++) printf("%d %d\n",i,i+1);
    }
    else if(n<=8)
    {
        for(int i=1;i<=n;i++) t[i]=b[i];
        term=zip();
        mp[term]=make_pair(0,0);
        for(int i=1;i<=n;i++) t[i]=a[i];
        beg=zip();
        dfs(beg,0);
        printf("%d\n",mp[beg].second);
        print();
    }
    else
    {
        int flag=1;
        for(int i=1;i<=n;i++) if(a[i]!=b[i]) flag=0;
        if(flag) puts("0");
    }
}
