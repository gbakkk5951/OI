#include<cstdio>
#include<algorithm>
using namespace std;
long long err[]={233,2333,23333,233333,2333333,23333333,233333333,2333333333LL,23333333333LL,233333333333LL,2333333333333LL,23333333333333LL,233333333333333LL,2333333333333333LL,23333333333333333LL};
long long f[111111]={};
int te,n,q;
long long x,y,z;
struct ff{long long x,y;};
void incc(int x,int y)
{
	for(int i=x;i<=y;i++)
		f[i]++;
}
bool check(int x,int y)
{
	for(int i=x;i<=y;i++)
		for(int j=0;j<15;j++)
			if(f[i]==err[j])
				return true;
	return false;
}
void getmax(int x,int y)
{
	long long maxx=0;
	for(int i=x;i<=y;i++)
		maxx=max(maxx,f[i]);
	for(int i=x;i<=y;i++)
		f[i]=maxx;
}
void getmin(int x,int y)
{
	long long minx=123456789123456789LL;
	for(int i=x;i<=y;i++)
		minx=min(minx,f[i]);
	for(int i=x;i<=y;i++)
		f[i]=minx;
}
void chu(ff &m,long long n)
{
	m.y+=m.x%n*10000000;
	m.x/=n,m.y/=n;
	m.x+=m.y/10000000;
	m.y%=10000000;
}
void jiaa(ff &a,ff b)
{
	a.x+=b.x,a.y+=b.y;
	a.x+=a.y/10000000,a.y%=10000000;
}
void jia(ff &m,long long n)
{
	m.y+=n;
	m.x+=(m.y/10000000);
	m.y%=10000000;
}
ff summ(ff a,ff b)
{
	a.x+=b.x,a.y+=b.y;
	a.x+=a.y/10000000;a.y%=10000000;
	return a;
}
void cheng(ff &m,long long n)
{
	m.x*=n,m.y*=n;
	m.x+=m.y/10000000;
	m.y%=10000000;
}
ff chengg(ff m,long long n)
{
	m.x*=n,m.y*=n;
	m.x+=m.y/10000000;
	m.y%=10000000;
	return m;
}
void getavg(int x,int y)
{
	ff sum={};
	for(int i=x;i<=y;i++)
		jia(sum,f[i]);
	chu(sum,y-x+1);
	for(int i=x;i<=y;i++)
		f[i]=sum.x*10000000+sum.y;
}
int main()
{
	freopen("1","r",stdin);
	freopen("2","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&te,&x);
		switch(te)
		{
		case 1:
			printf("%lld\n",f[x]);
			break;
		case 2:
			scanf("%lld%lld",&y,&z);
			for(int i=x;i<=y;i++)f[i]=z;
			while(check(x,y))
				incc(x,y);
			break;
		case 3:
			scanf("%lld%lld",&y,&z);
			for(int i=x;i<=y;i++)f[i]+=z;
			while(check(x,y))
				incc(x,y);
			break;
		case 4:
			scanf("%lld",&y);
			getmax(x,y);
			break;
		case 5:
			scanf("%lld",&y);
			getmin(x,y);
			break;
		case 6:
			scanf("%lld",&y);
			getavg(x,y);
			while(check(x,y))
				incc(x,y);
			break;
		}
	}
}
