#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int arr[10000000];
int main(){
	float a,b,c;
	int i,j,k;
	a=clock();
	for(i=0;i<10000000;i++){
		if(arr[i]=rand()){
		
		}
	}

	b=clock();
	printf("%f\n",b-a);

	for(i=9999999;i>=0;i--){
		if(arr[i]=rand()){
			
		}
	}	
	c=clock();
	printf("%f\n",c-b);
}
