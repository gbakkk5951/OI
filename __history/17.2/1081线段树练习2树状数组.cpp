#include<cstdio>
#define lb(x) x&(-x)
int b[200010];
int n;
int add(int x,int v){
	
	for(x;x;x-=lb(x))
	b[x]+=v;	
}
int sum(int x){
	int sl=0;
int l;
		for(l=x;l&&l<=n;l+=lb(l)){
			sl+=b[l];
		}
	return sl;
}


int main(){
int i,j,k,l,m;
	int q;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		add(i,j);
		add(i-1,-j);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&j);
		if(j==1){
			scanf("%d%d%d",&k,&l,&m);
			add(k-1,-m);
			add(l,m);
		}else{
			scanf("%d",&k);
			printf("%d\n",sum(k));
		}
	}
	
	
}
