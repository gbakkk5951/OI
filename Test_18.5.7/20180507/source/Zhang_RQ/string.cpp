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
const int MAXN=1E6+10;
int n,lg2[MAXN],ans=0;
char s[MAXN];
struct Suffix_Array{
    int Rank[MAXN],sa[MAXN],tp[MAXN],sum[MAXN],height[MAXN];
    int st[MAXN][22];
    void get_sa(int n,char *str)
    {
        int m=127;
        for(int i=1;i<=n;i++) Rank[i]=str[i],tp[i]=i;
        for(int i=0;i<=m;i++) sum[i]=0;
        for(int i=1;i<=n;i++) sum[Rank[tp[i]]]++;
        for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
        for(int i=n;i>=1;i--) sa[sum[Rank[tp[i]]]--]=tp[i];
        int p=1;
        for(int len=1;p<n;m=p,len<<=1)
        {
            p=0;
            for(int i=n-len+1;i<=n;i++) tp[++p]=i;
            for(int i=1;i<=n;i++) if(sa[i]>len) tp[++p]=sa[i]-len;
            for(int i=0;i<=m;i++) sum[i]=0;
            for(int i=1;i<=n;i++) sum[Rank[tp[i]]]++;
            for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
            for(int i=n;i>=1;i--) sa[sum[Rank[tp[i]]]--]=tp[i];
            swap(Rank,tp);Rank[sa[1]]=1,p=1;
            for(int i=2;i<=n;i++)
                Rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&(sa[i]+len<=n&&sa[i-1]+len<=n&&tp[sa[i]+len]==tp[sa[i-1]+len]))?p:++p;
        }
        int lst=0,j;
        for(int i=1;i<=n;height[Rank[i++]]=lst)
            for(lst=lst?lst-1:lst,j=sa[Rank[i]-1];str[i+lst]==str[j+lst];lst++);
    }
    void get_st(int n)
    {
        for(int i=1;i<=n;i++) st[i][0]=height[i];
        for(int j=1;j<=lg2[n];j++)
            for(int i=1;i<=n;i++)
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
    int query(int l,int r)
    {
        l=Rank[l],r=Rank[r];
        if(l>r) swap(l,r);
        l++;
        int len=lg2[r-l+1];
        return min(st[l][len],st[r-(1<<len)+1][len]);
    }
}SA,rSA;
inline int LCP(const int &i,const int &j) {return SA.query(i,j);}
inline int LCS(const int &i,const int &j) {return rSA.query(n-i+1,n-j+1);}
int main()
{
    #ifndef LOCAL
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
    #endif
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    SA.get_sa(n,s);SA.get_st(n);
    reverse(s+1,s+1+n);
    rSA.get_sa(n,s);rSA.get_st(n);
    reverse(s+1,s+1+n);
    for(int len=1;(len<<1)<=n;len++)
    {
        for(int i=1,j=len+1;j<=n;i+=len,j+=len)
        {
            if(s[i]!=s[j]) continue;
            int x=LCP(i,j),y=LCS(i-1,j-1);
            if(x+y>=len) ans=len;
        }
    }
    printf("%d\n",ans*2);
}
