#include <cstdio>
#include <cmath>

#define eps 1e-3

using namespace std;

int n;
double D[105][105], X[105], Y[105];

inline double sqr(double x)
{
	return x * x;
}

inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

void get_position(int i)
{
	double x1 = X[i - 1], y1 = Y[i - 1], x2 = X[i - 2], y2 = Y[i - 2], r1 = D[i - 1][i], r2 = D[i - 2][i];
	double px, nx, py, ny;
	if (abs(y1 - y2) <= eps)
	{
		px = (sqr(r1) - sqr(r2) + sqr(x2 - x1)) / ((x2 - x1) * 2);
		double s = sqrt(sqr(r1) - sqr(px));
		py = y1 + s;
		px = x1 + px;
		nx = px;
		ny = y1 - s;
	}
	else
	{
		double k = (x1 - x2) / (y2 - y1);
		//printf("k = %.6lf\n", k);
		double b = ((sqr(r1) - sqr(r2)) - (sqr(x1) - sqr(x2)) - (sqr(y1) - sqr(y2))) / ((y2 - y1) * 2);
		double A = sqr(k) + 1, B = 2 * (b - y1) * k - 2 * x1, C = sqr(b - y1) - sqr(r1) + sqr(x1);
		double delta = sqr(B) - 4 * A * C;
		/*if (delta < 0)
		{
			printf("delta = %.6lf\n", delta);
		}*/
		double sdel = sqrt(delta);
		px = (-B + sdel) / (2 * A);
		nx = (-B - sdel) / (2 * A);
		py = k * px + b;
		ny = k * nx + b;
	}
	for (int k = i - 3; k >= 1; k--)
	{
		double pd = dist(px, py, X[k], Y[k]);
		double nd = dist(nx, ny, X[k], Y[k]);
		//printf("P(%.6lf, %.6lf), N(%.6lf, %.6lf)\n", px, py, nx, ny);
		//printf("abs : %.6lf %.6lf\n", abs(pd - D[i][k]), abs(nd - D[i][k]));
		if (abs(pd - D[i][k]) < abs(nd - D[i][k]) - eps)
		{
			X[i] = px;
			Y[i] = py;
			return;
		}
		else if (abs(pd - D[i][k]) > abs(nd - D[i][k]) + eps)
		{
			X[i] = nx;
			Y[i] = ny;
			return;
		}
	}
	X[i] = px;
	Y[i] = py;
}

int main()
{
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%lf", &D[i][j]);
		}
	}
	X[1] = Y[1] = 0;
	X[2] = D[1][2], Y[2] = 0;
	X[3] = (sqr(D[1][3]) - sqr(D[2][3]) + sqr(X[2])) / (X[2] * 2);
	Y[3] = sqrt(sqr(D[1][3]) - sqr(X[3]));
	for (int i = 4; i <= n; i++)
	{
		get_position(i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%.6lf %.6lf\n", X[i], Y[i]);
	}
	return 0;
}
