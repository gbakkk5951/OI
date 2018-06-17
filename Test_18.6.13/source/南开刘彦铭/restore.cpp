#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 510
int n;
const double eps=1e-5;
double A[MAXN][MAXN];
struct node
{
	double x,y;
	node(double a=0,double b=0)
	{
		x=a;
		y=b;
	}
}T[MAXN*10];
double dis2(node a,node b)
{
	double x=a.x-b.x,y=a.y-b.y;
	return x*x+y*y;
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	T[1]=node(0,0);
	T[2]=node(A[1][2],0);
	double ang,l1=A[1][2],l2,l3;
	node L,tmp,tmp2;
	int flag=0;
	for(int i=3;i<=n;i++)
	{
		l2=A[1][i];
		l3=A[2][i];
		ang=acos((l1*l1+l2*l2-l3*l3)/(2.0*l1*l2));
		tmp=node(l2*cos(ang),l2*sin(ang));
		if(!flag)
		{
			T[i]=tmp;
			if(fabs(tmp.y)>eps)
			{
				flag=i;
				L=tmp;
			}
		}
		else
		{
			tmp2=node(tmp.x,-tmp.y);
			double d1=dis2(tmp,L),d2=dis2(tmp2,L);
			d1=fabs(d1-A[i][flag]*A[i][flag]);
			d2=fabs(d2-A[i][flag]*A[i][flag]);
			if(d1<d2)
			{
				T[i]=tmp;
			}
			else
			{
				T[i]=tmp2;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.6lf %.6lf\n",T[i].x,T[i].y);
	}
	return 0;
}
