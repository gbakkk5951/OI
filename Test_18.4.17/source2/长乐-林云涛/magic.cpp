#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int minn = 1233;
const int maxn = 423333;
int n;
long long k;
long long c[minn][minn];
long long fac[maxn], rev[maxn], num[maxn];
inline int Get()
{
	int x;
	char c;
	while((c = getchar()) < '0' || c > '9');
	x = c - '0';
	while((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
	return x;
}
inline bool Prime(long long x)
{
	long long s = sqrt(x);
	for(int i = 2; i <= s; ++i)
		if(!(x % i)) return false;
	return true;
}
inline long long Pow(long long x, int n)
{
	long long sum = 1;
	while(n)
	{
		if(n & 1) sum = sum * x % k;
		x = x * x % k;
		n >>= 1;
	}
	return sum;
}
inline void Inv()
{
	fac[0] = rev[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		fac[i] = fac[i - 1] * i % k;
		rev[i] = Pow(fac[i], k - 2);
	}
}
inline long long Com(int n, int m)
{
	if(!m) return 1;
	if(!n) return 0;
	if(n <= m) return n == m;
	if(c[n][m]) return c[n][m];
	if(n < k) return fac[n] * rev[m] % k * rev[n - m] % k;
	return Com(n / k, m / k) * Com(n % k, m % k) % k;
}
inline void Com(int n)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= i; ++j)
		{
			if(!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
		}
}
inline long long Cal(long long k)
{
	long long ans = 0;
	int cnt = 0;
	int m = n + 1 >> 1;
	for(int i = 1; i <= m; ++i)
		ans = (ans + num[++cnt] * Com(n - 1, i - 1) % k) % k;
	if(n & 1) --m;
	for(int i = m; i >= 1; --i)
		ans = (ans + num[++cnt] * Com(n - 1, i - 1) % k) % k;
	return ans;
}
int main()
{
	freopen("magic.in", "r", stdin), freopen("magic.out", "w", stdout);
	n = Get(), k = Get();
	for(int i = 1; i <= n; ++i) num[i] = Get();
	if(n <= 1000)
	{
		Com(n);
		cout<<Cal(k)<<endl;
		return 0;
	}
	if(k == 10)
	{
		Inv();
		Com(1000);
		long long a = Cal(2), b = Cal(5);
		long long ans = 5 * a + b;
		cout<<ans<<endl;
		return 0;
	}
	if(Prime(k))
	{
		Inv();
		Com(1000);
		cout<<Cal(k)<<endl;
		return 0;
	}
}
