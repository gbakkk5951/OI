#include<cstdio>
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int n;
	scanf("%d",&n);
	++n;
	double ans=0,p=1.0*n;
	for(int i=1;p<1e+12;p*=1.0*(n+i),i++)
	{
		if(i&1)
		{
			ans+=1.0/p;
		}
		else
		{
			ans-=1.0/p;
		}
	}
	printf("%.4lf\n",ans);
	return 0;
}
