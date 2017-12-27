#include<cstdio>
#include<cmath>
int main(){
	int n,i,j,g;
	scanf("%d",&n);
	g=sqrt(n);
	printf("%d=",n);
	for(i=2;i<=g;i++){

		if(!(n%i)){
			if(n==i){
				printf("%d",i);
				return 0;
			}			
			printf("%d*",i);
			n/=i;
			i--;
		}

		
	}
	if(n!=1){
		printf("%d",n);
	}
	
	
	
}
