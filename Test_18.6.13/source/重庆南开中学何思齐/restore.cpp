#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100+7;
const double eps=1e-5;
int n,t;
double h,s,a,b,l,c,Dis[N][N];
struct coor{
	double x,y;
	coor(){}
	coor(double a,double b):x(a),y(b){}
}A[N],X,Y;
inline double sqr(const double x){return x*x;}
inline double dis(coor A,coor B){return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));}
int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		scanf("%lf",&Dis[i][j]);
	l=Dis[1][2];
	A[1]=coor(0,0),A[2]=coor(l,0);
	for(t=3;t<=n;t++){
		a=Dis[1][t],b=Dis[2][t];
		s=(a+b+l)/2;
		s=sqrt(s*(s-a)*(s-b)*(s-c));
		h=s/l*2,c=sqrt(sqr(a)-sqr(h));
		A[t]=coor(c,h);
		if(h>eps)break;
	}
	for(i=t+1;i<=n;i++){
		a=Dis[1][i],b=Dis[2][i];
		s=(a+b+l)/2;
		h=sqrt(s*(s-a)*(s-b)*(s-c))/l*2,c=sqrt(sqr(a)-sqr(h));
		X=coor(c,h),Y=coor(c,-h);
		if(fabs(dis(X,A[t])-Dis[i][t])<fabs(dis(Y,A[t])-Dis[i][t]))A[i]=X;
		else A[i]=Y;
	}
	for(i=1;i<=n;i++)
		printf("%lf %lf\n",A[i].x,A[i].y);
}
