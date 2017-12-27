#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int l,r;
bool isprime[5000010];
int prime[50010];
int total;
int sum;
int main()
{
	int g;
	scanf("%d%d",&l,&r);
	g=sqrt(l);
	sum=r-max(l,2)+1;
	int i=0,j=0,k=0;
	
	for(i=2;i<=r;i++)
	{
		if(!isprime[i])
		{
			prime[total++]=i;
		}
		for(j=0;j<total&&(k=i*prime[j])<=r;j++)
		{
			
			isprime[k]=true;
			if(k>=l){
				sum--;
			}
			if(!(i%prime[j]))
			break;
			
		}
		
		
		
	}
	printf("%d",sum);
	
}
