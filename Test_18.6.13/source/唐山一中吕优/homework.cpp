#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double e,f[10005];
int n;

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	double L=0.2,R=0.4;
	while (R-L>0.000000001)  
	{
		double mid=(L+R)/2;
		if (log(mid)<=-1) e=mid,L=mid+0.000000001;
		else R=mid-0.000000001;
	}
	f[0]=1-e;
	for (int i=1;i<=n;i++) f[i]=1-i*f[i-1];
	printf("%.4f\n",f[n]);
	return 0;	
}
