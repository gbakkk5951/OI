#include<cstdio>
int main()
{
	int m,d,s;
	while(~scanf("%d%d",&m,&d))
	{
		s=(m*2+d)%3;
		switch(s)
		{
			case 0: 
			{
			printf("��ͨ\n");
			break;
			}
			case 1:
				{
					printf("��\n");
					break;
				}
			case 2:
				{
					printf("��\n");
					break;
				}
		}
		
	}
}
