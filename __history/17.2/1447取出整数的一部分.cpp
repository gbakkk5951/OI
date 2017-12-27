#include<cstdio>
int main()
{
	int list[11];
	list[1]=1;
	int i=0,j=0,k=0;
	for(i=2;i<11;i++)
	list[i]=10*list[i-1];
	int n,ws;
	scanf("%d%d",&n,&k);
	for(i=10;i>0;i--)
	{if(n>list[i])
	{
		ws=i;
		break;
	}
	}
	if(k==0)
	printf("%d",n);
	else if(k<0)
	{
		if(-k<ws)
		{
			printf("%d",n%list[-k+1]);
		}
		else if(-k==ws)
		printf("%d",n);
		else printf("Error");
	}
	else
	{
		if(k<ws)
		{
			printf("%d",n/list[ws-k+1]);
		}
		else if(k==ws)
		printf("%d",n);
		else printf("Error");
		
	}
	
	
}
