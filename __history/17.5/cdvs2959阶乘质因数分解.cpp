#include<cstdio>
using namespace std;
bool unprime[100010];
int prime[9600];
int tot;
struct _Main{
void getprime(){
	int i,j,k;
	for(i=2;i<=n;i++){
		if(!unprime[i]){
			prime[tot++]=i;
			for(j=i+i;j<=n;j+=i){
				unprime[j]=true;
			}
		}
	}
	
}
int n;
_Main(){
	int i,j,k;
	scanf("%d",&n);
	getprime();
	for(i=0;i<tot&&n>=prime[i];i++){
		k=0;
		for(j=prime[i];j<=n;j*=prime[i]){
			k+=n/j;
		}
		printf("%d ",k);
	}

	
}	
	
	
}cdvs2959;
int main(){}
