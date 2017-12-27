#include<cstdio>
#define lb(x) (x&-x)
#define tp long long
int c[200010];
int n;
int q;
void change(int x,tp v)
{
	
	printf("x=%d;",x);
	while(x<n)
	{
	
		c[x]+=v;
		printf("[%d]=%d;",x,c[x]);
		x+=lb(x);
	}
	
	
}

tp query(int l,int r){
	l--;
	tp tr=0,tl=0;
	if(l)
	while(l>0){
		tl+=c[l];
		l-=lb(l);
	}
	while(r>0){
		tr+=c[r];
		r-=lb(r);
	}
	return (tr-tl);
}



int main(){
	
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&j);
		printf("cg");
		change(i,j);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d",&j,&k,&l);
		if(j==1)
		change(k,(tp)l);
		else
		printf("%lld\n",query(k,l));
	}
	
}
