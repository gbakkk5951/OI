#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define U 3000000
#define P 1000000007
#define mod %P
#define inv2 500000004
#define inv6 166666668
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
int ps[U+100],np;
bool nop[U+100];
long long phi[U+100],iphi[U+100],iiphi[U+100];
long long sm[U+100];
void pre()
{
	nop[1]=1,phi[1]=1;
	for(int i=2;i<=U;++i)
	{
		if(!nop[i])
		{
			ps[++np]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=np&&ps[j]*i<=U;++j)
		{
			nop[i*ps[j]]=1;
			if(i%ps[j]==0)
			{
				phi[i*ps[j]]=phi[i]*ps[j];
				break;
			}
			else
				phi[i*ps[j]]=phi[i]*(ps[j]-1);
		}
	}
	for(int i=1;i<=U;++i)
	{
		iphi[i]=phi[i]*i mod;
		iiphi[i]=iphi[i]*i mod;
		iphi[i]+=iphi[i-1];
		if(iphi[i]>=P)
			iphi[i]-=P;
		iiphi[i]+=iiphi[i-1];
		if(iiphi[i]>=P)
			iiphi[i]-=P;
		phi[i]+=phi[i-1];
		if(phi[i]>=P)
			phi[i]-=P;
		sm[i]=1LL*(i+1)*i mod*inv2 mod;
	}
}
long long n,m,S,ans;
inline long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
inline long long solve0()
{
	long long re=P-S,mn=min(n,m);
	for(long long l=1,r;l<=mn;l=r+1)
	{
		r=min(n/(n/l),m/(m/l));
		re+=(n/l)*(m/l)mod*(phi[r]-phi[l-1]+P)mod;
		if(re>=P)
			re-=P;
	}
	return re;
}
inline long long solve1()
{
	long long re=P-sm[n]*m mod,mn=min(n,m);
	for(long long l=1,r;l<=mn;l=r+1)
	{
		r=min(n/(n/l),m/(m/l));
		re+=(m/l)*sm[n/l]mod*(iphi[r]-iphi[l-1]+P)mod;
		if(re>=P)
			re-=P;
	}
	return re;
}
inline long long solve2()
{
	long long re=P-sm[n]*sm[m]mod,mn=min(n,m);
	for(long long l=1,r;l<=mn;l=r+1)
	{
		r=min(n/(n/l),m/(m/l));
		re+=sm[n/l]*sm[m/l]mod*(iiphi[r]-iiphi[l-1]+P)mod;
		if(re>=P)
			re-=P;
	}
	return re;
}
int main()
{
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	pre();
	while(1)
	{
		rd(n),rd(m);
		if(n==0&&m==0)
			break;
		++n,++m;
		S=n*m mod;
		ans=(S*(S-1)mod)*((S-2)*inv6 mod)mod;
		ans-=(n*(n-1)mod)*((n-2)*inv6)mod*m mod;
		ans-=(m*(m-1)mod)*((m-2)*inv6)mod*n mod;
		ans-=2*S*solve0()mod;
		ans+=2*m*solve1()mod;
		swap(n,m);
		ans+=2*m*solve1()mod;
		ans-=2*solve2()mod;
		ans=(ans mod+P)mod;
		so("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
