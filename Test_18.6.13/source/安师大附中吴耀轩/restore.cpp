#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
typedef long double cdb;
const int maxn = 105;
const cdb eps = 1e-7;
const cdb xeps = 1e-5;

cdb d[maxn][maxn],d2[maxn][maxn];
cdb x[maxn],y[maxn];int n,sx,sy,o;

cdb sqr(cdb x) {return x*x;}
cdb LEF(cdb x) {return fabs(x)<eps?0:x;}
cdb check(cdb a,cdb b,int i)
{
	return fabs(sqr(a-x[o])+sqr(b-y[o])-d2[i][o]);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("restore.in","r",stdin);
		freopen("restore.out","w",stdout);
	#endif
	cin>>n;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		cin>>d[i][j],d2[i][j]=d[i][j]*d[i][j];
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
		if (d[i][j]>eps) sx=i,sy=j;
	if (sx&&sy) {
		x[sy]=d[sx][sy];
		cdb x0=x[sy];
		cdb x02=x0*x0;
		for (int i=1;i<=n;i++)
		if (i!=sx&&i!=sy) {
			cdb a=(x02+d2[sx][i]-d2[sy][i])/x0/2.0;
			cdb b=sqrt(LEF(d2[sx][i]-a*a));
			if (o&&check(a,-b,i)<check(a,b,i)) b*=-1;
			x[i]=a;y[i]=b;if (fabs(b)>eps&&!o&&(!o||fabs(b)>fabs(y[o]))) o=i;
		}
	}
	for (int i=1;i<=n;i++)
		printf("%.10lf %.10lf\n",(double)x[i],(double)y[i]);
	return 0;
}
