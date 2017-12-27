#include<cstdio>
int n,m;
int po[8];
int re[8];
void p(int a)
{

	if(a<=9)
	printf("%d",a);
	else printf("%c",a-10+'A');
}

int main()
{
	
	scanf("%d%d",&n,&m);
	int i=0;
	po[0]=1;
	for(i=1;i<8;i++)
	po[i]=m*po[i-1];
	
	for(i=1;i<8;i++)
	{
	re[i]=n%po[i]/po[i-1];
	
	}
		
	for(i=7;i>=1;i--)
	if(re[i])
	break;
	for(;i>=1;i--)
	p(re[i]);
	
}
