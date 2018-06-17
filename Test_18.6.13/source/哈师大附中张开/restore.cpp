#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps=1e-8;
int n;
double d[110][110], x[110], y[110];
double dis(int a, int b){return hypot(x[a]-x[b], y[a]-y[b]);}
int main(){
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf", &d[i][j]);
	x[1]=y[1]=0;
	x[2]=d[1][2], y[2]=0;
	int base=-1;
	for(int i=3;i<=n;i++){
		double a=d[1][i], b=d[1][2], c=d[2][i];
		double co=(a*a+b*b-c*c)/(2*a*b);
		if(fabs(co-1)<=eps)
			x[i]=a, y[i]=0;
		else if(fabs(co+1)<=eps)
			x[i]=-a, y[i]=0;
		else{
			x[i]=a*co; y[i]=sqrt(a*a-x[i]*x[i]);
			if(base==-1)
				base=i;
			else
				if(fabs(dis(i, base)-d[i][base])>eps)
					y[i]=-y[i];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%lf %lf\n", x[i], y[i]);
	return 0;
}
