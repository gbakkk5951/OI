#include<cstdio>
#include<cstring>
int l,r;
bool isprime[5000010];
int prime[5000010];
int total;
int sum;
int main()
{

	memset(isprime,true,5000010);
	scanf("%d%d",&l,&r);
	int i=0,j=0,k=0;
	
	for(i=2;i<=r;i++)
	{
		if(isprime[i])
		{
			prime[total++]=i;
			if(i>=l)
			sum++;
		}
		
		for(j=0;j<total&&i*prime[j]<=r;j++)
		{
			isprime[i*prime[j]]=false;
			if(!(i%prime[j]))
			break;
			
		}
		
		
		
	}
	printf("%d",sum);
	
}

