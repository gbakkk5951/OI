#include<cstdio>

int main(){
	int T,m,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n%(m+1)==0){
			printf("Rabbit\n");
		}else{
			printf("Grass\n");
		}
	}
}
