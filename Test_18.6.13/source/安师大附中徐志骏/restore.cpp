#include<stdio.h>
#include<math.h>
#include<iostream>
#define sqr(x) (x)*(x)
using namespace std;
int n;
double g[4][4];
int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&g[i][j]);
	if(n==1){printf("0.000000 0.000000\n"); return 0;}
	if(n==2){printf("0.000000 0.000000\n0.000000 %lf\n",g[1][2]); return 0;}
	if(n==3){
		printf("0.000000 0.000000\n%lf 0.000000\n",g[1][2]);
		double x=(sqr(g[1][2])+sqr(g[1][3])-sqr(g[2][3]))/(2*g[1][2]);
		double y=sqrt(sqr(g[1][3])-sqr(x));
		printf("%lf %lf\n",x,y);
		return 0;
	}
	return 0;
}
