#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
const int maxn = 400040;
int n, k, a[maxn], b[maxn];
long long ans, fz = 1, fm = 1, ny;
inline int readint()
{
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    int x = 0;
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return ;
    }
    else
    {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}

long long work(long long a, long long b)
{
    long long x, y;
    exgcd(a, b, x, y);
    return (x + b) % b;
}

int main()
{
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    n = readint();
    k = readint();
    for (int i = 1; i <= n; ++i) a[i] = readint();
    if (n <= 1000)
    {
        while (n)
        {
            for (int j = 1; j < n; ++j) b[j] = (a[j] + a[j + 1]) % k;
            for (int j = 1; j < n; ++j) a[j] = b[j];
            --n;
        }
        cout << a[1] ;
    }
    else
    {
        if (k == 10)
        {
            ans = a[1] + a[n];
            if (n & 1)
            {
                for (int i = 1; i <= (n >> 1); ++i)
                {
                    fz = fz * (n - i);
                    fm = fm * i;
                    ny = fz / fm;
                    if (ny % k == 0) break;
                    else
                    {
                        if (i != (n >> 1))
                            ans = (ans + ny * (a[i + 1] + a[n - i])) % k;
                        else ans = (ans + ny * a[i + 1]) % k;
                    }
                }
            }
            else
            {
                for (int i = 1; i < (n >> 1); ++i)
                {
                    fz = fz * (n - i);
                    fm = fm * i;
                    ny = fz / fm;
                    if (ny % k == 0) break;
                    else ans = (ans + ny * (a[i + 1] + a[n - i])) % k;
                }
            }
            cout << ans ;
        }
        else
        {
            ans = a[1];
            for (int i = 1; i < n; ++i)
            {
                fz = (fz * (n - i)) % k;
                fm = (fm * i) % k;
                ny = work(fm, k);
                ans = (ans + fz * a[i + 1] * ny) % k;
            }
            cout << ans ;
        }
    }
    return 0;
}
