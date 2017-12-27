#include<cstdio>
int main(){
	freopen("super.in","w",stdout);
	int i,j,k;
	for(i=0;i<500;i++)
	printf("1");
	printf("\n");
	for(j=0;j<2000;j++){
	for(i=0;i<499;i++)
		printf("1");
		printf("2");
	}
	fclose(stdout);
}
