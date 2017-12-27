#include<cstdio>
#include<cstring>
#define app struct
#define tp unsigned
app begin{
int nu;
int cnt;
unsigned int sz[31];
void ex(tp &a,tp &b){
	tp t=a;
	a=b;
	b=t;
}


begin(){
	unsigned int i,j,k,l,t;
scanf("%d",&nu);
for(cnt=1;cnt<=nu;cnt++)
{
	
	

	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++){
			scanf("%d",&t);
				if(i)
				sz[i*6+j]+=1<<(i*6-6+j+1);
				if(j)
				sz[i*6+j]+=1<<(i*6+j-1+1);
				if(i!=4)
				sz[i*6+j]+=1<<(i*6+6+j+1);
				if(j!=5)
				sz[i*6+j]+=1<<(i*6+j+1+1);
				sz[i*6+j]+=1<<(i*6+j+1);
				if(t)sz[i*6+j]+=1;
		}
	}

	gauss();
	
	/*test*/
	/*for(k=0;k<30;k++)
	{
	printf("[%d]",k);
	printf("%d=",sz[k]&1);
	for(i=0;i<5;i++){
		
		
		
		for(j=0;j<5;j++){
			printf("%d ",(sz[k]&(1<<(i*6+j+1)))>>(i*6+j+1));
		}
		printf("%d ",(sz[k]&(1<<(i*6+j+1)))>>(i*6+j+1));
	}
	printf("\n");
	}*/
	/*test end*/	
	
	printf("PUZZLE #%d\n",cnt);
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",(sz[30]&(1<<(i*6+j+1)))>>(i*6+j+1));
		}
		printf("%d\n",(sz[30]&(1<<(i*6+j+1)))>>(i*6+j+1));
	}
	memset(sz,0,sizeof(sz));
	
}
}
void gauss(){
	int i,j,k,l,m,n;
	for(i=0;i<=30;i++){
		for(j=i;j<30;j++){
			if(sz[j]&(1<<(i+1))){
				ex(sz[j],sz[i]);
				break;
			}
		}
		for(j=i+1;j<30;j++){
			if(sz[j]&(1<<(i+1)))
				sz[j]^=sz[i];
		}
	}
	for(i=29;i>=0;i--){
		if(sz[i]&1){
			sz[30]+=1<<(i+1);
		}
		for(j=i-1;j>=0;j--){
			if(sz[j]&(1<<(i+1)))
				sz[j]^=sz[i];
		}
	}
	
	
	
	
}




}instance;int main(){} 
