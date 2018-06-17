#include<bits/stdc++.h>
using namespace std;
const int N=105;
const double eps=0.001;
const double eps1=1e-8;

int n,i,j;
double x1,x2,jl[N][N];
double xa,ya,xb,yb,ss1;
double k,b,A,B,C,ss;

struct Point
{
	double x,y;
	double xx,yy;
}L[N];

double QJL(double xa,double ya,double xb,double yb)
{
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%lf",&jl[i][j]);
	L[1].x=0,L[1].y=0;
	L[2].x=jl[1][2],L[2].y=0;
	for(i=3;i<=n;i++)
	{
		xb=L[2].x;
		x1=jl[1][i],x2=jl[2][i];
		L[i].x=(x1*x1-x2*x2+xb*xb)/(2*xb);
		if(fabs(x1*x1-L[i].x*L[i].x)<eps1)
			L[i].y=0;
		else L[i].y=sqrt(x1*x1-L[i].x*L[i].x);
		L[i].xx=L[i].x;L[i].yy=-L[i].y;
		//if(i==5)cerr<<x1<<' '<<L[i].x;
//		cerr<<L[i].x<<' '<<L[i].y<<' '<<L[i].yy<<endl;
	}
	if(n<=3)
	{
		for(i=1;i<=n;i++)
			printf("%lf %lf\n",L[i].x,L[i].y);
		return 0;
	}
	j=3;
	while(j<=n&&(fabs(L[j].y)<eps1))j++;//cerr<<j<<endl;
	for(i=j+1;i<=n;i++)
	{
//		cerr<<QJL(L[j].x,L[j].y,L[i].x,L[i].y)<<endl;
		ss=QJL(L[j].x,L[j].y,L[i].x,L[i].y);
		ss1=QJL(L[j].x,L[j].y,L[i].xx,L[i].yy);
		if(fabs(ss-jl[j][i])<fabs(ss1-jl[j][i]))continue;
		else L[i].x=L[i].xx,L[i].y=L[i].yy;
	}
	for(i=1;i<=n;i++)
		printf("%lf %lf\n",L[i].x,L[i].y);
	return 0;
}
/*
X1^2=(x-xa)^2+(y-ya)^2;

x1^2=x^2+y^2

x2^2=x^2-2*xb*x+xb^2+y^2-2*yb*y+yb^2

x1^2-x2^2=2*(xb)*x-xb^2
x1^2-x2^2-xa^2+xb^2-ya^2+yb^2-2*(xb-xa)*x=+2*(yb-ya)*y

y=(xa-xb)/(yb-ya)x+(x1^2-x2^2-xa^2+xb^2-ya^2+yb^2)/(2*(yb-ya));
y=k*x+b;
(k=(xa-xb)/(yb-ya),b=(x1^2-x2^2-xa^2+xb^2-ya^2+yb^2)/(2*(yb-ya)))

x1^2=x^2-2*xa*x+xa^2+(k*x+b)^2-2*ya*(k*x+b)+ya^2;

0=(k^2+1)*x^2+2*(k*b-xa-ya*k)*x+xa^2+b^2-2*ya*b+ya^2-x1^2

0=A*x^2+B*x+C;
x=(-B+-sqrt(B*B-4*A*C))/(2*A);

X2^2=(x-xb)^2+(y-yb)^2;


*/
