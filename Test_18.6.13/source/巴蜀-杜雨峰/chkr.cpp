#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double d[505][505],x[505],y[505];
double Abs(double x)
{
	return x>0?x:-x;
}
int main()
{
	FILE *a=fopen("restore.in","r");
	freopen("restore.out","r",stdin);
	fscanf(a,"%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			fscanf(a,"%lf",&d[i][j]);
	for (int i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (Abs(d[i][j]-sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])))>0.001)
			{
				cout<<"BALL at "<<i<<" and "<<j<<"  calced:"<<sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<<" but act: "<<d[i][j]<<"\n";
				return 1;
			}
	cout<<"SSS\n";
	return 0;
}
