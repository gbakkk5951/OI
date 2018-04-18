#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 400010
using namespace std;
typedef long long LL;
int n, p;
int jc[N], ie[N];
int f[100][100];
int a[N], b[N];

inline void Plus(int &x, int y)
{
	x += y;
	x = x >= p ? x - p : x;
}

inline int Ksm(int x, int y)
{
	int ans = 1;
	for(; y; x = (LL)x * x % p, y >>= 1)
		if(y & 1) ans = (LL)ans * x % p;
	return ans;
}

inline int C1(int n, int m)
{
	return (LL)jc[n] * (LL)ie[m] % p * (LL)ie[n-m] % p;
}

inline int calc(int n, int m)
{
	if(n < m) return 0;
	else return f[n][m];
}

inline int C2(int n, int m)  //Lucas
{
	if(!n && !m) return 1;
	return (LL)C2(n / p, m / p) * calc(n % p, m % p) % p;
}

int main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);

	for(int i=0; i<=10; ++i)
	{
		f[i][0] = 1;
		for(int j=1; j<=i; ++j)
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	}
	
	scanf("%d%d", &n, &p);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
	
/*	
	for(;;)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cout << C2(x, y) << "\n";
	}
*/

	if(n <= 1000)
	{
		for(int i=1; i<n; ++i)
		{
			for(int j=1; j<n; ++j)
				b[j] = (a[j] + a[j + 1]) % p;
			for(int j=1; j<=n; ++j)
				a[j] = b[j];
		}
		cout << a[1];
	}
	else if(p > 10)
	{
		jc[0] = 1;
		for(int i=1; i<=n; ++i) jc[i] = (LL)jc[i - 1] * i % p;
//		ie[n] = Ksm(jc[n], p - 2);
		int flag = 0;
		for(int i=n; i>=0; --i)  //如果没有保证模数p > n，就要这么写
		{
			if(!flag)
			{
				if(jc[i]) ie[i] = Ksm(jc[i], p - 2);
				flag = 1;
			}
			else ie[i] = (LL)ie[i + 1] * (i + 1) % p;
		}
		
		int ans = 0;
		for(int i=1; i<=n; ++i)
			Plus(ans, (LL)a[i] * C1(n - 1, i - 1) % p);
		
		cout << ans;
	}
	else
	{	
		int ans = 0;
		for(int i=1; i<=n; ++i)
			Plus(ans, (LL)a[i] * C2(n - 1, i - 1) % p);

		cout << ans;
	}
}