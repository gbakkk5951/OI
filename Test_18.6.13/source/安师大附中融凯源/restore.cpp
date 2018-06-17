#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <time.h>
const long double eps=1e-3;
const int N=105;
long double dis[N][N],ax[N],ay[N];
long double x2,y2,T;
int n,seq[N];
using namespace std;

long double sqr(long double x){return x*x;}
long double ok(int n,long double x,long double y)
{
	int i;long double mx=0.0;
	for (i=1;i<n;i++)
	{
		long double v=fabs(sqrt(sqr(x-ax[seq[i]])+sqr(y-ay[seq[i]]))-dis[seq[i]][seq[n]]);
		if (v>mx) mx=v;
	}
	return mx;
}
void solve(int th)
{
	long double x=(sqr(dis[seq[1]][seq[th]])-sqr(dis[seq[2]][seq[th]]))/x2/2+x2/2;
	long double y=sqr(dis[seq[1]][seq[th]])-sqr(x);ax[seq[th]]=x;
	if (y<0){ax[seq[th]]=ay[seq[th]]=0;return;}
	if (ok(th,x,-sqrt(y))<=ok(th,x,sqrt(y))) ay[seq[th]]=-sqrt(y);
	else ay[seq[th]]=sqrt(y);
}
bool check()
{
	int i,j;
	for (i=1;i<=n;i++)
	for (j=i+1;j<=n;j++)
	if (fabs(sqrt(sqr(ax[i]-ax[j])+sqr(ay[i]-ay[j]))-dis[i][j])>eps) return false;
	return true;
}
int main()
{
	freopen ("restore.in","r",stdin);
	freopen ("restore.out","w",stdout);
	scanf ("%d",&n);
	int i,j;double init;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	scanf ("%lf",&init),dis[i][j]=init;
	for (i=1;i<=n;i++) seq[i]=i;
	ax[seq[1]]=ay[seq[1]]=0.0;
	if (n>1)
	{
		srand((int)(dis[1][2]*dis[1][2]*123));
		while (1)
		{
			random_shuffle(seq+1,seq+1+n);
			ax[seq[1]]=ay[seq[1]]=0.0;
			ax[seq[2]]=dis[seq[1]][seq[2]],ay[seq[2]]=0.0,x2=ax[seq[2]];
			for (i=3;i<=n;i++) solve(i);
			if (check()) break;
		}
	}
	else ax[1]=ay[1]=0.0;
	for (i=1;i<=n;i++) printf ("%.12lf %.12lf\n",(double)ax[i],(double)ay[i]);
	return 0;
}

