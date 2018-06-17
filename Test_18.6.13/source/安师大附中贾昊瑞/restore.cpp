#include"bits/stdc++.h"
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(register int i=j;i>=n;i--)
#define ll long long
#define N 110
using namespace std;
void in(int&a);void in(ll&a);
int n,eps=1e-5,k;double f[N][N];long double xx,yy,x,y;
bool fca(double x,double y){
	return x-y<eps&&y-x<eps;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	#endif
	in(n);
	F(i,1,n)F(j,1,n)scanf("%lf",&f[i][j]);
	printf("0.0000000000 0.0000000000\n");
	printf("%.10lf 0.0000000000\n",f[1][2]);
	F(i,3,n){
		if(fca(f[1][i]+f[2][i],f[1][2])||fca(f[1][i]-f[2][i],f[1][2])){
			printf("%.10lf 0.0000000000\n",f[1][i]);
			continue;
		}
		if(fca(-f[1][i]+f[2][i],f[1][2])){
			printf("%.10lf 0.0000000000\n",-f[1][i]);
			continue;
		}
		x=(f[1][2]*f[1][2]+f[1][i]*f[1][i]-f[2][i]*f[2][i])/2/f[1][2];
		y=sqrt(f[1][i]*f[1][i]-x*x);
		if(k){
			if(!fca(f[k][i]*f[k][i],(x-xx)*(x-xx)+(y-yy)*(y-yy)))y=-y;
		}
		else{
			k=i;
			xx=x;yy=y;
		}
		printf("%.10lf %.10lf\n",(double)x,(double)y);
	}
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=0;c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=0;c=getchar();}if(y)a=-a;}

