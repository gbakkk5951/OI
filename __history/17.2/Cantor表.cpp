#include<cstdio>
#include<cmath>
int x,n;
int zi,mu;
int bf;
int main(){
	scanf("%d",&x);
	if(x==1)
	{printf("1/1");
	return 0;
	}
	
n=(int)floor( sqrt(0.25+2*x)-0.5);
bf=0.5*n*(n+1);

if(n%2==0)
{
if(x==bf)
printf("%d/1",n);
else{
    zi=2+n-(x-bf);
	mu=x-bf;
	printf("%d/%d",zi,mu);
    }
}else
if(x==bf)
printf("1/%d",n);
else
{
	zi=x-bf;
	mu=2+n-(x-bf);
	printf("%d/%d",zi,mu);
}

}
