#include<cstdio>
#include<cstdlib>
#include<ctime>


int abs(int in){
	int y=in>>31;	
	return (y+in)^y;
}
int aabs(int in){
	z=in>>31;	
	return (z+in)^z;
}
int main(){
	float a,b,c;
	int n;
	int i,j,k;
scanf("%*d");
	a=(float)clock()/CLOCKS_PER_SEC;
	for(k=0;k<3;k++)
	for(i=0;i<100000000;i++){

		j=abs(i);
	}
	b=(float)clock()/CLOCKS_PER_SEC;
	printf("%f\n",b-a);
	
	for(k=0;k<3;k++)
	for(i=0;i<100000000;i++){
		j=aabs(i);
	}
	c=(float)clock()/CLOCKS_PER_SEC;
	printf("%f\n",c-b);	
}
