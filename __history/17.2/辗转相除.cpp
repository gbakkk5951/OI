#include<cstdio>
using namespace std;
int main()
{
	int a=0,b=0;
	int gcd(int,int);
	while(~scanf("%d%d",&a,&b))
	printf("%d\n",gcd(a,b));
	
	
	
}
int gcd(int x,int y)
{
//	return 0;
//return 	y?x:gcd(y,x%y);
	return x>y?(y?gcd(y,x%y):x):(x?gcd(x,y%x):y);
	
}
