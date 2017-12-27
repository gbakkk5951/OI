#include<cstdio>
#include<ctime>
struct _Main{
_Main(){
	long long i,j,k;
	float a,b,c,d,e;
	a=clock();
	for(k=0;k<1;k++){	
		for(i=0;i<100000000;i++){
			j=j+i*258;
		}
	}

	b=clock();
	printf("%f\n",b-a);
	for(k=0;k<1;k++){
		for(i=0;i<100000000;i++){
			j=j+(i<<8)+(i<<1);
		}		
		
	}

	
	c=clock();
	printf("%f\n",c-b);
}
	
	
	
}test;
int main(){}
