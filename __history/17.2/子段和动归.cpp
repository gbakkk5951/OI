#include<cstdio>


#define ini long long i=0,j=0,k=0;
#define tp long long
tp arr[200010];
tp aux[200010];

tp max(tp a,tp b){
	return a>b?a:b;
}
int n,q;
tp query(int l,int r){
	ini
	aux[l]=arr[l];
	j=aux[l];
	for(i=l+1;i<=r;i++){
		aux[i]=max(aux[i-1]+arr[i],arr[i]);
		j=max(j,aux[i]);
	}
	return j;
}
void  readin(){
	ini
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&arr[i+1]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d",&j,&k);
		printf("%lld\n",query(j,k));
	}
	
}

int main(){	readin();};
