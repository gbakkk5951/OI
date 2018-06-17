#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-3;
const int N=105;
struct A{
	db x,y;
}a[N];
db d[N][N],l;
int n;
db dis(A a,A b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
void out(){
	for(int i=1;i<=n;i++)
		printf("%lf %lf\n",a[i].x,a[i].y);
}
void dfs(int x){
	if(x>n){out();exit(0);}
	int i;db t,f1=0,f2=0;
	t=(l*l+d[x][1]*d[x][1]-d[x][2]*d[x][2])/(2*l*d[x][1]);
	a[x]=(A){t*d[x][1],sqrt(1-t*t)*d[x][1]};
	for(i=1;i<x;i++)
		f1=max(f1,fabs(dis(a[i],a[x])-d[i][x]));
	a[x]=(A){t*d[x][1],-sqrt(1-t*t)*d[x][1]};
	for(i=1;i<x;i++)
		f2=max(f2,fabs(dis(a[i],a[x])-d[i][x]));
	if(f1<f2) a[x]=(A){t*d[x][1],sqrt(1-t*t)*d[x][1]};
	dfs(x+1);
}
int main(){
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	int i,j;double x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%lf",&x);
			d[i][j]=x;
		}
	l=d[1][2];
	a[1]=(A){0,0};a[2]=(A){l,0};
	dfs(3);
	return 0;
}
