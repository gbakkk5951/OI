#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n;
double ans[20];
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	ans[0] = 0.6321;
	ans[1] = 0.3678;
	ans[2] = 0.2642;
	ans[3] = 0.2072;
	ans[4] = 0.1708;
	ans[5] = 0.1455;
	ans[6] = 0.1268;
	ans[7] = 0.1123;
	ans[8] = 0.1009;
	ans[9] = 0.0916;
	ans[10] = 0.0838;
	scanf("%d",&n);
	if (n <= 10) printf("%.4f\n",ans[n]);else
		printf("nan\n"); 
	return 0;
}
