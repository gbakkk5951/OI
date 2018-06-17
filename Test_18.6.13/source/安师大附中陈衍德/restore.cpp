#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;
const double eps=1e-3;
double D[110][110];
int n;
double X[110],Y[110];
double dist(int p,int q){
	return sqrt((X[p]-X[q])*(X[p]-X[q])+(Y[p]-Y[q])*(Y[p]-Y[q]));
}
void dfs(int d){
	if(d>n){
		for(int i=1;i<=n;i++)
		printf("%lf %lf\n",X[i],Y[i]);
		//spj
		/*bool gg=0;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(fabs(dist(i,j)-D[i][j])>1e-3){
			printf("GG!i=%d,j=%d,differ=%lf\n",i,j,fabs(dist(i,j)-D[i][j]));
			gg=1;
		}
		if(!gg)printf("Orz!\n");*/
		//end spj
		exit(0);
	}
	double y=(D[1][d]*D[1][d]-D[2][d]*D[2][d]+D[1][2]*D[1][2])/(2.0*D[1][2]);
	if(fabs(y*y-D[1][d]*D[1][d])<1e-8){
		X[d]=0;Y[d]=y;
		bool gg=0;
		for(int i=1;i<d;i++)
		if(fabs(dist(i,d)-D[i][d])>eps){
			gg=1;break;
		}
		if(!gg)dfs(d+1);
		X[d]=0;Y[d]=0;
	}
	else if(y*y>D[1][d]*D[1][d])return;
	else{
		double x=sqrt(D[1][d]*D[1][d]-y*y);
		X[d]=x;Y[d]=y;
		bool gg=0;
		for(int i=1;i<d;i++)
		if(fabs(dist(i,d)-D[i][d])>eps){
			//printf("%d %d %lf\n",i,d,fabs(dist(i,d)-D[i][d]));
			gg=1;break;
		}
		if(!gg)dfs(d+1);
		X[d]=-x;Y[d]=y;
		gg=0;
		for(int i=1;i<d;i++)
		if(fabs(dist(i,d)-D[i][d])>eps){
			gg=1;break;
		}
		if(!gg)dfs(d+1);
		X[d]=0;Y[d]=0;
	}
}
int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%lf",&D[i][j]);
	if(n==1){
		printf("0.000000 0.000000\n");
		return 0;
	}
	if(n==2){
		printf("0.000000 0.000000 0.000000 %lf\n",D[1][2]);
		return 0;
	}
	X[1]=0;Y[1]=0;X[2]=0;Y[2]=D[1][2];
	dfs(3);
	return 0;
}
