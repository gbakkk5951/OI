#include<cstdio>
#include<cmath>
int n;
int sum;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	else return gcd(b,a%b);
	
}
int main()
{
	int p,q;
    
	
	scanf("%d%d",&p,&q);

	n=q/p;
	int i=0;
	int g=sqrt(n);
	if(n==1)
	{printf("1");
	return 0;
	}
	if(q%p!=0||q<p)
	{printf("0");
	return 0;
	}
	for(i=1;i<=g;i++)
	{
		if(!(n%i))
	    {
	    	if(gcd(i,n/i)==1)
	    	sum++;
		}	
		
	}
	
	printf("%d",sum*2);
	return 0;
}


