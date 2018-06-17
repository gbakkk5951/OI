#define yuki(x, y) for(int i = x, __yuki__ = y; i < __yuki__; ++i)
#define yukj(x, y) for(int j = x, __yukj__ = y; j < __yukj__; ++j)
#define yukii(x, y) for(int i = x, __yukii__ = y; i <= __yukii__; ++i)
#define yukji(x, y) for(int j = x, __yukji__ = y; j <= __yukji__; ++j)
#define yuk(x, y, z) for(int x = y, __yuk__ = z; x < __yuk__; ++x)
#define yui(x, y, z) for(int x = y, __yui__ = z; x >= __yui__; --x)
#define sclr(x) memset(x, 0, sizeof(x))
#define sclr1(x) memset(x, -1, sizeof(x))
#define scl(x, y) memset(x, y, sizeof(x))
#define ft first
#define sc second
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long lol;
double f0 = 1-exp(-1), f1 = 0;
int n;
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
#endif // snowoi
    scanf("%d", &n);
    yukii(1, n)
        f0 = f1 = 1-i*f0;
    printf("%.4lf\n", f0);
	return 0;
}
