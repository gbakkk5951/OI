#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int get(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
double d[505][505];
struct node{double x,y;}p[505];
int n;
void work(int x){
	double d1=d[x][1],d2=d[x][2],d3=d[1][2];
	double pp=(d1*d1+d3*d3-d2*d2)/(2*d1*d3);
	double k=acos(pp);
	p[x].x=cos(k)*d1;
	p[x].y=sin(k)*d1;
//	cout<<"ans"<<d1<<" "<<k<<endl;
//	cout<<p[x].x<<" "<<p[x].y<<endl;
	for(int i=1;i<x;i++){
//		cout<<i<<" "<<x<<" "<<sqrt((p[x].x-p[i].x)*(p[x].x-p[i].x)+(p[x].y-p[i].y)*(p[x].y-p[i].y))<<" "<<d[x][i]<<endl;
//		cout<<"mfld"<<fabs(sqrt((p[x].x-p[i].x)*(p[x].x-p[i].x)+(p[x].y-p[i].y)*(p[x].y-p[i].y))-d[x][i])<<' '<<1e-3<<endl;
		if(fabs(sqrt((p[x].x-p[i].x)*(p[x].x-p[i].x)+(p[x].y-p[i].y)*(p[x].y-p[i].y))-d[x][i])>1e-3) p[x].y=-p[x].y;//,cout<<i<<endl;
	}
}
int main(){
  freopen("restore.in","r",stdin);
  freopen("restore.in","w",stdout);
	n=get();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&d[i][j]);
	p[1].x=p[1].y=0;
	p[2].x=d[1][2];p[2].y=0;
	for(int i=3;i<=n;i++) work(i);
	for(int i=1;i<=n;i++)
		printf("%.6lf %.6lf\n",p[i].x,p[i].y);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) printf("%.6lf ",d[i][j]);
//		cout<<endl;
//	}
	return 0;
}
/*
3
0.000000 0.231874 0.853317
0.231874 0.000000 0.637852
0.853317 0.637852 0.000000
*/
