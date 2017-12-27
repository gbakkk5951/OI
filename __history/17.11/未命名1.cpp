using namespace std;
int main(){}
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
struct _Main{
	double arr[10000050];
_Main(){
	double i;
	float a,b;
	a=clock();
	for(i=1.0;i<=10000000.0;i+=1.0){
		arr[(int)i]=sqrt(i);
	}
	b=clock();
	if(arr[rand()]>10){
		b-=1;
		b+=1;
	}else{
		a+=1;
	}
	printf("%f",b-a);
}
	
	
	
}tester;


