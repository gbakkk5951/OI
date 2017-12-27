#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1000000000
#define mod 1000000007
#define N 30
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
int n,i,j,T;
int cnt;
int pp[N],p[N],x[N],y[N];
double dis[N][N];
const int max_rand = 2333333;
void drunk()
{
    int i,x,y;
    fo(i,1,n) pp[i] = p[i];
    x = rand() % n + 1; y = rand() % n + 1;
    swap(pp[x],pp[y]);
}
void calc(int *p,double &s)
{
    int i; s = 0;
    fo(i,1,n-1) s += dis[p[i]][p[i+1]];
}
bool accept(double delta,double tmp)
{
    if (delta <= 0) return true;
    printf("%f\n",exp((-delta)/tmp));
    return rand() % max_rand <= exp((-delta)/tmp) * max_rand;
}
double solve()
{
    int i; double dis1,dis2;
    double res = 100000000.0;
    const double max_tmp = 100000;
    const double dec = 0.999;
    double tmp = max_tmp;
    fo(i,1,n) p[i] = i; calc(p,dis1);
    while (tmp > 0.01)
        {
            drunk(); calc(pp,dis2);
            if (accept(dis2-dis1,tmp))
                {fo(i,1,n) p[i] = pp[i]; dis1 = dis2;}
            tmp *= dec;
            cnt++;
            if (dis1 < res) res = dis1;
        }
    return res;
}

int main()
{
    cnt = 0;
    srand(233333);
    scanf("%d",&n);
    fo(i,1,n) scanf("%d%d",&x[i],&y[i]);
    fo(i,1,n) fo(j,1,n) dis[i][j] = dis[j][i] = hypot(x[i]-x[j],y[i]-y[j]);
    double ans = 1000000000.0; T = 150;
    while (T--) ans = min(ans,solve());
    printf("%.2lf\n",ans);
    return 0;
}
