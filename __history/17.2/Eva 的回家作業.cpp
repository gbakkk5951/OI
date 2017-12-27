#include<cstdio>
int main()
{
	int n;
	int a[4];
	int i;
	scanf("%d",&n);
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		scanf("%d",&a[j]);
		
		if(a[3]-a[2]==a[2]-a[1])
		{
			for(j=0;j<4;j++)
			printf("%d ",a[j]);
			printf("%d\n",2*a[3]-a[2]);
			
		}
		else
		{
			for(j=0;j<4;j++)
			printf("%d ",a[j]);
			printf("%d\n",a[3]*(a[3]/a[2]));
		}
		
	}
}
