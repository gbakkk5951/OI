#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define debug cout
using namespace std;
const int maxn=1e4+1e2;
bool bug;
int t,n;
long long int a[10],b[10];
long long int ans,mod;
long long int gcd(long long int a,long long int b)
{
	return (!(a%b))?b:gcd(b,a%b);
}
long long int exgcd(long long int a,long long int b,long long int &x,long long int &y)
{
    long long int d=a;
    if(b)
    {
        d=exgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1,y=0;
    }
    return d;
}
long long int calc(long long int a1,long long int a2,long long int b1,long long int b2)
{
	if(b1==0&&b2==0) {mod=a1*a2/gcd(a1,a2);return 0;}
//	if(a1<a2){swap(a1,a2);swap(b1,b2);}
	long long int g=gcd(a1,a2),delta=(b2-b1);
//	printf("gcd(%lld,%lld)=%lld ",a1,a2,g);
	if(abs(delta)%g){bug=1;return 0;}
	mod=a1*a2/g;
	long long int y1,y2;
	exgcd(a1,a2,y1,y2);
//	printf("y1=%lld y2=%lld ",y1,y2);
	long long int ret=a1*y1*(delta/g)+b1;
	
	ret%=mod;
	if(ret<0) ret+=mod;
	return ret;
}
int main()
{int t;
scanf("%d",&t);
while(t--)
{

    scanf("%d",&n);
    if(n==1)
    {
        long long int aa,bb;
        scanf("%lld%lld",&aa,&bb);
        if(!bb) printf("0\n");
        else printf("%lld\n",aa-bb);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",a+i,b+i);
        if(b[i])
        b[i]=a[i]-b[i];
    //	printf("a[%d]=%lld;b[%d]=%lld\n",i,a[i],i,b[i]);
	}
    for(int i=1;i<n&&!bug;i++)
    {
        long long int num=calc(a[i],a[i+1],b[i],b[i+1]);
    //    printf("mod=%lld;num=%lld\n",mod,num);
		a[i+1]=mod;
        b[i+1]=num;
        ans=num;
    }
    if(bug) {printf("-1\n");return 0;}
    printf("%lld\n",ans);

}	return 0;
}
