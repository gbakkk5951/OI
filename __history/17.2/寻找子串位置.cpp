#include<cstdio>
#include<cstring> 
char a[101],b[101];
int main()
{
scanf("%s%s",a,b);
int ia=strlen(a),ib	=strlen(b);

int i=0,j=0;
for(i=0;i<=ia-ib;i++)
{
	bool end=false;

	for(j=0;j<ib;j++)
	{

	if(b[j]!=a[i+j])
		{break;
		}else if(j==ib-1)
		end=true;
	}
	if(end)
	{printf("%d",i+1);
	return 0;
	}
}
	
 } 

