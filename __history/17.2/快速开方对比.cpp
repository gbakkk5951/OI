#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
int isqrt(float a)
{
	if(a==0)
	return 0;
	float result=a;
	float xhalf=0.5f*a;
	int i=*(int*)&result;
	i=0x5f375a86-(i>>1);
	result=*(float *)&i;
	result=result*(1.5f-xhalf*result*result);
	result=result*(1.5f-xhalf*result*result);
	return 1.0f/result;
	
}

int main()
{
int i=0;


float b1,b2,b3;
b1=(float)clock()/CLOCKS_PER_SEC;
for(i=0;i<10e8;i++)	
sqrt(i);
b2=(float)clock()/CLOCKS_PER_SEC;
printf("cmath开方用时%f\n",b2-b1);
for(i=0;i<10e8;i++)
isqrt(i);
b3=(float)clock()/CLOCKS_PER_SEC;
printf("快速开方用时%f",b3-b2);
	
	
}
