using namespace std;
int main(){}


#include<cstdio>
#include<cmath>
#include<algorithm>
double ans[3];
struct _Main{
double a,b,c,d,A,B,C,cita;	
const double eps 1e-8;
_Main(){
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	A=b*b-3*a*c;
	B=b*c-9*a*d;
	C=c*c-3*b*d;
	cita=acos( (2*A*b-3*a*B)
				/(2*A*sqrt(A))
			 );
	
	ans[0]= (-b-2*sqrt(A)*cos(cita/3))
			/(3*a);
	ans[1]= (-b+sqrt(A)*(cos(cita/3)+sqrt(3.0)*sin(cita/3)) )
			/(3*a);
	ans[2]= (-b+sqrt(A)*(cos(cita/3)-sqrt(3.0)*sin(cita/3)) )
			/(3*a);
	sort(ans,ans+3);
	printf("%.2f %.2f %.2f",ans[0]+eps,ans[1]+eps,ans[2]+eps);
}	

}cdvs1038;
