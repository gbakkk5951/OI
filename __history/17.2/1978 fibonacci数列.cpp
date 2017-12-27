#include<cstdio>
unsigned long long f[41]; 
int main()
{
	int n;
	scanf("%d",&n);
	f[1]=1;
	f[2]=f[1];
	int i=3;
	for(;i<=n;i++)
	f[i]=f[i-1]+f[i-2];
	
	printf("%llu",f[n]);
	
}
