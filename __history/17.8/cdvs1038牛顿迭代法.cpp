using namespace std;
int main(){}
#include<cmath>
#include<cstdio>
#include<algorithm>
#define eps 1e-2

	bool equal (double a,double b){
		return fabs(a-b)<eps;
	}


struct _Main{
double a,b,c,d;
double df(double x){
	return 3.0*a*x*x+2.0*b*x+c;
}
double f (double x){
	return a*x*x*x+b*x*x+c*x+d;
}	
void solve(double l,double r,double *ans,int &cnt){
	double mid=(l+r)/2;
	double x=mid,x0;
	while(l+0.5<r){
		x=mid=(l+r)/2;
		do{ x0=x;
			x=x0-f(x0)/df(x0);
		}while(!equal(x,x0) && !equal(0,f(x)));
		if(x<l){
			l=mid;
		}else if(x>r){
			r=mid;
		}else{
			ans[cnt++]=x;
			solve(l-eps,x-1+eps,ans,cnt);
			solve(x+1-eps,r+eps,ans,cnt);
			return;
		}
	}
	
	
	
}
struct doublecmp{
	bool operator () (double a,double b){
		return fabs(a-b)<eps;
	}
};
double roots[10];
int cnt;
_Main(){
	int x;int i;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	solve(-100,100,roots,cnt);
	sort(roots,roots+cnt);
	unique(roots,roots+cnt,doublecmp() );
	for(i=0;i<3;i++){
		printf("%.2f ",roots[i]);
	}
}
	
	
	
	
}cdvs1038;

