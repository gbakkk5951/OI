#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int year=2016;
int month=10;
int day=20;
int n=0;
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char data[1000][11];
int main(){

	char a[11];
	
	int pday=0;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{scanf("%d",&pday);
	for(;pday>=365;)
	{if(((year+1)%4==0&&(year+1)%100!=0)||((year+1)%400==0))
	{
		if(pday>=366)
		{
			year++;
			pday-=366;
		}
		else break;
	}else if(pday>=365)
		{
			year++;
			pday-=365;
		}
		else break;
		
		
	}
	

if(pday&&(year%4==0&&year%100!=0)||pday&&(year%400==0))
{

d[2]=29;}
else d[2]=28;
	while(day+pday>d[month])
	{
		pday-=(d[month]-day+1);
		month++;
		day=1;
		if(month==13)
		{month=1;
		year++;
		if(pday&&(year%4==0&&year%100!=0)||pday&&(year%400==0))
d[2]=29;
else d[2]=28;
		}
	}
	day+=pday;	
	
	sprintf(a,"%d.%02d.%02d",year,month,day);
strcpy(data[i],a);

		
		
		
		
		year=2016;month=10;day=20;
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",data[i]);
		
		
	}

}
