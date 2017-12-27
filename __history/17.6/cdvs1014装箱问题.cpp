using namespace std;
int main(){}
#include<cstdio>
struct _Main{
bool dp[20010];
int v;
int n;
int size[31];
_Main(){
	int used=0;
	int i,j,k;
	scanf("%d%d",&v,&n);
	for(i=0;i<n;i++){
		scanf("%d",size+i);
	}
	for(i=0;i<n;i++){
		for(j=v-size[i];j>=0;j--){
			if(dp[j]){
				dp[j+size[i]]=1;
			}
		}
		dp[size[i]]=1;
	}
	for(i=v;i>=0;i--){
		if(dp[i]){
			used=i;
			break;
		}
	}
	printf("%d",v-used);
}
	
	
	
	
	
	
	
	
	
	
	
}cdvs1014; 
