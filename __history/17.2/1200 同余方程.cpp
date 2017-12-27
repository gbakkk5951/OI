#include<cstdio>

int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x==1;y==0;
		return a£»	
	}
	int ans=gcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-a/b*y; 
	return ans;
	
}


int main()
{
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	printf("%d")
	
	
}
