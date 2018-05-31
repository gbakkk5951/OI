#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define si scanf
#define so printf
#define N 100100
#define INF  10000000000000
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
int n,nq; 
long long a[N];
long long fbd[20];
int main()
{
	freopen("eee.in","r",stdin);
	freopen("eee.out","w",stdout);
	rd(n),rd(nq);
	for(int i=1;i<=n;++i)
		rd(a[i]);
	int op,l,r;
	long long sm,mx,mn,x; 
	fbd[1]=233;
	for(int i=2;i<=16;++i)
		fbd[i]=fbd[i-1]*10+3;
	bool exst;
	for(int qq=1;qq<=nq;++qq)
	{
		rd(op);
		if(op==1)
		{
			rd(l);
			so("%lld\n",a[l]);
			continue;
		}
		rd(l),rd(r);
		if(op==2)
		{
			rd(x); 
			for(int i=l;i<=r;++i)
				a[i]=x;
		}
		else if(op==3)
		{
			rd(x);
			for(int i=l;i<=r;++i)
				a[i]+=x;
		}
		else if(op==4)
		{
			mx=-INF;
			for(int i=l;i<=r;++i)
				mx=max(mx,a[i]);
			for(int i=l;i<=r;++i)
				a[i]=mx;
		}
		else if(op==5)
		{
			mn=INF;
			for(int i=l;i<=r;++i)
				mn=min(mn,a[i]);
			for(int i=l;i<=r;++i)
				a[i]=mn;
		}
		else if(op==6)
		{
			sm=0;
			for(int i=l;i<=r;++i)
				sm+=a[i];
			sm=floor(1.0*sm/(1.0*(r-l+1)));
			for(int i=l;i<=r;++i)
				a[i]=sm;
		}
		while(1)
		{
			exst=0;
			for(int i=l;i<=r&&!exst;++i)
			for(int j=1;j<=16&&!exst;++j)
				if(a[i]==fbd[j])
					exst=1;
			if(!exst)
				break;
			for(int i=l;i<=r;++i)
				++a[i];
		}
		
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
