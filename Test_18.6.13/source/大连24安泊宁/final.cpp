#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ded if (DEBUG)
#define enter ded puts("");
#define bzsi(x) for (int i=0;i<(x);i++)
#define bzsj(x) for (int j=0;j<(x);j++)
#define jqei(x) for (int i=1;i<=(x);i++)
#define jqej(x) for (int j=1;j<=(x);j++)
int DEBUG;
int getint()
{
	int t;
	scanf("%d",&t);
	return t;
}
int read(int &x)
{
	return scanf("%d",&x);
}
int read(long long &x)
{
	return scanf("%lld",&x);
}
void exgcd(int a,int b,int &x,int &y)
{
	if (!b)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main()
{
#ifdef BZSJBYT
DEBUG=1;
freopen("D:\\bzsjbyt\\bzsjbyt.in","r",stdin);
freopen("D:\\bzsjbyt\\bzsjbyt.out","w",stdout);
//prefer AD? cat? jqe? or female creeper?
#else
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
#endif
	int n;
	read(n);
	int a,b;
	read(a);
	read(b);
	int x,y;
	exgcd(a,b,x,y);
	printf("%d %d\n%d %d\n",a,b,-y,x);
	return 0;
}
