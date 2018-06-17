#include<cstdio>
int n,A[10][10];
void work()
{
	bool ff=0;
	for(int i=-2000;i<=2000;i++)
	{
		for(int j=-2000;j<=2000;j++)
		{
			if((A[1][1]*j-A[1][2]*i)==1)
			{
				printf("%d %d\n%d %d\n",A[1][1],A[1][2],i,j);
				ff=1;
				return ;
			}
		}
	}
	if(!ff)
	{
		puts("no solution");
	}
	return ;
}
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[1][i]);
	}
	if(n<=2)
	{
		work();
	}
	else
	{
		puts("no solution");
	}
	return 0;
}
