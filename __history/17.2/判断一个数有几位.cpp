#include<cstdio>
int main()
{
	int n;
	int po[11];
	int i=2;
	po[1]=1;
	for(;i<=10;i++)
	po[i]=10*po[i-1];
	scanf("%d",&n);
	i=10;
	while(!(n/po[i]))
    i--;
	printf("%d",i);	
	
}
