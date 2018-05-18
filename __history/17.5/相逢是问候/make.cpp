#include<cstdlib>
#include<ctime>
#include<cstdio>
long long L_rand(){
	long long ans=0;
	ans^=(long long)rand();
	ans^=(long long)rand()<<15LL;
	ans^=(long long)rand()<<30LL;
//	ans|=(long long)rand()<<45LL;
}
int main(){
	freopen("data20.in","w",stdout);
	srand(time(0));
	int n=50000;
	int m=50000;
	int p=L_rand()%100000000+5;	
	int c=2;
	int i;
	
	
	
	printf("%d %d %d %d\n",n,m,p,c);
	for(i=0;i<n;i++){
		if(i&1){
			printf("%d ",L_rand()%p);
			
		}else{
			printf("%d ",0);
		}
		
	}
	printf("\n");
	int l,r;
	for(i=0;i<m;i+=2){
		l=rand()%n+1;
		r=l+rand()%(n-l+1);
		printf("1 %d %d\n",l,r);
		printf("0 %d %d\n",l,r);
	}
	fclose(stdout);
	
	
	
}
