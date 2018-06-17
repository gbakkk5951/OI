#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define si scanf
#define so printf
#define N 110
#define EPS 1e-7 
#define D1 d[i][p1]
#define D2 d[i][p2]
#define D3 d[i][p3]
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int n,p1,p2,p3;
long double d[N][N];
long double x[N],y[N],x0,y0;
inline int cmp(long double a,long double b)
{
	if(fabs(a-b)<=EPS)
		return 0;
	else if(a-b>EPS)
		return 1;
	else
		return -1;
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	rd(n);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
		si("%Lf",&d[i][j]);
	p1=1;
	x[1]=y[1]=0;
	long double mxd=0;
	for(int i=1;i<=n;++i)
		if(i!=p1&&cmp(mxd,d[1][i])<0)
		{
			p2=i;
			x[i]=d[1][i],y[i]=0;
			mxd=d[1][i];
		}
	for(int i=1;i<=n;++i)//寻找第三个点
		if(i!=p1&&i!=p2&&cmp(d[p1][p2],d[p1][i]+d[i][p2])!=0&&cmp(mxd,d[p1][i]+d[i][p2])<0)//不共线
		{
			x[i]=(D1*D1-D2*D2)/(2*x[p2])+x[p2]/2;
			if(cmp(D1,x[i])==0||cmp(D1,-x[i])==0)
				continue;
			else
				y[i]=sqrt(D1*D1-x[i]*x[i]);
			x0=x[i],y0=y[i];
			p3=i;
			mxd=d[p1][i]+d[p2][i];
		}
	if(p3==0)
	for(int i=1;i<=n;++i)
		if(i!=p1&&i!=p2)
		{
			p3=i;
			break;
		}
	for(int i=1;i<=n;++i)
		if(i!=p1&&i!=p2&&i!=p3)
		{
			x[i]=(D1*D1-D2*D2)/(2*x[p2])+x[p2]/2;
			if(cmp(D1,x[i])==0||cmp(D1,-x[i])==0)
				y[i]=0;
			else
				y[i]=sqrt(D1*D1-x[i]*x[i]);
			if(cmp(fabs((x[i]-x0)*(x[i]-x0)+(y[i]-y0)*(y[i]-y0)-D3*D3),fabs((x[i]-x0)*(x[i]-x0)+(y[i]+y0)*(y[i]+y0)-D3*D3))>0)
				y[i]=-y[i];
		}
	for(int i=1;i<=n;++i)
		so("%Lf %Lf\n",x[i],y[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
