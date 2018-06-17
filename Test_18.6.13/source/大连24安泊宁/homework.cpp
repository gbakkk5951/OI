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
#include<cmath>
const long double e=exp(-1);
long double cur=1-e;
int main()
{
#ifdef BZSJBYT
DEBUG=1;
//freopen("D:\\bzsjbyt\\bzsjbyt.in","r",stdin);
//1freopen("D:\\bzsjbyt\\bzsjbyt.out","w",stdout);
//prefer AD? cat? jqe? or female creeper?
#else
freopen("homework.in","r",stdin);
freopen("homework.out","w",stdout);
#endif
	int n;
	read(n);
	jqei(n) cur=1-cur*i;
	printf("%.4Lf",cur);
	
	return 0;
}
