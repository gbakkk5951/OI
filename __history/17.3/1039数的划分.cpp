#include<cstdio>
int n,k;
unsigned long long val;
int main(){
	int dfs(int nm,int km,int val);
	int i,j;
	scanf("%d%d",&n,&k);
	val=dfs(n,k,1);
	printf("%llu",val);	
}
unsigned long long dfs(int nm,int km,int val){
	if(km==1){
		if(nm>=val)
		return 1;
		return 0;
	}
	int i;
	unsigned long long ans=0;
	int g=nm/km;
	for(i=val;i<=g;i++){
		ans+=dfs(nm-i,km-1,i);
	}
	return ans;
}
