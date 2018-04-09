#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N=2e5+5;

typedef long long LL;

int n,m,h,t,D[N];

LL ans,s;

priority_queue <int> f;

priority_queue <int,vector<int>,greater<int> > g;

struct Data
{
    int x,y,typ;
}A[N];

bool operator < (const Data &a,const Data &b)
{
    return a.x<b.x || a.x==b.x && a.typ<b.typ;
}

char c;

int read()
{
    int x=0,sig=1;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-1;
    for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
    return x*sig;
}

int main()
{
    n=read(); m=read();
    for (int i=0;i<n;i++)
    {
        A[i].x=read(); A[i].typ=0;
    }
    for (int i=0;i<m;i++)
    {
        A[n].x=read(); A[n].y=read()-A[n].x; A[n++].typ=1;
    }
    sort(A,A+n);
    h=1;
    for (int i=0;i<n;i++)
    {
        if (A[i].typ==1) f.push(A[i].y);else
        {
            if (f.empty())
            {
                if (h<=t)
                {
                    s+=A[i].x-D[h++];
                    D[++t]=A[i].x;
                }
            }else
            {
                s+=A[i].x+f.top();
                g.push(f.top());
                f.pop();
                D[++t]=A[i].x;
            }
        }
    }
    ans=s;
    for (int i=h;i<=t;i++)
    {
        s-=g.top()+D[i];
        ans=max(ans,s);
        g.pop();
    }
    printf("%lld\n",ans);
    return 0;
}
