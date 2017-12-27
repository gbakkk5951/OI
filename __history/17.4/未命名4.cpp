#include<cstdio>
int main(){
	long long in, i;
	scanf("%lld",&in);
	for(i=2;i<in;i++){
		if(!(in%i)){
			printf("%lld\n",i);
		}
	}
	
	
} 
