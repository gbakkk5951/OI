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
const int N=200;
long double esp=1e-4;
long double dis[N][N];
int n,p1=-1,p2=-1,p3=-1;
vector<pair<long double,long double> > res;
long double cntdis(long double u1,long double v1,long double u2,long double v2)
{
	long double d1=u1-u2;
	long double d2=v1-v2;
	return sqrt(d1*d1+d2*d2);	
}
long double bzsabs(long double u)
{
	return u<0?-u:u;
}
bool equal(long double u,long double v)
{
	return abs(u-v)<esp;
}
#define mk make_pair
#define fi first
#define se second
int main()
{
#ifdef BZSJBYT
DEBUG=1;
freopen("D:\\bzsjbyt\\bzsjbyt.in","r",stdin);
freopen("D:\\bzsjbyt\\bzsjbyt.out","w",stdout);
//prefer AD? cat? jqe? or female creeper?
#else
freopen("restore.in","r",stdin);
freopen("restore.out","w",stdtout);
#endif
	read(n);
	bzsi(n) bzsj(n) scanf("%Lf",dis[i]+j);
	p1=0,p2=1;
	res.push_back(mk(0,0));
	res.push_back(mk(0,dis[0][1]));
	int k=2;
	while(equal(dis[0][k]+dis[1][k],dis[0][1])||equal(dis[0][1]+dis[0][k],dis[1][k])||equal(dis[0][1]+dis[1][k],dis[0][k]))
	{
		if (equal(dis[0][k]+dis[1][k],dis[0][1])||equal(dis[0][1]+dis[1][k],dis[0][k]))
		{
			res.push_back(mk(0,dis[0][k]));
		}
		else
		{
			res.push_back(mk(0,-dis[0][k]));
		}
		k++;
	}
	p3=k;
	long double a=dis[0][1],b=dis[0][k],c=dis[1][k];
	long double tmp=(a*a+b*b-c*c)/(2*a*b);
	res.push_back(mk(sqrt(1-tmp*tmp)*b,tmp*b));
	while(++k<n)
	{
		a=dis[0][1],b=dis[0][k],c=dis[1][k];
		tmp=(a*a+b*b-c*c)/(2*a*b);
		long double dx=sqrt(1-tmp*tmp)*b;
		long double dy=tmp*b;
		if (equal(cntdis(dx,dy,res[p3].fi,res[p3].se),dis[p3][k])) res.push_back(mk(dx,dy));
		else res.push_back(mk(-dx,dy));
	}
	bzsi(res.size()) printf("%Lf %Lf\n",res[i].fi,res[i].se);
	ded bzsi(n)
	bzsj(n)
		if (!equal(cntdis(res[i].fi,res[i].se,res[j].fi,res[j].se),dis[i][j])) return 1;
	return 0;
}
