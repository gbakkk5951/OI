#include<cstdio>
int main(){
	int i=1;
	double temp=1;
	for(i=1;i<200;i++){
		printf("%d:%f\n",i,temp*=(1.0+1.0/3));
	}
}
