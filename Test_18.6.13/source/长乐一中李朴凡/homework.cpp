#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
double f[10005];
int n, i;
int main()
{
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	cin >> n;
	f[0] = 1 - 1 / exp(1);
	for(i = 1; i <= n; i ++)
		f[i] = 1 - i * f[i - 1];
	printf("%.4lf\n", f[n]);
}