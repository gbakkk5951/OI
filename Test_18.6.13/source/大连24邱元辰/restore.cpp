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
typedef pair<double, double> poi;
const double eps = 1e-4;
int n;
double d[200][200];
poi pl[200];
bool c[200];
int dcmp(double x)
{
    return x < -eps ? -1 : x > eps;
}
void sread()
{
    scanf("%d", &n);
    yukii(1, n)
        yukji(1, n)
            scanf("%lf", d[i]+j);
}
double get2S(int a, int b, int c)
{
    double p = (d[a][b]+d[b][c]+d[a][c])/2;
    return 2*sqrt(p*(p-d[a][b])*(p-d[b][c])*(p-d[a][c]));
}
double gety(int x)
{
    return get2S(1, 2, x)/d[1][2];
}
double getx(int x, double y)
{
    double ret = sqrt(d[1][x]*d[1][x]-y*y);
    int t = dcmp(d[1][2]*d[1][2]+d[1][x]*d[1][x]-d[2][x]*d[2][x]);
    if(!t) return pl[1].ft;
    return t < 0 ? pl[1].ft-ret : pl[1].ft+ret;
}
double getdis(const poi &a, const poi &b)
{
    return sqrt((a.ft-b.ft)*(a.ft-b.ft)+(a.sc-b.sc)*(a.sc-b.sc));
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("restore.in", "r", stdin);
    freopen("restore.out", "w", stdout);
#endif // snowoi
    sread();
    pl[2] = poi(pl[1].ft+d[1][2], pl[1].sc);
    yuk(_, 0, 5)
    yukii(3, n)
    if(!c[i])
    {
        double y = gety(i);
        double x = getx(i, y);
        int maxp = -1, cho = 1;
        double maxv = 0;
        yukj(3, i)
        if(c[j])
        {
            double posv = fabs(getdis(pl[j], poi(x, y))-d[i][j]);
            double negv = fabs(getdis(pl[j], poi(x, -y))-d[i][j]);
            if(maxp == -1 || posv > maxv)
            {
                maxp = j;
                maxv = posv;
                cho = -1;
            }
            if(maxp == -1 || negv > maxv)
            {
                maxp = j;
                maxv = negv;
                cho = 1;
            }
        }
        if(i == 3+_ || _ == 4 || maxv > eps)
        {
            pl[i] = poi(x, y*cho);
            c[i] = true;
        }
    }
    yukii(1, n) printf("%.6lf %.6lf\n", pl[i].ft, pl[i].sc);
	return 0;
}
