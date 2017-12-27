#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-3;
double a,b,c,d;
inline double f(double x){return ((a*x+b)*x+c)*x+d;}
inline double df(double x){return (3*a*x+2*b)*x+c;}
double sol(double l,double r){//printf("sol %lf %lf\n",l,r);
    int step=20;double x=0;
    while(step--){
        x=x-f(x)/df(x);
    }
    return x;
}
int main(int argc, const char * argv[]) {
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double p1=(-sqrt(b*b-3*a*c)-b)/(3*a),
    p2=(+sqrt(b*b-3*a*c)-b)/(3*a);
    printf("%.2f %.2f %.2f\n",sol(-100,p1),sol(p1,p2),sol(p2,100));
    return 0;
}
