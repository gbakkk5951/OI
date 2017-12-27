#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;


bool isprime1(int num){
	int i;
	int g=sqrt(num);
	for(i=2;i<=g;i++){
		if(num%i == 0){
			return false;
		}
	}
	return true;
}
bool isprime2(int num){
	int i;
	for(i=2;i*i<=num;i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	float a,b,c,d;
	int i,j,k;
	a=clock();
	for(i=2;i<5000000;i++){
		
		isprime2(i);
	}
	b=clock();
	printf("%f\n",b-a);
	for(i=2;i<5000000;i++){
		isprime1(i);
	}
	c=clock();
	printf("%f",c-b);
}
