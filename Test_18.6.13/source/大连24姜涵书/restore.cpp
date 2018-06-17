#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ns namespace
#define lol long long
using ns std;
const int M = 233;
int n;
double d[M][M],x[M],y[M];
ns fc1
{
	void main1()
	{
		printf("0.000000 0.000000\n0.000000 %.6f\n",-d[1][2]);
		if(fabs(d[1][2])<=0.000000)
		{
			printf("0.000000 %.6f\n",d[1][3]);
			return;
		}
		y[3] = d[2][3] * d[2][3] - d[1][3] * d[1][3] - d[1][2] * d[1][2];
		y[3] /= (2 * d[1][2]);
		x[3] = sqrt(d[1][3] * d[1][3] - y[3] * y[3]);
		printf("%.6f %.6f\n",x[3],y[3]);
	}
}

int main()
{
#ifdef shorn

#else
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lf",&d[i][j]);
		}
	}
	if(n==3) return fc1::main1(),0;
	
	return 0;
}

