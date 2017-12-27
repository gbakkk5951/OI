#include<cstdio>
#include<cmath>
struct _Main{
int inline max(int a,int b){
	return a>b?a:b;
}	
_Main(){
	int a1=0;
	int i,n,p;
	scanf("%d",&n);
	p=sqrt(n);
	for(i=2;i<=p;i++){
		if(!(n%i)){
			a1=i;
			n/=i;
			break;
		}
	}
	printf("%d",max(a1,n));
	
}	
	
	
	
}cdvs1313;int main(){}
