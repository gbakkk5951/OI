#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int arr[1000005];
struct Main{
Main(){
	getchar();
	int i,j,k;	
	float a,b,c,d;
	for(i=0;i<1000000;i++){
		arr[i]=rand();
	}
	a=clock();
	i=-1000;
	while(i++){
		find1(i);
	}
	b=clock();
	printf("find1:%f\n",b-a);
	i=-1000;
	while(i++){
		find2(i);
	}
	c=clock();
	printf("find2:%f\n",c-b);
	i=-1000;
	while(i++){
		find3(i);
	}
	d=clock();
	printf("find3:%f\n",d-c);
/*	i=100000;
	while(i--){
		find3(i);
	}
	a=clock();	
	printf("find4:%f\n",a-d);
*/	
	system("pause");
}
int find1(int val){
	int i;
	for(i=0;i<1000000;i++){
		if(arr[i]==val){
			return i;
		}
	}return -1;
}
int find2(int val){
	int i=0;
	arr[1000000]=val;
	while(1){
		if(arr[i]==val)
			break;
		i++;
	}
	if(i!=1000000)return i;
	return -1;
}
int find3(int val){
	int i;
	for(i=0;i<1000000;i+=8){
		if(arr[i]==val){
			break;
		}
		if(arr[i+1]==val){
			i+=1;
			break;
		}		
		if(arr[i+2]==val){
			i+=2;
			break;
		}		
		if(arr[i+3]==val){
			i+=3;
			break;
		}		
		if(arr[i+4]==val){
			i+=4;
			break;
		}		
		if(arr[i+5]==val){
			i+=5;
			break;
		}
		if(arr[i+6]==val){
			i+=6;
			break;
		}
		if(arr[i+7]==val){
			i+=7;
			break;
		}				
	}
	if(i<1000000){return i;
	}return -1;
}


}instance;int main(){}


