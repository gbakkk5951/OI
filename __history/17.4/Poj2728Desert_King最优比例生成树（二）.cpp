#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;


struct _Main{
int n;
double val[1010];
int x[1010],y[1010],z[1010];	
double from[1010];
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
	double a1=0,b1=0;int i,j,k;
	double v;
	
	for(i=1;i<n;i++){
		val[i]=h(0,i)-l*dis(0,i);
		from[i]=0;
	}
	in[0]=true;
	int left = n-1;
	while(left){
		double mv=21474836481.5;int mp;
		for(i=1;i<n;i++){
			if(!in[i]&&val[i]<mv){
				mv=val[i];
				mp=i;
			}
		}
		in[mp]=true;
		left--;
		a1+=h(from[mp],mp);
		b1+=dis(from[mp],mp);
		for(i=0;i<n;i++){
			if(!in[i]){
				if(val[i]>(v=h(mp,i)-l*dis(mp,i))){
					val[i]=v;
					from[i]=mp;
				}
			}
		}
			
		
	}

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
