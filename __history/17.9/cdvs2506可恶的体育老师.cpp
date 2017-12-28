using namespace std;
int main(){}
#include<cstdio>
#include<cctype>

struct _Main{
int n;
int ph[70];int atk[70];	
	
_Main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&ph[i],&atk[i]);
	}scanf("%d%d",&atk[n],&ph[n]);
	for(i=0;i<n;i++){
		ph[n]-=((ph[i]+atk[n]-1)/atk[n]-1)*atk[i];
	}
	if(ph[n]>0){
		printf("yes!!very good");
	}else{
		printf("oh shit!");
	}

}	
	
	
	
	
	
	
}cdvs2506;
