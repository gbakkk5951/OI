#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define mod %P
#define U 100000
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
int ps[U+100],np;
bool nop[U+100];
inline void pre()
{
	nop[1]=1;
	for(int i=2;i<=U;++i)
	{
		if(!nop[i])
			ps[++np]=i;
		for(int j=1;j<=np&&ps[j]*i<=U;++j)
		{
			nop[i*ps[j]]=1;
			if(i%ps[j]==0)
				return;
		}
	}
}
long long a,b,P;
inline long long power(long long ori,long long t)
{
	long long re=1;
	while(t)
	{
		if(t&1)
			re=re*ori mod;
		ori=ori*ori mod;
		t>>=1;
	}
	return re;
}
inline bool IsPrime()
{
	for(int j=1;j<=np;++j)
		if(P%ps[j]==0)
			return 0;
	return 1;
}
long long ans[200];
int main()
{
	freopen("teaegg.in","r",stdin);
	freopen("teaegg.out","w",stdout);
	rd(a),rd(b),rd(P);
	pre();
	if(!IsPrime())
		P=2;
	if(P==2)
	{
		if(b==0)
			ans[++ans[0]]=0;
		else
			ans[++ans[0]]=1;
		so("%lld\n%lld\n",ans[0],ans[1]);
		return 0;
	}
	for(int i=0;i<P;++i)
	{
		if(power(i,a)==b)
			ans[++ans[0]]=i;
	}
	so("%lld\n",ans[0]);
	for(int i=1;i<=ans[0];++i)
		so("%lld ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
