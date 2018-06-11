#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define si scanf
#define so printf
#define N 100100
#define M 
#define INF  10000000000
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int n,K;
long long ln[N],ans,x[N];
inline long long ab(long long x)
{
	if(x>=0)	return x;
	else		return -x;
}
inline void solve(int r)
{
	for(int i=r-1;i;--i)
	{
		x[i]=min(x[i+1],x[i]);
		x[i]=min(x[i],ab(ln[r]-ln[i]));
		if(r-i+1>=K)
			ans=max(ans,(r-i)*x[i]);
	}
}
int main()
{
	freopen("gap.in","r",stdin);
	freopen("gap.out","w",stdout);
	int T;
	rd(T);
	while(T--)
	{
		rd(n),rd(K);
		for(int i=1;i<=n;++i)
			rd(ln[i]),x[i]=INF;
		ans=0;
		for(int r=1;r<=n;++r)
			solve(r);
		so("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
