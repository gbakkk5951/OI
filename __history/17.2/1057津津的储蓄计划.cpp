#include<cstdio>
int sav;
int hand;
int main()
{
	int i=0;
	int t1,t2;
	for(i=0;i<12;i++)
	{
		hand+=300;
		scanf("%d",&t1);
		if(t1>hand)
		{
		
		printf("%d",-(i+1));
		return 0;
		}else {
			hand-=t1;
		sav+=hand/100;
		hand=hand%100;
		}
		
	}
	printf("%d",hand+sav*120);
	
}
