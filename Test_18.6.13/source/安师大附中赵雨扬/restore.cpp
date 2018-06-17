#include <cstdio>
#include <cmath>

using namespace std;

struct IO_Tp
{
	bool is_digit(char ch) const
	{
		return '0' <= ch && ch <= '9';
	}
	
	const IO_Tp& operator>>(int& buf)
	{
		buf = 0;
		static char ch;
		while (ch = getchar(), !is_digit(ch))
			;
		do
			(buf *= 10) += ch & 15;
		while (ch = getchar(), is_digit(ch));
		return *this;
	}
} IO;

const int Max_N(105);

int N, cur;
double D[Max_N][Max_N], x[Max_N], y[Max_N];

inline double distance(const int& P1, const int& P2)
{
	return hypot(x[P1] - x[P2], y[P1] - y[P2]);
}

inline double area(const int& P1, const int& P2, const int& P3)
{
	double s((D[P1][P2] + D[P2][P3] + D[P3][P1]) / 2);
	return sqrt(s * (s - D[P1][P2]) * (s - D[P2][P3]) * (s - D[P3][P1]));
}

int main(int argc, char** argv)
{
	freopen("restore.in", "r", stdin);
	freopen("restore.out", "w", stdout);
	
	IO >> N;
	for (int i(0); i != N; ++i)
		for (int j(0); j != N; ++j)
			scanf("%lf", D[i] + j);
	cur = 1;
	if (N >= 3)
	{
		for (int i(2); i != N; ++i)
			if (D[0][cur] < D[0][i])
				cur = i;
	}
			
	x[0] = y[0] = y[cur] = 1E-15;
	x[cur] = D[0][cur];
	if (N >= 3)
	{
		for (int i(1); i != N; ++i)
			if (i != cur) 
			{
				y[i] = 2 * area(0, cur, i) / D[0][cur];
				x[i] = sqrt(D[0][i] * D[0][i] - y[i] * y[i]);
				double d(distance(cur, i));
				x[i] = -x[i];
				if (fabs(d - D[cur][i]) < fabs(distance(cur, i) - D[cur][i]))
					x[i] = -x[i];
			}
			int cur2(cur == 1 ? 2 : 1);
			for (int i(1); i != N; ++i)
				if (i != cur && y[cur2] < y[i])
					cur2 = i;
			if (y[cur2] > 1E-6)
				for (int i(1); i != N; ++i)
					if (i != cur && i != cur2)
					{
						double d(distance(cur2, i));
						y[i] = -y[i];
						if (fabs(d - D[cur2][i]) < fabs(distance(cur2, i) - D[cur2][i]))
							y[i] = -y[i];
					}
	}
	
	for (int i(0); i != N; ++i)
		printf("%lf %lf\n", x[i], y[i]);
	
	return 0;
}
