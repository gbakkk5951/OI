#include<cstdio>
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	int t1,t2;
	scanf("%d%d",&t1,&t2);
	printf("%d",gcd(t1,t2)); 
	
}
