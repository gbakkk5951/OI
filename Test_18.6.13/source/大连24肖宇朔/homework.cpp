#include <cstdio>
#include <cmath>

#define e 2.7182818284590452353602874713527

using namespace std;

int main()
{
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	int n;
	scanf("%d", &n);
	double _f = 1 - 1 / e;
	for (int i = 1; i <= n; i++)
	{
		double f = 1 - i * _f;
		_f = f;
	}
	printf("%.4lf\n", _f);
	return 0;
}
