
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long double LD;

const int Max_N(105);
const LD EPS(1E-3);

int N;
LD D[Max_N][Max_N];
LD X[Max_N][2], Y[Max_N][2];

inline LD squ(const LD &a)
{
	return a * a;
}

inline LD Dist(const LD &x1, const LD &y1, const LD &x2, const LD &y2)
{
	return squ(x1 - x2) + squ(y1 - y2);
}

void init()
{
	cin >> N;
	for (int i = 1;i <= N;++i)
		for (int j = 1;j <= N;++j)
			cin >> D[i][j];
}

void prepare()
{
	X[1][0] = X[1][1] = 0.0, Y[1][0] = Y[1][1] = 0.0;
	X[2][0] = X[2][1] = D[1][2], Y[2][0] = Y[2][1] = 0.0;
	for (int i = 3;i <= N;++i)
	{
		X[i][0] = X[i][1] = (squ(D[2][i]) - squ(X[2][0]) - squ(D[1][i])) / static_cast<LD>(-2.0 * D[1][2]);
		Y[i][0] = sqrt(fabs(squ(D[1][i]) - squ(X[i][0])));
		Y[i][1] = -sqrt(fabs(squ(D[1][i]) - squ(X[i][1])));
	}
}

inline bool equal(const double &a, const double &b)
{
	return fabs(a - b) < EPS;
}

bool check()
{
	for (int i = 4;i <= N;++i)
	{
		bool qwq;
		qwq = false;
		for (int j = 1;j <= i - 1;++j)
			if (equal(Dist(X[i][0], Y[i][0], X[j][0], Y[j][0]), squ(D[i][j])) == false)
			{
				qwq = true;
				break;
			}
		if (qwq)
		{
			swap(X[i][0], X[i][1]), swap(Y[i][0], Y[i][1]);
			qwq = false;
			for (int j = 1;j <= i - 1;++j)
				if (equal(Dist(X[i][0], Y[i][0], X[j][0], Y[j][0]), squ(D[i][j])) == false)
				{
					qwq = true;
					break;
				}
			if (qwq)
				return false;
		}
	}
	return true;
}

int main()
{
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	init();
	prepare();
	if (check())
		;
	else
	{
		swap(X[3][0], X[3][1]), swap(Y[3][0], Y[3][1]);
		check();
	}
	for (int i = 1;i <= N;++i)
		cout << X[i][0] << ' ' << Y[i][0] << endl;
	return 0;
}
