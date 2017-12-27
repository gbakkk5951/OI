#include<cstdio>
int getphi(int num){
	int ans=num;int rem=num;int i;	

	for(i=2;i*i<=num;i++){
		if(rem%i==0){
			ans=ans/i*(i-1);
			do{
				rem/=i;
			}while(rem%i==0);
		}
	}
	if(rem>1){
		ans=ans/rem*(rem-1);
	}return ans;
	
}

int main(){
	int p;
	while(~scanf("%d",&p)){
		printf("%d\n",getphi(getphi(p)));
	}
	
} 
