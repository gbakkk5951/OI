#include<stdio.h>
#include <algorithm> 
#include<cmath>
#include<vector>


using namespace std;
struct te
{
int a;
int b;	
}a;


int main()
{
	te operator + (const te x,const te y);
	te e[10];
	bool cmp(te ,te);
	int f;
	for(f=0;f<10;f++)
	{
		e[f].a =rand();
		
		
		
	}
	
	
	
	sort(&e[0],&e[9]+1,cmp);
	for(f=0;f<10;f++)
	{
		printf("%d\n",e[f].a );
		
	}
	
 } 
 
 bool cmp(te x,te y)
 {
 	return (x.a <y.a );
 	
 	
 }

 
 
te operator + (const te x,const te y)
{
	te c;
	c.a=x.a+y.a;
	c.b =x.b+y.b;
	return c;
	
	
	
}
