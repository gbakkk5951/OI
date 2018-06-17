#include <bits/stdc++.h>
using namespace std;

const int N=10;
int n,a[N],b[N][N];

int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	if(n==2)
	{
		for(i=-2000;i<=2000;i++)
		    if((1+a[2]*i)%a[1]==0&&abs((1+a[2]*i)/a[1])<=2000)
		    {
		    	printf("%d %d\n%d %d\n",a[1],a[2],i,(1+a[2]*i)/a[1]);
		        return 0;
		    }
		printf("no solution\n");
		return 0;
	}
	printf("no solution\n");
	return 0;
}

