#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
	srand(time(0));
	int n=200000;
	int q=100000;
	int i;
	freopen("data.txt","w",stdout);
	printf("%d\n",n);
	
	for(i=0;i<n;i++){
		printf("%d ",rand()+1);
	}
	printf("\n%d\n",q);

	for(i=0;i<q;i++){
		if(rand()%2)
			printf("1 %d\n",rand()%n);
		else
			printf("2 %d %d\n",rand()%n,rand()+1);
	}
} 
