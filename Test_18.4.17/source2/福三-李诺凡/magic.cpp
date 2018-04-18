#include<iostream>
#include<stdio.h>
using namespace std;
long long n,k,i,a[400001],factorial[400001]={1},answer=0,j;
long long pow (long long a,long long b=k-2)
{
	if (b==0)
	return 1;
	const long long c=pow(a,b/2); 
	if (b&1)
	return a*c%k*c%k;
	return c*c%k;
}
int main ()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for (i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	if (n>1000)
	{
		for (i=1;i<=n;i++)
		factorial[i]=i*factorial[i-1]%k;
		for (i=1;i<=n;i++)
		answer=(answer+a[i]*factorial[n-1]%k*pow(factorial[i-1])%k*pow(factorial[n-i])%k)%k;
		printf("%d",answer);
	}
	else
	{
		for (i=1;i<n;i++)
		for (j=1;j<=n-i;j++)
		a[j]=(a[j]+a[j+1])%k;
		printf("%d",a[1]);
	}
	return 0;
}
