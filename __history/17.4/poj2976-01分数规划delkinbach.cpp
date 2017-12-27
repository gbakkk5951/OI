#include<cstdio>
#include<algorithm>
#include<cmath>
#include<functional>
#define eps 1e-8
using namespace std;
struct _Main{
	struct fs{
		double d,a,b;
		bool friend operator < (fs in1,fs in2){
			return in1.d>in2.d;
		}
	}d[1010];
int n,k;
double ans;
int a[1010],b[1010];
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
void refresh(double l){
	int i,j;
	double as=0;
	for(i=0;i<n;i++){
		d[i].d=(double)a[i]-l*b[i];
		d[i].a=a[i];
		d[i].b=b[i];
	}sort(d,d+n);
}

void binary_search(){
	double l=0.0,mid,t;
	int j=n-k,i;
	double a1,b1;
	do{
		ans=l;a1=0;b1=0;
		refresh(l);
		for(i=0;i<j;i++){
			a1+=d[i].a;b1+=d[i].b;
		}
		l=a1/b1;
	}while(abs(ans-l)>=eps);
	ans=round(ans*100);
	
}	
}instance;int main(){}
