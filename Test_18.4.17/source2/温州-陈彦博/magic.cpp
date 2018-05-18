#include<cstdio>
#include<cstring>
#include<algorithm>
#define MO 1000000007
using namespace std;
int ans,uu,ww,dd,y,ll,w[1500000],c[1500000],d[22],g[1500000];
int m,o,p,wqy,c1,a[1500000],n,k;
inline int read(){
    int ret=0;char c=getchar();
    while((c>'9')||(c<'0'))c=getchar();
    while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
    return ret;
}

inline int ni(int o)
{
	d[0]=o;
	for(int i=1; i<=19; ++i)d[i]=(long long)d[i-1]*d[i-1]%k;
	int kk=k-2,cc=1;
	for(int i=19; i>=0; --i)
	{
		if(1<<i<=kk)
		{
			kk-=1<<i;
			cc=(long long)cc*d[i]%k;
		}
	}
	return cc;
}

int main()
{
    freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read(); k=read();
	for(int i=0; i<n; ++i)a[i]=read();
	if(n<=1000)
	{
		m=n;
		for(int j=m; j>1; --j)
		for(int i=0; i<j-1; ++i)a[i]=(a[i]+a[i+1])%k;
		printf("%d",a[0]);
		return 0;
	}   
	c[0]=1; o=1; p=1;
	for(int i=1; i<=n-1; ++i)
	if(i%k)c[i]=(long long)c[i-1]*i%k,w[i]=w[i-1];
	else 
	{
		ll=1; y=i;
		while(!y%k)
		{
			++ll;
			y/=k;
		}
		w[i]=w[i-1]+ll;
	}
	ww=w[n-1];
	dd=c[n-1];
	for(int i=0; i<=n-1; ++i)
	{
		o=c[i];
		p=c[n-i-1];
		c1=w[0]+w[n-i-1];
		if(ww>c1)
		{
			g[i]=0;
			continue;
		}
		uu=(long long)o*p%k;
		wqy=ni(uu);
		g[i]=(long long )dd*wqy%k;
	}
	for(int i=0; i<n; ++i)
	ans=(ans+(long long)a[i]*g[i]%k)%k;
	printf("%d",ans); 
}
