using namespace std;
#include<cstdio>
int val[30];
int main(){
	int n;int i;int j;int k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&val[i]);		
	}
	if(val[0]==0 && val[n-1]==0){
		printf("NO");
		return 0;
	}
	
	for(j=0;j<n;j++){
		if(val[j]==0)break;
	}
	for(k=n-1;k>=0;k--){
		if(val[k]==0)break;
	}

	if((n-k-1)&1 || j&1)printf("YES");
	else printf("NO");

	
}
