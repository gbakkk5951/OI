#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#define N 402
using namespace std;

int n;
double d[N][N],x[N],y[N];
double Abs(double x)
{
	return x<0?-x:x;
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%lf",&d[i][j]);
	
	x[1]=y[1]=0;
	x[2]=d[1][2],y[2]=0;
	if (d[1][3]==0)
		x[3]=x[1],
		y[3]=y[1];
	else if (d[2][3]==0)
		x[3]=x[2],
		y[3]=y[2];
	else	x[3]=d[1][3]*d[1][3]-d[2][3]*d[2][3]+d[1][2]*d[1][2],
		x[3]/=d[1][2]*2,
		y[3]=sqrt(d[1][3]*d[1][3]-x[3]*x[3]);
	
	for (int i=4;i<=n;i++)
	{
		int flg=0;
		for (int j=1;j<i;j++)
		{
			if (d[i][j]==0)
			{
				x[j]=x[i];
				y[j]=y[i];
				flg=1;
				break;
			}
		}
		if (!flg)
		{
			x[i]=d[1][i]*d[1][i]-d[2][i]*d[2][i]+d[1][2]*d[1][2],
			x[i]/=d[1][2]*2,
			y[i]=sqrt(d[1][i]*d[1][i]-x[i]*x[i]);
			if (Abs(sqrt((x[i]-x[3])*(x[i]-x[3])+(y[i]-y[3])*(y[i]-y[3]))-d[3][i])>0.001)
				y[i]=-y[i];
		}
	}
	cout<<fixed<<setprecision(6);
	for (int i=1;i<=n;i++)
		cout<<x[i]<<" "<<y[i]<<"\n";
}
