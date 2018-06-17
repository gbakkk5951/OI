#include<math.h>
#include<stdio.h>
#define abs(a) ((a)<0?-(a):(a))
double d[105][105],point[105][2];
bool equal(double d1,double d2)
{
	return abs(d1-d2)<0.000001;
}
double distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	int n,p;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lf",&d[i][j]);
	point[0][0]=point[0][1]=0;
	if(n>1)
	{
		point[1][0]=d[0][1],point[1][1]=0;
		for(p=2;p<n;p++)
			if(equal(d[0][1]+d[1][p],d[0][p])||equal(d[0][p]+d[p][1],d[0][1]))
				point[p][0]=d[0][p],point[p][1]=0;
			else if(equal(d[p][0]+d[0][1],d[p][1]))
				point[p][0]=-d[0][p],point[p][1]=0;
			else
				break;
		if(p<n)
		{
			point[p][0]=((d[0][p]*d[0][p]-d[1][p]*d[1][p])/point[1][0]+point[1][0])/2;
			point[p][1]=sqrt(d[0][p]*d[0][p]-point[p][0]*point[p][0]);
			for(int i=p+1;i<n;i++)
			{
				point[i][0]=((d[0][i]*d[0][i]-d[1][i]*d[1][i])/point[1][0]+point[1][0])/2;
				point[i][1]=sqrt(d[0][i]*d[0][i]-point[i][0]*point[i][0]);
				if(abs(distance(point[p][0],point[p][1],point[i][0],point[i][1])-d[p][i])
					>abs(distance(point[p][0],point[p][1],point[i][0],-point[i][1])-d[p][i]))
					point[i][1]=-point[i][1];
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%.6lf %.6lf\n",point[i][0],point[i][1]);
	return 0;
}

