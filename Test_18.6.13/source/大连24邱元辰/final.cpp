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
using namespace std;
typedef long long lol;
int a, b;
void exgcd(int a, int b, int &x, int &y)
{
    if(!b)
        x = 1, y = 0;
    else
    {
        exgcd(b, a%b, y, x);
        y -= a/b*x;
    }
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("final.in", "r", stdin);
    freopen("final.out", "w", stdout);
#endif // snowoi
    scanf("%*d%d%d", &a, &b);
    int x, y;
    exgcd(a, b, x, y);
    printf("%d %d\n%d %d\n", a, b, x, -y);
	return 0;
}
