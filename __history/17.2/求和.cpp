#include<cstdio> 

int sum=0,temp,n;
int main()
{
	int i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",&temp);
	sum+=temp;
	}
	printf("%d",sum);
}
