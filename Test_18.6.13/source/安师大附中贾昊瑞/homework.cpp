#include"bits/stdc++.h"
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(register int i=j;i>=n;i--)
#define ll long long
using namespace std;
void in(int&a);void in(ll&a);
long double ans,x=1,a=1;int n;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	#endif
	in(n);
	F(i,n+1,n+100000)a/=i,ans+=x*a,x=-x;
	printf("%.4lf\n",(double)ans);
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=0;c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=0;c=getchar();}if(y)a=-a;}

