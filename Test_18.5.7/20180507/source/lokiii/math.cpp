#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005;
int n,a[N],b[25],ans;
int read()
{
	int r=0,f=1;
	char p=getchar();
	while(p>'9'||p<'0')
	{
		if(p=='-')
			f=-1;
		p=getchar();
	}
	while(p>='0'&&p<='9')
	{
		r=r*10+p-48;
		p=getchar();
	}
	return r*f;
}
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n<=20)
	{
		for(int i=1;i<(1<<n);i++)
		{
			int x=i,tot=0,f=1;
			for(int j=1;j<=n&&x;j++,x>>=1)
				if(x&1)
					b[++tot]=a[j];
			for(int j=1;j<=tot&&f;j++)
				for(int k=1;k<=tot&&f;k++)
					if(j!=k&&gcd(b[j],b[k])!=1)
						f=0;
			ans+=f;
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}