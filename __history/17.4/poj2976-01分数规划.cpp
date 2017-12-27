#include<cstdio>
#include<algorithm>
#include<cmath>
#include<functional>
#define eps 1e-8
using namespace std;
struct _Main{
int n,k;
double ans;
int a[1010],b[1010];
double d[1010];
_Main(){
	int i,j;
	while(~scanf("%d%d",&n,&k)){
		if(!(n|k))return;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		binary_search();
		printf("%.0f\n",ans);
	}
}
double refresh(double mid){
	int i,j;
	double as=0;
	for(i=0;i<n;i++){
		d[i]=(double)a[i]-mid*b[i];
	}sort(d,d+n,greater<double>());
	j=n-k;
	for(i=0;i<j;i++){
		as+=d[i];
	}
	return as;
}

void binary_search(){
	double l=0.0,r=1.0,mid,t;
	do{
		mid=(l+r)/2.0;
		t=refresh(mid);
		if(t>0.0){
			l=mid;
		}else{
			r=mid;
		}
	}while(r-l>=eps);
	ans=round(r*100);
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
}instance;int main(){}
