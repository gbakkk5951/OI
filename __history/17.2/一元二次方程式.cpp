#include<cstdio>
#include<cmath>
int main()
{
	int i,j,k,l,m,n;
	while(~scanf("%d%d%d",&i,&j,&k))
	{
		int d=j*j-4*i*k;
		if(d<0)
		{
			printf("No real root\n");
		
		}else
		{
			if(d==0)
			{
				printf("Two same roots x=%d\n",-j/(2*i));
				
			}
			else
			{
				printf("Two different roots x1=%d , x2=%d\n",-(j-(int)sqrt(d))/(2*i),-(j+(int)sqrt(d))/(2*i));
				
			}
			
		}

		
		
	}
	
}
