#include<cstdio>
#include<cmath>
int sum;
bool isp(int x)
{int i=0;

	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		return false;
		
	}
	return true;
}
int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	if(l<2)
	l=2;
	int j=0;
	for(j=l;j<=r;j++)
	{
		if(isp(j))
		sum++;
	}
	printf("%d",sum);
	
}
