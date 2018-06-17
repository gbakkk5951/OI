#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
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
long double cntdis(long double u1,long double v1,long double u2,long double v2)
{
	long double d1=u1-u2;
	long double d2=v1-v2;
	return sqrt(d1*d1+d2*d2);	
}
vector<pair<long double,long double> > points;
#define mk make_pair
#define fi first
#define se second
int main()
{
#ifdef BZSJBYT
DEBUG=1;
freopen("D:\\bzsjbyt\\bzsjbyt.in","w",stdout);
//prefer AD? cat? jqe? or female creeper?
#else
#endif
	srand(time(0));
	int n;
	n=100;
	bzsi(n)
	points.push_back(mk((long double)rand()/RAND_MAX,(long double)rand()/RAND_MAX));
	printf("%d\n",n);
	bzsi(n)
	{
		bzsj(n)
			printf("%Lf ",cntdis(points[i].fi,points[i].se,points[j].fi,points[j].se));
		puts("");
	}
	bzsi(n)
		printf("%Lf %Lf\n",points[i].fi,points[i].se);
	return 0;
}
