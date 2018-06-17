#include <cstdio>
#include <algorithm>

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

const int Max_N(6);

int exgcd(int a, int b, int& x, int& y)
{
	bool f1(false), f2(false);
	if (a < 0)
	{
		a = -a;
		f1 = true;
	}
	if (b < 0)
	{
		b = -b;
		f2 = true;
	}
		if(b == 0)
		{
			x = 1, y = 0;
			return a;
		}
		int d(exgcd(b, a % b, y, x));
		y -= a / b * x;
	if (f1)
		a = -a, x = -x;
	if (f2)
		b = -b, y = -y;
	
	return d;
}

int N, H[Max_N][Max_N], P[Max_N], col1, col2, x, y;

int main(int argc, char** argv)
{
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	
	IO >> N;
	for (int i(0); i != N; ++i)
	{
		P[i] = i;
		for (int j(0); j != N; ++j)
			H[i][j] = 0;
	}
	for (int i(0); i != N; ++i)
		IO >> H[0][i];
	if (N == 2)
	{
		exgcd(H[0][0], H[0][1], H[1][1], H[1][0]);
		H[1][0] = -H[1][0];
	}
	else
	{
		for (int i(0); i != N; ++i)
			for (int j(i + 1); j != N; ++j)
				if (H[0][i] && H[0][j] && exgcd(H[0][i], H[0][j], x, y) == 1)
				{
					col1 = i, col2 = j;
					goto found;
				}
		found:
		if (col1 == 0 && col2 != 1)
		{
			swap(P[1], P[col2]);
			H[1][P[1]] = -x, H[1][0] = y;
		}
		else
		{
			swap(P[0], P[col1]);
			swap(P[1], P[col2]);
			H[1][P[1]] = x, H[1][P[0]] = -y;
		}
		
		for (int i(2); i != N; ++i)
			H[i][P[i]] = 1;
	}
	for (int i(0); i != N; ++i, putchar('\n'))
		for (int j(0); j != N; ++j)
			printf("%d ", H[i][j]);
	
	return 0;
}
