#include <math.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define _(x) (((x)<eps)&&(x>(-eps)))
using namespace std;
const long double eps=1e-3;
int ord[110];
long double g[110][110];
struct point{
	   long double x,y;
	   point (long double x_=0.0,long double y_=0.0){
			 x=x_;
			 y=y_;
	   }
}ans[110];
bool operator ==(const point x,const point y){
	 return (_(x.x-y.x)&&_(x.y-y.y));
}
pair <point,point> calc(point x,point y,long double da,long double db){
	 long double ax=x.x,ay=x.y,bx=y.x,by=y.y;
     long double k=(ax-bx)/(by-ay+0.00001),kb=(da*da-db*db+bx*bx+by*by-ax*ax-ay*ay)/(2*(by-ay)+0.00001),a=1+k*k,b=2*k*(kb-ay)-2*ax,c=ax*ax+(kb-ay)*(kb-ay)-da*da;
	 long double x1=(-b+sqrtl(b*b-4*a*c))/(2*a),y1=k*x1+kb,x2=(-b-sqrtl(b*b-4*a*c))/(a*a),y2=k*x2+kb;
	 return pair <point,point> (point(x1,y1),point(x2,y2));
}
int main(){
	int n,i,j,k,s1,s2;
	point x1,x2;
	pair <point,point> p;
	freopen ("restore.in","r",stdin);
	freopen ("restore.out","w",stdout);
	scanf ("%d",&n);
	for (i=1;i<=n;i++){
		for (j=1;j<=n;j++){
			cin>>g[i][j];
		}
		ord[i]=i;
	}
	srand(time(NULL));
	random_shuffle(ord+1,ord+n+1);
	ans[ord[1]]=point(0.0,0.0);
	ans[ord[2]]=point(0.0,g[ord[1]][ord[2]]);
	for (i=3;i<=n;i++){
		p=calc(ans[ord[1]],ans[ord[2]],g[ord[1]][ord[i]],g[ord[2]][ord[i]]);
		x1=p.first;
		x2=p.second;
		s1=0;
		s2=0;
		for (j=1;j<i-1;j++){
			for (k=j+1;k<i;k++){
				p=calc(ans[ord[j]],ans[ord[k]],g[ord[j]][ord[i]],g[ord[k]][ord[i]]);
				if (p.first==x1){
				   s1++;
				}
				if (p.first==x2){
				   s2++;
				}
				if (p.second==x1){
				   s1++;
				}
				if (p.second==x2){
				   s2++;
				}
			}
		}
		if (s1>=s2){
		   ans[ord[i]]=x1;
		}
		else{
		   	 ans[ord[i]]=x2;
		}
	}
	for (i=1;i<=n;i++){
		printf ("%lf %lf\n",(double)ans[i].x,(double)ans[i].y);
	}
	return 0;
}
