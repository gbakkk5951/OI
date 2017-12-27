#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *a;
	int num=0;
	a=freopen("Ëæ»úÊý.out","w",stdout);
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	printf("%d ",rand());
	fclose(a);
}
