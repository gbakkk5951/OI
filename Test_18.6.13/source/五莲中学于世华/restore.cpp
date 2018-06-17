#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define Int const int &
#define Double const double &
#define Vct const vct &

const int N=123;
const double eps=1e-7;

struct vct {
	double x, y;
	vct(Double a=0, Double b=0) {
		this->x = a;
		this->y = b;
	}
	vct operator + (Vct B) {
		return vct(this->x + B.x, this->y + B.y);
	}
	vct operator - (Vct B) const {
		return vct(this->x - B.x, this->y - B.y);
	}
	vct operator * (Double p) {
		return vct(this->x * p, this->y * p);
	}
	vct operator / (Double p) {
		return vct(this->x / p, this->y / p);
	}
	vct Rotate(Double a) {
		return vct(this->x * cos(a) - y * sin(a), this->x * sin(a) + this->y *  cos(a));
	}
	double Length(void) {
		return sqrt(this->x * this->x + this->y * this->y);
	}
};
typedef vct point;
double dist(const point &A, const point &B) {
	vct buf=B-A;
	return buf.Length();
}

double dis[N][N];
point w[N];

point work(Int t) {
	double d1=dis[t][t-2];
	double d2=dis[t][t-1];
	double d3=dis[t-1][t-2];
//	debug(d1);
//	debug(d2);
//	debug(d3);
	double a=(d1*d1+d3*d3-d2*d2)/(2*d3*d1);
	double alpha=acos(a);
//	debug(alpha);
	vct q=w[t-1]-w[t-2];
	point p=q.Rotate(alpha);
	point p2=q.Rotate(-alpha);
//	debug(p.x);
//	debug(p.y);
	p=p/p.Length()*d1+w[t-2];
	p2=p2/p2.Length()*d1+w[t-2];
	double z=0, z2=0;
	for (int i=1; i<t-2; i++) {
		z=max(z, abs(dis[i][t]-dist(p, w[i])));
		z2=max(z2, abs(dis[i][t]-dist(p2, w[i]))); 
	//	if (abs(dis[i][t]-dist(p, w[i]))<eps) {
	//		continue;
	//	}
	//	return q.Rotate(-alpha);
	}
	return z > z2 ? p2 : p;
}
void fc(void) {
	fclose(stdin);
	fclose(stdout);
	exit(0);
}
int main(void) {
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			scanf("%lf", &dis[i][j]);
		}
	}
	w[1]=vct(0, 0);
	puts("0.000000 0.000000");
	if (n==1) {		
		fc();
	}
	w[2]=vct(dis[1][2], 0);
	printf("%lf %lf\n", w[2].x, w[2].y);
	if (n==2) {
		fc();
	}
	for (int i=3; i<=n; i++) {
		w[i]=work(i);
		printf("%.6lf %.6lf\n", w[i].x, w[i].y);
	}
/*
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			vct m=w[j]-w[i];
			printf("%.6lf ", m.Length());
		}
		putchar('\n');
	}
*/
	fc();
}
/*
3
0.000000 0.231874 0.853317
0.231874 0.000000 0.637852
0.853317 0.637852 0.000000
*/
