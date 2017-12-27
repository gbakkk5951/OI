#include<cstdio>
#include<cctype>
#include<cstdlib>
int main()
{
char a[10]={'a','0','-','\0'};
if(isprint(a[0]))
printf("alpha\n");
if( isprint(a[1]))
printf("digit\n");
if(isprint(a[2]))
printf("minus");
if(!isprint(a[3]))
printf("no");

system("pause");



}
