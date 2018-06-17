#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 105;
double a[MAXN][MAXN], x[MAXN], y[MAXN];
int n, m, i, j, k;
struct sb{
	double x, y;
};
inline double getdis(double x, double y, double xx, double yy)
{
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}
inline double Fabs(double x)
{
	if (x < 0) x = -x;
	return x;
}
inline sb circle1(double x, double y, double r, double xx, double yy, double rr)
{
	double dis = getdis(x, y, xx, yy);
	if (Fabs(dis - r - rr) < 1e-8)
	{
		sb a;
		a.x = xx - x;
		a.y = yy - y;
		double bi = r / (r + rr);
		return (sb){a.x * bi + x, a.y * bi + y};
	}
	double co = (r * r + dis * dis - rr * rr) / (2.0 * r * dis);
	double si = sqrt(1 - co * co);
	double bi = r / dis;
	sb a, b;
	a.x = dis * co;
	a.y = dis * si;
	a.x *= bi;
	a.y *= bi;
	return (sb){a.x, a.y};
}
inline sb circle2(double x, double y, double r, double xx, double yy, double rr)
{
	double dis = getdis(x, y, xx, yy);
	if (Fabs(dis - r - rr) < 1e-8)
	{
		sb a;
		a.x = xx - x;
		a.y = yy - y;
		double bi = r / (r + rr);
		return (sb){a.x * bi + x, a.y * bi + y};
	}
	double co = (r * r + dis * dis - rr * rr) / (2.0 * r * dis);
	double si = -sqrt(1 - co * co);
	double bi = r / dis;
	sb a, b;
	a.x = dis * co;
	a.y = dis * si;
	a.x *= bi;
	a.y *= bi;
	return (sb){a.x, a.y};
}
int main()
{
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	cin >> n;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= n; j ++)
			scanf("%lf", &a[i][j]);
	x[1] = 0.0; y[1] = 0.0;
	x[2] = a[1][2]; y[2] = 0.0;
	for(i = 3; i <= n; i ++)
	{
		sb aa = circle1(x[1], y[1], a[1][i], x[2], y[2], a[2][i]);
		sb b = circle2(x[1], y[1], a[1][i], x[2], y[2], a[2][i]);
		bool OK = 1;
		for(j = 1; j < i; j ++)
			if (Fabs(getdis(aa.x, aa.y, x[j], y[j]) - a[j][i]) > 1e-8)
			{
				OK = 0;
				break;
			}
		if (OK) x[i] = aa.x, y[i] = aa.y;
		else x[i] = b.x, y[i] = b.y;
	}
	for(i = 1; i <= n; i ++)
		printf("%.6lf %.6lf\n", x[i], y[i]);
}