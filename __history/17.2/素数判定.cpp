#include<cmath>
#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int i=2;
	int g=sqrt(n);
	for(;i<=g;i++)
	{
		if(!(n%i))
		{printf("\\n");
		return 0;
		}
	}
	printf("\\t");
	return 0;
}
