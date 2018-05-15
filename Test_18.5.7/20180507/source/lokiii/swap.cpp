#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
int n,a[N],b[N],x[N],y[N],tot,v[N];
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
int main()
{
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),v[a[i]]=i;
	for(int i=1;i<=n;i++)
		b[i]=read();
	for(int i=n;i>=1;i--)
		if(a[i]!=b[i])
		{
			int x1=a[v[b[i]]],x2=a[i];//cerr<<x1<<" "<<x2<<endl;
			swap(a[v[b[i]]],a[i]);
			x[++tot]=v[x1],y[tot]=v[x2];
			swap(v[x1],v[x2]);
		}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}