#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <time.h>
#define db double
using namespace std;
int n;

int main()
{
	freopen("data.in", "w", stdout);
	double x;
	int a, b;
	srand((int)time(0));
	n = 1;
	cout << n << endl;
	for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= 4; ++j)
				{
					a = rand(), b = 1 + rand();
					x = (db)a / b;
					printf("%.8lf ", x);
					a = rand(), b = 1 + rand();
					x = (db)a / b;
					printf("%.8lf ", x);
				}
			printf("\n");
		}
	fclose(stdout);
	return 0;
}
