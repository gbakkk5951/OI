#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	double x, y;
	node(){}
	node(double _x, double _y) { x = _x, y = _y; }
}ans[110];

double d[110][110];

inline double pf(double x) { return x * x; }

const double eps = 1e-6;
inline int sgn(double x)
{
	if(fabs(x) <= eps) return 0;
	return x > 0.0 ? 1 : -1;
}

inline double dist(node a, node b) { return sqrt(pf(a.x - b.x) + pf(a.y - b.y)); }

inline int check(node P, int m)
{
	for(int i=1; i<m; ++i)
		if(sgn(dist(P, ans[i]) - d[m][i])) return 0;
	return 1;
}

int main()
{
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)
		scanf("%lf", &d[i][j]);
	
	ans[1] = node(0.0, 0.0);
	ans[2] = node(d[1][2], 0.0);
	for(int i=3; i<=n; ++i)
	{
		double a = d[1][i], b = d[2][i], c = d[1][2];
		double p = (a + b + c) / 2.0;
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		double h = 2.0 * s / c;
		double x = sqrt(pf(a) - pf(h));
		
		if(pf(b) > pf(a) + pf(c)) x = -x;
		
		node New = node(x, h);
		if(check(New, i)) ans[i] = New;
		else ans[i] = node(x, -h);
	}
	
	for(int i=1; i<=n; ++i)
		printf("%.6lf %.6lf\n", ans[i].x, ans[i].y);
}
