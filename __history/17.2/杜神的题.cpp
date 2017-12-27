#include<cstdio>
double po(int n);
int main(){
	int i,j;
	int ans=1;
	int n;
	while(1){
		scanf("%d",&n);
		double temp=1.0;
		
		printf("%f\n",po(n*(n+1)/2));
		
		ans=1;
	}
	
	
}
double po(int n){
	if(n==1){
		return (double)(1+1.0/3);
	}
	double temp=po(n/2);
	temp*=(double)temp;
	if(n&1){
		temp*=(double)1+(1.0/3);
	}
	return temp;
	
}
