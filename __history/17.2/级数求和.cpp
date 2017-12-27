#include<cstdio>
#include<vector>
int main()
{
	int goal=0;
	double sum=0;
	int i=1;
    scanf("%d",&goal);
	for(i=1;sum<=goal;i++)
	sum+=(double)1/i;
	printf("%d",i-1);
}
