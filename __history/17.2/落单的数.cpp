#include<cstdio> 
int main()
{
int save,temp,n,i;
scanf("%d%d",&n,&save);
for(i=1;i<n;i++)
{
scanf("%d",&temp);
save^=temp;
}
printf("%d",save);
}
