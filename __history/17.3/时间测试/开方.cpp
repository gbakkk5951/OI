#include<cstdio>
#include<cmath>
#include<ctime>
inline float qsqrt(float number){
	    int i;  
    float x2, y;  
    const float threehalfs = 1.5F;  
  
    x2 = number * 0.5F;  
    y  = number;  
    i  = * ( int * ) &y;       
    i  = 0x5f375a86 - ( i >> 1 );   
    y  = * ( float * ) &i;  
    y  = y * ( threehalfs - ( x2 * y * y ) );   
y  = y * ( threehalfs - ( x2 * y * y ) );     
y  = y * ( threehalfs - ( x2 * y * y ) );   
    return number*y;  
	
}
int main(){
	double a,b,c;
	int i,j,k;

	a=(double)clock()/CLOCKS_PER_SEC;
	for(i=0;i<5000000;i++){
		sqrt((float)i);
	}
	b=(double)clock()/CLOCKS_PER_SEC;
	printf("%f\n",b-a);
	for(i=0;i<5000000;i++){
		sqrt((float)i);
	}
	c=(double)clock()/CLOCKS_PER_SEC;
	printf("%f\n",c-b);	
}
