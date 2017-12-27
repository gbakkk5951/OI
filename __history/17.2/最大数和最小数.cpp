#include<cstdio>
int max=-2147483648,min=2147483647,temp,i,n;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
scanf("%d",&temp);	
	if(temp<min)
	min=temp;
	if(temp>max)
	max=temp;
}
	printf("%d %d",min,max);
}
