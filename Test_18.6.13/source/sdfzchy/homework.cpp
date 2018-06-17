//by achhhy
#include<cstdio>
using namespace std;
int n,m;
double ans;
int main()
{
 	freopen("homework.in","r",stdin);
 	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	for(int i=100000;i>n;--i) ans=(1-ans)/i;
	printf("%.4lf\n",ans);
	return 0;
}
