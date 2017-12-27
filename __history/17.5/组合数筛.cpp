#include<cstdio>
	int c[11][11];
int main(){
	int i,j,k;

	c[0][0]=1;
	printf("%d\n",1);
	for(i=1;i<=10;i++){
		c[0][i]=1;
		printf("1 ");
		for(j=1;j<=i;j++){
			c[j][i]=c[j-1][i-1]+c[j][i-1];
			printf("%d ",c[j][i]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
