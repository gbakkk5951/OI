#include<cstdio>
#include<algorithm>
#include<cmath>
long long m,n,f;
int main()
{
FILE *a=	freopen("Plant.in","r",stdin);
FILE *b=	freopen("Plant.out","w",stdout);
scanf("%lld%lld%lld",&n,&m,&f);

long long ans=1;
long long max,min=1;
if(m>n)
max=n;
else max=m;



long long mid;
while(1)
{
	if(max==min)
	if((m/max)*(n/max)>=f)
	{
	ans=max;
    break;
	}
	if(max==min+1)
	{if((m/max)*(n/max)>=f)
	ans=max;
	else if((m/min)*(n/min)>=f)
	ans=min;
	break;
	}
	
	
	mid=(max+min)/2;
	if((m/mid)*(n/mid)>=f)
	{
	ans=mid;
	min=mid;}
	else {
	max=mid;
	}
	
}
printf("%lld",ans);
 fclose(a);
 fclose(b);
 return 0;
 
}
