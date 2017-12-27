#include<cstdio>
#define ubt int 
#define omt int
#define ont int
struct begin{
ubt max (ubt a,ubt b){
	return a>b?a:b;
}
ont max(ont a,ont b,ont c){
	int mx=max(a,b);

	return max(mx,c);
}

int arr[200010]; 
ubt n;
ubt q;
void readin()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d",&j,&k);
		j--;k--;
		printf("%d\n",subquery(j,k));
		
	}
	
}


begin(){
	readin();
}
int subquery(int l,int r){
	if(l==r){
		return arr[l]/*>0?arr[l]:0*/;
	}
	int mid=(l+r)>>1;
	int lm=-2147483648,rm=-2147483648;
	int i,j=0,k=0;
	for(i=mid+1;i<=r;i++){
		j+=arr[i];
		lm=max(lm,j);		
	}
	for(i=mid;i>=l;i--){
		k+=arr[i];
		rm=max(rm,k);
	}
	return max(subquery(l,mid),subquery(mid+1,r),lm+rm);
	
}
	
	
	
}instance;






omt main(){}


