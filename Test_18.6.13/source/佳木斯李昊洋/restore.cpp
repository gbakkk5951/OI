#include<cstdio>
#include<cmath>
#define gm 101
using namespace std;
int n;
double c,d[gm][gm];
double px[gm],py[gm];
inline void calc(int no,double &x,double &y)
{
	double d1=d[1][no],d2=d[2][no];
	y=((d1*d1-d2*d2)/c+c)*0.5; x=sqrt(d1*d1-y*y);
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	scanf("%lf",d[i]+j);
	if(n>=2) py[2]=c=d[1][2];
	if(n>=3) calc(3,px[3],py[3]);
	for(int i=4;i<=n;++i)
	{
		calc(i,px[i],py[i]);
		for(int j=3;j<i;++j)
		if(fabs((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j])-d[i][j]*d[i][j])>1e-3)
		{
			px[i]=-px[i];
			break;
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("%.10lf %.10lf\n",px[i],py[i]);
	}
	return 0;
}
