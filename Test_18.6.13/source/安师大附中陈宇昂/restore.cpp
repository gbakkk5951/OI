#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

int N;
double G[4][4];

int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			scanf("%lf",&G[i][j]);
	if(N==1)
		printf("0.000000 0.000000\n");
	if(N==2)
		printf("0.000000 0.000000\n0.000000 %lf\n",G[1][2]);
	if(N==3){
		printf("0.000000 0.000000\n%lf 0.000000\n",G[1][2]); 
		double x=(G[1][2]*G[1][2]+G[1][3]*G[1][3]-G[2][3]*G[2][3])/(2*G[1][2]);
		double y=sqrt(G[1][3]*G[1][3]-x*x);
		printf("%lf %lf\n",x,y);
	}
	if(N==4){
		printf("0.000000 0.000000\n%lf 0.000000\n",G[1][2]); 
		double x=(G[1][2]*G[1][2]+G[1][3]*G[1][3]-G[2][3]*G[2][3])/(2*G[1][2]);
		double y=sqrt(G[1][3]*G[1][3]-x*x);
		double m=(G[1][4]*G[1][4]+G[1][2]*G[1][2]-G[2][4]*G[2][4])/(2*G[1][2]);
		double n=sqrt(G[1][4]*G[1][4]-m*m);
		if(fabs((m-x)*(m-x)+(n-y)*(n-y)-G[3][4]*G[3][4])<1e-2)
			printf("%lf %lf\n%lf %lf\n",x,y,m,n);
		else if(fabs((m-x)*(m-x)+(n+y)*(n+y)-G[3][4]*G[3][4])<1e-2)
			printf("%lf %lf\n%lf %lf\n",x,-y,m,n);
		else if(fabs((m-x)*(m-x)+(-n-y)*(-n-y)-G[3][4]*G[3][4])<1e-2)
			printf("%lf %lf\n%lf %lf\n",x,y,m,-n);
		else if(fabs((m-x)*(m-x)+(-n+y)*(-n+y)-G[3][4]*G[3][4])<1e-2)
			printf("%lf %lf\n%lf %lf\n",x,-y,m,-n);
	}
	return 0;
}
