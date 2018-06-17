#include<stdio.h>
int n;
int A[10];
int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&A[i]);
	if(n==1){
		if(A[1]==1)printf("%d",A[1]);
		else printf("no solution");
		return 0;
	}
	else if(n==2){
		for(int x=-2000;x<=2000;x++)
		for(int y=-2000;y<=2000;y++)
		if(A[1]*y-A[2]*x==1){
			printf("%d %d\n%d %d\n",A[1],A[2],x,y);
			return 0;
		}
		printf("no solution");
	}
	else printf("no solution");
	return 0;
}
