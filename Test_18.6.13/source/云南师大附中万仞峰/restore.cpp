#include <bits/stdc++.h>
#include <cmath>

using namespace std;

double dist[100][100];
double ans[100][2];

int main(void)
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	
	int n,k;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lf",&dist[i][j]);
		}
	}	
	
	ans[0][0]=0.0;
	ans[0][1]=0.0;
	ans[1][0]=0.0;
	ans[1][1]=dist[0][1];
	for(k=0;k<n;k++)
	{
		if(dist[0][k]+dist[1][k]-dist[0][1]>=1e-8)
		{
			break;
		}
	}
	ans[k][1]=(dist[0][k]*dist[0][k]-dist[1][k]*dist[1][k]+dist[0][1]*dist[0][1])/(2*dist[0][1]);
	ans[k][0]=sqrt(dist[0][k]*dist[0][k]-ans[k][1]*ans[k][1]);
	for(int i=2;i<n;i++)
	{
		double ty=(dist[0][i]*dist[0][i]-dist[1][i]*dist[1][i]+ans[1][1]*ans[1][1])/(2*ans[1][1]);
		double tx=sqrt(dist[0][i]*dist[0][i]-ty*ty);
		
		if((ans[k][1]-ty)*(ans[k][1]-ty)+(ans[k][0]-tx)*(ans[k][0]-tx)-dist[k][i]*dist[k][i]>=1e-3)
		{
			tx=-tx;
		}
		
		ans[i][1]=ty;
		ans[i][0]=tx;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%.6lf %.6lf\n",ans[i][0],ans[i][1]);
	}
	
	return 0;
}
