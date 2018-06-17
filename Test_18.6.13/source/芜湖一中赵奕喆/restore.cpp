#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

#define sqr(x) ((x) * (x))

const int N = 100 + 10;
const double eps = 1e-3;
int n;
double d[N][N];

struct P{
	double x, y;
	P(){}
	P(double _x, double _y){
		x = _x;
		y = _y;
	}
	void out(){
		printf("%.10lf %.10lf\n", x, y);
	}
};

double dis(P a, P b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int dmp(double a, double b){
	if(fabs(a - b) < eps) return 0;
	else if(a < b) return -1;
	else return 1;
}

void init(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%lf", &d[i][j]);
}

void work(){
	/*if(n == 1){
		P a1;
		a1 = P(0.0, 0.0);
		a1.out();
	}
	if(n == 2){
		P a1, a2;
		a1 = P(0.0, 0.0);
		a2 = P(0.0, d[1][2]);
		a1.out();
		a2.out();
	}
	if(n == 3){
		P a1, a2, a3;
		a1 = P(0.0, 0.0);
		a2 = P(0.0, d[1][2]);
		a3.y = (sqr(d[1][3]) + sqr(d[1][2]) - sqr(d[2][3])) / (2 * d[1][2]);
		a3.x = sqrt(sqr(d[1][3]) - sqr(a3.y));
		a1.out();
		a2.out();
		a3.out();
		P a4(1, 1);
		printf("%lf %lf %lf\n", dis(a1, a4), dis(a2, a4), dis(a4, a3));
		//printf("%lf %lf %lf\n", dis(a1, a2), dis(a1, a3), dis(a2, a3));
	}
	if(n == 4){
		P a1, a2, a3, a4;
		a1 = P(0.0, 0.0);
		a2 = P(0.0, d[1][2]);
		a3.y = (sqr(d[1][3]) + sqr(d[1][2]) - sqr(d[2][3])) / (2 * d[1][2]);
		a3.x = sqrt(sqr(d[1][3]) - sqr(a3.y));
		a4.y = (sqr(d[1][4]) + sqr(d[1][2]) - sqr(d[2][4])) / (2 * d[1][2]);
		a4.x = sqrt(sqr(d[1][4]) - sqr(a4.y));
		if(dmp(dis(a4, a3), d[3][4])) a4.x *= -1.0;
		a1.out();
		a2.out();
		a3.out();
		a4.out();
	}
	if(n > 4){*/
	P a[N];
	a[1] = P(0.0, 0.0);
	a[2] = P(0.0, d[1][2]);
	for(int i = 3; i <= n; i++){
		a[i].y = (sqr(d[1][i]) + sqr(d[1][2]) - sqr(d[2][i])) / (2 * d[1][2]);
		a[i].x = sqrt(sqr(d[1][i]) - sqr(a[i].y));
	}
	int k = 3;
	while(k <= n && !dmp(a[k].x, 0.0)) k++;
	if(k <= n)
	for(int i = 3; i <= n; i++){
		if(i == k) continue;
		if(dmp(dis(a[k], a[i]), d[k][i])) a[i].x *= -1.0;
	}
	//printf("%lf %lf\n", dis(a[k], a[77]), d[k][77]);
	for(int i = 1; i <= n; i++)
		a[i].out();
	
	/*bool ok = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(dmp(dis(a[i], a[j]), d[i][j])){
				printf("%d %d\n", i, j);
				ok = 0;
				break;
			}
		}
		//if(!ok) break;
	}
	if(ok) puts("Right");
	else puts("Wrong");*/
	/*for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++){
		if(i == j) printf("%lf", 0.0);
		else printf("%lf", dis(a[i], a[j]));
			printf("%s", j == n ? "\n" : " ");
	}*/
	//}
}

int main(){
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	init();
	work();
	return 0;
}
