#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
	srand(time(0));
	freopen("data.in","w",stdout); 
	int n=rand()%233+1,m=rand()%233+1;
	int i,j;
	printf("%d %d\n",n,m);
	for(i=0;i<n;i++){
		for(j=1;j<m;j++){
			printf("%d ",rand()%23334);
		}
		printf("\n");
	}
	for(i=0;i<m;i++){
		for(j=1;j<n;j++){
			printf("%d ",rand()%23334);
		}
		printf("\n");
	}
	fclose(stdout);
} 
