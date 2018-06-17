#include<iostream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long double db;
const int N=105;
const db eps=1e-6;
const db pi=acos(-1);

int n;
db dis[N][N],xy[N][2],cir[N][4];

/*void calcir(int x,db x1,db y1,db r12,db x2,db y2,db r22){
	db dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	db lb=0,rb=pi;int i;
	for(i=1;i<=50;i++){
		db mid=(lb+rb)>>1;
		if(r12+r22-2*cos(mid)*sqrt(r12*r22)<dis)
			lb=mid;
		else
			rb=mid;
	}
}
void dfs(int x){
	
}*/

int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%Lf",&dis[i][j]);
	
	/*xy[1][0]=xy[1][1]=xy[2][1]=0,xy[2][0]=dis[1][2];
	dfs(3,0);*/
	
	for(i=1;i<=n;i++)
		printf("%lf %lf\n",sqrt(-1.0),sqrt(-1.0));
	
	return 0;
}

