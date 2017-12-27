#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;


inline int max(int a,int b){
	return (a+b+abs(a-b))>>1;
}
inline int max_old(int a,int b){
	return a>b?a:b;
}
inline int abs(int a){
	return (a>>31^((a>>31)+a));
}
int main(){
	float a,b,c,d;
	int i,j,k;
	a=clock();
	for(i=0;i<10000000;i++){
		j=max_old(i,rand());
	}	

	b=clock();
	printf("%f\n",b-a);
	for(i=0;i<10000000;i++){
		
		//j=max(i,rand());
		scanf("%d%d",&j,&k);
		printf("%d\n",max(j,k));
	}


	c=clock();
	printf("%f\n",c-b);


}
