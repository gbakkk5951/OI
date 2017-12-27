#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define lowbit(x) (x&-x)
#define debug cout
const int maxn=200000+10;
lli org[maxn],added[maxn];
lli n,m;
void update(lli x,lli y,lli *to)
{
	while(x<=n)
	{
		to[x]+=y;
		x+=lowbit(x);
	}
}
lli query(lli x,lli *to)
{
	lli sum=0;
	while(x)
	{
		sum+=to[x];
		x-=lowbit(x);
	}
	return sum;
}
int main()
{
	scanf("%lld",&n);
	for(lli i=1,tmp;i<=n;i++)
	{
		scanf("%lld",&tmp);
		update(i,tmp,org);
	}
	scanf("%lld",&m);
	for(lli i=1,q,a,b,x;i<=m;i++)
	{
		scanf("%lld",&q);
		if(q==1)
		{
			scanf("%lld%lld%lld",&a,&b,&x);
			//debug<<a<<b<<x<<endl;
			update(a,-(a-1)*x,org);
			update(a,x,added);
			update(b,b*x,org);
			update(b,-x,added);
		}
		else if(q==2)
		{
			scanf("%lld%lld",&a,&b);
			lli ans=0;
			ans+=query(b,org)+b*query(b,added);
			ans-=query(a-1,org)+(a-1)*query(a-1,added);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
