#include<cstdio>
#include<cctype>
char x;
int sum;
int main()
{
	scanf("%c",&x);
	if(islower(x))
	{printf("I do not like lowercase letters!");
	return 0; 
	}
	int n;
	scanf("%d",&n);
	int i=0;
	char t;
	for(i=0;i<n;i++)
	{
	scanf("%c",&t);
	if(t==x)
	sum++;
	}
	printf("%d",sum);
} 
