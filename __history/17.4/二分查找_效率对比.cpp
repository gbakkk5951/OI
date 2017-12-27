#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int arr[1080];
int find1(int in){
	int l=0,r=1000;
	while(l^r){
		if(arr[(l+r)>>1]<in){
			l=((l+r)>>1)+1;
		}else{
			r=(l+r)>>1;
		}
		
	}
	if(arr[l]^in){
		return -1;
	}return l;
}
int find2(int t){
	int l=0;
	if(arr[511]<t)l=488;
	if(arr[l+256]<t)l+=256;
	if(arr[l+128]<t)l+=128;
	if(arr[l+64]<t)l+=64;
	if(arr[l+32]<t)l+=32;
	if(arr[l+16]<t)l+=16;
	if(arr[l+8]<t)l+=8;
	if(arr[l+4]<t)l+=4;
	if(arr[l+2]<t)l+=2;
	if(arr[l+1]<t)l+=1;
	if(arr[l]^t&&arr[l+1]==t)l++;
	//l++;-
	if(l>999||arr[l]^t){
		return -1;
	}return l;
}

inline int find3(int in){
	int *i=lower_bound(arr,arr+1000,in);
	if(*i==in)
		return i-arr;
	return -1;
}

int main(){
	float a,b,c,d,e,f;	
	int i,j,k;
	
	for(i=0;i<1000;i++){
		arr[i]=i;
	} 
	a=clock();
	for(k=1;k<1000000;k++)
	for(i=-1000;i<0/*00000*/;i++){
		find1(i);
	}
	b=clock();
	printf("%f\n",b-a);
	for(k=1;k<1000000;k++)
	for(i=-1000;i<0/*00000*/;i++){
		find2(i);
	}
	c=clock();
	printf("%f\n",c-b);	
	for(k=1;k<100000;k++)
	for(i=-1000;i<0/*00000*/;i++){
		find3(i);
	}
	d=clock();
	printf("%f\n",d-c);	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


