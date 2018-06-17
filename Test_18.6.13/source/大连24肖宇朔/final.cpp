#include <cstdio>

using namespace std;

int n, h[10][10];

void exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
	}
	else
	{
		exgcd(b, a % b, x, y);
		int temp = x;
		x = y;
		y = temp - a / b * y;
	}
}

int main()
{
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[1][i]);
	}
	if (n == 2)
	{
		if (h[1][1] >= 0)
		{
			if (h[1][2] >= 0)
			{
				exgcd(h[1][1], h[1][2], h[2][2], h[2][1]);
				h[2][1] = -h[2][1];
			}
			else
			{
				exgcd(h[1][1], -h[1][2], h[2][2], h[2][1]);
			}
		}
		else
		{
			if (h[1][2] >= 0)
			{
				exgcd(-h[1][1], h[1][2], h[2][2], h[2][1]);
				h[2][2] = -h[2][2];
				h[2][1] = -h[2][1];
			}
			else
			{
				exgcd(-h[1][1], -h[1][2], h[2][2], h[2][1]);
				h[2][2] = -h[2][2];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", h[i][j]);
		}
		printf("\n");
	}
	return 0;
}
