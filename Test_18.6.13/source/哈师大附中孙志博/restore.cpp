#include <cmath>
#include <cstdio>
using namespace std;
const int N=110;
struct point {
	double x,y;
	point(){}
	point(double X,double Y):x(X),y(Y){}
}p[N];
int n; double d[N][N];
void read() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		scanf("%lf",&d[i][j]);
	p[2]=point(d[1][2],0);
	return;
}
double sqr(double x) {
	return x*x;
}
bool judge(double a,double b) {
	return abs(a-b)<1;
}
point solve(int x) {
	if (d[x][1]<d[x][2]) {
		double dert=sqr(d[x][2])-sqr(d[x][1]);
		double lx=(sqr(d[1][2])-dert)/(2*d[1][2]);
		double py=sqrt(sqr(d[1][x])-sqr(lx));
		if (judge(sqr(lx)+sqr(py),sqr(d[1][x]))&&judge(sqr(p[2].x-lx)+sqr(py),sqr(d[2][x])))
			return point(lx,py);
		else {
			lx=(dert-sqr(d[1][2]))/(2*d[1][2]);
			py=sqrt(sqr(d[1][x])-sqr(lx));
			return point(-lx,py);
		}
	}
	else {
		double dert=sqr(d[x][1])-sqr(d[x][2]);
		double lx=(sqr(d[1][2])+dert)/(2*d[1][2]);
		double py=sqrt(sqr(d[1][x])-sqr(lx));
		if (judge(sqr(lx)+sqr(py),sqr(d[1][x]))&&judge(sqr(p[2].x-lx)+sqr(py),sqr(d[2][x])))
			return point(lx,py);
		else {
			lx=(dert-sqr(d[1][2]))/(2*d[1][2]);
			py=sqrt(sqr(d[2][x])-sqr(lx));
			return point(p[2].x+lx,py);
		}
	}
}
namespace s1 {
	void work() {
		p[3]=solve(3);
		return;
	}
}
namespace s2 {
	void work() {
		for (int i=3;i<=n;i++) {
			p[i]=solve(i);
			for (int j=1;j<i;j++)
				if (!judge(sqr(p[j].x-p[i].x)+sqr(p[j].y-p[i].x),sqr(d[i][j]))) {
					p[i].y=0-p[i].y;
					break;
				}
		}
		return;
	}
}
void out() {
	for (int i=1;i<=n;i++)
		printf("%.4lf %.4lf\n",p[i].x,p[i].y);
	return;
}
int main() {
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	read();
	if (n==3) s1::work();
	else s2::work();
	out();
	return 0;
}