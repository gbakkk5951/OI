#include"algorithm"
#include"stdlib.h"
#include"string.h"
#include"stdio.h"
#include"math.h"

using namespace std;

int n, m = 100000;
long double ans,fac[10005],ifac[1000005],sum;

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf ("%d",&n);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; i ++) fac[i] = fac[i-1] * i;
	for (int i = 1; i <= m; i ++) ifac[i] = -ifac[i-1] / i;
	ans = 0;
	for (int j = n + 1; j <= m; j ++) ans += ifac[j];
	ans *= fac[n] * ((n & 1) ? 1 : -1);
	printf ("%.4lf", (double) ans);
	return 0;
}
