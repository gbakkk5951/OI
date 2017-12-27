#include<cstdio>
int main()
{
double a,b;
scanf("%lf%lf",&a,&b);
if(a==b)
{
printf("yes");
return 0;
}
if(a>b)
{if(a-0.00000001<=b)
printf("yes");
else printf("no"); 
}else{
	if(a+0.00000001>=b)
printf("yes");
else printf("no"); 
	
} 

}
