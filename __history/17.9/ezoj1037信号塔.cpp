using namespace std;
int main(){}
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
int n;
double sqsum;
const double eps=1e-6;
const double pi=3.141;
struct Point{
	double d1,d2;
	
struct less1{
	bool operator () (const Point &a,const Point &b){
		return a.d1<b.d1;
	}
};	
struct less2{
	bool operator () (const Point &a,const Point &b){
		return a.d2<b.d2;
	}
};	
struct greater2{
	bool operator () (const Point &a,const Point &b){
		return a.d2>b.d2;
	}
};			
}arr[100010],org[2];
template<typename Type>
Type inline pf(Type a){
	return a*a;
}
priority_queue<Point,vector<Point>,Point::greater2 > heap;
struct _Main{

_Main(){
	while(~scanf("%d",&n)){
		int ans=0;
		int idx1;
		double r1,r2;int n2=0;
		double a,b;int i,j,k;
		scanf("%lf%lf%lf%lf%lf",&org[0].d1,&org[0].d2,&org[1].d1,&org[1].d2,&sqsum);
		sqsum/=pi;
		for(i=1;i<=n;i++){
			scanf("%lf%lf",&a,&b);
			arr[i].d1=sqrt(pf(a-org[0].d1)+pf(b-org[0].d2));
			arr[i].d2=sqrt(pf(a-org[1].d1)+pf(b-org[1].d2));
		}sort(arr+1,arr+n+1,Point::less1());
		for(idx1=n;idx1>0 && pf(arr[idx1].d1)>sqsum+eps;idx1--){
			heap.push(arr[idx1]);
		}
		for(;idx1>=0;idx1--){
			r1=arr[idx1].d1;
			r2=sqrt(sqsum-pf(r1));
			while(!heap.empty() && heap.top().d2 < r2+eps){
				heap.pop();n2++;
			}
			ans=max(ans,idx1+n2);
			heap.push(arr[idx1]);
		}
		printf("%d\n",n-ans);
		while(!heap.empty() )heap.pop();
	}
}	
	
}ezoj1037;



