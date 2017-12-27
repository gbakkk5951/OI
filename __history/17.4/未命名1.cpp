#include<cstdio>
#include<cmath>
int main(){
	int i,j,k;
	scanf("%lld",&i);
	j=sqrt(i);
	for(k=2;k<=j;k++){
		if(!(i%k))printf("%lld\n",k);
		
	}
	
}
