#include<cstdio>
#include<cstring>
int main()
{
	int i,g;
	char a[100];
	scanf("%s",a);
	g=strlen(a);
	if(a[0]!='-'&&a[0]!='+')
	{
	
	printf("-%s",a);
    return 0;
	}
	if(a[0]=='+')
	printf("-");
	
	for(i=1;i<g;i++)
	printf("%c",a[i]);
	
}
