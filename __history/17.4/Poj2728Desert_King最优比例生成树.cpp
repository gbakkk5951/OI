#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;


struct _Main{
struct edge;
priority_queue <edge> heap;
struct edge{
	int to,from;double val;
bool friend operator < (edge a,edge b){
	return a.val > b.val;
}
};
int n;
int x[1010],y[1010],z[1010];	
bool in[1010];
int read(){
	char t,f=1;int ans=0;
	while((t=getchar())<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
	}
	do{
	ans*=10;ans+=t-'0';
	}while((t = getchar()) <= '9' && t >= '0');
	return f*ans;
}
double dis(int a,int b){
	return sqrt((double)(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double h(int a,int b){
	return fabs((double)z[a]-z[b]);
}
double prim(double l){
	memset(in,0,sizeof(in));
	double a1=0,b1=0,ret=0;int i,j,k;
	double v;
	edge t;
	for(i=1;i<n;i++){
		t.from=0;
		t.to=i;
		t.val=h(0,i)-l*dis(0,i);
		heap.push(t); 
	}
	in[0]=true;
	int left = n-1;
	while(left){
		t=heap.top();
		heap.pop();
		if(!in[t.to]){
			left--;
			ret+=t.val;
			a1+=h(t.from,t.to);
			b1+=dis(t.from,t.to);
			t.from=t.to;
			in[t.from]=true;
			for(i=0;i<n;i++){
				if(!in[i]){
					t.to=i;
					t.val=h(t.from,i)-l*dis(t.from,i);
					heap.push(t); 
				}
			}
			
		}
	}
	while(!heap.empty())heap.pop();
	return a1/b1;
	
	
}
_Main(){
	int i,j,k;
	while(n=read()){
		for(i=0;i<n;i++){
			x[i]=read();y[i]=read();z[i]=read();
		}
		delkinbach();
	}
}
double ans;
void delkinbach(){
double l=0;	
	do{ans=l;
	l=prim(l);
	}while(fabs(l-ans)>eps);
	printf("%.3f\n",ans);
}
	
	
	
	
}instance;int main(){}
