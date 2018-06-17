#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

double di[110][110];
double x[110],y[110];
int n;

double Fabs(double x){
	return x>0?x:-x;
}

void out(){
	for(int i=1;i<=n;i++){
		printf("%.6lf %.6lf\n",x[i],y[i]);
	}
}

int check(double X,double Y,int id){
	for(int i=1;i<id;i++){
		if(Fabs(sqrt((X-x[i])*(X-x[i])+(Y-y[i])*(Y-y[i]))-di[i][id])>1e-3)return 0;
	}return 1;
}

void solve3(int id){
	if(id>n){
		out();
		exit(0);
	}//x-a1=p,y-b1=q;
	double a=di[id-2][id]*di[id-2][id];
	//p^2+q^2=d1^2
	double b=di[id-1][id]*di[id-1][id];
	double c=x[id-2]-x[id-1],d=y[id-2]-y[id-1];
	//(p+c)^2+(q+d)^2=d2^2
	double s=(-2*d)/(2*c);
	double t=(b-c*c-d*d-a)/(2*c);
	//p=-2qd/2c+(b-c^2-d^2-a)/2c
	//p=sq+t
	double ans1,ans2;
	double A=s*s+1,B=2*s*t,C=t*t-a;
	ans1=(-B+sqrt(B*B-4*A*C))/(2*A);
	ans2=(-B-sqrt(B*B-4*A*C))/(2*A);
	double a1,b1;
	a1=ans1+y[id-2],b1=sqrt(a-ans1*ans1)+x[id-2];
	if(check(b1,a1,id)){y[id]=a1;x[id]=b1;solve3(id+1);}
	a1=ans1+y[id-2],b1=-sqrt(a-ans1*ans1)+x[id-2];
	if(check(b1,a1,id)){y[id]=a1;x[id]=b1;solve3(id+1);}
	a1=ans2+y[id-2],b1=sqrt(a-ans2*ans2)+x[id-2];
	if(check(b1,a1,id)){y[id]=a1;x[id]=b1;solve3(id+1);}
	a1=ans2+y[id-2],b1=-sqrt(a-ans2*ans2)+x[id-2];
	if(check(b1,a1,id)){y[id]=a1;x[id]=b1;solve3(id+1);}
//	cerr<<B*B-4*A*C<<endl;
//	cerr<<ans2<<endl;
//	cerr<<C<<endl;
	
}

int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	srand(n);
	double X=1.986235*rand();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&di[i][j]);
	x[1]=0;y[1]=0;
	x[2]=di[1][2]*cos(X);y[2]=di[1][2]*sin(X);
	solve3(3);
	return 0;
}
