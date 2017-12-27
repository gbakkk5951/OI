#include<cstdio>
int n;
int y=1900,m=1,d=1,w=1;
int t[8];
int main()
{
	int i;
	scanf("%d",&n);
	while(y!=1900+n-1||m!=12||d!=31)
	{
//		printf("%d.%d.%d(%d)\n",y,m,d,w);
		if(d==13)
		t[w]++;
		w++;
		if(w==8)
		w=1;
		d++;
		if(m==2)
		{
			if(y%400==0||(y%4==0&&y%100))
			{
				if(d==30)
				{d=1;
				m++;
				}
				
			}
			else
			{
				if(d==29)
			{
					d=1;
				m++;
			}	
		}
		}else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d==32)
			{d=1;
			m++;
	
			if(m==13)
			{m=1;y++;
			}
			}
		}
		else
		{
			if(d==31)
			{d=1;
			m++;
			}
		}
		
	}
	
	
	
	
	printf("%d %d ",t[6],t[7]);
	for(i=1;i<6;i++)
	printf("%d ",t[i]);
}

