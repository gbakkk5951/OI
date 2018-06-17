#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define eps 1e-4
#define eqs 1e-7
using namespace std;
struct rylx{
	double x,y;
}ans[105];
struct ryll{
	rylx l,r;
};
double d[105][105];
int n;
int ryl(){
	int r=0,z=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')z=-1;c=getchar();
	}
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	return r*z;
}
ryll get(int x){
	double b=2*ans[2].y;
	double c=-ans[2].y*ans[2].y-d[1][x]*d[1][x]+d[2][x]*d[2][x];
	double t2=-c/b;
	ryll p;
	p.r.y=p.l.y=t2;
	p.l.x=sqrt(-t2*t2+d[1][x]*d[1][x]);
	p.r.x=-sqrt(-t2*t2+d[1][x]*d[1][x]);
	return p;
}
double get_dist(rylx x,rylx y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
bool jud(int x,ryll t){
	int jsq=0;
	for(int i=1;i<x;i++){
		//cout<<d[i][x]<<" "<<get_dist(ans[i],t)<<'\n';
		double t1=fabs(d[i][x]-get_dist(ans[i],t.l)),t2=fabs(d[i][x]-get_dist(ans[i],t.r));
		if(t1-t2>eps)return 0;
		if(t2-t1>eps)return 1;
		if(t1>t2&&t1-t2>eqs)jsq--;
		if(t2>t1&&t2-t1>eqs)jsq++;
	}
	//cout<<"haha"<<jsq<<'\n';
	return jsq>0;
}
int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	n=ryl();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%lf",&d[i][j]);
	}
	ans[1].x=0,ans[1].y=0;
	ans[2].x=0;ans[2].y=d[1][2];
	for(int i=3;i<=n;i++){
		ryll p=get(i);
	//	cout<<i<<" "<<jud(i,p.l)<<' '<<jud(i,p.r)<<'\n';
	//	cout<<"##"<<jud(i,p)<<"\n";
		if(i<=3)ans[i].x=p.l.x,ans[i].y=p.l.y;
		else if(jud(i,p))ans[i].x=p.l.x,ans[i].y=p.l.y;
		else ans[i].x=p.r.x,ans[i].y=p.r.y;
	}
	for(int i=1;i<=n;i++)printf("%0.6lf %0.6lf\n",ans[i].x,ans[i].y);
	return 0;
}

