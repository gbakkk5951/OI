#include <bits/stdc++.h>
using namespace std;

const int g=3;
const int N=10005;
const int M=1000005;
const int modA=100000;
const int mod=998244353;
const double e=2.7182818284590452353602874713527;
int n,d;
int w[M][2],nex[M];
int a[M],b[M],c[M],u[M],v[M];
double f[N];

int qpow(int a,int b,int c)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%c;
		a=1ll*a*a%c;
		b>>=1;
	}
	return ans;
}

void NTT(int *a,int l,int f)
{
	int i,j,k,x,y,p;
	for(i=0;i<l;i++)
	    nex[i]=(nex[i>>1]>>1)|((i&1)*(l/2));
	for(i=0;i<l;i++)
	    if(nex[i]>i)
	        swap(a[i],a[nex[i]]);
	for(i=1;i<l;i<<=1)
	    for(j=0;j<l;j+=(i<<1))
	        for(k=0,p=1;k<i;k++,p=1ll*p*w[i<<1][f]%mod)
	            x=a[j+k],y=1ll*a[j+k+i]%mod,a[j+k]=(x+y)%mod,a[j+k+i]=(x-y+mod)%mod;
	if(f)
		for(i=0,j=qpow(l,mod-2,mod);i<n;i++)
		    a[i]=1ll*a[i]*j%mod;
}

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	if(n<=10)
	{
		f[0]=1-1.0/e;
		for(i=1;i<=n;i++)
		    f[i]=1-i*f[i-1];
		printf("%.4lf",f[n]);
		return 0;
	}
	a[0]=1,a[1]=1,c[0]=1,c[1]=1;
	for(i=1;i<M;i<<=1)
	    w[i][0]=qpow(g,(mod-1)/i,mod),w[i][1]=qpow(w[i][0],mod-2,mod);
	for(i=n;i>=3;i--)
	{
		for(j=1,d=0;j<=a[0]||d;j++)
		{
		    a[j]=1ll*a[j]*i+d;
		    d=a[j]/modA;
		    a[j]%=modA;
		}
		a[0]=j-1;
	    if((n-i)%2)
	    {
	    	for(j=1,d=0;j<=max(a[0],c[0])||d;j++)
	    	{
	    		c[j]=c[j]+a[j]+d;
	    		d=c[j]/modA;
	    		c[j]%=modA;
	    	}
	    	c[0]=j-1;
	    }
	    else
	    {
	    	for(j=1,d=0;j<=max(a[0],b[0])||d;j++)
	    	{
	    		b[j]=b[j]+a[j]+d;
	    		d=b[j]/modA;
	    		b[j]%=modA;
	    	}
	    	b[0]=j-1;
	    }
	}
	cerr<<a[0]<<" "<<b[0]<<" "<<c[0]<<endl;
	//c-b+n!/e
	//c-b;
	//f[0]=-1;
	//fi=1-i*f[i-1]
	//printf("%.4lf",a+b*1.0/e);
	return 0;
}

