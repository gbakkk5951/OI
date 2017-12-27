#include<cstdio>
int main()
{
	long long sum=0,t;
	int n;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&t);
	    sum+=t;
	}
	printf("%lld",sum);
	}
