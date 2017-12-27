#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n;
void mov(int a,int b,int c,int times);
int main()
{
scanf("%d",&n);
printf("%d\n",(int)pow(2,n)-1);
int i=0;
mov(0,1,2,n);	
	
}
void mov(int a,int b,int c,int times)
{
	if(times==1)
	{

		printf("%d from %c to %c\n",times ,'A'+a,'A'+c);
	    return;
	}
	mov(a,c,b,times-1);
	printf("%d from %c to %c\n",times ,'A'+a,'A'+c);

	mov(b,a,c,times-1);	
}
