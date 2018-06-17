#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, a[2005], i, j;
int main()
{
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	cin >> n;
	for(i = 1; i <= n; i ++)
		cin >> a[i];
	if (n > 2) {cout << "no solution"; return 0;}
	for(i = -2000; i <= 2000; i ++)
		for(j = -2000; j <= 2000; j ++)
			if (j * a[1] - i * a[2] == 1)
			{
				cout << a[1] << " " << a[2] << endl << i << " " << j << endl;
				return 0;
			}
}