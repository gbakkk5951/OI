#include<cstdio>
int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		if(!(t%100))
		{
			if(!(t%400))
			printf("�c��\n");
			else printf("ƽ��\n"); 
			
		}
		else
		{
			if(!(t%4))
			printf("�c��\n");
			else
			printf("ƽ��\n");
		}
		
	}
	
	
}
