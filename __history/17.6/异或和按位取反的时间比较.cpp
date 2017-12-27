using namespace std;
int main(){}

#include<cstdio>
#include<ctime>
struct _Main{
_Main(){
	float a,b,c,d;
	int i,j,k;
	
	
	for(i=0;i<5000;i++){
		k++;
	}
	k=15;
	k=getchar();
	a=clock();
	for(i=0;i<50000000;i++){
		k=~k;
		k=~k;
		k=~k;
		k=~k;
		k=~k;
		k=~k;
		k=~k;
		k=~k;
		k=~k;
		k=~k;			
	}
	k=15;
	b=clock();
	k=getchar();
	c=clock();
	for(i=0;i<50000000;i++){
		k=k^(-1);
		k=k^(-1);
		k=k^(-1);
		k=k^(-1);
		k=k^(-1);
		k=k^(-1);		
		k=k^(-1);
		k=k^(-1);
		k=k^(-1);
		k=k^(-1);
	}

	d=clock();
	printf("%f\n%f",b-a,d-c);
}
	
	
}tst;
