#include<cstdio>
int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		if(!(t%100))
		{
			if(!(t%400))
			printf("閏年\n");
			else printf("平年\n"); 
			
		}
		else
		{
			if(!(t%4))
			printf("閏年\n");
			else
			printf("平年\n");
		}
		
	}
	
	
}
