#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 400005;
int n, k, i, j, a[MAXN], l, tot, ans, m, b[MAXN], pre[MAXN], inv[MAXN];
int c[2005][2005], f[2005][2005];
inline int get()
{
	char c;
	while ((c = getchar()) < 48 || c > 57);
	int res = c - 48;
	while ((c = getchar()) >= 48 && c <= 57)
		res = res * 10 + c - 48;
	return res;
}
inline bool check(int n)
{
	for(int i = 2; i * i <= n; i ++)
		if (!(n % i)) return 0;
	return 1;
}
inline int ksm(int x, int y, int z)
{
	int b = 1;
	while (y)
	{
		if (y & 1) b = (long long)x * b % z;
		x = (long long)x * x % z;
		y >>= 1;
	}
	return b;
}
inline int getc(int n, int m)
{
	if (m > n) return 0;
	if (n <= 2000) return c[n][m];
	return getc(n >> 1, m >> 1) & getc(n & 1, m & 1);
}
inline int getcc(int n, int m)
{
	if (m > n) return 0;
	if (n <= 2000) return f[n][m];
	return getcc(n / 5, m / 5) * getcc(n % 5, m % 5) % 5;
}
inline int getz(int n, int m)
{
	if (m > n) return 0;
	if (n < k) return pre[n] * (long long)inv[n - m] % k * (long long)inv[m] % k;
	return getz(n / k, m / k) * (long long)getz(n % k, m % k) % k; 
}
int main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n = get(); k = get();
	for(i = 1; i <= n; i ++)
		a[i] = get();
	if (n <= 10000)
	{
		m = n - 1;
		for(j = 1; j < n; j ++)
		{
			for(i = 1; i <= m; i ++)
			{
				b[i] = a[i] + a[i + 1];
				if (b[i] >= k) b[i] -= k;
			}
			for(i = 1; i <= m; i ++)
				a[i] = b[i];
			m --;
		}
		cout << b[1] << endl;
		return 0;
	}
	if (k == 10)
	{
		c[0][0] = 1;
		for(i = 1; i <= 2000; i ++)
		{
			c[i][0] = 1;
			for(j = 1; j <= i; j ++)
				c[i][j] = c[i - 1][j] ^ c[i - 1][j - 1];
		}
		f[0][0] = 1;
		for(i = 1; i <= 2000; i ++)
		{
			f[i][0] = 1;
			for(j = 1; j <= i; j ++)
			{
				f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
				while (f[i][j] >= 5) f[i][j] -= 5;
			}
		}
		for(i = 1; i <= n; i ++)
		{
			int p = getcc(n - 1, i - 1);
			int ok = getc(n - 1, i - 1);
			if ((p & 1) != ok) p += 5;
			ans += p * a[i];
			if (ans >= 10000000) ans %= k;
		}
		cout << ans % k << endl;
		return 0;
	}
	if (check(k))
	{
		pre[0] = 1;
		for(i = 1; i < k; i ++)
			pre[i] = pre[i - 1] * (long long)i % k;
		inv[k - 1] = ksm(pre[k - 1], k - 2, k);
		for(i = k - 2; i >= 0; i --)
			inv[i] = inv[i + 1] * (long long)(i + 1) % k;
//		for(i = 0; i <= k - 1; i ++)
	//		cout << pre[i] << " " << inv[i] << endl;
		for(i = 1; i <= n; i ++)
		{
			int p = getz(n - 1, i - 1);
			ans += a[i] * (long long)p % k;
			if (ans >= k) ans -= k;
		}
		cout << ans << endl;
		return 0;
	}
}
